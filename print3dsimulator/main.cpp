#include <iostream>
#include "class.h"
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

char a;
float kasa;
bool zlecienie=true;

Drukarka twojaDrukarka;
Drukarka ender(600, 1.5);
Drukarka prusa(1000, 2.5);
Drukarka prusaPro(1500, 3.5);
Filament fPla(10, 0);
Filament fAbs(20, 0);
Filament fTpu(30, 0);
Zlecenie zlecenie;

void podroz(int x)
{
    for (int i = 1; i <= x; i++)
    {
        system("cls"); //system("clear")
        if(i<=3) cout<<"Szykowanie sie do drogi";
        else if((i>3)&&(i<x)) cout<<"Przemieszczanie sie do celu";
        else if(i==x) cout<<"Jestes na miejscu";
        if(i%3==0) cout<<"."<<endl;
        if(i%3==1) cout<<".."<<endl;
        if(i%3==2) cout<<"..."<<endl;
        cout<<"(";
        for (int d = 0; d < i; d++) cout<<"#";
        for (int d = 0; d < x-i; d++) cout<<"_";
        cout<<")"<<endl;
        Sleep(1000);
    }
    return;
}

void komputer()
{
    bool exit=true;
    while (exit)
    {
        if(zlecienie){
            Zlecenie nowe(rand()%+100+100, rand()%50+50, rand()%30+30, rand()%3);
        }
        else{
            cout<<"Nie masz aktualnie zdanych zlecen :)"<<endl;
            getchar();
            exit=false;
        }
    }
    return;
}

void drukarnia()
{
    bool exit=true;
    while (exit)
    {
        getchar();
        exit=false;
    }
    return;
}

void s_drukarki()
{
    bool exit=true;
    while (exit)
    {
        getchar();
        exit=false;
    }
    return;
}

void s_samochody()
{
    bool exit=true;
    while (exit)
    {
        getchar();
        exit=false;
    }
    return;
}

void podworko()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"1. Idz do sklepu z drukarkami i filamentem"<<endl;
        cout<<"2. Idz do sklepu z samochodami"<<endl;
        cout<<"3. Wstecz"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            podroz(10);
            s_drukarki();
        break;
        case '2':
            podroz(60);
            s_samochody();
        break;
        case '3':
            exit=false;
        break;    
        }
    }
    return;
}

void dom()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"1. Idz do drukarni"<<endl;
        cout<<"2. Idz do komputera"<<endl;
        cout<<"3. Wyjdz z domu"<<endl;
        cout<<"4. Wyjdz do menu glownego"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            drukarnia();
        break;
        case '2':
            komputer();
        break;
        case '3':
            podworko();
        break;
        case '4':
            exit=false;
        break;
        }
    }
    return;
}

void menu_glowne()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"1. Nowa gra"<<endl;  
        cout<<"2. Wczytaj gre"<<endl;
        cout<<"3. Wyjdz"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            dom();
        break;
        case '2':
            system("cls"); //system("clear")
            cout<<"Na razie tego nie mamy :)"<<endl;
            getchar();
        break;
        case '3':
            exit=false;
        break;
        }
    }
    return;
}

int main()
{
    srand(time(NULL));
    menu_glowne();
    return 0;
}