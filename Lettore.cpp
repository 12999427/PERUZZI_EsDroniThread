//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#include "Lettore.h"

#include <thread>

#include "Scrittore.h"

Lettore::Lettore(char * filePathBase, int NumDrone, Scrittore * scrittore)
{
    numDrone = NumDrone;
    std::string base = filePathBase;
    base.append(std::to_string(NumDrone));
    base.append(".csv");

    myFilePath = base;

    sc = scrittore;

    FILEREADER = new std::ofstream(myFilePath);
    *FILEREADER << "\nLatitudine\tLongitudine\tAltitudine";
}

Lettore::~Lettore()
{
    FILEREADER->close();
}

void Lettore::EseguiLettore()
{
    while (true)
    {
        float altitudine, latitudine, longitudine;
        sc->OttieniCoordinataDrone(numDrone, &latitudine, &longitudine, &altitudine);

        *FILEREADER << "\n" << latitudine << "\t" << longitudine << "\t" << altitudine;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
