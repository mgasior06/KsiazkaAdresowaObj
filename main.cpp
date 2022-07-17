#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wylogowanieUzytkownika();
    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    return 0;
}
