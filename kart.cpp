#include "kart.h"

vaisseau::vaisseau(){
    pos=Vect(int(hauteur/2),int(largeur/2),0);
    vit=Vect(2,2,1);
}

Vect vaisseau::getP(){
    return pos;
}

Vect vaisseau::getV(){
    return vit;
}

void vaisseau::insert(circuit c, int valeur){
    for (int i=0;i<2;i++)
        for (int j=0;j<1;j++)
            for (int k=0;k<0;k++)
                c.setPixel(pixel(pos.getx()+i,pos.gety()+j,pos.getz()+k),valeur); //LA valeur 3 dans la grille glovale sera pour le vaisseau
}

void vaisseau::bouge(circuit c){
    insert(c,0);
    int key=clavier();
    //key_droite:16777236
    if(key==16777236){
        pos=pos+droite;
    }
    //key_gauche:16777234
    if(key==16777234){
        pos=pos+gauche;
    }
    //key_haut:16777235
    if(key==16777235){
        pos=pos+haut;
    }
    //key_bas:16777237
    if(key==16777237){
        pos=pos+bas;
    }
    insert(c,3);
}
