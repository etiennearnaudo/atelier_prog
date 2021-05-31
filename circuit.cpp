#include "circuit.h"

pixel::pixel(){
    x=0;
    y=0;
}

pixel::pixel(int x0, int y0,int z0){
    x=x0;
    y=y0;
    z=z0;
}

pixel::~pixel(){}

int pixel::getx(){
    return x;
}

int pixel::gety(){
    return y;
}

int pixel::getz(){
    return z;
}

void pixel::setx(int x0){
    x=x0;
}

void pixel::sety(int y0){
    y=y0;
}

void pixel::setz(int z0){
    z=z0;
}

int pixel::indice(int W,int H){
    return(x+y*W+W*H*z);
}

circuit::circuit(int w, int h, int d){
    width = w;
    heigth = h;
    depth = d;
    for(int n=0;n<distance_affichage;n++){
        obstacles[n]=obstacle(w,h,d);
        obstacles[n].set_type(0);
    }
    pixel p;
    for (int k=0;k<depth;k++){
        p.setz(k);
        for (int i=0;i<width;i++){
            p.setx(i);
            for (int j=1;j<heigth-1;j++){
                p.sety(j);
                tunnel[p.indice(width,heigth)] = 0;
            }
            p.sety(0);
            tunnel[p.indice(width,heigth)] = 1;
            p.sety(heigth-1);
            tunnel[p.indice(width,heigth)] = 1;
        }
        for (int i=1;i<heigth-1;i++){
            p.sety(i);
            for (int j=1;j<width-1;j++){
                p.setx(j);
                tunnel[p.indice(width,heigth)] = 0;
            }
            p.setx(0);
            tunnel[p.indice(width,heigth)] = 1;
            p.setx(width-1);
            tunnel[p.indice(width,heigth)] = 1;
        }
    }
}

circuit::~circuit(){}

void circuit::setPixel(pixel p,int value){
    tunnel[p.indice(width,heigth)] = value;
}

//void circuit::affiche(int z,int size,int dec_x,int dec_y){
//    pixel p;
//    p.setz(z);
//    for (int i=0;i<width;i++) for (int j=0;j<heigth;j++) {
//        p.setx(i);
//        p.sety(j);
//        if(tunnel[p.indice(width,heigth)]==2) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLUE);
//    }
//}

void circuit::affiche(int z){
    for(int i=distance_affichage-1;i>=0;i--){
        obstacles[i].affiche(i, decallage);
//        affiche((z+distance_affichage-i)%depth,taille_case-(distance_affichage-i),(distance_affichage-i)*(width/2),(distance_affichage-i)*((heigth/2)-3));
    }
}

void circuit::affiche_fond(int decallage){
    fillRect(0,0,width*taille_case,heigth*taille_case,WHITE);
    for(int n=distance_affichage;n>0;n--){
        int size = taille_case-(distance_affichage-n);
        int dec_x = (distance_affichage-n)*(width/2);
        int dec_y = (distance_affichage-n)*((heigth/2)-decallage);

        fillRect(dec_x,dec_y,(width)*size,size,BLACK); //haut
        fillRect(dec_x,dec_y,size,(heigth)*size,BLACK); //gauche
        fillRect(dec_x,(heigth-1)*size+dec_y,(width)*size,size,BLACK); //bas
        fillRect((width-1)*size+dec_x,dec_y,size,(heigth)*size,BLACK); //droite

    }

}

int circuit::getPixel(pixel p){
    return tunnel[p.indice(width,heigth)];
}

void circuit::reinit_couche(int z){
//    obstacles[z].set_type(0);
    pixel p;
    p.setz(z);
    for (int i=0;i<width;i++){
        p.setx(i);
        for (int j=1;j<heigth-1;j++){
            p.sety(j);
            tunnel[p.indice(width,heigth)] = 0;
        }
        p.sety(0);
        tunnel[p.indice(width,heigth)] = 1;
        p.sety(heigth-1);
        tunnel[p.indice(width,heigth)] = 1;
    }
    for (int i=1;i<heigth-1;i++){
        p.sety(i);
        for (int j=1;j<width-1;j++){
            p.setx(j);
            tunnel[p.indice(width,heigth)] = 0;
        }
        p.setx(0);
        tunnel[p.indice(width,heigth)] = 1;
        p.setx(width-1);
        tunnel[p.indice(width,heigth)] = 1;
    }
}

obstacle::obstacle(int w,int h,int z){
    int n=Random(1,3);
    pixel pix(0,0,z);
    if (n==1){
        type=1;
        taille = ((w/2)-1)*(h-2);
        ob = new pixel[taille];
        for (int i=0;i<w/2-1;i++) for (int j=0;j<h-2;j++) {
            pix.setx(i+1);
            pix.sety(j+1);
            ob[i+((w/2)-1)*j]=pix;
        }
    }
    if (n==2){
        type=2;
        taille = (w-2)*((h/2)-1);
        ob = new pixel[taille];
        for (int i=0;i<w-2;i++) for (int j=0;j<h/2-1;j++) {
            pix.setx(i+1);
            pix.sety(j+1);
            ob[i+(w-2)*j]=pix;
       }
    }
    if(n==3){
        type=3;
        taille = 3*(w-2);
        ob = new pixel[taille];
        for (int i=0;i<w-2;i++) for (int j=0;j<3;j++){
            pix.setx(i+1);
            pix.sety((h/2)+j);
            ob[i+(w-2)*j]=pix;
        }
    }
    principal = pixel(0,0,0);
}

//obstacle::obstacle(){
//    obstacle(largeur,hauteur,profondeur);
//}

obstacle::~obstacle(){
    delete[] ob;
}


void obstacle::insert(circuit &c){
    cout << taille <<endl;
    pixel pix;
    for (int i=0;i<taille;i++) {
        pix=ob[i];
        c.setPixel(pix,2);
   }
}

void obstacle::affiche(int couche, int decallage){
    int n=couche;
    int w=largeur;
    int h=hauteur;
    int size = taille_case-(distance_affichage-n);
    int dec_x = (distance_affichage-n)*(w/2);
    int dec_y = (distance_affichage-n)*((h/2)-decallage);

    if (type==1){
        fillRect(dec_x,dec_y,(int(w/2)-1)*size,(h-1)*size,BLUE);
    }

    if (type==2){
        fillRect(dec_x,dec_y,(w-1)*size,(int(h/2)-1)*size,BLUE);
    }

    if(type==3){
        int largeur_bande = 3 ;
        fillRect(dec_x,int(h/2)*size-dec_y,(w-1)*size,largeur_bande*size,BLUE);
    }
}

int obstacle::gettaille(){
    return taille;
}

int obstacle::get_type(){
    return type;
}

void obstacle::set_type(int Type){
    type=Type;
}

