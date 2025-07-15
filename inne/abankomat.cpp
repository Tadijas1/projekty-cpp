#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

int a;
int czas;
int kasa=0;
int kasa_k=0;
string login;
string haslo;
string czy_l;
string czy_h;
bool czy_konto=false;

int main()
{
    while(1==1)
    {
        system("cls");
        cout<<"1. Idz do bankomatu"<<endl;
        cout<<"2. Idz do pracy"<<endl;
        cout<<"Co robisz: ";
        cin>>a;

        if(a==1)
        {
            system("cls");
            cout<<"1. Zaloguj sie"<<endl;
            cout<<"2. Stworz konto"<<endl;
            cout<<"3. Wstecz"<<endl;
            cout<<"Co robisz: ";
            cin>>a;
            
            if ((a==1)&&(czy_konto==true))
            {
                system("cls");
                cout<<"Podaj login: ";
                cin>>czy_l;
                cout<<"Podaj haslo: ";
                cin>>czy_h;

                if ((czy_l==login)&&(czy_h==haslo))
                {
                    system("cls");
                    cout<<"Udalo ci sie zalogowc"<<endl;
                    Sleep(1000);
                    system("cls");
                    cout<<"Na koncie posiadasz "<<kasa_k<<" pieniedzy"<<endl;
                    cout<<"W gotowce posiadasz "<<kasa<<" pieniedzy"<<endl;
                    cout<<"1. Wplac pieniadze"<<endl;
                    cout<<"2. Wyplac pieniadze"<<endl;
                    cout<<"Co robisz: ";
                    cin>>a;

                    if (a==1)
                    {
                        system("cls");
                        cout<<"Ile chcesz wplacic: ";
                        cin>>a;

                        if (a<=kasa)
                        {
                            system("cls");
                            kasa_k=kasa_k+a;
                            kasa=kasa-a;
                            cout<<"Ukonczono"<<endl;
                            Sleep(1500);                    
                        }

                        else
                        {
                            system("cls");
                            cout<<"Nie masz tyle pieniedzy w gotowce"<<endl;
                            Sleep(1500);
                        }
                        
                    }

                    else if (a==2)
                    {
                        system("cls");
                        cout<<"Ile chcesz wyplacic: ";
                        cin>>a;

                        if (a<=kasa_k)
                        {
                            system("cls");
                            kasa_k=kasa_k-a;
                            kasa=kasa+a;
                            cout<<"Ukonczono"<<endl;
                            Sleep(1500);
                        }

                        else
                        {
                            system("cls");
                            cout<<"Nie masz wystarczajacej ilosci gotowki na koncie"<<endl;
                            Sleep(1500);
                        }
                        
                    }
                    
                    
                }

                else
                {
                    system("cls");
                    cout<<"Zle wprowadzone dane"<<endl;
                    Sleep(1500);
                }
                
                
            }

            else if (a==2)
            {
                system("cls");
                cout<<"Jaki chcesz miec login: ";
                cin>>login;
                cout<<"Jakie chcesz miec haslo: ";
                cin>>haslo;
                system("cls");
                cout<<"Konto zostalo utworzone"<<endl;
                czy_konto=true;
                Sleep(1500);
            }

            else if ((czy_konto==false)&&(a==1))
            {
                system("cls");
                cout<<"Nie masz jeszcze konta"<<endl;
                Sleep(1500);
            }
            
        }

        else if(a==2)
        {
            system("cls");
            cout<<"Ile chcesz pracowac: ";
            cin>>czas;
            for (int i=czas; i!=0; i--)
            {
                system("cls");
                cout<<i<<endl;
                Sleep(1000);
            }
            
            kasa=kasa+czas;
            system("cls");
            cout<<"Zarobiles "<<czas<<" pieniedzy"<<endl;
            Sleep(1500);
            
        }

    }
}