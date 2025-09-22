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