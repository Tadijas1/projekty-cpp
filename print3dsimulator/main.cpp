#include <iostream>
#include "class.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string>
//#include <cmath>

using namespace std;

char a;
float kasa=2000;
bool czyZlecenie=false, czyStowrzonaFirma=true; //TESTY
int ktoraDrukarka=1; //TESTY
int ktoryTransport=0;

Drukarka tabD[3] = {Drukarka("ender", 1200, 1), Drukarka("prusa", 2500, 1.5), Drukarka("prusaPro", 4000, 2)};
Drukarka twojaDrukarka=tabD[2]; //TESTY
Filament tabF[3] = {Filament("PLA", 80, 300), Filament("ABS", 90, 300), Filament("PET", 100, 300)}; //TESTY
Transport twojTransport;
Transport tabT[3] = {Transport("rower",2000, 1.5), Transport("skuter",3500, 2), Transport("samochod",5000, 2.5)};
Zlecenie twojeZlecenie;

void podroz_druk(int x, bool c)
{
    if(c) x/=twojTransport.szybkosc;
    for (int i = 1; i <= x; i++)
    {
        system("cls"); //system("clear")
        cout<<x<<endl;
        if(c){
            if(i<=3) cout<<"Szykowanie sie do drogi";
            else if((i>3)&&(i<x)) cout<<"Przemieszczanie sie do celu";
            else if(i==x) cout<<"Jestes na miejscu";
        }
        else{
            if(i<=5) cout<<"Nagrzewanie dyszy";
            else if((i>5)&&(i<=x-5)) cout<<"Drukowanie";
            else if(i>=x-5) cout<<"Odklejanie durku";
        }
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

void kupowanie_filamentu(int a)
{
    string bufor;
    int x;
    float b;
    bool e=true;
    if(a==1) b=tabF[0].cena_kg/1000; else if(a==2) b=tabF[1].cena_kg/1000; else if(a==3) b=tabF[2].cena_kg/1000;

    while(e)
    {
        system("cls"); //system("clear")
        cout<<"(w gramach)"<<endl;
        cout<<"Ile kupujesz: "; cin>>bufor;
        try{
            x=stoi(bufor);
            if((x>0)&&(kasa-x*b>=0)) e=false;
            else{
                system("cls"); //system("clear")
                cout<<"Nie masz tyle pieniedzy"<<endl;
                getchar();getchar();
            }
        }
        catch(...){
            e=true;
        }
    }

    switch (a)
    {
    case 1:
        kasa-=x*b;
        tabF[0].ilosc+=x;
    break;
    case 2:
        kasa-=x*b;
        tabF[1].ilosc+=x;
    break;
    case 3:
        kasa-=x*b;
        tabF[2].ilosc+=x;
    break;
    }
    system("cls"); //system("clear")
    cout<<"Kupiono "<<x<<" gramow filamentu"<<endl;
    cout<<"Zaplacono: "<<x*b<<endl;
    cout<<"Masz teraz: "<<kasa<<endl;
    getchar();getchar();
    return;
}

void kupowanie_drukarki(int a)
{
    string nazwa, bufor; int cena; float szybkosc;
    switch (a)
    {
    case 1:
        nazwa=tabD[0].nazwa;
        cena=tabD[0].cena;
        szybkosc=tabD[0].szybkosc;
    break;
    case 2:
        nazwa=tabD[1].nazwa;
        cena=tabD[1].cena;
        szybkosc=tabD[1].szybkosc;
    break;
    case 3:
        nazwa=tabD[2].nazwa;
        cena=tabD[2].cena;
        szybkosc=tabD[2].szybkosc;
    }
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"Nazwa drukarki: "<<nazwa<<endl;
        cout<<"Cena: "<<cena<<endl;
        cout<<"Szybkosc drukarki: "<<szybkosc<<endl;
        cout<<"Czy chcesz ja kupic?"<<endl;
        cin>>bufor;

        if((bufor=="tak")||(bufor=="TAK")){
            if(kasa-cena>=0){
                system("cls"); //system("clear")
                kasa-=cena;
                if(a==1) {twojaDrukarka=tabD[0];} else if(a==2) {twojaDrukarka=tabD[1];} 
                else if(a==3) {twojaDrukarka=tabD[2];}
                cout<<"Kupiono drukarke!"<<endl;
                cout<<"Stan konta wynosi teraz: "<<kasa<<endl;
                ktoraDrukarka++;
                getchar();getchar();
                exit=false;
            }
            else{
                system("cls"); //system("clear")
                cout<<"Nie masz tyle pieniedzy"<<endl;
                getchar();getchar();
                exit=false;
            }
        }
        else if((bufor=="nie")||(bufor=="NIE")) exit=false;
    }
    return;
}

void kupowanie_transportu(int a)
{
    string nazwa, bufor; int cena; float szybkosc;
    switch (a)
    {
    case 1:
        nazwa=tabT[0].nazwa; cena=tabT[0].cena; szybkosc=tabT[0].szybkosc;
    break;
    case 2:
        nazwa=tabT[1].nazwa; cena=tabT[1].cena; szybkosc=tabT[1].szybkosc;
    break;
    case 3:
        nazwa=tabT[2].nazwa; cena=tabT[2].cena; szybkosc=tabT[2].szybkosc;
    break;
    }

    bool exit=true;
    while (exit)
    {
        system("cls"); //system("clear")
        cout<<"Nazwa pojazdu: "<<nazwa<<endl;
        cout<<"Cena: "<<cena<<endl;
        cout<<"Szybkosc: "<<szybkosc<<endl;
        cout<<"Czy chcesz go kupic?"<<endl;
        cin>>bufor;

        if((bufor=="tak")||(bufor=="TAK")){
            if(kasa-cena>=0){
                system("cls"); //system("clear")
                kasa-=cena;
                if(a==1) {twojTransport=tabT[0];} else if(a==2) {twojTransport=tabT[1];} 
                else if(a==3) {twojTransport=tabT[2];}
                cout<<"Kupiono pojazd!"<<endl;
                cout<<"Stan konta wynosi teraz: "<<kasa<<endl;
                ktoryTransport++;
                getchar();getchar();
                exit=false;
            }
            else{
                system("cls"); //system("clear")
                cout<<"Nie masz tyle pieniedzy"<<endl;
                getchar();getchar();
                exit=false;
            }
        }
        else if((bufor=="nie")||(bufor=="NIE")) exit=false;
    }
    return;
}

//-----------------------------------------------------

void komputer()
{
    bool exit=true;
    while (exit)
    {
        system("cls"); //system("clear")
        if(czyZlecenie==false){
            cout<<"Masz nowe zlecenie!"<<endl;
            Zlecenie noweZ(rand()%+100+100, rand()%200+100, rand()%30+30, rand()%3);
            noweZ.pokaz();
            cout<<"1. Przyjmij zlecenie"<<endl;
            cout<<"2. Odrzuc zlecenie"<<endl;
            a=getch(); cout<<endl;

            switch (a)
            {
            case '1':
                twojeZlecenie=noweZ;
                czyZlecenie=true;
                exit=false;
            break;
            case '2':
                cout<<"Zlecenie odrzucone!"<<endl;
                cout<<"Czekaj na następne"<<endl;
                exit=false;
            break;
            }
        }
        else{
            cout<<"Nie masz aktualnie zdanych zlecen :)"<<endl;
            getchar();
            exit=false;
        }
    }
    return;
}

void tworzenieStrony()
{
    bool exit=true;
    while (exit)
    {
        system("cls"); //system("clear")
        cout<<"Nie masz jeszcze zarejstrowaniej firmy!"<<endl;
        cout<<"Czy chcesz ja teraz zarejstrowac?"<<endl;
        cout<<"1. tak"<<endl;
        cout<<"2. nie"<<endl;
        a=getch(); cout<<endl;

        if(a=='1'){
            Danefirmy danefirmy;
            danefirmy.tworzenie();
            czyStowrzonaFirma=true;
            exit=false;
        }
        else if(a=='2') exit=false;
    }
    return;
}

//-----------------------------------------------------

void magazyn()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        
        cout<<"Posiadany filament | Posiadane drukarki | Posiadane pojazdy"<<endl; //19, 20, 17
        
        for (int i = 0; i < 3; i++)
        {
            int ile = to_string(tabF[i].ilosc).size();
            cout<<tabF[i].nazwa<<": "<<tabF[i].ilosc<<" gramow";
            for (int i = 0; i < abs(ile+12-19); i++) cout<<" ";
            cout<<"| ";

            cout<<tabD[i].nazwa;
            for (int i = 0; i < abs(static_cast<int>(tabD[i].nazwa.size())-20); i++) cout<<" ";
            cout<<"| ";

            cout<<tabT[i].nazwa;
            for (int i = 0; i < abs(static_cast<int>(tabT[i].nazwa.size())-17); i++) cout<<" ";
            cout<<"|";
            cout<<endl;
        }
        getchar();
        exit=false;
    }
    return;
}

