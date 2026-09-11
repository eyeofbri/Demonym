#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>

inline void formatActiveAge(
    uint32_t totalSeconds,
    char* output,
    size_t outputSize
) {
    if (output == nullptr || outputSize == 0) {
        return;
    }

    constexpr uint32_t SECONDS_PER_MINUTE = 60u;
    constexpr uint32_t SECONDS_PER_HOUR = 60u * SECONDS_PER_MINUTE;
    constexpr uint32_t SECONDS_PER_DAY = 24u * SECONDS_PER_HOUR;
    constexpr uint32_t DAYS_PER_YEAR = 365u;

    const uint32_t totalDays = totalSeconds / SECONDS_PER_DAY;
    const uint32_t secondsWithinDay = totalSeconds % SECONDS_PER_DAY;
    const uint32_t hours = secondsWithinDay / SECONDS_PER_HOUR;
    const uint32_t minutes =
        (secondsWithinDay % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE;
    const uint32_t seconds = secondsWithinDay % SECONDS_PER_MINUTE;

    if (totalDays == 0) {
        std::snprintf(
            output,
            outputSize,
            "%02lu:%02lu:%02lu",
            static_cast<unsigned long>(hours),
            static_cast<unsigned long>(minutes),
            static_cast<unsigned long>(seconds)
        );
        return;
    }

    if (totalDays < DAYS_PER_YEAR) {
        std::snprintf(
            output,
            outputSize,
            "%03lud %02lu:%02lu:%02lu",
            static_cast<unsigned long>(totalDays),
            static_cast<unsigned long>(hours),
            static_cast<unsigned long>(minutes),
            static_cast<unsigned long>(seconds)
        );
        return;
    }

    const uint32_t years = totalDays / DAYS_PER_YEAR;
    const uint32_t daysWithinYear = totalDays % DAYS_PER_YEAR;
    std::snprintf(
        output,
        outputSize,
        "%luy %03lud %02lu:%02lu",
        static_cast<unsigned long>(years),
        static_cast<unsigned long>(daysWithinYear),
        static_cast<unsigned long>(hours),
        static_cast<unsigned long>(minutes)
    );
}
