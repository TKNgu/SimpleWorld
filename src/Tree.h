#ifndef Tree_h
#define Tree_h

typedef struct {
    double x;
    double y;
    double w;
    double h;

    double area;
    double energy;
} Tree;

void TreeUpdate(Tree *tree, const double sunLightValue);
void TreeView(const Tree *tree);

#endif
