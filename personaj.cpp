#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Personaj {
private:
	char* nume;
	float putere;
	int pret;
	bool sageti;
	int nrPuteri;
	string* puteri;
	const int id;
	static int contor;
public:
	Personaj() :id(contor++)
	{
		this->nume = new char[strlen("Ashe") + 1];
		strcpy(this->nume, "Ashe");
		this->putere = 99;
		this->pret = 1500;
		this->sageti = true;
		this->nrPuteri = 2;
		this->puteri = new string[this->nrPuteri];
		this->puteri[0] = "ingheata";
		this->puteri[1] = "teleporteaza";
	}
	Personaj(Personaj& p) :id(contor++)
	{
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->putere = p.putere;
		this->pret = p.pret;
		this->sageti = p.sageti;
		this->nrPuteri = p.nrPuteri;
		this->puteri = new string[this->nrPuteri];
		for(int i = 0; i < this->nrPuteri; i++)
		{
			this->puteri[i] = p.puteri[i];
		}
	}
	~Personaj();
Personaj &operator=(const Personaj& p)
{
	if (this != p)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;

		}
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->putere = p.putere;
		this->pret = p.pret;
		this->sageti = p.sageti;
		this->nrPuteri = p.nrPuteri;
		if (this->puteri != NULL)
		{
			delete[] this->puteri;
		}
		for (int i = 0; i < this->nrPuteri;i++)
		{
			this->puteri[i] = p.puteri[i];
		}
		return *this;
	}
}
	Personaj operator+(Personaj & p1)
	{
		Personaj result = *this;
		result.putere = this->putere + p1.putere;
		return result;
	}
	char* getNume(){return this->nume;}
	float getPutere() { return this->putere; }
	int getPret() { return this->pret; }
	bool getSageti() { return this->sageti; }
	 static int getContor() { return contor; }
	  int getID() { return this->id; }
	void afisare()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Putere: " << this->putere << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Sageti: " << this->sageti << endl;
		cout << "Numar puteri: " << this->nrPuteri << endl;
		cout << "Puteri: ";
		for (int i = 0; i < this->nrPuteri; i++)
		{
			cout << this->puteri[i] << " ";
		}
		cout << endl;
	}
	void modificaNumePutere(const char * nume, float putere)
	{
		delete this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->putere = putere;
	}
};
class animal
{
private:
	string nume;
	Personaj personaj;
public:
	animal()
	{
		this->nume = nume;
		this->personaj;
	}
	animal(string nume, Personaj p)
	{
		this->nume = nume;
		this->personaj = p;
	}
	string getNume()
	{
		return this->nume;
	}
	Personaj getPersonaj()
	{
		return this->personaj;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}
	void setPersonaj(Personaj p)
	{
		this->personaj = p;
	}
	void Afis()
		{ cout << this->personaj.getNume() << " are animalul " << this->nume;
		}
};
int Personaj::contor = 0;
Personaj::~Personaj()
{
	delete[] this->nume;
	delete[] this->puteri;
}
const int Lupta(Personaj personaj01, Personaj personaj02)
{

	if (personaj01.getPutere() > personaj02.getPutere())
	{
		cout << "Id personaj: ";return personaj01.getID();
	}
	else
	{
		cout << "id personaj: ";return personaj02.getID();

	}
}

	/*return (personaj01.getPutere() > personaj02.getPutere())
		? personaj01.getContor()
		:  personaj02.getContor();*/

void main()
{
	Personaj personaj1;
	Personaj personaj2(personaj1);
	personaj2.modificaNumePutere("Tresh", 100);
	personaj1.afisare();
	personaj2.afisare();
	animal a("yummy", personaj1);
	a.Afis();
}
