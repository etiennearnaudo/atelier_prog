#ifndef OUTILS_H
#define OUTILS_H

#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>

using namespace Imagine;
using namespace std;

typedef Image<byte> Img;


const int taille_case = 10 ;
const int largeur = 32 ;
const int hauteur = 32 ;
const int profondeur = 25 ;


void InitRandom();

int Random(int a, int b);

#endif // OUTILS_H
