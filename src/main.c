#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#include "World.h"
#include "Clock.h"
#include "SunLight.h"

static World world;

void cancelHandler() {
    world.isRunning = false;
}

int main(int argc, char *argv[]) {
    InitWorld(&world);
    signal(SIGINT, cancelHandler);
    while (world.isRunning) {
        sleep(1);
        WorldUpdate(&world);
        WorldView(&world);
    }
    return 0;
}
