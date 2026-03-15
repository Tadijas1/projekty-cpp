#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

int ileP;

class Proces
{
    public:
    string nazwa;
    int czasPrzyjscia;
    int czasPrzetwarzania;

    Proces(string n="", int czPrzyj = 0, int czPrzet = 0) {
        nazwa = n;
        czasPrzyjscia = czPrzyj;
        czasPrzetwarzania = czPrzet;
    }

    void pokaz() {
        cout<<nazwa<<": ";
        cout<<czasPrzyjscia<<" ";
        cout<<czasPrzetwarzania<<endl;
        return;
    }
};

int main()
{
    system("cls"); //system("clear");

    //Logo
    cout<<"! PLANOWANIE METODA SJF !"<<endl;

    //Pierwsze pytanie
    cout<<"Ile chcesz miec procesow: "; cin>>ileP;

    //Tworzenie tablicy
    vector<Proces> procesy;

    for (int i = 0; i < ileP; i++)
    {
        //Pytania o dane
        system("cls"); //system("clear");
        int x, y;
        cout<<"Czas Przyjscia "<<i+1<<" procesu: "; cin>>x;
        cout<<"Czas Przetwarzania "<<i+1<<" procesu: "; cin>>y;
        procesy.push_back(Proces(string("P") + to_string(i+1), x, y));
    }

    //Pokazanie tablicy na początek
    system("cls"); //system("clear");
    for (int i = 0; i < procesy.size(); i++)
    {
        procesy[i].pokaz(); 
    }

    while(!procesy.empty())
    {
        //Sortowanie przy pomocy czas przyjścia (BOMBELKOWE)
        for (int i = 0; i < procesy.size(); i++) {   
            for(int i = 0; i < procesy.size()-1; i++) {
                if(procesy[i].czasPrzyjscia > procesy[i+1].czasPrzyjscia) {
                    Proces bufor;
                    bufor = procesy[i];
                    procesy[i] = procesy[i+1];
                    procesy[i+1] = bufor;
                }
            }
        }
        
        //Ile jest procesów z zerem
        bool czy_zero = true;
        int ileliczb = 0;
        for (int i = 0; czy_zero == true; i++)
        {
            if(procesy[i].czasPrzyjscia == 0) ileliczb++;
            else czy_zero = false;
        }

        //Sortowanie przy pomocy czas przetwarzania (BOMBELKOWE)
        for (int d = 0; d < ileliczb; d++) {   
            for(int i = 0; i < ileliczb-1; i++) {
                if(procesy[i].czasPrzetwarzania > procesy[i+1].czasPrzetwarzania) {
                    Proces bufor;
                    bufor = procesy[i];
                    procesy[i] = procesy[i+1];
                    procesy[i+1] = bufor;
                }
            }
        }

        //JEDEN TIK
        procesy[0].czasPrzetwarzania--;
        if(procesy[0].czasPrzetwarzania == 0) procesy.erase(procesy.begin());

        //Zmniejszanie czasuPrzyjścia u każdego procesu
        for (int i = 0; i < procesy.size(); i++) if(procesy[i].czasPrzyjscia > 0) procesy[i].czasPrzyjscia--;

        //pokazywanie co się zmieniło
        system("cls"); //system("clear");
        for (int i = 0; i < procesy.size(); i++)
        {
            procesy[i].pokaz(); 
        }

        Sleep(1000);
    }

    return 0;
}