#include <iostream>

using namespace std;

class Drukarka
{
    int cena;
    float szybkosc;
    string nazwa;

    public:
    Drukarka(int=0,float=0,string="");
};

class Filament
{
    int cena_kg;
    string nazwa;

    public:
    Filament(int=0,string="");
};

class Transport
{
    float szybkosc;
    string nazwa;

    public:
    Transport(float=0,string="");
};