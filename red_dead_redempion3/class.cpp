#include <iostream>
#include <unistd.h>
#include "class.h"

using namespace std;


Jedzenie::Jedzenie(string n, int i)
{
    nazwa=n;
    ile_HP=i;
}

void Jedzenie::wykorzystanie()
{
    cout<<"Nazwa to: "<<nazwa<<endl;
    cout<<"Przwraza jedzenia: "<<ile_HP<<endl;
}

//-------------------------------------------------

Dynamit::Dynamit(string n, int i)
{
    nazwa=n;
    ile_WROGOW=i;
}

void Dynamit::wykorzystanie()
{
    cout<<"Nazwa to: "<<nazwa<<endl;
    cout<<"Zabija wrogow: "<<ile_WROGOW<<endl;
}

//--------------------------------------------------

Bron::Bron(string n, int ma, int ia)
{
    nazwa=n;
    max_w_magazynku=ma;
    ile_w_magazynku=ia;
}

void Bron::przeladuj()
{
    for (int i = 0; i <= max_w_magazynku; i++)
    {
        cout<<i<<"/"<<max_w_magazynku<<endl;
        sleep(0.5);
    }
    
    ile_w_magazynku=max_w_magazynku;
}

void Bron::strzal()
{
    if(ile_w_magazynku>=1) ile_w_magazynku--;
    else cout<<"Nie masz już amunicji. Przeładuj!"<<endl;
}

Pistolet::Pistolet(string n, int ma, int ia)
:Bron(n, ma, ia)
{
    
}