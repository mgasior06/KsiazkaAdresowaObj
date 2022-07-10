#include "AdresatMenedzer.h"
int AdresatMenedzer::dodajAdresata(vector <Adresat> adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawIdAdresata(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    cin >> imie;
    imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    cin >> numerTelefonu;
    numerTelefonu = zamienPierwszaLitereNaDuzaAPozostaleNaMale(numerTelefonu);
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    cin >> email;
    email = zamienPierwszaLitereNaDuzaAPozostaleNaMale(email);
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    cin >> adres;
    adres = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adres);
    adresat.ustawAdres(adres);

    return adresat;
}

string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
