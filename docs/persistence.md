# Persistence and Recovery

Saving became one of the larger technical parts of Demonym because a virtual creature only works if the player can trust that it will still be there after a reboot.

## What I wanted from the save system

- keep creature identity stable
- survive an interrupted or failed write when possible
- keep older data readable through migrations
- avoid freezing gameplay every time a small value changes
- recover from a bad checkpoint without immediately destroying the last good one
- keep maintenance/debug information available when storage starts acting strangely

## Redundant checkpoints

The active creature uses multiple internal checkpoint candidates instead of one replace-in-place blob.

A simplified recovery idea is:

```text
read checkpoint candidates
        |
        v
validate each one
        |
        v
ignore bad candidates
        |
        v
pick newest valid sequence
        |
        v
restore creature
```

The small public example in [`examples/persistence-model`](../examples/persistence-model/) only demonstrates that last selection step.

## Validation before recovery

A checkpoint does not become the recovery source just because it exists. It has to pass the production validation rules first.

The full record/authentication format stays private.

## Retry/backoff

One important hardware bug caused failed autosaves to be retried too aggressively. That could turn a storage problem into a repeated write loop and make the whole device feel slow.

Later versions moved failed writes onto a bounded retry/backoff schedule. Routine input can also mark data dirty and save shortly after the immediate interaction instead of forcing a blocking write inside every button event.

## Isolated checkpoint storage

As the NVS debugging got deeper, the redundant creature checkpoints were separated into stable namespaces/slots so one unhealthy allocation path was less likely to take out the whole recovery set.

A degraded fallback mode was also added for cases where a device could still update an older authenticated checkpoint but could not create healthy fresh slots.

I kept repair as an explicit maintenance action. I did not want the game silently wiping all device storage because one write failed.

## SD-backed data

Larger history-style data is a better fit for SD than repeatedly expanding internal NVS use. Later work moved toward a hybrid approach where the active creature stays small and recoverable while larger archive/history data can live on SD with fallback behavior.

## Migrations

The project has changed save structures many times. New code needs to recognize older versions, migrate them when possible, and avoid treating an old-but-valid record as random corruption.

## Public example limits

The public persistence example does not include:

- real Demonym record layouts
- NVS or SD I/O
- authentication/key material
- CRC/authentication details
- migration code
- repair tools
- backoff scheduling

I am keeping those parts in the private repo.
