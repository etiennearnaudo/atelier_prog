#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "outils.h"

class pixel{
    int x,y,z;
public:
    pixel();
    pixel(int x0,int y0,int z0);
    int getx();
    int gety();
    int getz();
    void setx(int a);
    void sety(int a);
    void setz(int a);
    int indice(int W,int H);
};

class circuit{
    bool* tunnel;
    int width, heigth, depth;
public:
    circuit(int w, int h, int d);
};


#endif // CIRCUIT_H
