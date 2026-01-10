#include <iostream>
#include "class.h"
#include <conio.h>
#include <string>

using namespace std;

Drukarka::Drukarka(string n,int c, float s)
{
    nazwa=n;
    cena=c;
    szybkosc=s;
}
//-----------------------------------------------------

Filament::Filament(string n, float c, int i)
{
    nazwa=n;
    cena_kg=c;
    ilosc=i;
}

//-----------------------------------------------------

Transport::Transport(string n, int c, float s)
{
    nazwa=n;
    cena=c;
    szybkosc=s;
}

//-----------------------------------------------------

Zlecenie::Zlecenie(float z, int f, int c, int tf)
{
    zysk=z;
    ileFilament=f;
    ileCzasu=c;
    typFilamentu=tf;
}

void Zlecenie::pokaz()
{
    cout<<"Zysk: "<<zysk<<endl;
    cout<<"Potrzebny filament: "<<ileFilament<<" gramy"<<endl;
    cout<<"Typ filamentu: ";
    if(typFilamentu==0) cout<<"PLA"<<endl;
    else if(typFilamentu==1) cout<<"ABS"<<endl;
    else if(typFilamentu==2) cout<<"PET"<<endl;
    cout<<endl;
    cout<<"Potrzebny czas na wydruk: "<<ileCzasu<<" sekund"<<endl;
    return;
}

//-----------------------------------------------------

Danefirmy::Danefirmy(string n, string em, string nt, string hp)
{
    nazwa=n;
    email=em;
    numerTelefonu=nt;
    hasloPromocyjne=hp;
}

void Danefirmy::tworzenie()
{
    bool calosc=true;
    while(calosc)
    {
        system("cls"); //system("clear")
        bool exit=true;
        while(exit)
        {
            system("cls"); //system("clear")
            cout<<"Jak ma sie nazywac twoja firma: ";
            getline(cin, nazwa);
            if(nazwa!="") exit=false;
        }
        exit=true;
        while(exit)
        {
            system("cls"); //system("clear")
            cout<<"Jaki ma miec e-mail twoja firma: ";
            cin>>email;
            if(email.find("@gmail.com")<email.size()-1) exit=false;
        }
        exit=true;
        while(exit)
        {
            system("cls"); //system("clear")
            cout<<"Jaki ma miec numer telefonu twoja firma: ";
            cin>>numerTelefonu;
            if(numerTelefonu.size()==9) exit=false;
        }
        exit=true;
        while(exit)
        {
            system("cls"); //system("clear")
            cout<<"Jakie ma miec haslo promocyjne twoja firma: ";
            getline(cin, hasloPromocyjne);
            if(hasloPromocyjne!="") exit=false;
        }

        exit=true;
        while(exit)
        {
            system("cls"); //system("clear")
            cout<<"Czy wszystko sie zgadza?"<<endl;
            cout<<"Nazwa: "<<nazwa<<endl;
            cout<<"E-mail: "<<email<<endl;
            cout<<"Numer telefonu: "<<numerTelefonu<<endl;
            cout<<"Haslo promocyjne: "<<hasloPromocyjne<<endl;

            cout<<"1. tak"<<endl;
            cout<<"2. zacznij jeszcze raz"<<endl;
            char a=getch(); cout<<endl;

            if(a=='1') {exit=false; calosc=false;}
            else if(a=='2') exit=false;
        }
    }
    system("cls"); //system("clear")
    cout<<"Zarejstrowano firme!"<<endl;
    getchar();
    return;
}

//-----------------------------------------------------

