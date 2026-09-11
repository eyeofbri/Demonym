# Simplified Procedural Sprite Demo

This is a small public sprite experiment based on a few ideas used in Demonym. It is not the production creature generator.

## Sprator reference

One project that helped me a lot early on was [yurkth/sprator](https://github.com/yurkth/sprator).

I found it while I was figuring out how I wanted small generated creatures to work. The mirrored/seeded procedural approach was especially useful as a reference. Demonym's actual generator changed a lot from there and now has its own Lineages, forms, stages, cleanup rules, palettes, faces, inheritance, and history systems.

I am keeping this demo much closer to the basic idea:

- deterministic seeded generation
- generate one side of a body
- do a small neighbor/smoothing pass
- mirror the result
- check that the same seed stays repeatable

## Run

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o sprite_demo
./sprite_demo
./sprite_demo 12345
```

Using the same seed should print the same ASCII creature.
