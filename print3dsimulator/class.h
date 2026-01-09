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
    friend void drukowanie();
};

class Filament
{
    float cena_kg;
    int ilosc;

    public:
    Filament(float=0,int=0);
    friend void kupowanie_filamentu(int a);
    friend void drukowanie();
};

class Transport
{
    string nazwa;
    int cena;
    float szybkosc;

    public:
    Transport(string="",int=0,float=1);
    friend void kupowanie_transportu(int a);
    friend void podroz_druk(int x, bool c);
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
    friend void drukowanie();
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