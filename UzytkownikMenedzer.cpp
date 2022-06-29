#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika(uzytkownicy);
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
        //uzytkownik.login = wczytajLinie();

    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    //uzytkownik.haslo = wczytajLinie();
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
            return true;
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
     for (int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;

    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    //Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login (logowanie): ";
    //login = wczytajLinie();
    cin >> login;

    //vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if ( uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                //haslo = wczytajLinie();
                cin >> haslo;

                //if (itr -> haslo == haslo)
                if ( uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    //return itr -> id;
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    //while (itr != uzytkownicy.end())
   // {
//        if (itr -> login == login)
//        {
//            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
//            {
//                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
//                haslo = wczytajLinie();
//                cin >> haslo;
//
//                if (itr -> haslo == haslo)
//                {
//                    cout << endl << "Zalogowales sie." << endl << endl;
//                    system("pause");
//                    return itr -> id;
//                }
//            }
//            cout << "Wprowadzono 3 razy bledne haslo." << endl;
//            system("pause");
//            return 0;
//        }
      //  itr++;
  //  }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
