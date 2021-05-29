// Imagine++ project
// Project:  test
// Author:   Etien
// Date:     2021/04/26

#include "circuit.h"
#include "kart.h"

int main()
{
    InitRandom();

    circuit circ(largeur,hauteur,profondeur);

    vaisseau v;
    circ.affiche(0);
    v.affiche(PURPLE);
    click();
    obstacle ob1(largeur,hauteur,0);
    obstacle ob2(largeur,hauteur,4);

    ob1.insert(circ);
    ob2.insert(circ);
    for(int k=0;k<distance_affichage;k++){
        v.bouge(circ,k);
        milliSleep(attente);
    }
    return 0;

}

///Test 3D
//    openWindow3D(largeur*taille_case, hauteur*taille_case);

//    Mesh face_gauche=Mesh::Plane(DoublePoint3(0,int(hauteur*taille_case/2),int(taille_case/2)),DoubleVector3(0,hauteur*taille_case,0),DoubleVector3(0,0,taille_case)); //Face gauche
//    Mesh face_droite=Mesh::Plane(DoublePoint3(largeur*taille_case,int(hauteur*taille_case/2),int(taille_case/2)),DoubleVector3(0,hauteur*taille_case,0),DoubleVector3(0,0,taille_case));
//    Mesh face_haut=Mesh::Plane(DoublePoint3(int(largeur*taille_case/2),hauteur*taille_case,int(taille_case/2)),DoubleVector3(largeur*taille_case,0,0),DoubleVector3(0,0,taille_case));
//    Mesh face_bas=Mesh::Plane(DoublePoint3(int(largeur*taille_case/2),0,int(taille_case/2)),DoubleVector3(largeur*taille_case,0,0),DoubleVector3(0,0,taille_case));
//    showMesh(face_gauche);
//    showMesh(face_droite);
//    showMesh(face_bas);
//    showMesh(face_haut);

//    setCamera(DoublePoint3(int(largeur*taille_case/2),int(hauteur*taille_case/2),0),DoublePoint3(0,0,taille_case),DoubleVector3(0,1,0));

//    endGraphics();
