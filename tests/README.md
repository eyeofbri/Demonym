# Public Tests

These tests cover only the selected public examples. They are representative of the style of host-side validation used during Demonym development, not a copy of the complete private QA suite.

The production v0.9.22 package contains 190 host-side validation/regression utilities accumulated across versions, plus separate PlatformIO builds and physical Cardputer testing.

Public CI currently verifies:

- deterministic PRNG behavior
- fixed-capacity screen routing/back history
- active-time formatting
- deterministic/symmetric simplified sprite generation
- newest-valid simplified checkpoint recovery
