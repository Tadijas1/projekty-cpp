#include <iostream>
#include "class.h"

using namespace std;

Zombie::Zombie(string n, int a, int h)
{
    nazwa=n;
    atak=a;
    hp=h;
}

void Zombie::wyswietlanie()
{
    cout<<"Mob: "<<nazwa<<endl;
    cout<<"Atak: "<<atak<<endl;
    cout<<"Punkty życia: "<<hp<<endl;
}

Szkielet::Szkielet(string n,int d, int a, int h) 
:Zombie(n, a, h)
{
    nazwa=n;
    dystans_s=d;
}

void Szkielet::wyswietlanie()
{
    Zombie::wyswietlanie();
    cout<<"Dystans ataku: "<<dystans_s<<endl;
}