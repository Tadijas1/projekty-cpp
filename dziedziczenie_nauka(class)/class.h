#include <iostream>

using namespace std;

class Zombie
{
    int atak;
    int hp;

    protected:
    string nazwa;

    public:
    Zombie(string="Zombie",int=0,int=0);
    void wyswietlanie();
};

class Szkielet :public Zombie
{
    int dystans_s;

    public:
    Szkielet(string="Szkielet",int=1,int=1,int=1);
    void wyswietlanie();
};