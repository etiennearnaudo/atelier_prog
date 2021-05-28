#include "outils.h"

void InitRandom()
{
    srand((unsigned int)time(0));
}

int Random(int a, int b)
{
    return int(a + (rand()%(b-a+1)));
}

//-------Classe Vect---------//

Vect::Vect(int a, int b, int c){
    x=a;
    y=b;
    z=c;
}

Vect Vect::operator+(Vect a){
    Vect v;
    v.x=x+a.x;
    v.y=y+a.y;
    v.z=z+a.z;
    return v;
}

Vect Vect::operator-(Vect a){
    Vect v;
    v.x=x-a.x;
    v.y=y-a.y;
    v.z=z-a.z;
    return v;
}

Vect Vect::operator*(double a){
    Vect v;
    v.x=x*a;
    v.y=y*a;
    v.z=z*a;
    return v;
}

Vect Vect::operator/(double a){
    Vect v;
    v.x=x/a;
    v.y=y/a;
    v.z=z/a;
    return v;
}

int Vect::getx(){
    return x;
}

int Vect::gety(){
    return y;
}

int Vect::getz(){
    return z;
}

void Vect::setx(int a){
    x=a;
}

void Vect::sety(int a){
    y=a;
}

void Vect::setz(int a){
    z=a;
}


//----- Gestion du clavier -----

int clavier() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}
