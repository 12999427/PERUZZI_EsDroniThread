//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#include "Scrittore.h"

#include <thread>

Scrittore::Scrittore()
{
    sdk = nullptr;
}

Scrittore::Scrittore(SDK * sdk)
{
    this->sdk = sdk;
}

void Scrittore::EseguiScrittore()
{
    while (true)
    {
        float altitudine, latitudine, longitudine;
        int n = sdk->getDroneData(&latitudine, &longitudine, &altitudine);

        if (n < 0) continue;

        M_Mappa.lock();
        posizioniDroni[n].altitudine = altitudine;
        posizioniDroni[n].latitudine = latitudine;
        posizioniDroni[n].longitudine = longitudine;
        M_Mappa.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Scrittore::OttieniCoordinataDrone(int drone, float *latitudine, float *longitudine, float *altitudine)
{
    M_Mappa.lock();
    * latitudine = posizioniDroni[drone].latitudine;
    * longitudine = posizioniDroni[drone].longitudine;
    * altitudine = posizioniDroni[drone].altitudine;
    M_Mappa.unlock();
}