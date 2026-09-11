# Supported Hardware

Demonym is currently built around the **M5Stack Cardputer ADV**.

## Current

| Device | Status | Controls | ESP-NOW |
| --- | --- | --- | --- |
| M5Stack Cardputer ADV | Main target | built-in keyboard | Yes |

## Devices I may try later

I am interested in getting Demonym running on more ESP32 hardware, but I do not want to split the project into a different repo for every board.

Possible future targets include:

| Device | Current plan |
| --- | --- |
| M5Stack Cardputer Zero | likely future target once hardware is available |
| M5StickC Plus / similar M5 devices | possible with an external joystick or different controls |
| ESP32-2432S028R / CYD | possible, but it would need a touch/control and layout pass |
| other ESP32-S3 handhelds | depends on display, controls, RAM, storage, and radio support |

## What changes between devices

The game logic does not need to be rewritten for every device, but these parts may:

- display setup and screen layout
- keyboard / buttons / touch input
- audio output
- SD and flash storage details
- motion sensor support
- battery and power handling
- pins and board setup

I plan to keep pulling those hardware-specific parts away from the main game logic as I work on ports.

If multiple devices support the same game version, I plan to attach each binary to the same GitHub Release with the device name in the filename.
