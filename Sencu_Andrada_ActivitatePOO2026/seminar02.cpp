#include <iostream>
using namespace std;
struct Cladire {
	char* culoare;
	float inaltime;
	int nrEtaje;
	bool deschis;

};
Cladire citireCladire() {
	Cladire c;
	char x[100];
	cout << "Culoare: ";
	cin >> x;
	c.culoare = new char[strlen(x) + 1];
	strcpy_s(c.culoare, strlen(x) + 1, x);
	cout << "\nInaltime: ";
	cin >> c.inaltime;
	cout << "\nNrEtaje: ";
	cin >> c.nrEtaje;
	cout << "\nDeschis: ";
	cin >> c.deschis;
	return c;
}
void afisareCladire(Cladire c)
{	cout << "\nCuloare: " << c.culoare;
	cout << "\nInaltime: " << c.inaltime;
	cout << "\nNrEtaje: " << c.nrEtaje;
	cout << "\nDeschis: " << c.deschis;
}
void modificareNrEtaje(int noulNrEtaje, Cladire *c)
{
	(*c).nrEtaje = noulNrEtaje;
}
void main() {
	Cladire c = citireCladire();
	afisareCladire(c);
    modificareNrEtaje(10, &c);
	afisareCladire(c);
}