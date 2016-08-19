//=======================================
// Nazwa  : pracownik.cpp
// Autor  : Kefas
// Wersja : 2.32
// Opis   : Program drugi - Informatyka 2
//=======================================

#include "pracownik.h"

Pracownik::Pracownik()
{
    cout << "Wprowadzanie danych nowego pracownika..." << endl;
    cout << "Imie: ";
    cin >> imie;
    cout << "Nazwisko: ";
    cin >> nazwisko;
    cout << "Pesel: ";
    cin >> pesel;
    cout << "Numer identyfikacji podatkowej: ";
    cin >> nip;
}

Pracownik::Pracownik(string im, string nzwsk, string psl, string np)
{
    zatrudnienie = true;
    imie = im;
    nazwisko = nzwsk;
    pesel = psl;
    nip = np;
}

Staly::Staly(): Pracownik()
{
    cout << "Miesieczne wynagrodzenie: ";
    cin >> wynagrodzenie;
}

Staly::Staly(string im, string nzwsk, string psl, string np, double wngrdzn): Pracownik(im, nzwsk, psl, np)
{
    wynagrodzenie = wngrdzn;
}

Zleceniobiorca::Zleceniobiorca(): Pracownik()
{
    cout << "Godzinna stawka: ";
    cin >> stawka;
    cout << "Przepracowane godziny: ";
    cin >> godziny;
}

Zleceniobiorca::Zleceniobiorca(string im, string nzwsk, string psl, string np, double stwk, int gdzn): Pracownik(im, nzwsk, psl, np)
{
    stawka = stwk;
    godziny = gdzn;
}

Handlujacy::Handlujacy(): Pracownik()
{
    cout << "Wartosc pojedynczej transakcji: ";
    cin >> wartosc;
    cout << "Ilosc transakcji: ";
    cin >> transakcje;
}

Handlujacy::Handlujacy(string im, string nzwsk, string psl, string np, double wrtsc, int trnskcj): Pracownik(im, nzwsk, psl, np)
{
    wartosc = wrtsc;
    transakcje = trnskcj;
}

void czyszczenie()
{
    printf("\033[2J"); // Czyści ekran
    printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}
