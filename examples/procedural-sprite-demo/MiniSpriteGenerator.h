#pragma once

#include <array>
#include <cstdint>
#include <string>

// Small public reference example.
// This is not Demonym's production SpriteGenerator.
// Early procedural-sprite work on Demonym was also helped by:
// https://github.com/yurkth/sprator

class MiniRandom {
public:
    explicit MiniRandom(uint32_t seed) : state_(seed == 0 ? 0x6D2B79F5u : seed) {}

    uint32_t next() {
        uint32_t x = state_;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        state_ = x;
        return x;
    }

    bool chance(uint8_t percent) { return (next() % 100u) < percent; }

private:
    uint32_t state_;
};

struct MiniSprite {
    static constexpr int WIDTH = 16;
    static constexpr int HEIGHT = 16;
    std::array<uint8_t, WIDTH * HEIGHT> pixels{};

    bool at(int x, int y) const {
        return pixels[static_cast<size_t>(y * WIDTH + x)] != 0;
    }
};

class MiniSpriteGenerator {
public:
    MiniSprite generate(uint32_t seed) const {
        MiniRandom random(seed);
        MiniSprite sprite{};

        // Generate only the left half. Bias the center rows toward a body and
        // leave the outer edge relatively sparse.
        for (int y = 2; y < MiniSprite::HEIGHT - 2; ++y) {
            for (int x = 2; x < MiniSprite::WIDTH / 2; ++x) {
                const int verticalDistance = (y > 7) ? y - 7 : 7 - y;
                const int horizontalDistance = (MiniSprite::WIDTH / 2 - 1) - x;
                int probability = 67 - verticalDistance * 4 - horizontalDistance * 3;
                if (probability < 18) probability = 18;
                if (random.chance(static_cast<uint8_t>(probability))) {
                    set(sprite, x, y, true);
                }
            }
        }

        // Guarantee a central core before smoothing.
        for (int y = 5; y <= 10; ++y) {
            set(sprite, 6, y, true);
            set(sprite, 7, y, true);
        }

        smoothLeftHalf(sprite, 2);
        mirror(sprite);
        return sprite;
    }

    bool isSymmetric(const MiniSprite& sprite) const {
        for (int y = 0; y < MiniSprite::HEIGHT; ++y) {
            for (int x = 0; x < MiniSprite::WIDTH / 2; ++x) {
                if (sprite.at(x, y) != sprite.at(MiniSprite::WIDTH - 1 - x, y)) {
                    return false;
                }
            }
        }
        return true;
    }

    int bodyPixels(const MiniSprite& sprite) const {
        int count = 0;
        for (uint8_t pixel : sprite.pixels) count += pixel ? 1 : 0;
        return count;
    }

    std::string toAscii(const MiniSprite& sprite) const {
        std::string out;
        for (int y = 0; y < MiniSprite::HEIGHT; ++y) {
            for (int x = 0; x < MiniSprite::WIDTH; ++x) {
                out += sprite.at(x, y) ? '#' : ' ';
            }
            out += '\n';
        }
        return out;
    }

private:
    static void set(MiniSprite& sprite, int x, int y, bool value) {
        if (x < 0 || y < 0 || x >= MiniSprite::WIDTH || y >= MiniSprite::HEIGHT) return;
        sprite.pixels[static_cast<size_t>(y * MiniSprite::WIDTH + x)] = value ? 1u : 0u;
    }

    static int neighbors(const MiniSprite& sprite, int x, int y) {
        int count = 0;
        for (int oy = -1; oy <= 1; ++oy) {
            for (int ox = -1; ox <= 1; ++ox) {
                if (ox == 0 && oy == 0) continue;
                const int nx = x + ox;
                const int ny = y + oy;
                if (nx >= 0 && ny >= 0 && nx < MiniSprite::WIDTH / 2 && ny < MiniSprite::HEIGHT && sprite.at(nx, ny)) {
                    ++count;
                }
            }
        }
        return count;
    }

    static void smoothLeftHalf(MiniSprite& sprite, int passes) {
        for (int pass = 0; pass < passes; ++pass) {
            MiniSprite next = sprite;
            for (int y = 1; y < MiniSprite::HEIGHT - 1; ++y) {
                for (int x = 1; x < MiniSprite::WIDTH / 2; ++x) {
                    const int count = neighbors(sprite, x, y);
                    if (sprite.at(x, y)) {
                        set(next, x, y, count >= 3);
                    } else {
                        set(next, x, y, count >= 5);
                    }
                }
            }
            sprite = next;
        }
    }

    static void mirror(MiniSprite& sprite) {
        for (int y = 0; y < MiniSprite::HEIGHT; ++y) {
            for (int x = 0; x < MiniSprite::WIDTH / 2; ++x) {
                set(sprite, MiniSprite::WIDTH - 1 - x, y, sprite.at(x, y));
            }
        }
    }
};
