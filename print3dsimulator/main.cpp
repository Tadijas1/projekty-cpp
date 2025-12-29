#include <iostream>
#include "class.h"
#include <conio.h>

using namespace std;

char a;

void komputer()
{
    getchar();
    return;
}

void drukarnia()
{
    getchar();
    return;
}

void podroz(int x)
{
    getchar();
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
        cout<<"3. Wroc do domu"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            podroz(30);
        break;
        case '2':
            podroz(60);
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
        cout<<"4. Wstecz"<<endl;
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
    menu_glowne();
    return 0;
}