#include <iostream>
#include <vector>

using namespace std;

int ileP;

class Proces
{
    public:
    int czasPrzyjscia;
    int czasPrzetwarzania;

    Proces(int czPrzyj = 0, int czPrzet = 0) {
        czasPrzyjscia = czPrzyj;
        czasPrzetwarzania = czPrzet;
    }

    void pokaz() {
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
        procesy.push_back(Proces(x, y));
    }

    //Sortowanie przy pomocy czasuPrzetwarzania (BOMBELKOWE)
    for (int i = 0; i < procesy.size(); i++) {   
        for(int i = 0; i < procesy.size()-1; i++) {
            if(procesy[i].czasPrzetwarzania > procesy[i+1].czasPrzetwarzania) {
                Proces bufor;
                bufor = procesy[i];
                procesy[i] = procesy[i+1];
                procesy[i+1] = bufor;
            }
        }
    }
    

    //Test
    system("cls"); //system("clear");
    for (int i = 0; i < procesy.size(); i++)
    {
        procesy[i].pokaz();
    }
    getchar();getchar();

    return 0;
}