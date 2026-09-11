# Simplified Persistence Model

The real Demonym save system uses redundant internal checkpoints plus additional recovery/migration behavior. This public example intentionally models only one idea: **when several checkpoint candidates exist, restore the newest candidate that has already passed validation**.

It does not include:

- NVS or SD access
- Demonym record layouts
- CRC/authentication logic
- key material
- migration paths
- replacement/backup I/O
- backoff scheduling
- repair/diagnostic behavior

See [Persistence & Recovery](../../docs/persistence.md) for the architectural overview.
