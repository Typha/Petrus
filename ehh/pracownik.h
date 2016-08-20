//===============================================
// Nazwa          : pracownik.h
// System         : Windows 8
// Autor          : Piotr
// Opis           : Program drugi - Informatyka 2
// Refaktoryzacja : 19.08.2016
//===============================================

#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include <iostream>
#include <cstdio>
#include <string>
#define PROCENT 0.35
#define PREMIA 1.5

using namespace std;

class Pracownik
{
private:
    bool zatrudnienie;
    string imie;
    string nazwisko;
    string nip;
public:
    string pesel;
    Pracownik();
    Pracownik(string im, string nzwsk, string psl, string np);
    bool sprawdzDane(string im, string nzwsk);
    virtual void wyswietlDane() = 0;
    virtual void obliczZarobki() = 0;
    virtual ~Pracownik() {};
};

class Staly: public Pracownik
{
private:
    double wynagrodzenie;
public:
    Staly();
    Staly(string im, string nzwsk, string psl, string np, double wngrdzn);
    void obliczZarobki() {} // bardzo wa¿ne
    void wyswietlDane();
    ~Staly() {};
};

class Zleceniobiorca: public Pracownik
{
private:
    double stawka;
    int godziny;
    double wynagrodzenie;
public:
    Zleceniobiorca();
    Zleceniobiorca(string im, string nzwsk, string psl, string np, double stwk, int gdzn);
    void wyswietlDane();
    void obliczZarobki();
    ~Zleceniobiorca() {}
};

class Handlujacy: public Pracownik
{
private:
    double wartosc;
    int transakcje;
    double wynagrodzenie;
public:
    Handlujacy();
    Handlujacy(string im, string nzwsk, string psl, string np, double wrtsc, int trnskcj);
    void wyswietlDane();
    void obliczZarobki();
    ~Handlujacy() {}
};

void enter();
void naglowek();
void czyszczenie();

#endif
