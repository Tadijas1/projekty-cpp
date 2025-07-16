#include <iostream>
#include "produkt.h"
#include <cstdlib> // czyszczenie ekranu
#include <vector> // dodawanie obiektów do tablicy

using namespace std;

int a;
string jaki;
int ileClass=0;
vector<Produkt> p;
bool koniec=false;

void dodawanie()
{
    system("clear");
    p.push_back(Produkt());
    ileClass++;
}

void pokazywanie()
{
    system("clear");
    if(p.empty()==false){
        cout<<"Nazwa | Kategoria | Cena"<<endl;
        skalowanie();
        for (int i = 0; i < ileClass; i++)
        {
            p[i].pokaz();
        }
    }
    else{
        cout<<"Nie masz jeszcze żadnego produktu!"<<endl;
    }

    getchar();getchar();
}

void usuwanie()
{
    system("clear");
    if(p.empty()==false){
        bool czy=false;
        cout<<"(Aby wyjść wpisz /)"<<endl;
        cout<<"Jaki produkt chcesz usunąć? ";
        cin>>jaki;
        if(jaki!="/"){
            for (int i = 0; i < ileClass; i++)
            {
                if(p[i].sprawdzanie(jaki)){
                    czy=true;
                    p.erase(p.begin() + i);
                    ileClass--;
                    cout<<"Produkt usunięto pomyślnie"<<endl;
                }
            }
            if(czy==false){
                cout<<"Nie ma takiego produktu"<<endl;
            }
        }
        else{
            return;
        }
    }
    else{
        cout<<"Nie masz jeszcze żadnego produktu!"<<endl;
    }

    getchar();getchar();
}

int skalowanie()
{
    int max=0;
    for (int i = 0; i < ileClass; i++)
    {
        if(p[i].skalowanie()>max) max=p[i].skalowanie();
    }
    return max;
}

int main()
{
    while(koniec==false)
    {
        system("clear");
        cout<<"___Panel główny___"<<endl;
        cout<<"1. Dodaj produkt"<<endl;
        cout<<"2. Pokarz produkty"<<endl;
        cout<<"3. Usuń produkt"<<endl;
        cout<<"4. Wyjdź"<<endl;
        cout<<"5. Testy"<<endl;
        cin>>a;

        switch(a)
        {
        case 1:
            dodawanie();
        break;
        case 2:
            pokazywanie();
        break;
        case 3:
            usuwanie();
        break;
        case 4:
            koniec=true;
        break;
        case 5:
            skalowanie();
        break;
        default:
            cout<<"coś nie działa"<<endl;
        break;
        }
    }
    return 0;
} 