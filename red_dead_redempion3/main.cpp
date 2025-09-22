#include <iostream>
#include "class.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int zycie=10, sokole_oko=5, wrogowie, trudnosc;

void strzelanina(int t,int w)
{
    bool czy=true, jeszzce_raz=true;
    int strzal;
    cout<<"Nacisnij S aby zobaczyc swoje statystyki (moższ to zrobic w kazdej chwili)"<<endl;
    while (czy)
    {
        if(1==rand()%3+1)
        {
            if(zycie-1==0) cout<<"NIE ZYJESZ"<<endl; czy=false;
            cout<<"Zostales trafiony! Masz o jedno zycie mniej!"<<endl;

        }
        cout<<"Wybierz liczbe od 1-"<<t<<": ";
        cin>>strzal;

        int los1 = rand()%t+1;
        int los2;
        do
        {
            los2 = rand()%t+1;
        } while (los1==los2);
        int los3;
        do
        {
            los3 = rand()%t+1;
        } while (los3==los1);
        
        if(jeszzce_raz)
        {
            if(strzal==los1) cout<<"Trafiles w glowe!"<<endl;
            else if((strzal==los2)||(strzal==los3)) cout<<"Trafiles w cialo! Strzel jeszcze raz aby zabic!"<<endl; jeszzce_raz=false;
            else cout<<"Nie trafiles"<<endl;
            Sleep(2000);
        }
        else{
            jeszzce_raz=true;
        }
    }
    
    
}

void akcja(Przedmiot *x)
{
    x -> wykorzystanie();
}

int main()
{
    srand(time(NULL));

    strzelanina(5, 3);

    Jedzenie p1("puszka", 10);
    Dynamit d1("bomba", 2);

    Przedmiot *wsk;

    akcja(&p1);
    akcja(&d1);

    return 0;
}