#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <vector>

using namespace std;

string przedmioty[4] = {"", "", "", ""};
char a;

int strzal(int x);
void loot(int x);

void strzelnica(int x, int &zycie)
{
    bool wygrana=false;
    bool kryjowka=false;
    char wystrzal;
    int wynik;
    int liczbaElementow=sizeof(przedmioty)/sizeof(przedmioty[0]);
    while(wygrana==false)
    {
        system("cls");
        cout<<"Pozostale zycie: "<<zycie<<endl;
        cout<<"Pozostalo "<<x<<" wrogow"<<endl;
        cout<<"1. Strzel"<<endl;
        if(kryjowka==false){
            cout<<"2. Ukryj sie"<<endl;
        }
        else cout<<"2. Otworz ekwipunek"<<endl;

        a=getch();
        cout<<endl;

        switch (a)
        {
        case '1':
            system("cls");
            cout<<"Wybierz licze 1-4"<<endl;
            cout<<"Dwie z nich to pudlo"<<endl;
            cout<<"Jedna z nich to trafienie normalne a ostatnie to trafienie w glowe"<<endl;

            wystrzal=getch();
            cout<<endl;
            wystrzal = wystrzal - '0'; // zamiana znaku '1' na liczbę 1

            wynik=strzal(wystrzal);
            
            if(wynik==1)
            {
                system("cls");
                cout<<"Trafles w glowe!"<<endl;
                cout<<"Jeden przeciwnik umiera"<<endl;
                x--;
                cout<<"Nacisnij dowolny przecisk by kontynuowac..."<<endl;
                getch();
            }
            
            else if(wynik==2)
            {
                system("cls");
                cout<<"Trafiles przeciwnika normalnie i musis go trafic jeszcze raz!"<<endl;
                cout<<"Wybierz licze 1-4"<<endl;

                wystrzal=getch();
                cout<<endl;
                wystrzal = wystrzal - '0';

                wynik=strzal(wystrzal);

                if((wynik==1)||(wynik==2)){
                    system("cls");
                    cout<<"Zabilasz przeciwnika!"<<endl;
                    x--;
                    cout<<"Nacisnij dowolny przecisk by kontynuowac..."<<endl;
                    getch();
                }
                else{
                    system("cls");
                    cout<<"Trafili cie!"<<endl;
                    cout<<"Tracisz 1 zycie"<<endl;
                    zycie--;
                    cout<<"Nacisnij dowolny przecisk by kontynuowac..."<<endl;
                    getch();
                }
            }
            else{
                system("cls");
                cout<<"Nie trafiles!"<<endl;
                cout<<"Trafili cie!"<<endl;
                cout<<"Tracisz 1 zycie"<<endl;
                zycie--;
                cout<<"Nacisnij dowolny przecisk by kontynuowac..."<<endl;
                getch();
            }
        break;
        case '2':
            if(kryjowka==false){
                kryjowka=true;
                int trafienie = rand() % 2 + 1;
                if(trafienie==1){
                    system("cls");
                    cout<<"Podczas krycia sie zostales trafiony"<<endl;
                    zycie--;
                }
                if(trafienie==2){
                    system("cls"); cout<<"Udalo ci sie ukryc bez zostania trafionym"<<endl;
                }
            }
            else if(kryjowka==true){
                if((przedmioty[0]=="nie masz zadnych przedmiotow!")){
                    system("cls");
                    cout<<przedmioty[0]<<endl;
                }
                else if((przedmioty[0]=="")&&(przedmioty[1]=="")&&(przedmioty[2]=="")&&(przedmioty[3]=="")){
                    system("cls");
                    cout<<"Nie masz zadnych przedmiotow!"<<endl;
                }
                else{
                    system("cls");
                    cout<<"Wybierz przedmiot ktorego chcesz urzyc:"<<endl;

                    for (int i = 0; i < 4; i++)
                    {
                        cout<<i+1<<". "<<przedmioty[i]<<endl;
                    }
                    
                    a=getch();
                    cout<<endl;

                    if((a=='1')||(a=='2')||(a=='3')||(a=='4')){
                        int liczba=a-'0';

                        if(przedmioty[liczba-1]=="Bimber"){
                            system("cls");
                            
                            cout<<"Wipiles bimber"<<endl;
                            cout<<"Aby zginac, przeciwnicy musza trafic cie raz wiecej"<<endl;
                            zycie++;
                            przedmioty[liczba-1]="";
                        }
                        else if(przedmioty[liczba-1]=="Cygaro"){
                            system("cls");
                            cout<<"Wypaliles cygaro"<<endl;
                            cout<<"Masz teraz sokoli wzrok"<<endl;
                            przedmioty[liczba-1]="";
                        }
                        else if(przedmioty[liczba-1]=="Dynamit"){
                            system("cls");
                            cout<<"Rzucasz drnamit w strone wrogow"<<endl;
                            cout<<"Po wybuchu dwoch z nich juz nie wstaje"<<endl;
                            x-=2;
                            przedmioty[liczba-1]="";
                        }
                        else{
                            system("cls");
                            cout<<"To miejsce jest puste!"<<endl;
                        }
                    }
                    else{
                        system("cls");
                        cout<<"Nie ma takiego miejsca!"<<endl;
                    }
                }
            }
            getch();
        break;
        }
        if((x==0)||(zycie==0)) wygrana=true;
    }
    system("cls");
    if(x==0){
        system("cls");
        cout<<"wygrywasz"<<endl;
        cout<<"Nacisnij dowolny przecisk by kontynuowac..."<<endl;
        getch();
    }
    else{
        system("cls");
        cout<<"Przegrywasz!!!"<<endl;
        exit(0);
    }
}

