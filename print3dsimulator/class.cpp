#include <iostream>
#include "class.h"

using namespace std;

Drukarka::Drukarka(int c, float s, string n)
{
    cena=c;
    szybkosc=s;
    nazwa=n;
}

//-----------------------------------------------------

Filament::Filament(int c, string n)
{
    cena_kg=c;
    nazwa=n;
}

//-----------------------------------------------------

Transport::Transport(float s, string n)
{
    szybkosc=s;
    nazwa=n;
}

//-----------------------------------------------------

