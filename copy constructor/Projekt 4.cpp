#include <iostream>

using namespace std;

class Pasazer
{
private:
    string imie;
    string nazwisko;
    int rok_urodzenia;
public:
    Pasazer(string imie = "imie", string nazwisko = "nazwisko", int rok_urodzenia = 0)
    {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->rok_urodzenia = rok_urodzenia;
    }
    Pasazer(const Pasazer& p)
    {
        this->imie = p.imie;
        this->nazwisko = p.nazwisko;
        this->rok_urodzenia = p.rok_urodzenia;
        cout << "Skopiowano pasazera: " << imie << " " << nazwisko << endl;
    }

    void print()
    {
        cout << this->imie << " " << this->nazwisko << " " << this->rok_urodzenia << endl;
    }
};

class Autokar
{
private:
    string miejsce_docelowe;
    int predkosc_maksymalna;
    const static int miejsca = 8;
    Pasazer* lista_pasazerow[miejsca];
public:
    Autokar(string miejsce_docelowe = "nieznane", int predkosc_maksymalna = 0)
    {
        this->miejsce_docelowe = miejsce_docelowe;
        this->predkosc_maksymalna = predkosc_maksymalna;
        for (int i = 0; i < this->miejsca; i++)
        {
            lista_pasazerow[i] = nullptr;
        }
        cout << "Utworzono autokar do: " << miejsce_docelowe << endl;
    }

    Autokar(const Autokar& a) 
    {
        miejsce_docelowe = a.miejsce_docelowe;
        predkosc_maksymalna = a.predkosc_maksymalna;
        for (int i = 0; i < miejsca; i++) 
        {
            if (a.lista_pasazerow[i] != nullptr) 
            {
                lista_pasazerow[i] = new Pasazer(*(a.lista_pasazerow[i]));
            }
            else 
            {
                lista_pasazerow[i] = nullptr;
            }
        }
        cout << "Skopiowano autokar do: " << miejsce_docelowe << endl;
    }


    bool dodajPasazera(Pasazer* p) 
    {
        for (int i = 0; i < miejsca; i++) 
        {
            if (lista_pasazerow[i] == nullptr) 
            {
                lista_pasazerow[i] = p;
                return true;
            }
        }
        return false;
    }

    void print() const
    {
        cout << "Autokar do: " << miejsce_docelowe << " Predkosc maksymalna: " << predkosc_maksymalna << endl;
        for (int i = 0; i < miejsca; i++)
        {
            if (lista_pasazerow[i])
            {
                lista_pasazerow[i]->print();
            }
        }
    }

        void setPredkosc(int predkosc)
        {
            this->predkosc_maksymalna = predkosc;
        }
};

int main()
{
    Pasazer p1;
    Pasazer p2("Jan", "Kowalski", 1985);
    Pasazer p3(p2);
    Autokar a1;
    Autokar a2("Krakow", 90);
    Autokar a3(a2);
    a3.setPredkosc(110);

    a1.print();
    a2.print();
    a3.print();

    a1.dodajPasazera(&p1);
    a1.dodajPasazera(&p2);
    a1.dodajPasazera(&p3);

    cout << "Po dodaniu pasazerow:" << endl;
    a1.print();

    return 0;
}