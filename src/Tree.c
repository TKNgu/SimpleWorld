#include "Tree.h"
#include <math.h>
#include <stdio.h>

void TreeUpdate(Tree *tree, const double sunLightValue) {
    double newEnergy = tree->energy + sunLightValue * tree->area;
    double newArea = tree->area * newEnergy / tree->energy;
    tree->area = newArea;
    tree->energy = newEnergy;
    tree->w = tree->h = sqrt(newArea);
}

void TreeView(const Tree *tree) {
    printf("Tree %0.3f %0.3f %0.5f %0.5f\n", tree->x, tree->y, tree->w, tree->h);
}
