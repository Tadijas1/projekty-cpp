#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

int ileP;
int tik = 0;

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
    vector<int> kiedyZakonczono;
    vector<string> ktoryProces;

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
    Sleep(2000);

    //PĘTLA GŁÓWNA
    while(!procesy.empty())
    {
        //Sortowanie przy pomocy czas przyjścia (BOMBELKOWE)
        for (int i = 0; i < procesy.size(); i++) {   
            for(int d = 0; d < procesy.size()-1; d++) {
                if(procesy[d].czasPrzyjscia > procesy[d+1].czasPrzyjscia) {
                    Proces bufor;
                    bufor = procesy[d];
                    procesy[d] = procesy[d+1];
                    procesy[d+1] = bufor;
                }
            }
        }
        
        //Ile jest procesów z zerowym czasem przyjścia
        int ileliczb = 0;
        bool exit = true;
        
        for (int i = 0; (i < procesy.size()) && (exit); i++)
        {
            if(procesy[i].czasPrzyjscia == 0) ileliczb++;
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

        //ZWIĘKSZANIE TIKU O 1
        tik++;

        //ZAKOŃCZENIE PROCESU
        if(procesy[0].czasPrzyjscia == 0) procesy[0].czasPrzetwarzania--;
        if(procesy[0].czasPrzetwarzania == 0){
            kiedyZakonczono.push_back(tik);
            ktoryProces.push_back(procesy[0].nazwa);
            procesy.erase(procesy.begin());
        }

        //Zmniejszanie czasuPrzyjścia u każdego procesu
        for (int i = 0; i < procesy.size(); i++) if(procesy[i].czasPrzyjscia > 0) procesy[i].czasPrzyjscia--;

        //pokazywanie co się zmieniło
        system("cls"); //system("clear");
        for (int i = 0; i < procesy.size(); i++)
        {
            procesy[i].pokaz();
        }
        Sleep(750);
    }

    for (int i = 0; i < kiedyZakonczono.size(); i++)
    {
        cout<<ktoryProces[i]<<": "<<kiedyZakonczono[i]<<endl;
    }

    getchar();getchar();
    

    return 0;
}