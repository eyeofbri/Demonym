# Simplified Procedural Sprite Demo

This is a **public reference example**, not Demonym's production creature generator.

It demonstrates only a few concepts used by the real system:

- deterministic seeded generation
- generating one half of a body
- simple cellular-neighbor smoothing
- mirroring for symmetry
- validating repeatability/symmetry

The production generator is considerably larger and includes eight Lineages, life stages, Adult forms, multiple body-plan grammars, cleanup/component validation, palettes, faces, mutation/history marks, blink frames, and compatibility versioning.

## Run

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o sprite_demo
./sprite_demo
./sprite_demo 12345
```

Supplying the same seed produces the same ASCII organism.
