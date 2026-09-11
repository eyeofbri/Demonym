# Public Tests

These tests only cover the code examples in this public repo. The full private v0.9.22 project has 190 host-side validation/regression utilities plus the normal PlatformIO builds and real Cardputer testing.

The public CI currently checks:

- deterministic PRNG output
- fixed-size screen routing and Back history
- active-time formatting
- repeatable/symmetric output from the small sprite demo
- newest-valid selection in the small checkpoint example

I plan to add more public tests if I move more self-contained examples into this repo later.
