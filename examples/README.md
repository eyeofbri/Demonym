# Public Code Examples

I am not putting the complete Demonym firmware in this repo. This folder has a few smaller pieces that I am comfortable keeping public.

## Small pieces from the real project

[`core-utilities/`](core-utilities/) contains three small headers based on the v0.9.22 source:

- `SeededRandom.h` - deterministic PRNG/mixing helper
- `ScreenRouter.h` - fixed-size screen history without heap allocation
- `AgeFormatter.h` - compact active-time formatting

These are small enough to share without opening up a major game system.

## Procedural sprite demo

[`procedural-sprite-demo/`](procedural-sprite-demo/) is a small desktop-only sprite generator. It is not the real Demonym `SpriteGenerator`.

When I first started experimenting with generated creatures, [yurkth/sprator](https://github.com/yurkth/sprator) helped a lot. The Demonym generator ended up becoming much larger and more specific to the game, but Sprator was one of the useful references behind the early approach.

The public demo keeps the idea simple: seeded cells, light cleanup, mirroring, and repeatable output.

## Persistence example

[`persistence-model/`](persistence-model/) shows one small recovery idea: when several checkpoint candidates exist, choose the newest one that has already passed validation.

It does not contain Demonym's record format, authentication code, NVS/SD code, migrations, or keys.

## Building locally

A C++17 compiler is enough for these public examples/tests. From the repo root on a Unix-like shell:

```bash
g++ -std=c++17 -Wall -Wextra tests/core_utilities_test.cpp -Iexamples/core-utilities -o /tmp/core_utils_test
/tmp/core_utils_test

g++ -std=c++17 -Wall -Wextra examples/procedural-sprite-demo/main.cpp -o /tmp/sprite_demo
/tmp/sprite_demo

g++ -std=c++17 -Wall -Wextra tests/procedural_sprite_test.cpp -o /tmp/procedural_sprite_test
/tmp/procedural_sprite_test

g++ -std=c++17 -Wall -Wextra tests/persistence_model_test.cpp -o /tmp/persistence_model_test
/tmp/persistence_model_test
```

GitHub Actions runs the same checks after a push or pull request.
