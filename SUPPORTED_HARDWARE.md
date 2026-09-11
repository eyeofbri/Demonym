# Supported Hardware

Demonym was originally designed and developed for the **M5Stack Cardputer ADV**. The public repository is device-neutral so additional ESP32 targets can be added later without splitting the project into separate repositories.

## Current support

| Device | Status | Display / Input | Local Multiplayer | Notes |
| --- | --- | --- | --- | --- |
| M5Stack Cardputer ADV | **Supported** | Built-in display + keyboard | ESP-NOW | Primary development and physical-test target |

## Planned / experimental targets

Additional ESP32 devices are being evaluated. A port may require adaptation for:

- display dimensions and orientation
- input model (keyboard, buttons, joystick, or touch)
- audio output
- SD / flash storage availability
- battery and power behavior
- motion sensors
- ESP-NOW support and radio coexistence

A device is not considered **Supported** until core lifecycle, saving, menus, Training, Roam, Battle, and recovery behavior have been tested on physical hardware.

## Release assets

The game version remains the release version; hardware is encoded in the asset filename.

Examples:

```text
demonym-cardputer-adv-v0.9.22.bin
demonym-cardputer-zero-v1.0.bin
demonym-m5stickc-plus-v1.0.bin
```

A single GitHub Release may contain multiple device binaries when more than one target supports that version.

## Portability direction

The current production firmware was built around Cardputer ADV hardware. Future ports should isolate device-specific behavior behind a small hardware adaptation layer rather than forking the game logic per device.

See [docs/porting.md](docs/porting.md) for the proposed direction.
