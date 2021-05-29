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
    openWindow(width*taille_case,heigth*taille_case);
}

circuit::~circuit(){}

void circuit::setPixel(pixel p,int value){
    tunnel[p.indice(width,heigth)] = value;
}

void circuit::affiche(int z,int size,int dec_x,int dec_y){
    pixel p;
    p.setz(z);
    for (int i=0;i<width;i++) for (int j=0;j<heigth;j++) {
        p.setx(i);
        p.sety(j);
        if(tunnel[p.indice(width,heigth)]==1) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLACK);
        if(tunnel[p.indice(width,heigth)]==2) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,BLUE);
//        if(tunnel[p.indice(width,heigth)]==3) fillRect(p.getx()*size+dec_x,p.gety()*size+dec_y,size,size,PURPLE);
    }
}

void circuit::affiche(int z){
    fillRect(0,0,width*taille_case,heigth*taille_case,WHITE);
    for(int i=1;i<distance_affichage+1;i++){
        affiche(z+(distance_affichage-i),taille_case-(distance_affichage-i),(distance_affichage-i)*(width/2),(distance_affichage-i)*((heigth/2)-3));
    }
}

int circuit::getPixel(pixel p){
    return tunnel[p.indice(width,heigth)];
}

void circuit::reinit_couche(int z){};

obstacle::obstacle(int w,int h,int z){
    int n=Random(0,2);
    pixel pix(0,0,z);
    if (n==0){
        taille = ((w/2)-1)*(h-2);
        ob = new pixel[taille];
        for (int i=0;i<w/2-1;i++) for (int j=0;j<h-2;j++) {
            pix.setx(i+1);
            pix.sety(j+1);
            ob[i+((w/2)-1)*j]=pix;
        }
    }
    if (n==1){
        taille = (w-2)*((h/2)-1);
        ob = new pixel[taille];
        for (int i=0;i<w-2;i++) for (int j=0;j<h/2-1;j++) {
            pix.setx(i+1);
            pix.sety(j+1);
            ob[i+(w-2)*j]=pix;
       }
    }
    if(n==2){
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

int obstacle::gettaille(){
    return taille;
}
