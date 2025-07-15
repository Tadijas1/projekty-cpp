#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int a, trafienie1, trafienie2, trafienie3, strzal, tarcze=0;
bool pudlo=false, czy=false;

int main()
{
    system("cls");
    srand(time(NULL));
    cout<<"Witaj na strzelnicy!"<<endl;
    cout<<"1. Latwy\n2. Normalny"<<endl;
    cout<<"Wybierz tryb: ";
    cin>>a;

    if (a==1)
    {
        while (pudlo==false)
        {
            trafienie1=rand()%5+1;
            trafienie2=rand()%5+1;
            while (czy==false)
            {
                if (trafienie2==trafienie1)
                {
                    trafienie1=rand()%5+1;
                }
                else
                {
                    czy=true;
                }
                
            }
            czy=false;
            trafienie3=rand()%5+1;
            while (czy==false)
            {
                if ((trafienie3==trafienie1)||(trafienie3==trafienie2))
                {
                    trafienie3=rand()%5+1;
                }
                else
                {
                    czy=true;
                }
            }
            czy=false;

            system("cls");
            cout<<"Wybierz liczbe od 1 do 5: ";
            cin>>strzal;

            if ((strzal==trafienie1)||(strzal==trafienie2)||(strzal==trafienie3))
            {
                tarcze++;
                cout<<"Trafiles "<<tarcze<<" razy w tarcze"<<endl;
                getchar();
            }

            else
            {
                pudlo=true;
            }           
        }

        system("cls");
        cout<<"Koniec gry! Nie trafiles!"<<endl;
        cout<<"Twoj wynik to: "<<tarcze<<endl;
        getchar();
    }

    if (a==2)
    {
        while (pudlo==false)
        {
            system("cls");
            trafienie1=rand()%5+1;
            trafienie2=rand()%5+1;
            while (czy==false)
            {
                if (trafienie2==trafienie1)
                {
                    trafienie2=rand()%5+1;
                }
                else
                {
                    czy=true;
                }
            }
            czy=false;
            
            cout<<"Wybierz liczbe od 1 do 5: ";
            cin>>strzal;

            if ((strzal==trafienie1)||(strzal==trafienie2))
            {
                tarcze++;
                cout<<"Trafiles w "<<tarcze<<" tarcze"<<endl;
                getchar();
            }
            else
            {
                pudlo=true;
            }
        }
        
        system("cls");
        cout<<"Koniec gry! Nie trafiles!"<<endl;
        cout<<"Twoj wynik to: "<<tarcze<<endl;
        getchar();
    }
    
    return 0;
}