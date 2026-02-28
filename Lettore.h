//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#ifndef PERUZZI_ESDRONITHREAD_LETTORE_H
#define PERUZZI_ESDRONITHREAD_LETTORE_H
#include <string>

#include <fstream>
#include "Scrittore.h"


class Lettore
{
public:
    Lettore(char * filePathBase, int NumDrone, Scrittore * scrittore);
    ~Lettore();

    void EseguiLettore();
    int numDrone;
private:
    std::string myFilePath;
    Scrittore * sc;
    std::ofstream * FILEREADER;
};


#endif //PERUZZI_ESDRONITHREAD_LETTORE_H