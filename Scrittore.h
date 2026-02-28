//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#include <map>
#include "SDK.h"

#ifndef PERUZZI_ESDRONITHREAD_SCRITTORE_H
#define PERUZZI_ESDRONITHREAD_SCRITTORE_H

class Scrittore
{
public:
    Scrittore();
    Scrittore(SDK * sdk);
    void EseguiScrittore();
    void OttieniCoordinataDrone(int drone, float *latitudine, float *longitudine, float *altitudine);

private:
    std::map<int, Coordinata> posizioniDroni;
    SDK * sdk;
    std::mutex M_Mappa;
};


#endif //PERUZZI_ESDRONITHREAD_SCRITTORE_H