int main()
{
    przedmioty[0]="nie masz zadnych przedmiotow!";
    srand(time(NULL));
    int liczba_w=2;
    int zycie=3;
    while(1==1){
        system("cls");
        cout<<"Zycie to: "<<zycie<<endl;
        cout<<"1. Strzerlanina"<<endl;
        cout<<"2. Rabowanie"<<endl;
        cout<<"3. Wyjdz"<<endl;

        a=getch();
        cout<<endl;

        switch (a)
        {
        case '1': strzelnica(liczba_w, zycie);
        break;
            
        case '2': loot(liczba_w);
        break;

        case '3': exit(0);
        }
    }
    return 0;
}

int strzal(int x)
{
    int wygrana;
    bool koniec=false;
    while(koniec==false)
    {
        int trafienie1 = rand() % 4 + 1;
        int trafienie2;

        do {
            trafienie2 = rand() % 4 + 1;
        } while (trafienie2 == trafienie1);

        if(x==trafienie1){
            koniec=true; wygrana=1;
        }
        else if(x==trafienie2){
            koniec=true; wygrana=2;
        }
        else{
            koniec=true; wygrana=3;
        }
    }
    return wygrana;
}

void loot(int x)
{
    bool koniec = false;
    int szufladka=0;
    if(przedmioty[0]=="nie masz zadnych przedmiotow!") przedmioty[0]="";
    if(przedmioty[3]!=""){
        system("cls");
        cout<<"Masz juz pelny ekwipunek"<<endl;
        cout<<"Nie wystarczajaco miejca aby rabowac!"<<endl;
        getch();
    }
    else{
        int losowanie;
        for (int i = x*5; i > 0; i--)
        {
            system("cls");
            cout<<i<<endl;
            Sleep(1000);
        }
        for (int i = 0; i < x; i++)
        {
            losowanie = rand() % 3 + 1;
            losowanie = rand() % 3 + 1;
            losowanie = rand() % 3 + 1;
            losowanie = rand() % 3 + 1;

            if(przedmioty[3]==""){
                switch (losowanie)
                {
                case 1:
                    for (int i = 0; i < 4; i++) {
                        if (przedmioty[i] == ""){
                            system("cls");
                            przedmioty[i] = "Bimber";
                            cout << "Znalazles Bimber!" << endl;
                            getch();
                            break;
                        }
                    }
                break;

                case 2:
                    for (int i = 0; i < 4; i++) {
                        if (przedmioty[i] == ""){
                            system("cls");
                            przedmioty[i] = "Cygaro";
                            cout << "Znalazles Cygaro!" << endl;
                            getch();
                            break;
                        }
                    }
                break;

                case 3:
                    for (int i = 0; i < 4; i++) {
                        if (przedmioty[i] == ""){
                            system("cls");
                            przedmioty[i] = "Dynamit";
                            cout << "Znalazles Dynamit!" << endl;
                            getch();
                            break;
                        }
                    }
                break;
                }
            }
            else{
                system("cls");
                cout<<"Masz juz pely ekwipunek!"<<endl;
                cout<<"Nie mozesz miec wiecej przedmiotow w ekwipunku!"<<endl;
                getch();
            }
            koniec=false;
        }
    }
}