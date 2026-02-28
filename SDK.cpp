//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#include "SDK.h"
#include <random> // Header for modern random tools

SDK::SDK(int numdroni)
{
    numDroni = numdroni;

    for (int i = 0; i<numdroni; i++)
    {
        posizioniDroni[i].altitudine = i;
        posizioniDroni[i].latitudine = i;
        posizioniDroni[i].longitudine = i;
    }
}

int SDK::getDroneData(float *latitudine, float *longitudine, float *altitudine)
{
    int NDrone = rand()%numDroni;

    float delta = (-5 + rand()%11)/100.0;

    posizioniDroni[NDrone].altitudine += delta;
    posizioniDroni[NDrone].longitudine += delta;
    posizioniDroni[NDrone].latitudine += delta;

    *latitudine = posizioniDroni[NDrone].latitudine;
    *longitudine = posizioniDroni[NDrone].longitudine;
    *altitudine = posizioniDroni[NDrone].altitudine;

    return NDrone;
}