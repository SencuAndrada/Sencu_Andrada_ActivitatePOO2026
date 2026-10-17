#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Prajitura
{
public:
	char* denumire;
	float pret;
	float cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;

	//sunt in zona de acces privata daca nu punem public la inceput
	//vom construi un constructor, are aceleasi particularitati cu clasa si nu returneaza nimic, nu are tip returnat, are acelaasi nume cu clasa

	Prajitura()
	{
		this->denumire = new char[strlen("Tiramisu") + 1];//this arate adresa obiectului curent, sageata face deferentiere si accesare
		strcpy(denumire, "Tiramisu");
		this->pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}
	//initializeaza cu valori toate atributele clasei

	Prajitura(const char* denumire, float pret)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}
	//afisare este o metoda, nu primeste Prajitura pt ca este deja in interiorul clasei
	void Afisare()
	{
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "De post: " << this->dePost << endl;
		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingrediente: ";
		for (int i = 0;i < this->nrIngrediente;i++)
		{
			cout << this->ingrediente[i] << " ";
		}
		cout << endl;
	}
	float CostMediuGram()
	{
		if (this->cantitate == 0)
		{
			return 0;
		}
		else
		{
			return this->pret / this->cantitate;
		}
	}
	void ModificaDenumire(const char* denumire)
	{
		delete this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
};
//Calculeaza e o functie
float CalculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri)
{
	float greutate = 0;
	for (int p = 0;p < nr_prajituri;p++)
		greutate += prajituri[p].cantitate;
	return greutate;
}
void main()
{
	Prajitura p2("Amandina", 40);
	p2.Afisare();
	Prajitura p;
	p.Afisare();
	cout << p.CostMediuGram();
	Prajitura* prajituri;
	prajituri = new Prajitura[3];
	prajituri[2].Afisare();
	prajituri[1].pret = 50;
	prajituri[2].cantitate = 70;
	prajituri[0].ModificaDenumire("tort");
	prajituri[1].ModificaDenumire("ecler");
	for (int i = 0; i < 3;i++)
	{
		cout << prajituri[i].denumire << " " << prajituri[i].CostMediuGram() << endl;
	}
	float greutate_totala = CalculeazaCantitateTotala(prajituri, 3);
	cout << "Total: " << greutate_totala << endl;
}