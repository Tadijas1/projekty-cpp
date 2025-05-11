#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

string a;
int liczba1;
int liczba2;

int dodawanie(int x, int y)
{
    return x+y;
}

int odejmowanie(int x, int y)
{
    return x-y;
}

int mnorzenie(int x, int y)
{
    return x*y;
}

float dzielenie(float x, float y)
{
    return x/y;
}

int main()
{
    while (1==1)
    {
    system("cls");
    cout<<"Podaj 1 liczbe: ";
    cin>>liczba1;
    system("cls");
    cout<<"Podaj 2 liczbe: ";
    cin>>liczba2;
    system("cls");
    cout<<"Cohcesz zrobic: ";
    cin>>a;

    if (a=="dodac")
    {
        system("cls");
        cout<<dodawanie(liczba1, liczba2)<<endl;
        getchar();getchar();
    }

    if (a=="odjac")
    {
        system("cls");
        cout<<odejmowanie(liczba1, liczba2)<<endl;
        getchar();getchar();
    }

    if (a=="wymnorzyc")
    {
        system("cls");
        cout<<mnorzenie(liczba1, liczba2)<<endl;
        getchar();getchar();
    }

    if (a=="podzielic")
    {
        system("cls");
        cout<<dzielenie(liczba1, liczba2)<<endl;
        getchar();getchar();
    }

    }

    return 0;
}