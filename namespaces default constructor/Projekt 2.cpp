#include <iostream>
#include <algorithm>
using namespace std;

namespace ksiazki 
{
    class Ksiazka 
    {
    private:
        string tytul;
        string autor;
        int rok_wydania;
        static int licznik;

    public:
        Ksiazka(string tytul = "Nieznany tytul", string autor = "Nieznany autor", int rok_wydania = 0) 
        {
            this->tytul = tytul;
            this->autor = autor;
            this->rok_wydania = rok_wydania;
            licznik++;
            cout << "Utworzono ksiazke: " << tytul << " autor: " << autor << endl;
        }

        bool czyXXwiek() const 
        {
            return rok_wydania >= 1901 && rok_wydania <= 2000;
        }

        void print() const 
        {
            cout << "Tytul: " << tytul << ", Autor: " << autor << ", Rok wydania: " << rok_wydania << endl;
        }

        int getRok() const 
        {
            return rok_wydania;
        }

        static int getLicznik() 
        {
            return licznik;
        }

        bool operator < (const Ksiazka& ksiazka) const 
        {
            return this->rok_wydania < ksiazka.rok_wydania;
        }
    };

    void sortuj(Ksiazka* tab, int size) 
    {
        for (int i = 0; i < size - 1; i++) 
        {
            for (int j = 0; j < size - i - 1; j++) 
            {
                if (tab[j].getRok() < tab[j + 1].getRok()) 
                {
                    Ksiazka temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
            }
        }
    }

    int Ksiazka::licznik = 0;
}

int main() 
{
    ksiazki::Ksiazka domyslna;
    domyslna.print();

    ksiazki::Ksiazka tablicaKsiazek[4] = 
    {
        ksiazki::Ksiazka("Hobbit", "J.R.R. Tolkien", 1937),
        ksiazki::Ksiazka("1984", "George Orwell", 1949),
        ksiazki::Ksiazka("Harry Potter", "J.K. Rowling", 1997),
        ksiazki::Ksiazka("Władca Pierścieni", "J.R.R. Tolkien", 1954)
    };

    cout << "\nInformacje o utworzonych ksiazkach:\n";
    for (int i = 0; i < 4; ++i) 
    {
        tablicaKsiazek[i].print();
    }

    cout << "\nSprawdzenie, czy ksiazki sa wydane w XX wieku:\n";
    for (int i = 0; i < 4; ++i) 
    {
        cout << "Ksiazka \"" << i + 1 << (tablicaKsiazek[i].czyXXwiek() ? "\" jest" : "\" nie jest") << " z XX wieku.\n";
    }

    cout << "\nSortowanie ksiazek po roku wydania:\n";
    ksiazki::sortuj(tablicaKsiazek, 4);
    for (int i = 0; i < 4; ++i) 
    {
        tablicaKsiazek[i].print();
    }

    cout << "\nLiczba utworzonych ksiazek: " << ksiazki::Ksiazka::getLicznik() << endl;

    return 0;
}
