# Repository Scope

This repository is the **public showcase and firmware distribution home** for Demonym. The complete production firmware is maintained in a separate private repository.

The split is intentional. Demonym is both a portfolio project and a game that may continue to evolve across additional ESP32 hardware, so the public repository shows meaningful engineering work without publishing a rebuildable copy of the entire product.

## What is public

- Player-facing documentation and the full Player Manual
- Architecture and engineering notes
- Supported-hardware and porting documentation
- Public release notes and downloadable firmware binaries
- Selected, low-risk production-derived utilities
- Simplified examples demonstrating important architecture ideas
- Representative public tests and CI
- Screenshots, photos, diagrams, and other approved project media

## What remains private

- Complete `src/`, `include/`, and production PlatformIO project
- Full application state and rendering implementation
- Complete BattleEngine and combat data tables
- Complete procedural creature generator implementation
- Production save encoding/authentication details and secret material
- Full ESP-NOW packet definitions, authentication details, and runtime implementation
- Complete economy/balance/content tables
- Development shortcuts, diagnostics that expose internal data, and device-specific test state
- Unreleased experiments, cut content, and abandoned branches
- Any credentials, keys, personal device identifiers, or local configuration

## Code in `examples/`

Public examples are explicitly labeled as one of the following:

**Production-derived** — small pieces taken from the real firmware because they are useful demonstrations and do not expose a sensitive subsystem.

**Simplified reference** — clean-room/public-facing examples that demonstrate an approach used by Demonym but are intentionally smaller and structurally different from the production implementation.

Do not assume that the examples form a complete or directly buildable version of the game.

## Licensing / reuse

No open-source license is granted for the Demonym project as a whole by this repository. Unless a file explicitly states otherwise, project code, documentation, names, and original assets remain copyright of their respective author(s).

The public examples are provided for review and educational inspection as part of this portfolio repository. If broader reuse licensing is added later, it will be stated explicitly in the relevant directory or file.
