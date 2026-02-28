//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#include <map>
#include <random>
#ifndef PERUZZI_ESDRONITHREAD_SDK_H
#define PERUZZI_ESDRONITHREAD_SDK_H

struct Coordinata
{
public:
    float latitudine, longitudine, altitudine;

    Coordinata(float _latitudine, float _longitudine, float _altitudine)
    {
        latitudine = _latitudine;
        altitudine = _altitudine;
        longitudine = _longitudine;
    }

    Coordinata() {
        latitudine = 0;
        longitudine = 0;
        altitudine = 0;
    }
};

class SDK
{
public:
    SDK(int numdroni);
    int getDroneData(float *latitudine, float *longitudine, float *altitudine);

private:
    int numDroni;
    std::map<int, Coordinata> posizioniDroni;
};


#endif //PERUZZI_ESDRONITHREAD_SDK_H