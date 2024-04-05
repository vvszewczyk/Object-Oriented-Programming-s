#include <iostream>

using namespace std;


class Student
{
private:
	string imie;
	string nazwisko;
	string kierunek;
	int rok_studiow;

public:
	void setImie(string imieM)
	{
		this->imie = imieM;
	}

	string getImie()
	{
		return this->imie;
	}

	void setNazwisko(string nazwiskoM)
	{
		this->nazwisko = nazwiskoM;
	}

	string getNazwisko()
	{
		return this->nazwisko;
	}

	void setKierunek(string kierunekM)
	{
		this->kierunek = kierunekM;
	}

	string getKierunek()
	{
		return this->kierunek;
	}

	void setRokStudiow(int rok_studiowM)
	{
		this->rok_studiow = rok_studiowM;
	}

	int getRokStudiow()
	{
		return this->rok_studiow;
	}



};

class Grupa
{
	int nr_grupy = 1;
	int i = 0;
	static const int limit = 10;
	Student tablica[limit];



public:
	void Wypisz()
	{
		for (size_t i = 0; i < this->i; i++)
		{

			cout << this->nr_grupy << " ";
			cout << this->tablica[i].getImie()<<" ";
			cout << this->tablica[i].getNazwisko()<<" ";
			cout << this->tablica[i].getKierunek()<<" ";
			cout << this->tablica[i].getRokStudiow()<<endl;
		}
	}

	bool dodajStudenta(Student studentM)
	{
		if (this->i < limit)
		{
			this->tablica[this->i++] = studentM;
			return true;
		}
		else return false;
	}

	void przepiszStudenta(Grupa &nowaGrupa, string imie, string nazwisko)
	{
		for (int j = 0; j < this->i; j++)
		{
			if (this->tablica[j].getImie() == imie && this->tablica[j].getNazwisko() == nazwisko)
			{
				nowaGrupa.dodajStudenta(this->tablica[j]);
				for (int k = j; k < this->i - 1; k++)
				{
					this->tablica[k] = this->tablica[k + 1];
				}
				this->i--;
				return;
			}
		}
		cout << "Student nie znaleziony." << endl;
	}

};


int main()
{
	Student* student = new Student;

	student->setImie("Maciej");
	student->setNazwisko("Chodyn");
	student->setKierunek("'Fizyka kwantowa'");
	student->setRokStudiow(2);

	Student Studenci2[2];

	Studenci2[0].setImie("Krzysztof");
	Studenci2[0].setNazwisko("Banas");
	Studenci2[0].setKierunek("'Translacja kodu zrodlowego z czterech jezykow naraz'");
	Studenci2[0].setRokStudiow(4);

	Studenci2[1].setImie("Rafal");
	Studenci2[1].setNazwisko("Kapica");
	Studenci2[1].setKierunek("'Matematyka'");
	Studenci2[1].setRokStudiow(7);

	cout << student->getImie()<<" "<<student->getNazwisko()<<" "<<student->getKierunek()<<" "<<student->getRokStudiow()<<"\n";

	for (size_t i = 0; i <= 1; i++)
	{
		cout << Studenci2[i].getImie() << " " << Studenci2[i].getNazwisko() << " " << Studenci2[i].getKierunek() << " " << " " << Studenci2[i].getRokStudiow() << "\n";
	}

	Grupa grupa;

	grupa.dodajStudenta(*student);
	grupa.dodajStudenta(Studenci2[0]);
	grupa.dodajStudenta(Studenci2[1]);

	grupa.Wypisz();
	Grupa grupa2;

	grupa.przepiszStudenta(grupa2, "Krzysztof", "Banas");

	cout << "Czlonkowie grupy 1:\n";
	grupa.Wypisz();
	cout << endl;
	cout << "Czlonkowie grupy 2:\n";
	grupa2.Wypisz();

	return 0;
}