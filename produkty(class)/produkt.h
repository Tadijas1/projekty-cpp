#include <iostream>

using namespace std;

class Produkt
{
    private:
    string nazwa;
    string kategoria;
    int cena;
    
    public:
    Produkt();
    void pokaz();
    bool sprawdzanie(string);
    int skalowanie();
};