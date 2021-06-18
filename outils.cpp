#include "outils.h"

void InitRandom()
{
    srand((unsigned int)time(0));
}

int Random(int a, int b)
{
    return int(a + (rand()%(b-a+1)));
}

//----- Gestion du clavier -----

int clavier() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}
