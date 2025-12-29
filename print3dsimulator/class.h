#include <iostream>

using namespace std;

class Drukarka
{
    int cena;
    float szybkosc;
    string nazwa;

    public:
    Drukarka(string="",int=0,float=0);
};

class Filament
{
    int cena_kg;
    string nazwa;

    public:
    Filament(string="",int=0);
};

class Transport
{
    float szybkosc;
    string nazwa;

    public:
    Transport(string="",float=0);
};