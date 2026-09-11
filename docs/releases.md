# Release & Binary Conventions

GitHub Releases are the distribution location for Demonym firmware. Compiled `.bin` files are intentionally excluded from ordinary Git history.

## Public milestone releases

The current historical public archive uses these broad milestones:

- v0.1
- v0.2
- v0.3
- v0.4
- v0.5
- v0.6
- v0.7
- v0.8
- v0.9
- v0.9.22 — Balance + Content Lock

The private development repository contains many more patch snapshots.

## Asset naming

Use:

```text
demonym-<device>-v<version>.bin
```

Examples:

```text
demonym-cardputer-adv-v0.9.22.bin
demonym-cardputer-zero-v1.0.bin
```

If a release contains different image types, make that explicit:

```text
demonym-cardputer-adv-v1.0-full.bin
demonym-cardputer-adv-v1.0-app.bin
```

Do not make a user infer whether an image is a merged/full-flash image or an application-only binary.

## Multi-device releases

A game release can contain several hardware assets:

```text
Demonym v1.1
├── demonym-cardputer-adv-v1.1.bin
├── demonym-cardputer-zero-v1.1.bin
└── demonym-m5stickc-plus-v1.1.bin
```

If a target is not compatible with that release, omit the asset and document its latest supported version instead of publishing a misleading binary.

## Flashing information

Each release should state:

- supported device
- whether the file is full/merged or application-only
- required flash address/tool when relevant
- whether upgrading preserves Demonym save data
- whether both devices need the same Link Protocol / Battle Rules version for Connect
- known issues

Do **not** assume that every `.bin` can safely be flashed at the same address. The release notes are the authority for that asset.

## Checksums

For long-term archival releases, adding a SHA-256 checksum file is recommended:

```text
demonym-cardputer-adv-v0.9.22.bin
demonym-cardputer-adv-v0.9.22.sha256
```

This is especially useful once multiple hardware builds are distributed from the same release.
