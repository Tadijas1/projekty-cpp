#include <iostream>
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