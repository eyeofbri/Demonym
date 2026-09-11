# Core Utilities

These three headers come from small, self-contained parts of the Demonym v0.9.22 code. I picked them because they show a few patterns from the real firmware without exposing a larger game system.

## `SeededRandom.h`

A small deterministic xorshift-style PRNG and seed-mixing helper. I use deterministic generation in several places where the same compact input needs to reproduce the same result.

## `ScreenRouter.h`

A simple screen router with an eight-entry fixed history buffer. It avoids heap allocation and keeps lifecycle screens out of normal Back navigation.

## `AgeFormatter.h`

Formats active creature time into a compact string that fits the Cardputer display.

These files are only utilities. They are nowhere near enough to build the game.
