//
// Created by SOR Team Robocup ITIS Rossi Vicenza on 27/02/26.
//

#include "Lettore.h"

#include <iostream>
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
    *FILEREADER << "Latitudine\tLongitudine\tAltitudine" << std::endl;
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

        if (numDrone == 0)
        {
            std::cout << "\n" << latitudine << "\t" << longitudine << "\t" << altitudine <<std::flush;
        }

        *FILEREADER << latitudine << "\t" << longitudine << "\t" << altitudine << std::endl;

        /*
        Stesso problema del cout — ofstream è bufferizzato. Aggiungi std::flush o << std::endl:
            *FILEREADER << "\n" << latitudine << "\t" << longitudine << "\t" << altitudine << std::flush;

        Oppure dopo la scrittura:
            cppFILEREADER->flush();

        Il programma gira all'infinito quindi il buffer non viene mai svuotato automaticamente (cosa che succederebbe alla chiusura del file), e i dati rimangono in memoria senza essere scritti su disco.
        Ma quando nel distruttore faccio ->close non dovrebbe permettermi di vedere il contenuto dopo il termine del exe?
        Sì, close() svuota il buffer, ma il problema è che il programma non termina mai — i thread girano in while(true) all'infinito, quindi il distruttore non viene mai chiamato.
        Quindi o aggiungi std::flush durante la scrittura, oppure gestisci una condizione di uscita dai thread.
        Ma quando faccio ctrl c
        Quando fai Ctrl+C il programma riceve SIGTERM/SIGINT e viene killato immediatamente dal OS — i distruttori non vengono chiamati, quindi close() non viene mai eseguito e il buffer rimane non svuotato.
        Soluzione più semplice: aggiungi std::flush come detto prima.
        */

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
