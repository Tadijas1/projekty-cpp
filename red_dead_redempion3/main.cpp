#include <iostream>
#include "class.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int zycie=10, sokole_oko=5;
char a;

void wykonajStrzal(bool &c, int t, int &w);

void czy_oberwales(bool &c)
{
    //czy cię trafiono
    if(1==rand()%3+1){
        cout<<"Zostales trafiony! Masz o jedno zycie mniej!"<<endl;
        if(zycie-1==0){cout<<"NIE ZYJESZ"<<endl; c=false;}
        zycie--;
    }
}

void strzelanina(int &t,int &w)
{
    system("clear");
    bool czy=true, pierwszyNapis=true, jeszce_raz=true;
    while (czy)
    {
        system("clear");
        //przypomnienie
        if(pierwszyNapis){cout<<"Nacisnij S aby zobaczyc swoje statystyki (moższ to zrobic w kazdej chwili)"<<endl; pierwszyNapis=false;}
        //wybieranie
        cout<<"Trwa walka!"<<endl;
        cout<<"1. Strzelasz"<<endl;
        cin>>a;

        switch (a)
        {
        case '1':
            wykonajStrzal(jeszce_raz, t, w);
            czy_oberwales(czy);
        break;
        case 's':
            //staty
            system("clear");
            cout<<"Życie: "<<zycie<<endl;
            cout<<"Sokole oko: "<<sokole_oko<<endl;
            cout<<"Pozostali wrogowie: "<<w<<endl;
            sleep(2);
        break;
        default:
            cout<<"Coś poszło nie tak"<<endl;
        break;
        }
    }
}

void wykonajStrzal(bool &c,int t,int &w)
{
    system("clear");
    char strzal;
    cout<<"Wybierz liczbe od 1-"<<t<<": ";
    cin>>strzal;

    //losowanie
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
    } while ((los3==los1) || (los3==los2));
    
    //staty
    if(strzal=='s'){
        system("clear");
        cout<<"Życie: "<<zycie<<endl;
        cout<<"Sokole oko: "<<sokole_oko<<endl;
        cout<<"Pozostali wrogowie: "<<w<<endl;
        sleep(2);
    }
    else{
        system("clear");
        //zamiana chara na int'a
        strzal=strzal - '0';
        //czy trafil
        if(c){
            //nowa osoba
            if(strzal==los1){cout<<"Trafiles w glowe!"<<endl;}
            else if((strzal==los2)||(strzal==los3)){cout<<"Trafiles w cialo! Strzel jeszcze raz aby zabic!"<<endl; c=false;}
            else cout<<"Nie trafiles"<<endl;
            sleep(2);
        }
        else{
            //ta sama osoba
            if((strzal==los1)||(strzal==los2)||(strzal==los3)){cout<<"Trafiłeś!"<<endl; w=w-1; c=false;}
            else cout<<"Nie trafileś!"<<endl;
            sleep(2);
        }
    }
    return;
}

void akcja(Przedmiot *x)
{
    x -> wykorzystanie();
}

int main()
{
    int wrogowie=3, trudnosc=5;
    srand(time(NULL));

    strzelanina(trudnosc, wrogowie);

    // Jedzenie p1("puszka", 10);
    // Dynamit d1("bomba", 2);

    // Przedmiot *wsk;

    // akcja(&p1);
    // akcja(&d1);

    return 0;
}