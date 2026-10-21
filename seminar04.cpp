#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Prajitura {
private:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	const int id;//este un atribut constat, se initialzeaza dupa semnatura constructorului
	static int contor;//atribut static
public:
	Prajitura():id(contor++) {

		this->denumire = new char[strlen("Tiramisu")+1];
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
	Prajitura(const char*denumire,float pret):id(contor++) {
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
	Prajitura(const Prajitura& p):id(contor++) //e transmis prin referinta, punem const ca sa nu modificam obiectul, e constructor de copiere
	{
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->pret = p.pret;
		this->cantitate = p.cantitate;
		this->dePost = p.dePost;
		this->nrIngrediente = p.nrIngrediente;
		this->ingrediente = new string[this->nrIngrediente];
		for (int i=0;i < this->nrIngrediente; i++)
		{
			this->ingrediente[i] = p.ingrediente[i];
		}
	}
	~Prajitura(); //e un destructor
	//geter, se recomanda sa se declare dupa destructor, e o metoda cat si o functie
	int getCantitate() {
		return this->cantitate;

	}
	int getNrIngrediente()
	{
		return this->nrIngrediente;
	}
	float getPret()
	{
		return this->pret;
	}
	static int getContor()
	{
		return contor;
	}
	
	void afisare()
	{
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate<< endl;
		cout << "De Post: " << (this->dePost ? "DA" : "NU") << endl;
		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0;i < this->nrIngrediente;i++)
		{
			cout << this->ingrediente[i] << "; ";
		}
		cout << endl;

	}
	float costMediuGram() {
		if (this->cantitate == 0) {
			return 0;
		}
		else {
			return this->pret / this->cantitate;
		}
	}

	void modificaDenumire(const char* denumire) {
		delete this->denumire;

		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}


};
//initializare atribut static, se face imediat dupa ce se termina clasa
//se specifica clasa de unde provine, se pune operatorul de rezolutie

int Prajitura::contor = 100;
//destructorul curata ceea ce s a alocat in constructor,se autoapeleaza 
Prajitura::~Prajitura() {
	delete[] this->denumire;
	delete[] this->ingrediente;

}

float calculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri) {
	float greutate = 0;

	for (int p = 0; p < nr_prajituri; p++)
		greutate += prajituri[p].getCantitate();

	return greutate;
}
float CalculeazaPretPerIngrediente(Prajitura p)
{
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();
}

void main() {
 Prajitura p;//breakpoint ul: atunci cand programul ruleaza, programul se opreste aici
 p.afisare();
	cout << CalculeazaPretPerIngrediente(p);
	//Prajitura* pp;
	//(*pp).afisare();//se dereferentiaza si se apeleaza prin punct 
	//pp->afisare();//dereferentiaza si acceseaza
	Prajitura::getContor();
	

}//aici se va distruce obiectul p, cand i se termina durata de viata in corpul in care e declarat