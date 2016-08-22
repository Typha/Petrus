//===============================================
// Nazwa          : main.cpp
// System         : Windows 8
// Autor          : Piotr
// Opis           : Program drugi - Informatyka 2
// Refaktoryzacja : 20.08.2016
//===============================================

#include <vector>
#include <windows.h>
#include "pracownik.h"

int main()
{
    vector <Pracownik*> kadra;
    kadra.push_back(new Staly("Piotr","Wierchowienski","63032300373","4457301037",3300));
    kadra.push_back(new Staly("Mikolaj","Stawrogin","89102905493","7260631988",4100));
    kadra.push_back(new Zleceniobiorca("Iwan","Szatow","77082213114","6825506522",2300,50));
    kadra.push_back(new Zleceniobiorca("Aleksy","Kirillow","85052403018","5913117469",2700,35));
    kadra.push_back(new Handlujacy("Sergiusz","Liputin","67052801713","4621950579",800,14));
    kadra.push_back(new Handlujacy("Ignacy","Lebiadkin","79091902931","8442924521",850,10));
    unsigned short wybor;
    do
    {
        cout << "Zarzadzanie kadra pracownicza:" << endl;
        cout << "[1] --> Zatrudnij stalego pracownika" << endl;
        cout << "[2] --> Zatrudnij zleceniobiorce" << endl;
        cout << "[3] --> Zatrudnij handlujacego" << endl;
        cout << "[4] --> Wyswietl dane pracownika" << endl;
        cout << "[5] --> Wyswietl dane calej kadry" << endl;
        cout << "[6] --> Wyswietl liczbe pracownikow" << endl;
        cout << "[7] --> Zwolnij pracownika" << endl;
        cout << "[8] --> Zwolnij cala kadre" << endl;
        cout << "[0] --> Wyjscie" << endl;
        cout << "Twoj wybor: " << endl;
        do
        {
            cin.clear();
            cin.sync();
            cin >> wybor;
        }
        while(!cin.good());
        cout << endl;
        switch(wybor)
        {
        case 1 :
            kadra.push_back(new Staly());
            break;
        case 2 :
            kadra.push_back(new Zleceniobiorca());
            break;
        case 3 :
            kadra.push_back(new Handlujacy());
            break;
        case 4 :
        {
            if(kadra.empty())
            {
                cout << "Brak zatrudnionych pracownikow. [ENTER]" << endl;
                enter();
                break;
            }
            cout << "Wyszukiwanie pracownika na podstawie imienia i nazwiska..." << endl;
            string szukaneImie,szukaneNazwisko;
            cout << "Imie: ";
            cin >> szukaneImie;
            cout << "Nazwisko: ";
            cin >> szukaneNazwisko;
            unsigned int i;
            for(i=0; i<kadra.size(); i++)
            {
                if(kadra[i]->sprawdzDane(szukaneImie,szukaneNazwisko))
                {
                    kadra[i]->wyswietlDane();
                    cout << "Aby powrocic do menu nacisnij [ENTER]." << endl;
                    enter();
                    break;
                }
            }
            if(i==kadra.size())
            {
                cout << "Brak pracownika o takim imieniu u nazwisku. [ENTER]";
                enter();
                break;
            }
        }
        break;
        case 5 :
        {
            if(kadra.empty())
            {
                cout << "Brak zatrudnionych pracownikow. [ENTER]" << endl;
                enter();
                break;
            }
            unsigned int i;
            naglowek();
            for(i=0; i<kadra.size(); i++)
            {
                cout.width(5);
                cout << left << i;
                kadra[i]->wyswietlDane();
            }
            cout << "Aby powrocic do menu nacisnij [ENTER]." << endl;
            enter();
        }
        break;
        case 6 :
            cout << "Liczba pracownikow: " << kadra.size() <<  ". [ENTER]" << endl;
            enter();
            break;
        case 7 :
        {
            if(kadra.empty())
            {
                cout << "Brak zatrudnionych pracownikow. [ENTER]" << endl;
                enter();
                break;
            }
            cout << "Usuwanie pracownika o podanym indeksie" << endl;
            unsigned int szukanyIndeks;
            do
            {
                cout << "Indeks:";
                cin.clear();
                cin.sync();
                cin >> szukanyIndeks;
            }
            while(szukanyIndeks>kadra.size() || !cin.good());
            kadra.erase(kadra.begin()+szukanyIndeks);
            cout << "Usunieto pracownika. Aby powrocic do menu nacisnij [ENTER]." << endl;
            enter();
        }
        break;
        case 8 :
            kadra.clear();
            cout << "Cala kadra zostala zwolniona. [ENTER]" << endl;
            enter();
            break;
        }
        system("cls");
    }
    while(wybor!=0);
    return 0;
}
