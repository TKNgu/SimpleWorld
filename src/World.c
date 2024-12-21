#include "World.h"
#include <stdlib.h>
#include <stdio.h>

void InitWorld(World *world) {
    world->isRunning = true;
    InitClock(&world->clock);
    world->sunLight= (SunLight) {
        .startTime = ClockGetTime(&world->clock),
        .dayLeng = 10,
        .nightLeng = 10,
        .isDay = true,
    }; 

    world->numTree = 1;
    world->trees = (Tree *)malloc(world->numTree * sizeof(Tree));
    world->trees[0] = (Tree) {
        .x = 0,
        .y = 0,
        .w = 0,
        .h = 0,
        .area = 0.001,
        .energy = 1,
    };
}

void ReleaseWorld(World *world) {
    if (world->trees) {
        free(world->trees);
    }
}

void WorldUpdate(World *world) {
    double sunLightValue = SunLightGetValue(&world->sunLight, &world->clock);
    
    for (size_t index = 0; index < world->numTree; index++) {
        TreeUpdate(world->trees + index, sunLightValue);
    }
}

void WorldView(const World *world) {
    printf("View World\n");
    for (size_t index = 0; index < world->numTree; index++) {
        TreeView(world->trees + index);
    }
}
