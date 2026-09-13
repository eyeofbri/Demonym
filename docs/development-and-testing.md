# Development and Testing

Demonym runs on embedded hardware, but I try to keep as much game logic as possible testable on a normal computer.

## Host-side tests

By v0.9.22 the private project had **190 host-side validation and regression utilities** collected over development.

They cover areas such as:

- procedural creature generation
- deterministic seeds
- save compatibility and migration
- checkpoint recovery
- Battle rules and move behavior
- Pressures and status effects
- Roam generation
- Training rules
- economy/balance limits
- Signal Legacy and inheritance
- source-level regression checks for bugs that had already been fixed once

A lot of these started because a specific hardware bug was hard to reproduce quickly on the Cardputer.

## Real hardware still matters

Host tests cannot tell me whether:

- a screen is hard to read on the actual 240x135 display
- held keys feel right
- an animation blocks input
- ESP-NOW drops after several rounds
- NVS writes stall the UI
- brightness/dimming feels bad
- audio is too loud
- an SD card or power cycle changes behavior

Those still need the Cardputer.

## Two-device testing

Once I had two Cardputer ADV units, Connect testing got much more useful. That exposed timing bugs that were not obvious in single-device simulation, especially around round transitions, ACK timing, dropped sessions, and what happens when both players act at nearly the same time.

## Storage testing

One Cardputer eventually developed repeated NVS allocation/save failures while another device running the same code was fine.

That led to several save-system changes, including better diagnostics, bounded retry/backoff, isolated checkpoints, degraded fallback behavior, and repair tools.

A full erase/reinstall later restored normal behavior on the problem device. That was a useful reminder that the device's accumulated NVS state can be part of the bug, not just the current save code.

## Result first, save second

Some late-alpha screens were changed so the player sees the result before heavier save work happens.

On a desktop, a short write is easy to ignore. On a small ESP32, even a brief storage pause can make a button or result screen feel broken.

## On-device screenshots

v0.9.22.2 has a small screenshot function built into the Cardputer build. Pressing **Fn/Opt + P** writes the current 240x135 framebuffer to the SD card as a PNG under `/demonym/screenshots/`. Files are numbered automatically as `shot_001.png`, `shot_002.png`, and so on.

I added this mostly because taking clean screenshots with a camera was getting in the way of documenting the game. It also gives me a quick way to capture a screen while testing something without adding a separate desktop renderer or rebuilding the UI as a mockup.

The screenshots in the public docs are meant to come from the real game whenever possible.

## Public tests

The tests in this repo only cover the public examples. The workflow in `.github/workflows/public-examples.yml` builds and runs them with a normal C++17 compiler.

That public set currently checks:

- deterministic random output
- screen history/back behavior
- active-time formatting
- the simplified procedural sprite demo
- the simplified checkpoint selector