void drukowanie()
{
    // dawanie zmiennych
    int ileF;
    if(twojeZlecenie.typFilamentu==0) ileF=tabF[0].ilosc;
    else if(twojeZlecenie.typFilamentu==1) ileF=tabF[1].ilosc;
    else if(twojeZlecenie.typFilamentu==2) ileF=tabF[2].ilosc;
    string bufor;

    bool exit=true;
    while (exit)
    {
        // wypisywanie danych druku
        twojeZlecenie.pokaz();
        cout<<"Posiadany filament tego typu: "<<ileF<<" gramow"<<endl;
        cout<<"Aktualna drukarka: "<<twojaDrukarka.nazwa<<endl;
        cout<<"Czy rozpoczac drukowanie?"<<endl; cin>>bufor;

        //warunki
        if((bufor=="nie")||(bufor=="NIE")) exit=false;
        else if((bufor=="tak")||(bufor=="TAK")){
            if(twojeZlecenie.ileFilament>ileF){
                system("cls"); //system("clear")
                cout<<"Nie masz wystarczajacej ilosci filamentu"<<endl;
                getchar();getchar();
                exit=false;
            }
            else{
                podroz_druk(twojeZlecenie.ileCzasu/=twojaDrukarka.szybkosc, false);
                system("cls"); //system("clear")
                cout<<"Wydruk gotowy"<<endl;
                cout<<"Otrzymane pieniadze: "<<twojeZlecenie.zysk<<endl;
                cout<<"Zluzyty filament: "<<twojeZlecenie.ileFilament<<endl;
                getchar();getchar();
                if(twojeZlecenie.typFilamentu==0) tabF[0].ilosc-=twojeZlecenie.ileFilament;
                else if(twojeZlecenie.typFilamentu==1) tabF[1].ilosc-=twojeZlecenie.ileFilament;
                else if(twojeZlecenie.typFilamentu==2) tabF[2].ilosc-=twojeZlecenie.ileFilament;
                kasa+=twojeZlecenie.zysk;
                czyZlecenie=false;
                exit=false;
            }
        }
    }
    return;
}

