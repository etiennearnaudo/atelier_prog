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

Vect2::Vect2(int a, int b){
    x=a;
    y=b;
}

Vect2 Vect2::operator+(Vect2 a){
    Vect2 v;
    v.x=x+a.x;
    v.y=y+a.y;
    return v;
}

Vect2 Vect2::operator-(Vect2 a){
    Vect2 v;
    v.x=x-a.x;
    v.y=y-a.y;
    return v;
}

Vect2 Vect2::operator*(double a){
    Vect2 v;
    v.x=x*a;
    v.y=y*a;
    return v;
}

Vect2 Vect2::operator/(double a){
    Vect2 v;
    v.x=x/a;
    v.y=y/a;
    return v;
}

int Vect2::getx(){
    return x;
}

int Vect2::gety(){
    return y;
}

void Vect2::setx(int a){
    x=a;
}

void Vect2::sety(int a){
    y=a;
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
