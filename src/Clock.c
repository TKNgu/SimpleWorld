#include "Clock.h"
#include <time.h>
#include <unistd.h>

void InitClock(Clock *clock) {
    clock_gettime(CLOCK_MONOTONIC, clock);
}

double ClockGetTime(const Clock *clock) {
    struct timespec timeNow;
    clock_gettime(CLOCK_MONOTONIC, &timeNow);
    return timeNow.tv_sec - clock->tv_sec + (timeNow.tv_nsec - clock->tv_nsec) / 1000000000.0;
}
