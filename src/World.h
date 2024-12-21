#ifndef World_h
#define World_h

#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>

#include "Clock.h"
#include "SunLight.h"
#include "Tree.h"

typedef struct {
    atomic_bool isRunning;
    Clock clock;
    SunLight sunLight;

    size_t numTree;
    Tree *trees;
} World;

void InitWorld(World *world);
void ReleaseWorld(World *world);
void WorldUpdate(World *world);
void WorldView(const World *world);

#endif
