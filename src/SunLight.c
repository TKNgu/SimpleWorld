#include "SunLight.h"
#include <stdbool.h>
#include "Clock.h"

double SunLightGetValue(SunLight *sunLight, const Clock *clock) {
    double deltaTime = ClockGetTime(clock) - sunLight->startTime;
    if (sunLight->isDay) {
        if (deltaTime > sunLight->dayLeng) {
            sunLight->isDay = false;
            sunLight->startTime += sunLight->dayLeng;
            return 0;
        }
        return 1;
    }
    if (deltaTime > sunLight->nightLeng) {
        sunLight->isDay = true;
        sunLight->startTime += sunLight->nightLeng;
        return 1;
    }
    return 0;
}
