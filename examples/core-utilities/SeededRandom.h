#pragma once

#include <stdint.h>

class SeededRandom {
public:
    explicit SeededRandom(uint32_t seed) : state_(seed == 0 ? 0x6D2B79F5u : seed) {}

    uint32_t nextU32() {
        uint32_t x = state_;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        state_ = x;
        return x;
    }

    uint32_t range(uint32_t minimum, uint32_t maximumInclusive) {
        if (maximumInclusive <= minimum) {
            return minimum;
        }
        const uint32_t span = maximumInclusive - minimum + 1u;
        return minimum + (nextU32() % span);
    }

    float unitFloat() {
        return static_cast<float>(nextU32() & 0x00FFFFFFu) /
               static_cast<float>(0x01000000u);
    }

    bool chance(uint8_t percent) {
        return range(0, 99) < percent;
    }

    static uint32_t mix(uint32_t seed, uint32_t value) {
        uint32_t x = seed ^ (value + 0x9E3779B9u + (seed << 6) + (seed >> 2));
        x ^= x >> 16;
        x *= 0x7FEB352Du;
        x ^= x >> 15;
        x *= 0x846CA68Bu;
        x ^= x >> 16;
        return x == 0 ? 0xA5A5A5A5u : x;
    }

private:
    uint32_t state_;
};
