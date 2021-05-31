// Imagine++ project
// Project:  test
// Author:   Etien
// Date:     2021/04/26

#include "circuit.h"
#include "kart.h"
#include "affichage.h"

void key(){
        int key=clavier();
        cout<<key<<endl;
        //key_entrée 16777220
        //key_echape 16777216
    }



int main()
{
    InitRandom();

    jeu();

    endGraphics();

    return 0;

}
