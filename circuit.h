#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "outils.h"

class pixel{
    int x,y,z;
public:
    pixel();
    ~pixel();
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
    int* tunnel;
    int width, heigth, depth;
public:
    circuit(int w, int h, int d);
    ~circuit();
    void setPixel(pixel p,int value);
    void affiche(int z,int size,int dec_x,int dec_y);
    void affiche(int z);
    int getPixel(pixel p);
};

class obstacle{
    pixel* ob;
    pixel principal;
    int taille;
public:
    obstacle(int w,int h,int z);
    ~obstacle();
    void insert(circuit c);
    int gettaille();
};


#endif // CIRCUIT_H
