#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Wektor
{
    friend ostream& operator<<(ostream& output, Wektor p);
    friend Wektor operator+ (Wektor p1, Wektor p2);
    friend double operator* (Wektor p1, Wektor p2);
    friend void sort(Wektor* arr, int size);
    friend int main();
private:
    int x;
    int y;
    double length=0;
public:
    Wektor(int X=0, int Y=0)
    {
        this->x = X;
        this->y = Y;
    }

    void dlugosc()
    {
        this->length = sqrt(pow(this->x, 2) + pow(this->y, 2));
    }
};

//do podpunktu A
ostream& operator<<(ostream& output, Wektor p)//wypisywanie
{
    output << "Wsp x: " << p.x;
    output << " Wsp y: " << p.y << endl;
    return output;
}

//do podpunktu B
Wektor operator+ (Wektor p1, Wektor p2)  //dodawanie dwoch punktow
{
    Wektor p(p1.x+p2.x, p1.y+p2.y);
    return p;
}

//do podpunktu C
double operator* (Wektor p1, Wektor p2)  //mnozenie dwoch punktow
{
    double liczba = (p1.x * p2.x) + (p1.y * p2.y);
    return liczba;
}


void sort(Wektor* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].length < arr[min].length)
                min = j;
        }

        Wektor buffer = arr[i];
        arr[i] = arr[min];
        arr[min] = buffer;
    }
}

int main()
{
    //PODPUNKT A
    cout << "PODPUNKT A" << endl;
    Wektor w1 = Wektor(3, 5);
    Wektor w2 = Wektor(-2, 7);
    cout << w1;
    cout << w2;

    //PODPUNKT B
    cout << "\nPODPUNKT B" << endl;
    cout << "w1 + w2 = " << w1 + w2<<endl;

    //PODPUNKT C
    cout << "\nPODPUNKT C" << endl;
    cout << "w1 * w2 = " << w1 * w2 << endl;

    //PODPUNKT D
    Wektor tablica[20];
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        tablica[i] = Wektor(rand()%31-15, rand() % 31 - 15);
        tablica[i].dlugosc();
    }

    //PODPUNKT E
    cout << "\nPODPUNKT E" << endl;
    sort(tablica, 20);
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
        cout << tablica[i];
        cout << tablica[i].length;
    }


    return 0;
}
