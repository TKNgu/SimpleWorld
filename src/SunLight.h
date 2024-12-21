#ifndef SunLight_h
#define SunLight_h

#include <stdbool.h>

#include "Clock.h"

typedef struct {
    double startTime;
    double dayLeng;
    double nightLeng;
    bool isDay;
} SunLight;

double SunLightGetValue(SunLight *sunLight, const Clock *clock);

#endif
