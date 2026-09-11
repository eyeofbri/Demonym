# Release and Binary Notes

I use GitHub Releases for downloadable Demonym firmware. I am keeping compiled `.bin` files out of normal Git history.

## Public milestone releases

The public release history is much shorter than the private development history.

Current public milestones:

- v0.1
- v0.2
- v0.3
- v0.4
- v0.5
- v0.6
- v0.7
- v0.8
- v0.9
- v0.9.22

The private repo has the patch builds between those versions.

## Binary names

I plan to use:

```text
demonym-<device>-v<version>.bin
```

For example:

```text
demonym-cardputer-adv-v0.9.22.bin
demonym-cardputer-zero-v1.0.bin
```

If I need to publish more than one image type, I will make that obvious in the name:

```text
demonym-cardputer-adv-v1.0-full.bin
demonym-cardputer-adv-v1.0-app.bin
```

## Multiple devices in one release

A future release may look like:

```text
Demonym v1.1
├── demonym-cardputer-adv-v1.1.bin
├── demonym-cardputer-zero-v1.1.bin
└── demonym-m5stickc-plus-v1.1.bin
```

If a device is not ready for that version, I will leave its binary out and list the latest version that does support it.

## Flashing notes

For each device build I plan to include enough information to tell the player:

- which device it is for
- whether it is a full/merged image or app-only image
- the flash address/tool if needed
- whether upgrading keeps existing save data
- any Connect protocol compatibility notes
- known issues

I do not want somebody guessing that every `.bin` uses the same flash address.

## Checksums

For the more important archived releases I may also attach SHA-256 files, for example:

```text
demonym-cardputer-adv-v0.9.22.bin
demonym-cardputer-adv-v0.9.22.sha256
```
