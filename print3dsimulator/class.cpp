#include <iostream>
#include "class.h"

using namespace std;

Drukarka::Drukarka(string n, int c, float s)
{
    nazwa=n;
    cena=c;
    szybkosc=s;
}

//-----------------------------------------------------

Filament::Filament(string n, int c)
{
    nazwa=n;
    cena_kg=c;
}

//-----------------------------------------------------

Transport::Transport(string n, float s)
{
    nazwa=n;
    szybkosc=s;
}

//-----------------------------------------------------

