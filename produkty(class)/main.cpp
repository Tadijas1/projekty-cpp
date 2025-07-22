#include <iostream>
#include "produkt.h"
#include <cstdlib> // czyszczenie ekranu
#include <vector> // dodawanie obiektów do tablicy
#include <fstream> //możliwość odczytywania z pliku tekstowego

using namespace std;

int a;
string jaki;
int ileClass=0;
vector<Produkt> p;
bool koniec=false;

int skalowanie_n();
int skalowanie_k();
void skalowanie_naglowku();

void dodawanie()
{
    system("clear");
    p.push_back(Produkt());
    p.back().wczytaj();
    ileClass++;
}

void pokazywanie()
{
    system("clear");
    if(p.empty()==false){
        skalowanie_naglowku();
        for (int i = 0; i < ileClass; i++)
        {
            p[i].pokaz(skalowanie_n(), skalowanie_k());
        }
    }
    else{
        cout<<"Nie masz jeszcze żadnego produktu!"<<endl;
    }

    getchar();getchar();
}

void usuwanie()
{
    bool czy_petla=false;

    while(czy_petla==false)
    {
        if(p.empty()==false){
            bool czy=false;
            system("clear");
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
                        czy_petla=true;
                        getchar();
                    }
                }
                if(czy==false){
                    cout<<"Nie ma takiego produktu"<<endl;
                    getchar();
                }
            }
            else{
                czy_petla=true;
            }
        }
        else{
            cout<<"Nie masz jeszcze żadnego produktu!"<<endl;
            czy_petla=true;
        }

        getchar();
    }
}

int skalowanie_n()
{
    int max=5;
    for (int i = 0; i < ileClass; i++)
    {
        if(p[i].nazwa.length()>max) max=p[i].nazwa.length();
    }
    return max;
}

int skalowanie_k()
{
    int max=9;
    for (int i = 0; i < ileClass; i++)
    {
        if(p[i].kategoria.length()>max) max=p[i].kategoria.length();
    }
    return max;
}

void skalowanie_naglowku()
{
    int spacje1;
    int spacje2;
    cout<<"Nazwa";
    spacje1=skalowanie_n()-5;

    for (int i = 0; i < spacje1; i++)
    {
        cout<<" ";
    }
    cout<<" | Kategoria";
    spacje2=skalowanie_k()-9;

    for (int i = 0; i < spacje2; i++)
    {
        cout<<" ";
    }
    cout<<" | Cena"<<endl;
    
    for (int i = 0; i < spacje1+spacje2+24; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    
}

int main()
{
    Produkt p1("banan", "owoc", 10);
    p.push_back(p1);
    ileClass++;
    Produkt p2("śliwka", "owoc", 15);
    p.push_back(p2);
    ileClass++;
    Produkt p3("papryka", "warzywo", 20);
    p.push_back(p3);
    ileClass++;
    
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
            system("clear");
            
            getchar();getchar();
        break;
        default:
            cout<<"coś nie działa"<<endl;
        break;
        }
    }
    return 0;
} 