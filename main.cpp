#include <iostream>
#include <thread>

#include "Lettore.h"
#include "Scrittore.h"
#include "SDK.h"
#include <vector>

int main(int argc, char* argv[])
{
    char * file_prefix = argv[0];

    int numDroni = 8;

    SDK sdk(numDroni);
    Scrittore scrittore(&sdk);

    std::vector<Lettore *> lettori;

    for (int i = 0; i<numDroni; i++)
    {
        lettori.push_back(new Lettore(file_prefix, i, &scrittore));
    }

    std::thread T_Scrittore(&Scrittore::EseguiScrittore, &scrittore);

    std::vector<std::thread *> T_Lettori;
    for (int i = 0; i<numDroni; i++)
    {
        T_Lettori.push_back(new std::thread(&Lettore::EseguiLettore, (lettori[i])));
    }

    T_Scrittore.join();
    for (int i = 0; i<numDroni; i++)
    {
        T_Lettori[i]->join();
    }

    delete &T_Scrittore;
    for (int i = 0; i<numDroni; i++)
    {
        delete T_Lettori[i];
    }
    return 0;
}
