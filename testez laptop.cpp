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
	friend class Student;
	Laptop():id(contor++)
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
	Laptop(const char* denumire, float pret ) :id(contor++)
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
	Laptop(const Laptop &l) :id(contor++)
	{
		this->denumire = new char[strlen(l.denumire) + 1];
		strcpy(this->denumire, l.denumire);
		this->pret = l.pret;
		this->memorieRam = l.memorieRam;
		this->gaming = l.gaming;
		this->nrSpecificatii = l.nrSpecificatii;
		this->specificatii = new string[this->nrSpecificatii];
	for(int i =0; i< this->nrSpecificatii; i++)
	{
		this->specificatii[i] = l.specificatii[i];
	}
	}
	~Laptop();
	Laptop operator=(const Laptop& l)
	{
		if (this != &l)
		{
			if (this->denumire != NULL)
			{
				delete[] this->denumire;
			}
			this->denumire = new char[strlen(l.denumire) + 1];
			strcpy(this->denumire, l.denumire);
			this->pret = l.pret;
			this->memorieRam = l.memorieRam;
			this->gaming = l.gaming;
			this->nrSpecificatii = l.nrSpecificatii;
			if (this->specificatii != NULL)
			{
				delete[] this->specificatii;
			}
			this->specificatii = new string[this->nrSpecificatii];
			for (int i = 0; i < this->nrSpecificatii; i++)
			{
				this->specificatii[i] = l.specificatii[i];
			}
			return *this;
		}
	}
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
	 void setDenumire(char* denumire )
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
	 string operator[](int pozitie)
	 {
		 if (pozitie >= 0 && pozitie < this->nrSpecificatii)
			 return this->specificatii[pozitie];
		 else return this->specificatii[0];
	 }
	 bool operator==(Laptop& l)
	 {
		 if (!(strcmp(this->denumire, l.denumire)))
			 return true;
		 else return false;
	 }
	 float operator-=(Laptop& l)
	 {
		 if (this->pret >= l.pret)
			 return this->pret - l.pret;
		 else return l.pret - this->pret;
	 }
	 Laptop operator+(Laptop &l)
	 {
		 Laptop result = *this;
		 result.pret = this->pret + l.pret;
		 return result;
	 }
	 float operator()()
	 {
		 return this->costMediuGB();
	 }
	 float costMediuGB()
	 {
		 return this->pret / this->memorieRam;
	 }
};
Laptop::~Laptop()
{
	delete[] this->denumire;
	delete[] this->specificatii;
}
int Laptop::contor = 0;
ostream& operator<<(ostream& out, Laptop& l)
{
	out << "denumire: " << l.getDenumire() << endl;
	out << "pret: " <<l.getPret() << endl;
	out << "memorie RAM: " << l.getMemorieRAM() << endl;
	out << "gaming: " << l.getGaming() << endl;
	out << "numar specificatii: " << l.getNrSpecificatii() << endl;
	for(int i=0; i<l.getNrSpecificatii(); i++)
	{
		out << "specificatia[" << i << "]: " << l.getSpecificatii() << endl;
	}
	out << endl;
	out << "id: " << l.getId() << endl;
	out << "contor: " << l.getContor() << endl;
	return out;
}
class Student
{
private:
	string nume;
	Laptop laptop;
public:
	Student()
	{
		this->nume = "gigi";
		
	}
	Student(string nume, Laptop L)
	{
		this -> nume = nume;
			this->laptop = L;
	}
	string setNume()
	{
		return this->nume;
	}
	Laptop setLaptop()
	{
		return this->laptop;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}
	void setLaptop(Laptop L )
	{
		this->laptop = L;
	}
	void afis()
	{
		cout << "studentul " << this->nume << " are laptopul " << laptop.denumire << endl;
	}
};
void main()
{
	Laptop L1;
	cout << L1 << endl;
	Laptop L2("acer", 5000);
	cout << L2 << endl;
	Laptop L3(L1);
	cout << L3 << endl;
	L3 = L1 + L2;
	cout << L3 << endl;
	cout << L3[0] << endl;
	if (L2 == L1)
		cout << "da"; 
	else cout<<"nu" ;
	L3 -= L1;
	cout << L3;
	Student s;
	s.afis();
}