void drukarnia()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"1. Idz do drukarki"<<endl;
        cout<<"2. Idz do magazynu"<<endl;
        cout<<"3. Wstecz"<<endl;
        a=getch(); cout<<endl;

        if(a=='1'){
            system("cls"); //system("clear")
            if(czyZlecenie==false) {cout<<"Nie masz aktulalnie zadnych zlecen"<<endl; getchar();}
            else if(ktoraDrukarka==0){cout<<"Nie masz jeszcze zadnej drukarki"<<endl; getchar();}
            else drukowanie();
        }
        else if(a=='2') magazyn();
        else if(a=='3') exit=false;
    }
    return;
}

//-----------------------------------------------------

void s_filament()
{
    bool exit=true;
    while (exit)
    {
        system("cls"); //system("clear")
        string bufor;
        cout<<"(dostepne typy filamentu: PLA, ABS, PET) wpisz q aby wyjsc"<<endl;
        cout<<"Jaki filament: "; cin>>bufor;
        if((bufor=="PLA")||(bufor=="pla")) {kupowanie_filamentu(1); exit=false;}
        else if((bufor=="ABS")||(bufor=="abs")) {kupowanie_filamentu(2); exit=false;}
        else if((bufor=="PET")||(bufor=="pet")) {kupowanie_filamentu(3); exit=false;}
        else if(bufor=="q") exit=false;
    }
    return;
}

void s_drukarki()
{
    bool exit=true;
    while (exit)
    {
        system("cls"); //system("clear")
        cout<<"Jaka drukarke chcesz kupic?"<<endl;
        if(ktoraDrukarka==0)cout<<"1. Ender"<<endl;
        if(ktoraDrukarka<=1)cout<<"2. Prusa"<<endl;
        if(ktoraDrukarka<=2)cout<<"3. PrusaPro"<<endl;
        else cout<<"Masz juz najlepsza drukarke :)"<<endl;
        cout<<"4. Wstecz"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            if(ktoraDrukarka==0)
            {
                kupowanie_drukarki(1);
            }
        break;
        case '2':
        if(ktoraDrukarka<=1)
        {
            kupowanie_drukarki(2);
        }
        break;
        case '3':
        if(ktoraDrukarka<=2)
        {
            kupowanie_drukarki(3);  
        }
        break;
        case '4':
            podroz_druk(60, true);  
            exit=false;
        break;
        }
    }
    return;
}

