#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlWszystkichAdresatow(vector <Adresat> adresaci);
    void wyswietlDaneAdresata(Adresat adresat);


public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    int dodajAdresata(vector <Adresat> adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();

};
#endif

