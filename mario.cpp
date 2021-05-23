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
    cout << 1 << endl;
    obstacle ob1(largeur,hauteur,0);
    cout << 2 << endl;
    obstacle ob2(largeur,hauteur,4);
    cout << 3 << endl;
    ob1.insert(circ);
    cout << 4 << endl;
    ob2.insert(circ);
    cout << 5 << endl;
    circ.affiche(0);
    click();
    circ.affiche(1);
    click();
    circ.affiche(2);
    click();
    circ.affiche(3);
    click();
    circ.affiche(4);

    endGraphics();

    return 0;

}
