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
    protected:
    string nazwa;
    int max_w_magazynku;
    int ile_w_magazynku;
    public:
    virtual void przeladuj() = 0;
    virtual bool strzal() = 0;
    friend void statystyki(int w);
    friend void strzelanina(int &t,int &w);
};

class Pistolet :public Bron
{
    public:
    Pistolet(string="Broń",int=0,int=0);
    virtual void  przeladuj();
    virtual bool strzal();
};

class Strzelba :public Bron
{
    public:
    Strzelba(string="Broń",int=0,int=0);
    virtual void  przeladuj();
    virtual bool strzal();
};