//=======================================
// Nazwa  : pracownik.h
// Autor  : Kefas
// Wersja : 2.32
// Opis   : Program drugi - Informatyka 2
//=======================================

#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include <iostream>
#include <cstdio>
#include <string>
#define PROCENT 1.5
#define STRUMIEN 256

using namespace std;

class Pracownik
{
private:
    bool zatrudnienie;
    string imie;
    string nazwisko;
    string pesel;
    string nip;
public:
    Pracownik();
    Pracownik(string im, string nzwsk, string psl, string np);
    void zmianaZatrudnienia(Pracownik prcwnk);
    //virtual void wyswietlDane() = 0;
    //virtual void obliczZarobki() = 0;
    ~Pracownik() {};
    // jest to jednoczesnie implementacja
    // zastanowić się gdyby nie było destruktora
};

class Staly: public Pracownik
{
private:
    double wynagrodzenie;
public:
    Staly();
    Staly(string im, string nzwsk, string psl, string np, double wngrdzn);
    //void wyswietlDane(); // const
    ~Staly() {};
};

class Zleceniobiorca: public Pracownik
{
private:
    double stawka;
    int godziny;
public:
    Zleceniobiorca();
    Zleceniobiorca(string im, string nzwsk, string psl, string np, double stwk, int gdzn);
    //void wyswietlDane(); // const
    //void obliczZarobki();
    ~Zleceniobiorca() {}
};

class Handlujacy: public Pracownik
{
private:
    double wartosc;
    int transakcje;
public:
    Handlujacy();
    Handlujacy(string im, string nzwsk, string psl, string np, double wrtsc, int trnskcj);
    //void wyswietlDane(); // const
    //void obliczZarobki();
    ~Handlujacy() {}
};

void czyszczenie();
#endif
