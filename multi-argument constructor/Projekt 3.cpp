#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Przedmiot 
{
private:
    string nazwa;
    int atak;
    int obrona;

public:
    Przedmiot(string nazwa = "Nieznana nazwa") 
    {
        this->atak = rand() % 101 + 100;
        this->obrona = rand() % 101;
        this->nazwa = nazwa;
    }

    int getAtak() const 
    {
        return atak;
    }

    int getObrona() const 
    {
        return obrona;
    }

    void wyswietlPrzedmiot() const 
    {
        cout << nazwa << " Atak: " << atak << " Obrona: " << obrona << endl;
    }
};

class Bohater 
{
private:
    string pseudonim;
    string klasa;
    int punkty_zycia;
    Przedmiot ekwipunek[4];

public:
    //Konstruktor domyslny
    Bohater() : pseudonim("Bezimienny"), klasa("Brak"), punkty_zycia(1200) 
    {
        cout << "Utworzono domyslnego bohatera." << endl;
    }

    //Konstruktor wieloargumentowy
    Bohater(string p, string k, int pz) : pseudonim(p), klasa(k), punkty_zycia(pz) 
    {
        cout << "Utworzono bohatera: " << pseudonim << endl;
    }

    void ustawEkwipunek(const Przedmiot* przedmioty, int rozmiar) 
    {
        for (int i = 0; i < rozmiar; i++) 
        {
            ekwipunek[i] = przedmioty[i];
        }
    }

    void wyswietlBohatera() const 
    {
        cout << pseudonim << " " << klasa << " " << punkty_zycia << endl;
        for (const auto& przedmiot : ekwipunek) 
        {
            przedmiot.wyswietlPrzedmiot();
        }
    }

    int getPunktyZycia() const 
    {
        return punkty_zycia;
    }

    void setPunktyZycia(int nowe_punkty) 
    {
        punkty_zycia = nowe_punkty;
    }

    string getPseudonim() const 
    {
        return pseudonim;
    }

    //Funkcja do obliczania sumy ataku i obrony ekwipunku
    int sumaAtaku() const 
    {
        int suma = 0;
        for (const auto& przedmiot : ekwipunek) 
        {
            suma += przedmiot.getAtak();
        }
        return suma;
    }

    int sumaObrony() const 
    {
        int suma = 0;
        for (const auto& przedmiot : ekwipunek) 
        {
            suma += przedmiot.getObrona();
        }
        return suma;
    }
};

void pojedynek(Bohater& bohater1, Bohater& bohater2) 
{
    int suma_ataku1 = bohater1.sumaAtaku();
    int suma_obrony2 = bohater2.sumaObrony();

    bohater2.setPunktyZycia(bohater2.getPunktyZycia() - (suma_ataku1 - suma_obrony2));

    int suma_ataku2 = bohater2.sumaAtaku();
    int suma_obrony1 = bohater1.sumaObrony();

    bohater1.setPunktyZycia(bohater1.getPunktyZycia() - (suma_ataku2 - suma_obrony1));

    if (bohater1.getPunktyZycia() > bohater2.getPunktyZycia()) 
    {
        cout << bohater1.getPseudonim() << " wygrywa z " << bohater1.getPunktyZycia() << " punktami zycia!" << endl;
    }
    else 
    {
        cout << bohater2.getPseudonim() << " wygrywa z " << bohater2.getPunktyZycia() << " punktami zycia!" << endl;
    }
}

int main() 
{
    srand(time(NULL));

    Bohater bohater1;
    Bohater bohater2("Maciek", "Bestia", 1000);

    Przedmiot tablica_przedmiotow1[] = 
    {
        Przedmiot("Miecz"),
        Przedmiot("Tarcza"),
        Przedmiot("Helm"),
        Przedmiot("Zbroja")
    };

    Przedmiot tablica_przedmiotow2[] = 
    {
        Przedmiot("Luk"),
        Przedmiot("Kolczuga"),
        Przedmiot("Naszyjnik"),
        Przedmiot("Pierscien")
    };

    bohater1.ustawEkwipunek(tablica_przedmiotow1, 4);
    bohater2.ustawEkwipunek(tablica_przedmiotow2, 4);

    bohater1.wyswietlBohatera();
    bohater2.wyswietlBohatera();

    pojedynek(bohater1, bohater2);

    return 0;
}
