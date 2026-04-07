#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

char a;
int ileP;
int tik = 0;

class Proces
{
    public:
    int numer;
    int czasPrzy_lub_Prio;
    int czasPrzetwarzania;
    int kiedyZakonczono;
    

    Proces(int id = 0, int czPrzyj = 0, int czPrzet = 0, int kz = 0) {
        numer = id;
        czasPrzy_lub_Prio = czPrzyj;
        czasPrzetwarzania = czPrzet;
        kiedyZakonczono = kz;
    }

    void pokaz() {
        cout<<"P"<<numer<<": ";
        cout<<czasPrzy_lub_Prio<<" ";
        cout<<czasPrzetwarzania<<endl;
        return;
    }
};

int rotacyjne(vector<Proces> procesy, vector<Proces> &procesyKopia)
{
    int licznik = 0;
    Proces bufor;
    while (!procesy.empty())
    {
        //przeprowadzanie procesu lub wywłaszczanie go
        if(licznik != 5) {
            procesy[0].czasPrzetwarzania--;
            licznik++;
        } else {
            bufor = procesy[0];
            procesy.erase(procesy.begin());
            procesy.push_back(bufor);

            procesy[0].czasPrzetwarzania--;
            licznik = 1;
        }

        //ZWIĘKSZANIE TIKU O 1
        tik++;

        //ZAKOŃCZENIE PROCESU
        if(procesy[0].czasPrzetwarzania == 0){
            int i = procesy[0].numer;
            procesyKopia[i-1].kiedyZakonczono = tik;
            procesy.erase(procesy.begin());
        }
        
        //pokazywanie co się zmieniło
        system("cls"); //system("clear");
        for (int i = 0; i < procesy.size(); i++)
        {
            procesy[i].pokaz();
        }

        Sleep(1000);
    }   
}

int planowanie(vector<Proces> procesy, vector<Proces> &procesyKopia, bool wybor)
{

    //PĘTLA GŁÓWNA
    while(!procesy.empty())
    {
        //Sortowanie przy pomocy czas przyjścia lub priotytetu (BOMBELKOWE)
        for (int i = 0; i < procesy.size(); i++) {   
            for(int d = 0; d < procesy.size()-1; d++) {
                if(procesy[d].czasPrzy_lub_Prio > procesy[d+1].czasPrzy_lub_Prio) {
                    Proces bufor;
                    bufor = procesy[d];
                    procesy[d] = procesy[d+1];
                    procesy[d+1] = bufor;
                }
            }
        }
        
        if(wybor){
            //Ile jest procesów z zerowym czasem przyjścia
            int ileliczb = 0;
            bool exit = true;
            
            for (int i = 0; (i < procesy.size()) && (exit); i++)
            {
                if(procesy[i].czasPrzy_lub_Prio == 0) ileliczb++;
                else exit = false;
            }
            

            //Sortowanie przy pomocy czas przetwarzania (BOMBELKOWE)
            for (int i = 0; i < ileliczb; i++) {   
                for(int d = 0; d < ileliczb-1; d++) {
                    if(procesy[d].czasPrzetwarzania > procesy[d+1].czasPrzetwarzania) {
                        Proces bufor;
                        bufor = procesy[d];
                        procesy[d] = procesy[d+1];
                        procesy[d+1] = bufor;
                    }
                }
            }
        }

        //ZWIĘKSZANIE TIKU O 1
        tik++;

        //ZAKOŃCZENIE PROCESU
        if(wybor && procesy[0].czasPrzy_lub_Prio == 0) procesy[0].czasPrzetwarzania--;
        if(!wybor) procesy[0].czasPrzetwarzania--;
        if(procesy[0].czasPrzetwarzania == 0){
            int i = procesy[0].numer;
            procesyKopia[i-1].kiedyZakonczono = tik;
            procesy.erase(procesy.begin());
        }

        //Zmniejszanie czasuPrzyjścia u każdego procesu
        if(wybor) {for (int i = 0; i < procesy.size(); i++) if(procesy[i].czasPrzy_lub_Prio > 0) procesy[i].czasPrzy_lub_Prio--;}

        //pokazywanie co się zmieniło
        system("cls"); //system("clear");
        for (int i = 0; i < procesy.size(); i++)
        {
            procesy[i].pokaz();
        }
        Sleep(750);
    }

    return 0;
}

