# Core Utilities

These three headers are **production-derived** from the Demonym v0.9.22 source tree. They were selected because they are self-contained and demonstrate embedded-oriented implementation choices without publishing a major game subsystem.

## `SeededRandom.h`

A compact deterministic xorshift-style PRNG plus seed-mixing helper. Demonym relies heavily on deterministic generation so a creature or procedural system can be reproduced from compact identity/state.

## `ScreenRouter.h`

A small screen router with a fixed eight-entry history buffer. It avoids heap allocation and treats lifecycle transitions differently from ordinary navigable screens.

## `AgeFormatter.h`

Formats active creature time into compact forms suitable for a 240×135 display.

The production application contains substantially more surrounding logic; these files are not enough to build Demonym.
