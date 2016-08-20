//===============================================
// Nazwa          : pracownik.cpp
// System         : Windows 8
// Autor          : Piotr
// Opis           : Program drugi - Informatyka 2
// Refaktoryzacja : 19.08.2016
//===============================================

#include "pracownik.h"

Pracownik::Pracownik()
{
    zatrudnienie = true;
    cout << "Wprowadzanie danych nowego pracownika..." << endl;
    cout << "Imie: ";
    cin >> imie;
    cout << "Nazwisko: ";
    cin >> nazwisko;
    cout << "PESEL: ";
    cin >> pesel;
    cout << "NIP: ";
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
    obliczZarobki();
}

Zleceniobiorca::Zleceniobiorca(string im, string nzwsk, string psl, string np, double stwk, int gdzn): Pracownik(im, nzwsk, psl, np)
{
    stawka = stwk;
    godziny = gdzn;
    obliczZarobki();
}

Handlujacy::Handlujacy(): Pracownik()
{
    cout << "Wartosc pojedynczej transakcji: ";
    cin >> wartosc;
    cout << "Ilosc transakcji: ";
    cin >> transakcje;
    obliczZarobki();
}

Handlujacy::Handlujacy(string im, string nzwsk, string psl, string np, double wrtsc, int trnskcj): Pracownik(im, nzwsk, psl, np)
{
    wartosc = wrtsc;
    transakcje = trnskcj;
    obliczZarobki();
}

void Zleceniobiorca::obliczZarobki()
{
    if(godziny>40)
        wynagrodzenie = stawka * PREMIA;
    else
        wynagrodzenie = stawka;
}

void Handlujacy::obliczZarobki()
{
    wynagrodzenie = wartosc * transakcje * PROCENT;
}

void Pracownik::wyswietlDane()
{
    cout.width(15);
    cout << left << imie;
    cout.width(15);
    cout << left << nazwisko;
    cout.width(15);
    cout << left << pesel;
    cout.width(15);
    cout << left << nip;
}

void Staly::wyswietlDane()
{
    Pracownik::wyswietlDane();
    cout.width(15);
    cout.setf( ios::showpoint );
    cout << left << wynagrodzenie << endl;
}

void Zleceniobiorca::wyswietlDane()
{
    Pracownik::wyswietlDane();
    cout.width(15);
    cout.setf( ios::showpoint );
    cout << left << wynagrodzenie << endl;
}

void Handlujacy::wyswietlDane()
{
    Pracownik::wyswietlDane();
    cout.width(15);
    cout.setf( ios::showpoint );
    cout << left << wynagrodzenie << endl;
}

bool Pracownik::sprawdzDane(string im, string nzwsk)
{
    if(imie == im && nazwisko == nzwsk)
        return true;
    return false;
}

void enter()
{
    getchar();
    getchar();
}
void naglowek()
{
    cout.width(15);
    cout << left << "Imie:";
    cout.width(15);
    cout << left << "Nazwisko:";
    cout.width(15);
    cout << left << "PESEL:";
    cout.width(15);
    cout << left << "NIP:";
    cout.width(15);
    cout << left << "Wynagrodzenie:" << endl;
}

void czyszczenie()
{
    printf("\033[2J"); // Czyœci ekran
    printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}
