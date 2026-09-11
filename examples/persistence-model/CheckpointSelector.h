#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

// Simplified public reference example.
// This models only newest-valid redundant checkpoint selection.
// It is NOT Demonym's production persistence/authentication implementation.

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
