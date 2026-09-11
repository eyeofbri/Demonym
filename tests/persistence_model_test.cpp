#include <array>
#include <cassert>
#include <iostream>

#include "../examples/persistence-model/CheckpointSelector.h"

int main() {
    std::array<PublicCheckpoint, 3> checkpoints{{
        {true, 10u},
        {false, 99u},
        {true, 12u},
    }};

    auto selected = newestValidCheckpoint(checkpoints);
    assert(selected.has_value());
    assert(*selected == 2u);

    checkpoints[2].valid = false;
    selected = newestValidCheckpoint(checkpoints);
    assert(selected.has_value());
    assert(*selected == 0u);

    checkpoints[0].valid = false;
    selected = newestValidCheckpoint(checkpoints);
    assert(!selected.has_value());

    std::cout << "simplified checkpoint selection=PASS\n";
    return 0;
}
