#include <cassert>
#include <cstring>
#include <iostream>

#include "SeededRandom.h"
#include "ScreenRouter.h"
#include "AgeFormatter.h"

int main() {
    // Same seed -> same deterministic sequence.
    SeededRandom a(123456u);
    SeededRandom b(123456u);
    for (int i = 0; i < 64; ++i) {
        assert(a.nextU32() == b.nextU32());
    }

    // Router remembers ordinary navigation and unwinds in order.
    ScreenRouter router;
    assert(router.current() == ScreenId::Habitat);
    assert(router.go(ScreenId::MainMenu));
    assert(router.go(ScreenId::Stats));
    assert(router.back());
    assert(router.current() == ScreenId::MainMenu);
    assert(router.back());
    assert(router.current() == ScreenId::Habitat);

    // Lifecycle transitions clear ordinary back navigation when forced.
    router.go(ScreenId::MainMenu);
    router.force(ScreenId::HatchSequence);
    assert(!router.back());

    char text[32]{};
    formatActiveAge(90u, text, sizeof(text));
    assert(std::strcmp(text, "00:01:30") == 0);

    formatActiveAge(24u * 60u * 60u + 5u, text, sizeof(text));
    assert(std::strcmp(text, "001d 00:00:05") == 0);

    std::cout << "core utilities=PASS\n";
    return 0;
}
