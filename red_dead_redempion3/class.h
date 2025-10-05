#include <iostream>

using namespace std;

class Przedmiot
{
    public:
    virtual void wykorzystanie()=0;
};

class Jedzenie :public Przedmiot
{
    string nazwa;
    int ile_HP;

    public:
    Jedzenie(string="brak",int=0);
    virtual void wykorzystanie();
    
};

class Dynamit :public Przedmiot
{
    string nazwa;
    int ile_WROGOW;

    public:
    Dynamit(string="brak",int=0);
    virtual void wykorzystanie();
    
};

//---------------------------------------------

class Bron
{
    string nazwa;
    string jaka_amunicja;
    int max_w_magazynku;
    int ile_w_magazynku;

    public:
    Bron(string="Broń",string="jakaś napewno",int=0,int=0);
    void przeladuj();
    void strzal();
};