#ifndef Clock_h
#define Clock_h

#include <time.h>
#include <unistd.h>

typedef struct timespec Clock;

void InitClock(Clock *clock);
double ClockGetTime(const Clock *clock);

#endif
