#include <iostream>

using namespace std;

class Drukarka
{
    string nazwa;
    int cena;
    float szybkosc;

    public:
    Drukarka(string="",int=0,float=0);
    friend void kupowanie_drukarki(int a);  
};

class Filament
{
    int cena_kg;
    int ilosc;

    public:
    Filament(int=0,int=0);
    friend void kupowanie_filamentu(int a);
};

class Transport
{
    string nazwa;
    float szybkosc;

    public:
    Transport(float=0);
};

class Zlecenie
{
    float zysk;
    int ileFilament;
    int ileCzasu;
    int typFilamentu;

    public:
    Zlecenie(float=0,int=0,int=0,int=0);
    void pokaz();
};

class Danefirmy
{
    string nazwa;
    string email;
    string numerTelefonu;
    string hasloPromocyjne;

    public:
    Danefirmy(string="",string="",string="",string="");
    void tworzenie();
};