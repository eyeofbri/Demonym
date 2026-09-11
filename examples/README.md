# Public Code Examples

The examples in this directory are intentionally **not** the complete Demonym firmware.

They are selected to demonstrate code organization, deterministic logic, and embedded-oriented design while keeping the production game private.

## Production-derived utilities

[`core-utilities/`](core-utilities/) contains small headers derived directly from the v0.9.22 production source:

- `SeededRandom.h` — deterministic PRNG/mixing helper
- `ScreenRouter.h` — bounded menu/screen history without dynamic allocation
- `AgeFormatter.h` — compact active-time display formatting

These are small, low-risk pieces that show some of the style used by the actual firmware.

## Simplified reference examples

[`procedural-sprite-demo/`](procedural-sprite-demo/) is a small desktop-only demonstration of deterministic mirrored creature generation. It is **not** the production SpriteGenerator.

[`persistence-model/`](persistence-model/) demonstrates selecting the newest valid redundant checkpoint. It does **not** contain Demonym's production save encoding, authentication, NVS/SD I/O, migrations, or secret material.

## Building the examples locally

A C++17 compiler is enough for the public examples/tests. From the repository root on a Unix-like shell:

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

GitHub Actions runs the same representative checks automatically.
