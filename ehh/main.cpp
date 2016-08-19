//=======================================
// Nazwa  : main.cpp
// Autor  : Kefas
// Wersja : 2.32
// Opis   : Program drugi - Informatyka 2
//=======================================

#include <vector>
#include "pracownik.h"

int main()
{
    vector <Pracownik> baza;
    // Zbieszona ekipa...
    baza.push_back(Staly("Piotr","Wierchowieñski","63032300373","4457301037",3300));
    baza.push_back(Staly("Miko³aj","Stawrogin","89102905493","7260631988",4100));
    baza.push_back(Zleceniobiorca("Iwan","Szatow","77082213114","6825506522",2300,40));
    baza.push_back(Zleceniobiorca("Aleksy","Kiri³³ow","85052403018","5913117469",2700,25));
    baza.push_back(Handlujacy("Sergiusz","Liputin","67052801713","4621950579",560,14));
    baza.push_back(Handlujacy("Ignacy","Lebiadkin","79091902931","8442924521",770,10));
    //...Koniec :)
    int wybor;
    do
    {
        cout << "Edycja kadry pracowniczej:" << endl;
        cout << "[1] --> Dodaj stalego pracownika na koncu danych" << endl;
        cout << "[2] --> Dodaj zleceniobiorce na koncu danych" << endl;
        cout << "[3] --> Dodaj handulajcego na koncu danych" << endl;
        cout << "[4] --> Zmien stan zatrudnienia pracownika" << endl; // zastanowi  si
        cout << "[5] --> Usun pracownika z kadry" << endl;
        cout << "[6] --> Usun cala kadre" << endl;
        cout << "[0] --> Wyjscie" << endl;
        cout << "Twoj wybor: " << endl;
        do
        {
            cin.clear();
            cin.sync();
            cin >> wybor;
        }
        while(!cin.good());
        switch(wybor)
        {
        case 1 :
            baza.push_back(Staly());
            break;
        case 2 :
            baza.push_back(Zleceniobiorca());
            break;
        case 3 :
            baza.push_back(Handlujacy());
            break;
        case 4 :
            break;
        case 5 :
            break;
        case 6 :
            break;
        }
    }
    while(wybor!=0);
    return 0;
}
