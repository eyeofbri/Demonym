#include <cassert>
#include <iostream>

#include "../examples/procedural-sprite-demo/MiniSpriteGenerator.h"

int main() {
    MiniSpriteGenerator generator;

    for (uint32_t seed = 1; seed <= 500; ++seed) {
        const MiniSprite first = generator.generate(seed);
        const MiniSprite second = generator.generate(seed);

        assert(first.pixels == second.pixels);
        assert(generator.isSymmetric(first));

        const int count = generator.bodyPixels(first);
        assert(count > 0);
        assert(count < MiniSprite::WIDTH * MiniSprite::HEIGHT);
    }

    std::cout << "simplified procedural sprite validation=PASS\n";
    return 0;
}