int pytania_i_wynik(int wybor)
{
    //PYTANIA O DANE
    system("cls"); //system("clear");

   //Logo
    if(wybor) cout<<"! PLANOWANIE METODA SJF !"<<endl;
    else cout<<"! PLANOWANIE METODA PRIOTYTETU !"<<endl;

    //Pierwsze pytanie
    cout<<"Ile chcesz miec procesow: "; cin>>ileP;

    //Tworzenie tablicy
    vector<Proces> procesy;

    for (int i = 0; i < ileP; i++)
    {
        //Pytania o dane
        system("cls"); //system("clear");
        int x, y;
        if(wybor == 1) {cout<<"Czas Przyjscia "<<i+1<<" procesu: "; cin>>x;}
        else if(wybor == 0) {cout<<"Priorytet "<<i+1<<" procesu: "; cin>>x;}
        else if(wybor == 2) x=0;
        cout<<"Czas Przetwarzania "<<i+1<<" procesu: "; cin>>y;
        procesy.push_back(Proces(i+1, x, y));
    }

    //Tworzenie kopii przypomocy której będziemy prowadzić na koniec obliczenia
    vector<Proces> procesyKopia = procesy;

    //Pokazanie tablicy na początek
    system("cls"); //system("clear");  
    for (int i = 0; i < procesy.size(); i++)
    {
        procesy[i].pokaz(); 
    }
    Sleep(1000);

    //--------------------------------------------------------------------------------------

    //Przydszelenie odpowaedniego planowania
    if(wybor == 1 || wybor == 0) planowanie(procesy, procesyKopia, wybor);
    else rotacyjne(procesy, procesyKopia);

    //--------------------------------------------------------------------------------------

    //OBLICZANIE I PREZENTOWANIE WYNIKU
    //Sortowanie procesówKopii przy pomocy czasu skończenia procesu (BOMBELKOWE)
    for (int i = 0; i < procesyKopia.size(); i++) {   
        for(int d = 0; d < procesyKopia.size()-1; d++) {
            if(procesyKopia[d].kiedyZakonczono > procesyKopia[d+1].kiedyZakonczono) {
                Proces bufor;
                bufor = procesyKopia[d];
                procesyKopia[d] = procesyKopia[d+1];
                procesyKopia[d+1] = bufor;
            }
        }
    }

    //Po ilu tikach procesy zostały zakończone
    cout<<"Procesy zostaly zakonczone po tylu tikach: "<<endl;
    for (int i = 0; i < procesyKopia.size(); i++)
    {
        cout<<"P"<<procesyKopia[i].numer<<": "<<procesyKopia[i].kiedyZakonczono<<endl;
    }
    cout<<endl<<"Nacisnij enter";
    getchar();getchar();
    
    //Czas oczeniwania procesów
    float SCzO = 0;

    for (int i = 0; i < procesyKopia.size(); i++)
    {
        if(wybor) SCzO += procesyKopia[i].kiedyZakonczono - procesyKopia[i].czasPrzy_lub_Prio - procesyKopia[i].czasPrzetwarzania;
        if(!wybor) SCzO += procesyKopia[i].kiedyZakonczono - 0 - procesyKopia[i].czasPrzetwarzania;
    }

    //Średni czas oczekiwania
    SCzO /= procesyKopia.size();

    system("cls"); //system("clear");
    cout<<"Sredni czas oczekiwania: "<<SCzO<<" tikow";
    getchar();
}

int main()
{
    int wybor;

    system("cls"); //system("clear");
    cout<<"!Wyierz metode planowania!"<<endl;
    cout<<"1. SJF"<<endl;
    cout<<"2. Priorytetu"<<endl;    
    cout<<"3. Rotacyjne"<<endl;
    a = getch(); cout<<endl;

    if(a == '1') wybor = true;
    else if(a == '2') wybor = false;
    else if(a == '3') wybor = 2;
    pytania_i_wynik(wybor);

    return 0;
}