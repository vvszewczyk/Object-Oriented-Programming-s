#include <iostream>
#include <vector>

using namespace std;

class Ulamek
{
private:
    friend Ulamek dodaj(Ulamek u1, Ulamek u2);
    int licznik;
    int mianownik;
public:
    Ulamek(int licznik, int mianownik) 
    {
        this->licznik = licznik;
        this->mianownik = mianownik;
    }

    //konstruktor konwertujacy
    Ulamek(int licznik) 
    {
        this->licznik = licznik;
        mianownik = 1;
    }

    int gcd(int a, int b)
    {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) 
            {
                break;
            }
            result--;
        }
        return result;
    }

    void skrocUlamek()
    {
        int GCD = gcd(licznik, mianownik);
        licznik /= GCD;
        mianownik /= GCD;
    }

    void wypiszUlamek() 
    {
        cout << licznik << "/" << mianownik <<endl;
    }

    operator double()
    {
        return (double)licznik / (double)mianownik;
    }

    bool operator>(Ulamek& u) const 
    {
        return double() > double(u);
    }
};

Ulamek dodaj(Ulamek u1, Ulamek u2)
{
    Ulamek wynik(u1.licznik * u2.mianownik + u2.licznik * u1.mianownik, u1.mianownik * u2.mianownik);
    wynik.skrocUlamek();
    return wynik;
}

//do D
double kwadratLiczby(double liczba) 
{
    return liczba * liczba;
}

Ulamek findMax(const vector<Ulamek>& ulamki) 
{
    Ulamek max = ulamki[0];
    for (int i = 1; i < ulamki.size(); i++) {
        if (ulamki[i] > max) {
            max = ulamki[i];
        }
    }
    return max;
}

void generatorUlamkow(int N) 
{
    vector<Ulamek> ulamki;
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int licznik = rand() % 2001 - 1000;
        int mianownik = rand() % 2001 - 1000;
        if (mianownik == 0) {
            mianownik = 1;
        }
        Ulamek ulamek(licznik, mianownik);
        ulamki.push_back(ulamek);
    }
    for (int i = 0; i < ulamki.size(); i++) {
        cout << "Ulamek " << i + 1 << ": " << ulamki[i] << endl;
    }
    Ulamek max = findMax(ulamki);
    cout << "Najwiekszy ulamek: " << max << endl;
}

int main()
{
    //PODPUNKT A
    cout << "Podpunkt A\n";
    Ulamek ulamki[3] = { Ulamek(1,2), Ulamek(5,8), Ulamek(7,9) };
    for (int i = 0; i < 3; i++) 
    {
        ulamki[i].wypiszUlamek();
    }

    //PODPUNKT B
    cout << "Podpunkt B\n";
    Ulamek wynik = dodaj(ulamki[0], ulamki[1]);
    wynik.wypiszUlamek();

    //PODPUNKT C
    cout << "Podpunkt C\n";
    Ulamek wynik2 = dodaj(ulamki[0], 7);
    wynik2.wypiszUlamek();
    
    //PODPUNKT D
    cout << "Podpunkt D\n";
    double wynik3 = kwadratLiczby(ulamki[2]);
    cout << wynik3 << endl;

    //PODPUNKT E
    cout << "Podpunkt E\n";
    Ulamek ulamekE(88, 22);
    ulamekE.skrocUlamek();
    ulamekE.wypiszUlamek();

    //PODPUNKT F
    cout << "Podpunkt F\n";
    generatorUlamkow(10);

    return 0;
}