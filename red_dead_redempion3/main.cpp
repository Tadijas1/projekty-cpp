#include <iostream>
#include "class.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int zycie=10, sokole_oko=5;
char a;

void zmiana_broni(int &j);
void wykonajStrzal(bool &c, int t, int &w);

void czy_oberwales(bool &c, int s)
{
    //czy cię trafiono
    if(1==rand()%s+1){
        system("clear");
        cout<<"Zostales trafiony! Masz o jedno zycie mniej!"<<endl;
        if(zycie-1==0){cout<<"NIE ZYJESZ"<<endl; c=false;}
        zycie--;
        sleep(2);
    }
}

void strzelanina(int &t,int &w)
{
    system("clear");
    bool czy=true, pierwszyNapis=true, jeszce_raz=true;
    int szansa_na_dostanie, jaka_bron;
    if(t==7) szansa_na_dostanie=1;
    else if(t==6) szansa_na_dostanie=2;
    else if(t==5) szansa_na_dostanie=rand()%3+3;;
    while (czy)
    {
        system("clear");
        //przypomnienie
        if(pierwszyNapis){cout<<"Nacisnij S aby zobaczyc swoje statystyki (moższ to zrobic w kazdej chwili)"<<endl; pierwszyNapis=false;}
        //wybieranie
        cout<<szansa_na_dostanie<<endl;
        cout<<"Trwa walka!"<<endl;
        cout<<"1. Strzelasz"<<endl;
        cout<<"2. Zmień broń"<<endl;
        switch (t)
        {
        case 7:
            cout<<"3. Zejdź z konia"<<endl;
        break;
        case 6:
            cout<<"3. Schowaj się"<<endl;
        break;
        case 5:
            cout<<"3. Zmień kryjówkę"<<endl;
            cout<<"4. Otwórz ekwipunek"<<endl;
        break;
        default:
        break;
        }
        cin>>a;

        switch (a)
        {
        case '1':
            wykonajStrzal(jeszce_raz, t, w);
            czy_oberwales(czy, szansa_na_dostanie);
        break;
        case '2':
            zmiana_broni(jaka_bron);
        break;
        case '3':
            if(t==7){t--; szansa_na_dostanie++;}
            if(t==6){t--; szansa_na_dostanie=rand()%3+3;}
            else szansa_na_dostanie=rand()%3+3;
            czy_oberwales(czy, szansa_na_dostanie);
        break;
        case '4'||(t==5):
            cout<<"dziala"<<endl;
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
        //czy nie ma wrogów
        if(w==0){cout<<"WYGRANA"<<endl; czy=false;}
    }
}

void wykonajStrzal(bool &j,int t,int &w)
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
        if(j){
            //nowa osoba
            if(strzal==los1){cout<<"Trafiles w glowe! Zabiłeś jednego przeciwnika!"<<endl;}
            else if((strzal==los2)||(strzal==los3)){cout<<"Trafiles w cialo! Strzel jeszcze raz aby zabic!"<<endl; j=false;}
            else cout<<"Nie trafiles"<<endl;
            sleep(2);
        }
        else{
            //ta sama osoba
            if((strzal==los1)||(strzal==los2)||(strzal==los3)){cout<<"Trafiłeś! Zabiłeś jednego przeciwnika!"<<endl; w-=1; j=true;}
            else cout<<"Nie trafileś!"<<endl;
            sleep(2);
        }
    }
    return;
}

void zmiana_broni(int &j)
{
    cout<<"dziala"<<endl;
    sleep(2);
}

void akcja(Przedmiot *x)
{
    x -> wykorzystanie();
}

int main()
{
    int wrogowie=3, trudnosc=6;
    srand(time(NULL));

    //strzelanina(trudnosc, wrogowie);

    // Jedzenie p1("puszka", 10);
    // Dynamit d1("bomba", 2);

    // Przedmiot *wsk;

    // akcja(&p1);
    // akcja(&d1);

    return 0;
}