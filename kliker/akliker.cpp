#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>


using namespace std;

int klik=0;
char wybor;

int main()
{
    fstream plik;
    string linia;
    plik.open("aa_plik_kliker.txt", ios::in);

    getline(plik, linia);
    klik=atoi(linia.c_str());

    while(true){
        system("cls");
        cout<<"Wcisni = aby zapisac i wyjsc"<<endl;
        cout<<"Wcisni - aby zresetowac licznik"<<endl;
        cout<<"Masz "<<klik<<" klikow"<<endl;
        cout<<"!Kliker!"<<endl;

        wybor=getch();
        cout<<endl;
        
        if(wybor=='='){
            fstream plik;
            plik.open("aa_plik_kliker.txt", ios::out);

            plik<<klik;
            plik.close();
            exit(0);
        }

        if (wybor=='-')
        {
            klik=-1;
        }
        
        klik++;
    }
    return 0;
}
