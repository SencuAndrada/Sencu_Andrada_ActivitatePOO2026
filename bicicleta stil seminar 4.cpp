/*
 ============================================================================
 CERINȚĂ: Clasa "Bicicleta"
 ============================================================================
 1. Atribute (private):
    - marcă (alocată dinamic)
    - preț
    - număr viteze
    - dacă este electrică sau nu
    - număr accesorii
    - listă accesorii (alocată dinamic)
    - id si contor 

 2. Funcționalități (public):
    - Constructori (implicit, cu parametri, de copiere)
    - Destructor
    - Afișare
    - Gettere
    - O metodă care modifică marca bicicletei
    - O metodă care calculează ceva legat de viteze/preț

 3. La nivel global:
    - O funcție care afiseaza id ul a 3 biciclete
 ============================================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class bicicleta
{private:
	char* marca;
	float pret;
    int nrViteze;
    bool electrica;
    int nrAccesorii;
    string* accesorii;
    int const id;
    static int contor;
public:
    //constructor implicit
    bicicleta():id(contor+=2)
    {
        this->marca = new char[strlen("decathlon") + 1];
        strcpy(this->marca, "decathlon");
        this->pret = 1500;
        this->nrViteze = 2;
        this->electrica = false;
        this->nrAccesorii = 2;
        this->accesorii = new string[this->nrAccesorii];
        this->accesorii[0] = "claxon";
        this->accesorii[1] = "lumini";

    }
    //constructor cu parametrii denumire si pret
    bicicleta(const char* marca, float pret):id(contor+=2)
    {
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);
        this->pret = pret;
        this->nrViteze = 3;
        this->electrica = true;
        this->nrAccesorii = 2;
        this->accesorii = new string[this->nrAccesorii];
        this->accesorii[0] = "display";
        this->accesorii[1] = "vitezometru";
    }
    //constructor de copiere
    bicicleta( const bicicleta& b):id(contor+=2)
    {
        this->marca = new char[strlen(b.marca + 1)];
        strcpy(this->marca, b.marca);
        this->pret = b.pret;
        this->nrViteze = b.nrViteze;
        this->electrica = b.electrica;
        this->nrAccesorii = b.nrAccesorii;
        this->accesorii = new string[this->nrAccesorii];
        for(int i=0; i< this->nrAccesorii; i++)
        {
            this->accesorii[i] = b.accesorii[i];
        }
    }
    //destructor
    ~bicicleta();
    //getteri
    char * getMarca(){return this->marca; }
    float getPret() { return this->pret; }
    int getNrViteze() { return this->nrViteze; }
    bool getElectrica() { return this->electrica; }
    int static getContor() { return contor; }
    void afisare()
    {
        cout << "marca: " << this->marca << endl;
        cout << "pret: " << this->pret << endl;
        cout << "nr viteze: " << this->nrViteze << endl;
        cout << "electrica: " << this->electrica << endl;
        cout << "nr accesorii: " << this->nrAccesorii << endl;
        for(int i=0;i< this->nrAccesorii; i++)
        {
            cout << this->accesorii[i] << " ";

        }
        cout << endl;
    }
    void ModificaMarca(const char* marca)
    {
        delete this->marca;
        this->marca = new char[strlen(marca) + 1];
        strcpy(this->marca, marca);
    }
    float PretPeViteza()
    {
        return this->pret / this->nrViteze;
    }

};
int bicicleta::contor = 1024;
//destructor
bicicleta::~bicicleta()
{
    delete[] this->marca;
    delete[] this->accesorii;
}

void IDbiciclete(bicicleta b1, bicicleta b2, bicicleta b3)
{
    cout << "id bicicleta 1: " << b1.getContor() << endl;
    cout << "id bicicleta 2: " << b2.getContor() << endl;
    cout << "id bicicleta 3: " << b3.getContor() << endl; }
void main()
{
    bicicleta b1;
    bicicleta b2("IronMan", 3000);
    bicicleta b3 ;
    b3.ModificaMarca("Specialized");
    b1.afisare();
    b2.afisare();
    b3.afisare();
    cout << b3.PretPeViteza();
    IDbiciclete(b1, b2, b3);
}