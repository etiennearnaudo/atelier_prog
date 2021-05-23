#include "outils.h"

void InitRandom()
{
    srand((unsigned int)time(0));
}

int Random(int a, int b)
{
    return int(a + (rand()%(b-a+1)));
}
