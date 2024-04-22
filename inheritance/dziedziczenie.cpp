#include <iostream>

using namespace std;

class Zwierze
{
protected:
    string imie;
    double masa;
    int liczba_nog;
public:
    Zwierze(string imie="", double masa=0, int liczba_nog=0)
    {
        this->imie = imie;
        this->masa = masa;
        this->liczba_nog = liczba_nog;
    }

    virtual void wyswietl()
    {
        cout << this->imie << " " << this->masa << " " << this->liczba_nog << "\n";
    }

    double Masa()
    {
        return this->masa;
    }
};

class Pies :public Zwierze
{
private:
    string rasa;
    string kolor_siersci;
public:
    Pies(string imie, double masa, int liczba_nog, string rasa, string kolor)
    {
        this->rasa = rasa;
        this->kolor_siersci = kolor;
        this->imie = imie;
        this->masa = masa;
        this->liczba_nog = liczba_nog;
    }
    void wyswietl()
    {
        cout << this->imie << " " << this->masa << " " << this->liczba_nog << " " << this->rasa << " " << this->kolor_siersci<<"\n";
    }
};

class Papuga :public Zwierze
{
private:
    string kolor_pior;
public:
    Papuga(string imie, double masa, int liczba_nog, string kolor)
    {
        this->imie = imie;
        this->masa = masa;
        this->liczba_nog = liczba_nog;
        this->kolor_pior = kolor;
    }
    Papuga(Papuga& obiekt, string imie, double masa)
    {
        this->imie = imie;
        this->masa = masa;
        this->kolor_pior = obiekt.kolor_pior;
        this->liczba_nog = obiekt.liczba_nog;
    }

    void wyswietl()
    {
        cout << this->imie << " " << this->kolor_pior << " " << this->liczba_nog << " " << this->masa << "\n";
    }
};



void sortowanie(Zwierze** tablica, int rozmiar)
{
    int i, j, min_idx;

    for (i = 0; i < rozmiar - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < rozmiar; j++) 
        {
            if (tablica[j]->Masa() < tablica[min_idx]->Masa())
                min_idx = j;
        }
        if (min_idx != i)
            swap(tablica[min_idx], tablica[i]);
    }
}


int main()
{
    //PODPUNKT A
    Zwierze ZWIERZE1("Burek", 10.0, 4);
    ZWIERZE1.wyswietl();

    //PODPUNKT B
    Pies* piesek = new Pies("Lucky", 5.2, 4, "kundel", "bury");
    piesek->wyswietl();

    //PODPUNKT C
    Papuga papuszka1 = Papuga("Betty", 0.5, 2, "kolorowa");
    Papuga papuszka2 = Papuga(papuszka1, "Lucy", 0.6);
    papuszka1.wyswietl();
    papuszka2.wyswietl();

    cout << endl;
    cout << endl;

    //PODPUNKT D
    Zwierze** tablica = new Zwierze * [4];
    tablica[0] = &ZWIERZE1;
    tablica[1] = piesek;
    tablica[2] = &papuszka1;
    tablica[3] = &papuszka2;

    for (int i = 0; i < 4; i++)
    {
        tablica[i]->wyswietl();
    }

    //PODPUNKT E
    sortowanie(tablica, 4);
    cout << endl;
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        tablica[i]->wyswietl();
    }
    
    delete piesek;
    delete [] tablica;

    return 0;
}