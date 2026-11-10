#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Laptop
{
private:
	char* denumire;
	float pret;
	int memorieRam;
	bool gaming;
	int nrSpecificatii;
	string* specificatii;
	int const id;
	static int contor;
public:

	Laptop() :id(contor++)
	{
		this->denumire = new char[strlen("lenovo") + 1];
		strcpy(this->denumire, "lenovo");
		this->pret = 2000;
		this->memorieRam = 10;
		this->gaming = true;
		this->nrSpecificatii = 1;
		this->specificatii = new string[this->nrSpecificatii];
		this->specificatii[0] = "leduri";
	}
	Laptop(const char* denumire, float pret) :id(contor++)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->memorieRam = 10;
		this->gaming = true;
		this->nrSpecificatii = 1;
		this->specificatii = new string[this->nrSpecificatii];
		this->specificatii[0] = "leduri";
	}
	Laptop(const Laptop& l) :id(contor++)
	{
		this->denumire = new char[strlen(l.denumire) + 1];
		strcpy(this->denumire, l.denumire);
		this->pret = l.pret;
		this->memorieRam = l.memorieRam;
		this->gaming = l.gaming;
		this->nrSpecificatii = l.nrSpecificatii;
		this->specificatii = new string[this->nrSpecificatii];
		for (int i = 0; i < this->nrSpecificatii; i++)
		{
			this->specificatii[i] = l.specificatii[i];
		}
	}
	~Laptop();

	char* getDenumire() const
	{
		return this->denumire;
	}
	float getPret() const
	{
		return this->pret;
	}
	int getMemorieRAM() const
	{
		return this->memorieRam;
	}
	bool getGaming() const
	{
		return this->gaming;
	}
	int getNrSpecificatii() const
	{
		return this->nrSpecificatii;
	}
	string* getSpecificatii() const
	{
		return this->specificatii;
	}
	static int getContor()
	{
		return contor;
	}
	int getId() const
	{
		return this->id;
	}
	void setDenumire(char* denumire)
	{
		this->denumire = denumire;
	}
	void setPret(float pret)
	{
		this->pret = pret;
	}
	void setMemorieRAM(int memorieRAM)
	{
		this->memorieRam = memorieRAM;

	}
	void setGaming(bool gaming)
	{
		this->gaming = gaming;
	}
	void setNrSpecificatii(int nrSpecificatii)
	{
		this->nrSpecificatii = nrSpecificatii;
	}
	void setSpecificatii(string* specificatii)
	{
		for (int i = 0;i < this->nrSpecificatii; i++)
		{
			this->specificatii[i] = specificatii[i];
		}
	}
	friend istream& operator>>(istream& in, Laptop& l)
	{
		cout << "denumire: ";
		char denumire[10];
		in >> denumire;
		if (l.denumire != NULL)
		{
			delete[] l.denumire;
		}
		l.denumire = new char[strlen(denumire) + 1];
		strcpy(l.denumire, denumire);
		cout << "pret";
		float pret;
		in >> pret;
		l.pret = pret;
		int memorieRAM;
		cout << "memorie ram";
		in >> memorieRAM;
		l.memorieRam = memorieRAM;
		bool gaming;
		cout << "gaming";
		in >> gaming;
		l.gaming = gaming;
		int nrSpecificatii;
		cout << "nr specificatii";
		in >> nrSpecificatii;
		l.nrSpecificatii = nrSpecificatii;
		if(l.specificatii!=NULL)
		{
			delete[] l.specificatii;
		}
		string specificatii;
		l.specificatii = new string[nrSpecificatii];
		for (int i = 0;i < nrSpecificatii; i++)
		{
			cout << "specificatia" << i;
			in >> specificatii[i];
			l.specificatii[i] = specificatii[i];
		}
		return in;

	}
	friend ostream& operator<<(ostream& out, Laptop& l)
	{
		out << "denumire: " << l.denumire << endl;
		out << "pret: " << l.pret << endl;
		out << "memorie RAM: " << l.memorieRam<< endl;
		out << "gaming: " << l.gaming << endl;
		out << "numar specificatii: " << l.nrSpecificatii << endl;
		for (int i = 0; i < l.nrSpecificatii; i++)
		{
			out << "specificatia[" << i << "]: " << l.specificatii << endl;
		}
		out << endl;
		out << "id: " << l.id << endl;
		out << "contor: " << l.contor << endl;
		return out;
	}
	Laptop operator++()
	{
		this->nrSpecificatii++;
		return *this;
	}
	Laptop &operator--(int) //cu polimorfism 
	{
		this->nrSpecificatii--;
		return *this;
	}
	Laptop* operator->()
	{
		this->pret = 1000;
		return this;
	}
	Laptop operator!()
	{
		Laptop l = *this;
		l.gaming = !l.gaming;
		return l;
	}
	operator float()
	{
		return gaming;
	}
	explicit operator int()
	{
		return pret;
	}
};
Laptop::~Laptop()
{
	delete[] this->denumire;
	delete[] this->specificatii;
}
int Laptop::contor = 0;
void main()
{
	Laptop L1;
	cout << L1 << endl;//
	Laptop L2("asus", 4000.0f);
	cout << L2 << endl;//
	Laptop L3(L2);
	cout << ++L3 << endl;//
	cout << L2-- << endl;//
	Laptop L4=!L1;
	cout << L4 << endl;//
	Laptop L5;
	cin >> L5;
	cout << L5 << endl;
	
	
	float gaming = L1;
	cout <<"gaming "<< gaming << endl;
	int pret=(int)L2;
	cout << pret;



}