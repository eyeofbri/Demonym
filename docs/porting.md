# Porting Notes

The Cardputer ADV is still the main target, but I would like Demonym to run on more ESP32 devices later.

I do not want to solve that by copying the whole game into a new repo for every board. The cleaner direction is to keep the game systems shared and isolate the parts that actually depend on the hardware.

## Parts most likely to need adapters

### Display

The current UI was built around a 240x135 screen. Other devices may need different font sizes, panel layouts, clipping rules, or complete screen variants.

### Input

Cardputer uses a keyboard. Other devices may use:

- a few buttons
- a joystick
- touch
- rotary controls

The game should ask for actions like Up, Down, Confirm, Back, or Context instead of caring which physical key produced them.

### Audio

Different boards may use a speaker, buzzer, I2S audio, or no audio at all.

### Storage

Flash layout, NVS size, SD support, and filesystem choices can change between boards.

### Motion

Motion Ecology should stay optional. A device without a compatible accelerometer still needs to run the normal creature/game loop.

### Networking

ESP-NOW support is one of the more important shared features. A port that keeps ESP-NOW can still participate in the same general Connect idea, but the build also needs compatible link/battle protocol versions.

## Rough direction

I expect the long-term split to look something like:

```text
Demonym game systems
        |
        +-- display adapter
        +-- input adapter
        +-- audio adapter
        +-- storage adapter
        +-- motion adapter
        +-- radio / ESP-NOW adapter
```

I am not forcing a full hardware abstraction rewrite before I actually need it. I plan to pull these pieces out as real ports make the need obvious.

## Release handling

If several devices support the same game version, I plan to keep one GitHub Release and attach one binary per device.

A device can also lag behind for a while. In that case I will list its latest supported version in [SUPPORTED_HARDWARE.md](../SUPPORTED_HARDWARE.md) instead of creating a separate project history for it.
