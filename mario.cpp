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


    return 0;

}

//    circuit circ(largeur,hauteur,profondeur);

//    vaisseau v;
//    circ.affiche(0);
//    v.affiche(PURPLE);
//    click();
//    obstacle ob1(largeur,hauteur,0);
//    obstacle ob2(largeur,hauteur,4);

//    ob1.insert(circ);
//    ob2.insert(circ);
//    for(int k=0;k<distance_affichage;k++){
//        v.bouge(circ,k);
//        milliSleep(attente);
//    }
//    return 0;

//}
