// Imagine++ project
// Project:  test
// Author:   Etien
// Date:     2021/04/26

#include "circuit.h"








int main()
{
    InitRandom();

    circuit circ(largeur,hauteur,profondeur);
    circ.affiche(0);
    click();
    obstacle ob1(largeur,hauteur,0);
    obstacle ob2(largeur,hauteur,4);
    ob1.insert(circ);
    ob2.insert(circ);
    circ.affiche(0);
    milliSleep(200);
    circ.affiche(1);
    milliSleep(200);
    circ.affiche(2);
    milliSleep(200);
    circ.affiche(3);
    milliSleep(200);
    circ.affiche(4);

    endGraphics();

    return 0;

}
