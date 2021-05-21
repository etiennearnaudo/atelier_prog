#include "circuit.h"

pixel::pixel(){
    x=0;
    y=0;
}

pixel::pixel(int x0, int y0,int z0){
    x=x0;
    y=y0;
    z=z0;
}

int pixel::getx(){
    return x;
}

int pixel::gety(){
    return y;
}

int pixel::getz(){
    return z;
}

void pixel::setx(int x0){
    x=x0;
}

void pixel::sety(int y0){
    y=y0;
}

void pixel::setz(int z0){
    y=z0;
}

int pixel::indice(int W,int H){
    return(y*W+x+W*H*z);
}

circuit::circuit(int w, int h, int d){
    tunnel = new pixel[w*h*d];
    width = w;
    heigth = h;
    depth = d;
}
