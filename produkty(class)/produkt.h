#include <iostream>

using namespace std;

class Produkt
{
    private:
    string nazwa;
    string kategoria;
    long long cena;
    
    public:
    Produkt(string="nieznany produkt",string="nieznana kategoria",int=0);
    void wczytaj();
    void pokaz(int, int);
    bool sprawdzanie(string);
    void plik(int);
    void zapisz(int,int);
    friend int skalowanie_n();
    friend int skalowanie_k();
    friend void sortowanie_b();
};