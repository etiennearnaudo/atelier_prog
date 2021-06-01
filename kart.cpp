#include "kart.h"
#include "affichage.h"


vaisseau::vaisseau(){
    taille=Vect2(taille_vaisseau_x,taille_vaisseau_y);
    pos=Vect2(int(hauteur/2)-int(taille.getx()/2),int(largeur/2)-int(taille.gety()/2));
    vit=Vect2(2,2);
    int w_v=get_taille().getx(), h_v=get_taille().gety() ;
    byte* rgb_vaisseau;
    assert(loadColorImage(srcPath("Xwing.bmp"), rgb_vaisseau, w_v, h_v)); // Stop si l'image n'est pas chargee
    image=NativeBitmap(w_v,h_v);
    image.setColorImage(0, 0, rgb_vaisseau, w_v, h_v);
}

vaisseau::~vaisseau(){
    delete[] rgb_vaisseau ;
}
Vect2 vaisseau::getP(){
    return pos;
}

Vect2 vaisseau::getV(){
    return vit;
}

void vaisseau::affiche(Color C){
/// Version carrés :
//    fillRect(getP().getx()*taille_case,getP().gety()*taille_case,get_taille().getx()*taille_case,get_taille().gety()*taille_case,C);

/// Avec image bmp :
    putNativeBitmap(taille_case*getP().getx(),taille_case*getP().gety(),image); //On affiche uniquement la tête
}

void vaisseau::bouge(circuit &c, int decallage){
//    affiche(WHITE);
    c.affiche(decallage);

    int key=clavier();
    //key_droite:16777236
    if(key==16777236 && (getP().getx()+taille.getx()-1 + v_x<largeur)){
        pos=pos+droite;
    }
    //key_gauche:16777234
    if(key==16777234 && (getP().getx()-v_x>=0)){
        pos=pos+gauche;
    }
    //key_haut:16777235
    if(key==16777235 && (getP().gety()-v_y>=0)){
        pos=pos+haut;
    }
    //key_bas:16777237
    if(key==16777237 && (getP().gety()+taille.gety()+ v_x<hauteur)){
        pos=pos+bas;
    }
    affiche(PURPLE);
}

Vect2 vaisseau::get_taille(){
    return taille;
}