void jaki_sklep()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"Jestes przed sklepem"<<endl;
        cout<<"1. Wchodzisz do dzialu z drukarkami"<<endl;
        cout<<"2. Wchodzisz do dzialu z filamentem"<<endl;
        cout<<"3. Wracasz do domu"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            s_drukarki();
        break;
        case '2':
            s_filament();
        break;
        case '3':
            podroz_druk(30, true);
            exit=false;
        break;
        }
    }
    return;
}

//--------------------------

void s_pojazdy()
{
    bool exit=true;
    while (exit)
    {
        system("cls"); //system("clear")
        cout<<"Jaki srodek transportu chcesz kupic?"<<endl;
        if(ktoryTransport==0) cout<<"1. Rower"<<endl;
        if(ktoryTransport<=1) cout<<"2. Skuter"<<endl;
        if(ktoryTransport<=2) cout<<"3. Samochod"<<endl;
        else cout<<"Masz juz najlepszy rodzaj transportu"<<endl;
        cout<<"4. Wroc do domu"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            if(ktoryTransport==0){
                kupowanie_transportu(1);
            }
        break;
        case '2':
            if(ktoryTransport<=1){
                kupowanie_transportu(2);
            }
        break;
        case '3':
            if(ktoryTransport<=2){
                kupowanie_transportu(3);
            }
        break;
        case '4':
            podroz_druk(60, true);
            exit=false;
        break;
        }
    }
    return;
}

//--------------------------

void totolotek()
{
    bool exit=true;
    while (exit)
    {
        int los, liczba;
        string bufor;
        bool c=true;
        los=rand()%100+1;
        while(c)
        {
            system("cls"); //system("clear")
            cout<<"Wybierz liczbe z przedzialu 1-100: ";
            cin>>bufor;
            try{
                liczba=stoi(bufor);
                kasa-=10;
                c=false;
            }
            catch(...){
                cout<<"Niepoprawnie wpisana liczba"<<endl;
                getchar();getchar();
            }
        }
        if(los==liczba){
            system("cls"); //system("clear")
            cout<<"GRATULACJE WYGRALES!"<<endl;
            cout<<"Zdobywasz 1000$"<<endl;
            kasa+=1000;
            getchar();getchar();
            exit=false;
        }
        else{
            system("cls"); //system("clear")
            cout<<"Nieststy nie zgadles :("<<endl;
            cout<<"Powodzenia nastepnym razem"<<endl;
            getchar();getchar();
            exit=false;
        }
    }
    return;
}

void kiosk()
{
    bool exit=true;
    while(exit)
    {   
        system("cls"); //system("clear")
        cout<<"1. Graj w totolotka (koszt 10$)"<<endl;
        cout<<"2. Wracasz do domu"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            if(kasa-10>0) {totolotek();}
            else {cout<<"Masz za malo pieniedzy"<<endl; getchar();}
        break;
        case '2':
            podroz_druk(15, true);
            exit=false;
        break;
        }
    }
    return;
}

//--------------------------

void podworko()
{
    bool exit=true;
    while(exit)
    {
        system("cls"); //system("clear")
        cout<<"1. Idz do sklepu z drukarkami i filamentem"<<endl;
        cout<<"2. Idz do sklepu z pojazdami"<<endl;
        cout<<"3. Idz do kiosku"<<endl;
        cout<<"4. Wstecz"<<endl;
        a=getch(); cout<<endl;

        switch (a)
        {
        case '1':
            podroz_druk(30, true);
            jaki_sklep();
        break;
        case '2':
            //podroz_druk(60, true);
            s_pojazdy();
        break;
        case '3':
            podroz_druk(15, true);
            kiosk();
        break;
        case '4':
            exit=false;
        break;    
        }
    }
    return;
}

//-----------------------------------------------------

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
            if(czyStowrzonaFirma) komputer();
            else tworzenieStrony();
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