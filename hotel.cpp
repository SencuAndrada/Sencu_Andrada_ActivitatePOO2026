#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Hotel
{
private:
	char* nume;
	int nrCamere;
	float pret;
	bool AC;
	int nrBonus;
	string* bonus;
public:
	friend class Client;
	Hotel()
	{
		this->nume = new char[strlen("california") + 1];
		strcpy(this->nume, "california");
		this->nrCamere = 1000;
		this->pret = 140;
		this->AC = true;
		this->nrBonus = 2;
		this->bonus = new string[this->nrBonus];
		this->bonus[0] = "piscina";
		this->bonus[1] = "snack";
	}
	Hotel(Hotel& h)
	{
		
			this->nume = new char[strlen(h.nume) + 1];
			strcpy(this->nume, h.nume);
			this->nrCamere = h.nrCamere;
			this->pret = h.pret;
			this->AC = h.AC;
			this->nrBonus = h.nrBonus;
			this->bonus = new string[this->nrBonus];
			for (int i = 0; i < this->nrBonus; i++)
			{
				this->bonus[i] = h.bonus[i];
			}
	}
	~Hotel();
	Hotel &operator=(const Hotel & H)
	{
		if (this != NULL)
		{
			if (this->nume != NULL)
			{
				delete[] this->nume;
			}
			this->nume = new char[strlen(H.nume) + 1];
			strcpy(this->nume, H.nume);
			this->nrCamere = H.nrCamere;
			this->pret = H.pret;
			this->AC = H.AC;
			this->nrBonus = H.nrBonus;
			if (this->bonus != NULL)
			{
				delete[] this->bonus;
			}
			this->bonus = new string[this->nrBonus];
			for (int i = 0; i < this->nrBonus; i++)
			{
				this->bonus[i] = H.bonus[i];
			}
		}
		return *this;
	}
	Hotel operator+(Hotel& h1)
	{
		Hotel result = *this;
		result.pret = this->pret + h1.pret;
		return result;
	}
	void modificaNume(const char* nume)
	{
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	void modificaPret(float pret)
	{
		
		this->pret = pret;
	}
	char* getNume()
	{
		return this->nume;
	}
	float getPret()
	{
		return this->pret;
	}
	bool getAC()
	{
		return this->AC;
	}
	int getNrBonus()
	{
		return this->nrBonus;
	}
	string* getBonus()
	{
		return this->bonus;
	}
	void afiseaza()
	{
		cout << "nume: " << this->nume << endl;
		cout << "pret: " << this->pret << endl;
		cout << "nrCamere: " << this->nrCamere << endl;
		cout << "AC: " << this->AC << endl;
		cout << "nr bonusuri: " << this->nrBonus << endl;
		for(int i=0; i<this->nrBonus;i++)
		{
			cout << "bonus" << i << " " << this->bonus[i] << ", ";
		}
		cout << endl;
	}
};
class Client
{
private:
	string nume;
	Hotel hotel;
public:
	Client()
	{
		this->nume = "gigi";
		
	}
	Client(string nume, Hotel ho)
	{
		this->nume = nume; 
		this->hotel = ho;
	}
	string getNume()
	{
		return this->nume;
	}
	Hotel getHotel()
	{
		return this->hotel;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}
	void setHotel(Hotel ho)
	{
		this->hotel = ho;
	}
	void HotelClient()
	{
		cout << this->nume << " sta la hotelul " << this->hotel.getNume();
	}
};
Hotel::~Hotel()
{
	delete[] this->nume;
	delete[] this->bonus;
}
void main()
{Hotel h1;
Hotel h2(h1);
h2.modificaNume("topola");
Hotel h3;
h3 = h1;
Hotel h4;
h4 = h3 + h2;
h3.modificaNume("cismigiu");
h3.modificaPret(200);
h1.afiseaza();
h2.afiseaza();
h3.afiseaza();
h2 + h3;
Client c;
c.HotelClient();
}