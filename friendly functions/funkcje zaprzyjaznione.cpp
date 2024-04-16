#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

class Punkt;
class Prostokat;
class Okrag;

class Punkt
{
    friend class Prostokat;
    friend int czyPrzecina(Okrag* tabOkr1, Okrag* tabOkr2);
    friend void wypisz(Punkt p);
    friend void wypisz(Prostokat pr);
    friend void wypisz(Okrag o);

private:
    int x;
    int y;

public:
    Punkt(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

class Prostokat
{
    friend void wypisz(Prostokat pr);
private:
    Punkt lewy_dolny_wierzcholek;
    double szerokosc;
    double wysokosc;

public:
    Prostokat(Punkt ldw, double width = 0, double height = 0)
    {
        this->lewy_dolny_wierzcholek = ldw;
        this->szerokosc = width;
        this->wysokosc = height;
    }

    bool czyWspolne(Punkt p, Prostokat pr)
    {
        double odleglosc_x = abs(p.x - pr.lewy_dolny_wierzcholek.x);
        double odleglosc_y = abs(p.y - pr.lewy_dolny_wierzcholek.y);
        double odleglosc = sqrt(pow(odleglosc_x, 2) + pow(odleglosc_y, 2));
        double przekatna = sqrt(pow(pr.szerokosc, 2) + pow(wysokosc, 2));

        if (odleglosc_x <= pr.szerokosc && odleglosc_y <= pr.wysokosc && odleglosc <= przekatna)
            return true;
        else
            return false;
    }
};

class Okrag
{
    friend int czyPrzecina(Okrag* tabOkr1, Okrag* tabOkr2);
    friend void wypisz(Okrag o);

private:
    Punkt srodek_okregu;
    int promien;

public:
    Okrag(Punkt so = Punkt(0, 0), int r = 0)
    {
        this->srodek_okregu = so;
        this->promien = r;
    }
};

int czyPrzecina(Okrag *tabOkr1, Okrag *tabOkr2)
{
    int counter = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            double midLength = sqrt(pow(tabOkr1[i].srodek_okregu.x-tabOkr2[j].srodek_okregu.x, 2) + pow(tabOkr1[i].srodek_okregu.y-tabOkr2[j].srodek_okregu.y, 2));
            double diff = abs(tabOkr1[i].promien - tabOkr2[j].promien);
            double sum = tabOkr1[i].promien + tabOkr2[j].promien;
            if (diff<midLength && sum>midLength)
                counter++;
        }
    }
    return counter;
}

void wypisz(Punkt p)
{
    cout << endl;
    cout << "Wsp x: " << p.x;
    cout << "\nWsp y: " << p.y;
}

void wypisz(Prostokat pr)
{
    cout << "\nWsp x lewego dolnego srodka: " << pr.lewy_dolny_wierzcholek.x;
    cout << "\nWsp y lewego dolnego srodka: " << pr.lewy_dolny_wierzcholek.y;
    cout << "\nSzerokosc: " << pr.szerokosc;
    cout << "\nWysokosc: " << pr.wysokosc;
}

void wypisz(Okrag o)
{
    cout <<"\nWsp x srodka okregu: " << o.srodek_okregu.x;
    cout <<"\nWsp y srodka okregu: " << o.srodek_okregu.y;
    cout <<"\nPromien okregu: " << o.promien;
}

int main()
{
    Punkt tablica[3] = { Punkt(5,2), Punkt(-9,-9), Punkt(2,3) };

    Prostokat prostokat = Prostokat(Punkt(-8, 6), 13, 10);


    for (int i = 0; i < 3; i++) 
    {
        if (prostokat.czyWspolne(tablica[i], prostokat))
            cout << "Punkt " << i + 1 << " nalezy do prostokata." << endl;
        else
            cout << "Punkt " << i + 1 << " nie nalezy do prostokata." << endl;
    }

    srand(time(NULL));
    Okrag tablica1[100];
    for (int i = 0; i < 100; i++)
    {
        tablica1[i] = Okrag(Punkt(rand() % 6, rand() % 6 - 5), rand() % 10 + 1);
    }

    Okrag* tablica2 = new Okrag[50];
    for (int i = 0; i < 50; i++)
    {
        tablica2[i] = Okrag(Punkt(rand() % 16 - 5, rand() % 16 - 10), rand() % 15 + 1);
    }


    cout<<"\nIlosc okregow ktore sie przecina: " << czyPrzecina(tablica1, tablica2);

    cout << endl;
    wypisz(tablica[0]);
    cout << endl;
    wypisz(prostokat);
    cout << endl;
    wypisz(tablica1[20]);

    delete[] tablica2;
    return 0;
}
