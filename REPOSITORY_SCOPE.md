# Repository Scope

This is the public Demonym repo. The complete firmware lives in a separate private repo.

I am keeping the split because I want this repo to be useful for releases, documentation, and code samples without putting the entire game online.

## Public here

- README and project notes
- player manual
- supported hardware notes
- public firmware releases
- selected screenshots and hardware photos as I add them
- architecture notes
- a few small production-derived utilities
- simplified examples based on systems used in the game
- a small public test suite for those examples

## Private for now

- complete `src/`, `include/`, and production library tree
- full BattleEngine
- full creature generator
- save/authentication implementation
- ESP-NOW packet definitions and full link runtime
- complete balance/content tables
- internal debug and development shortcuts
- unreleased experiments
- full private regression suite

## About the examples

There are two kinds of code in `examples/`.

**Production-derived:** small pieces taken from the real firmware that are self-contained and do not expose a major subsystem.

**Simplified example:** smaller public versions I wrote to show the general idea without copying the full production implementation.

The procedural sprite example also credits [yurkth/sprator](https://github.com/yurkth/sprator), which was a useful reference when I was first experimenting with generated creature sprites.

## Licensing

I have not added a broad open-source license to the full project. If I decide to make any example or part of the project reusable under a specific license later, I will put that license directly with the relevant code.
