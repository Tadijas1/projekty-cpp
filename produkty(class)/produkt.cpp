#include <iostream>
#include "produkt.h"
#include <limits> // sprownza czy do int'a nie trafił string
#include <cstdlib> // czyszczenie ekranu
#include <string> // sprawdza ile liter jest w wyrazie

using namespace std;

int policzZnakiUTF8(const string& tekst)
{
    int ileLiter = 0;
    for (size_t i = 0; i < tekst.length(); ++i) {
        // Jeśli bajt nie zaczyna się od "10xxxxxx", to nowy znak
        if ((tekst[i] & 0b11000000) != 0b10000000) {
            ++ileLiter;
        }
    }
    return ileLiter;
}

void ileSpacji(int x)
{
    for (int i = 0; i < x; i++)
    {
        cout<<" ";
    }
}

Produkt::Produkt(string n,string k,int c)
{
    nazwa=n;
    kategoria=k;
    cena=c;
}

void Produkt::wczytaj()
{
    bool czy=false;
    cout<<"Podaj nazwę produktu: ";
    cin>>nazwa;
    cout<<"Podaj kategorię produktu: ";
    cin>>kategoria;
    cout<<"Podaj cenę produktu: ";
    
    while(czy==false){
        cin>>cena;
        if((cin.fail()) || (cena<=0)){
            system("clear");
            cout<<"Niepoprawnie wpisana cena!"<<endl;
            cout<<"Wpisdz ją ponownie!"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            czy=true;
        }
    }
}

void Produkt::pokaz(int max_n,int max_k)
{
    int spacje;
    spacje=max_n-policzZnakiUTF8(nazwa);
    cout<<nazwa;

    ileSpacji(spacje);
    cout<<" | "<<kategoria;
    
    spacje=max_k-policzZnakiUTF8(kategoria);

    ileSpacji(spacje);
    cout<<" | "<<cena<<endl;
}

bool Produkt::sprawdzanie(string j)
{
    if(j==nazwa) return true;
    else return false;
}