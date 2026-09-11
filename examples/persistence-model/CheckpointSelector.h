#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

// Small public example of newest-valid checkpoint selection.
// The real Demonym persistence/authentication code stays in the private repo.

struct PublicCheckpoint {
    bool valid = false;
    uint32_t sequence = 0;
};

template <std::size_t N>
std::optional<std::size_t> newestValidCheckpoint(
    const std::array<PublicCheckpoint, N>& checkpoints
) {
    std::optional<std::size_t> best;

    for (std::size_t i = 0; i < checkpoints.size(); ++i) {
        if (!checkpoints[i].valid) continue;
        if (!best || checkpoints[i].sequence > checkpoints[*best].sequence) {
            best = i;
        }
    }

    return best;
}
