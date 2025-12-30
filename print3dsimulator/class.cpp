#include <iostream>
#include "class.h"

using namespace std;

Drukarka::Drukarka(int c, float s)
{
    cena=c;
    szybkosc=s;
}

void Drukarka::fun()
{
    cout<<nazwa<<endl;
    cout<<cena<<endl;
    cout<<szybkosc<<endl;
    return;
}

//-----------------------------------------------------

Filament::Filament(int c, int i)
{
    cena_kg=c;
    ilosc=i;
}

//-----------------------------------------------------

Transport::Transport(float s)
{
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

//-----------------------------------------------------

