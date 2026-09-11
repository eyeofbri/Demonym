# Simplified Persistence Model

The real Demonym save system has redundant checkpoints plus migration, repair, retry/backoff, authentication, and other recovery behavior.

I kept this public example to one small idea: **if several checkpoint candidates exist, choose the newest one that has already passed validation**.

It does not include:

- NVS or SD access
- Demonym save layouts
- CRC/authentication code
- key material
- migrations
- backup/replacement I/O
- retry/backoff scheduling
- repair tools

See [Persistence and Recovery](../../docs/persistence.md) for more background.
