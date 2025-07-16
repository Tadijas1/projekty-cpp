#include <iostream>
#include "produkt.h"
#include <limits> // sprownza czy do int'a nie trafił string
#include <cstdlib> // czyszczenie ekranu
#include <string> // sprawdza ile liter jest w wyrazie

using namespace std;

Produkt::Produkt()
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

void Produkt::pokaz()
{
    if(nazwa.length()==4){
        cout<<"Działa"<<endl;
    }
    cout<<nazwa<<" | "<<kategoria<<" | "<<cena<<endl;
}

bool Produkt::sprawdzanie(string j)
{
    if(j==nazwa) return true;
    else return false;
}

int Produkt::skalowanie()
{
    return nazwa.length();
}