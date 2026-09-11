#include <cstdlib>
#include <iostream>

#include "MiniSpriteGenerator.h"

int main(int argc, char** argv) {
    uint32_t seed = 0xD3A01001u;
    if (argc > 1) {
        seed = static_cast<uint32_t>(std::strtoul(argv[1], nullptr, 0));
    }

    MiniSpriteGenerator generator;
    const MiniSprite sprite = generator.generate(seed);

    std::cout << "seed=" << seed
              << " pixels=" << generator.bodyPixels(sprite)
              << " symmetric=" << (generator.isSymmetric(sprite) ? "yes" : "no")
              << "\n\n";
    std::cout << generator.toAscii(sprite);
    return 0;
}
