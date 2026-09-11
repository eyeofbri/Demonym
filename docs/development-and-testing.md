# Development & Testing

Demonym is developed for physical embedded hardware, but a large amount of its logic is deliberately testable without the Cardputer attached.

By v0.9.22, the private package contains **190 host-side validation/regression utilities** accumulated over the project's development history.

## Test layers

### 1. Host-side deterministic validation

Pure C++ logic is compiled and exercised on a desktop where possible. Examples of the kinds of invariants checked in the private suite include:

- procedural generator determinism and symmetry
- generated-body bounds and fallback rates
- lifecycle transition conditions
- dungeon/room generation invariants
- battle math and rule-version behavior
- Training game state/results
- save structure sizes and compatibility
- migration behavior
- progression and Legacy inheritance
- economy/balance constants
- source-level regressions for bugs that were easy to reintroduce

These tests are fast and reproducible, which makes them useful before flashing hardware.

### 2. Build validation

The production project uses PlatformIO with C++17 and warning flags. A clean firmware build catches integration errors that host tests cannot see, particularly around Arduino/M5 libraries and ESP32-specific APIs.

### 3. Physical-device validation

A successful host test is not treated as proof that an embedded feature works. Physical testing covers things such as:

- display composition and text clipping
- held keys / key-release behavior
- speaker timing
- sleep/dimming transitions
- flash/NVS latency
- SD insertion/removal and fallback behavior
- memory pressure
- ESP-NOW packet loss / timing
- two-device battle synchronization
- reboot and recovery behavior

### 4. Multi-device testing

Two Cardputer ADV units are used to test discovery, session establishment, Battle, Exchange, disconnect/recovery, and actual human-paced linked play. Several important protocol fixes came specifically from physical matches that looked correct in isolated logic tests.

## Selected debugging case studies

### Storage failure looked like a performance bug

One Cardputer became choppy while save attempts repeatedly failed. Instrumentation showed that the application was performing blocking failed NVS work too frequently. The save system was changed to use deferred checkpoints and retry backoff.

A later full erase/reinstall restored healthy allocation behavior on that device, supporting the diagnosis that accumulated NVS state was a major factor rather than the creature simulation itself.

### Network correctness was not network usability

Early ESP-NOW battles could establish successfully but occasionally fail after a round or two with a rival-response timeout. Reliability work added clearer acknowledgement/retry boundaries, heartbeats, liveness thresholds, and session convergence rules.

### Rendering and persistence need scheduling boundaries

Several late-alpha changes deliberately present UI/result feedback before heavier persistence. On a desktop, writing immediately is often invisible; on a small ESP32, the timing can be noticeable to the player.

### A feature can be technically possible and still be deferred

An always-on physical signal-ecology concept was shelved after earlier passive scanning experiments created frame-rate/complexity concerns. The project kept only a low-duty presence mechanism and reserved richer signal scanning for explicit short actions if revisited.

That decision reflects an important embedded constraint: background features compete for the same CPU, radio, storage, and power budget as the game.

## Public CI

The public repository intentionally tests only its selected examples. The workflow under `.github/workflows/public-examples.yml` compiles and runs the example tests with a standard C++17 compiler.

This provides a visible, reproducible sample of the testing approach without publishing the complete production QA suite.
