#include <iostream>
#include "produkt.h"
#include <cstdlib> // czyszczenie ekranu
#include <vector> // dodawanie obiektów do tablicy
#include <fstream> //możliwość odczytywania z pliku tekstowego
#include <limits>

using namespace std;

int a;
string jaki;
vector<Produkt> p;
bool koniec=false;

int skalowanie_n();
int skalowanie_k();
void skalowanie_naglowku();

void sortowanie_b()
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = p.size()-1; j>=1; j--)
        {
            int miejscje=0;
            bool czy=true;
            while(czy)
            {
                if(int(p[j].kategoria[miejscje])<int(p[j-1].kategoria[miejscje]))
                {
                    cout<<"zamiana: "<<miejscje<<endl;
                    Produkt bufor; bufor=p[j-1];
                    p[j-1]=p[j];
                    p[j]=bufor;
                    czy=false;
                }
                else if((int(p[j].kategoria[miejscje])>int(p[j-1].kategoria[miejscje])) || (miejscje==p[j-1].kategoria.size()-1)){
                    cout<<"nic: "<<miejscje<<endl;
                    czy=false;
                }
                else if(miejscje==p[j].kategoria.size()-1){
                    cout<<"zamiana: "<<miejscje<<endl;
                    Produkt bufor; bufor=p[j-1];
                    p[j-1]=p[j];
                    p[j]=bufor;
                    czy=false;
                }
                miejscje++;
            }
        }
        
    }
    
}

void dodawanie()
{
    system("clear");
    p.push_back(Produkt());
    p.back().wczytaj();
    sortowanie_b();
}

void pokazywanie()
{
    system("clear");
    if(p.empty()==false){
        skalowanie_naglowku();
        for (int i = 0; i < p.size(); i++)
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
            system("clear");
            bool czy=false;
            cout<<"(Aby wyjść wpisz /)"<<endl;
            cout<<"Jaki produkt chcesz usunąć? ";
            cin>>jaki;
            if(jaki!="/"){
                for (int i = 0; i < p.size(); i++)
                {
                    if(p[i].sprawdzanie(jaki)){
                        czy=true;
                        p.erase(p.begin() + i);
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
            system("clear");
            cout<<"Nie masz jeszcze żadnego produktu!"<<endl;
            czy_petla=true;
            getchar();
        }

        getchar();
    }
}

int skalowanie_n()
{
    int max=5;
    for (int i = 0; i < p.size(); i++)
    {
        if(p[i].nazwa.length()>max) max=p[i].nazwa.length();
    }
    return max;
}

int skalowanie_k()
{
    int max=9;
    for (int i = 0; i < p.size(); i++)
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

int obliczanie_lini()
{
    fstream plik;
    plik.open("plik.txt", ios::in);

    if(plik.good()==false){
        cout<<"Nie udało się otworzyć pliku!"<<endl;
        cout<<"Stwórz na początku jakiś zapis!"<<endl;
        exit(0);
    }

    string linia;
    int ile_lini=0;

    while (getline(plik, linia))
    {
        ile_lini++;
    }
    return ile_lini;
}

void zapisywanie()
{
    std::ofstream plik("plik.txt");
    plik.close();

    for (int i = 0; i < p.size(); i++)
    {
        p[i].zapisz(i, p.size());
    }
}

void poczatek()
{
    bool czy=true;
    while(czy)
    {
        system("clear");
        cout<<"1. Nowy magazyn"<<endl;
        cout<<"2. Wczytaj magazyn"<<endl;
        cin>>a;

        if(a==1){
            return;
        }

        else if(a==2){
            for (int i = 1; i <= obliczanie_lini()/3; i++)
            {
                p.push_back(Produkt());
                p.back().plik(i);
            }
            return;
        }
    }
}

int main()
{

    // Produkt p1("banan", "b", 10);
    // p.push_back(p1);
    // Produkt p2("śliwka", "ac", 15);
    // p.push_back(p2);
    // Produkt p3("papryka", "ab", 20);
    // p.push_back(p3);
    // Produkt p4("kokos", "abb", 20);
    // p.push_back(p4);
    // Produkt p5("ziemniak", "a", 20);
    // p.push_back(p5);
    // Produkt p6("malina", "aba", 20);
    // p.push_back(p6);
    // sortowanie_b();

    poczatek();

    while(koniec==false)
    {
        system("clear");
        cout<<"___Panel główny___"<<endl;
        cout<<"1. Dodaj produkt"<<endl;
        cout<<"2. Pokarz produkty"<<endl;
        cout<<"3. Usuń produkt"<<endl;
        cout<<"4. Wyjdź i zapisz"<<endl;
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
            zapisywanie();
            koniec=true;
        break;
        case 5:
            system("clear");

            cout<<"Na razie nie ma żadnych testów"<<endl;

            getchar();getchar();
        break;
        default:
            cout<<"coś nie działa"<<endl;
        break;
        }
    }
    return 0;
} 