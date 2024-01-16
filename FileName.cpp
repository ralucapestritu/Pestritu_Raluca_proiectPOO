#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

// porturi


class PortMaritim {
	const int idPort;
	string locatie;
	float capacitate;
	int nrContainere;
	float* pret;
	static float TVA;
	static int contor;
public:

	//Constructor fara parametrii
	PortMaritim() :idPort(contor++)
	{
		this->locatie = "constanta";
		this->capacitate = 2.5;
		this->nrContainere = 0;
		this->pret = NULL;
	}

	//Constructor cu 2 parametrii
	PortMaritim(string locatie, float capacitate) :idPort(contor++)
	{
		this->locatie = locatie;
		this->capacitate = capacitate;
		this->nrContainere = 0;
		this->pret = NULL;
	}

	//Constructor cu toti paramterii
	PortMaritim(string locatie, float capacitate, int nrContainere, float* pret) :idPort(contor++)
	{
		this->locatie = locatie;
		this->capacitate = capacitate;
		this->nrContainere = nrContainere;
		this->pret = new float[this->nrContainere];
		for (int i = 0; i < this->nrContainere; i++)
		{
			this->pret[i] = pret[i];
		}
	}

	~PortMaritim()
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
	}

	void afisare()
	{
		cout << "Locatia portului este: " << this->locatie << ", avand o capacitate de " << this->capacitate << " , are numar de containere " << this->nrContainere << " si pretul pentru fiecare container este: ";
		for (int i = 0; i < this->nrContainere; i++)
		{
			cout << this->pret[i] << " ";
		}
		cout << "Marfa din containere are TVA-ul: " << this->TVA;
		cout << endl;
	}

	static void setTVA(float TVA)
	{
		PortMaritim::TVA = TVA;
	}

	const int getIdPort()
	{
		return this->idPort;
	}
	string getLocatie()
	{
		return this->locatie;
	}
	float getCapacitate()
	{
		return this->capacitate;
	}
	float getNrContainere()
	{
		return this->nrContainere;
	}
	float* getPret()
	{
		return this->pret;
	}

	void setLocatie(string LocatieNoua)
	{
		this->locatie = LocatieNoua;
	}
	void setCapacitate(float CapacitateNoua)
	{
		this->capacitate = CapacitateNoua;
	}
	void setContainere(int nrContainereNou, float* pretNou)
	{
		this->nrContainere = nrContainereNou;
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->pret = new float[this->nrContainere];
		for (int i = 0; i < this->nrContainere; i++)
		{
			this->pret[i] = pretNou[i];
		}
	}

	//Constructorul de copiere
	PortMaritim(const PortMaritim& m) :idPort(contor++)
	{
		this->locatie = m.locatie;
		this->capacitate = m.capacitate;
		this->nrContainere = m.nrContainere;
		this->pret = new float[this->nrContainere];
		for (int i = 0; i < this->nrContainere; i++)
		{
			this->pret[i] = m.pret[i];
		}
	}

	float mediePreturiContainere()
	{
		float rezultat = 0;
		for (int i = 0; i < this->nrContainere; i++)
		{
			rezultat = rezultat + this->pret[i];
		}
		rezultat = rezultat / this->nrContainere;
		return rezultat;
	}


	static float getTVA() {
		return PortMaritim::TVA;
	}

	//Operatorul=
	PortMaritim& operator=(const PortMaritim& m)
	{
		if (this->pret != NULL)
		{
			delete[]this->pret;
		}
		this->locatie = m.locatie;
		this->capacitate = m.capacitate;
		this->nrContainere = m.nrContainere;
		this->pret = new float[this->nrContainere];
		for (int i = 0; i < this->nrContainere; i++)
		{
			this->pret[i] = m.pret[i];
		}
		return *this;
	}

	//Operatorul<<
	friend ostream& operator<<(ostream& out, PortMaritim& m)
	{
		cout << "Id: " << m.idPort << endl;
		cout << "locatie: " << m.locatie << endl;
		cout << "capacitate: " << m.capacitate << endl;
		cout << "Numar containere: " << m.nrContainere << endl;
		cout << "Pret: " << endl;
		for (int i = 0; i < m.nrContainere; i++)
		{
			cout << m.pret[i] << endl;
		}
		return out;
	}
	//fisiere text
	friend ofstream& operator<<(ofstream& file, PortMaritim& m)
	{
		file << m.locatie << endl;
		file << m.capacitate << endl;
		file << m.nrContainere << endl;
		for (int i = 0; i < m.nrContainere; i++)
		{
			file << m.pret[i] << endl;
		}
		return file;
	}
	friend ifstream& operator>>(ifstream& file, PortMaritim& m)
	{
		delete[]m.pret;
		file >> m.locatie;
		file >> m.capacitate;
		file >>m.nrContainere;
		m.pret = new float[m.nrContainere];
		for (int i = 0; i < m.nrContainere; i++)
		{
			file >> m.pret[i];
		}
		return file;
	}

	//Operatorul>>
	friend istream& operator>>(istream& in, PortMaritim& m)
	{
		delete[]m.pret;
		in >> m.locatie;
		cout << endl;
		in >> m.capacitate;
		cout << endl;
		in >> m.nrContainere;
		cout << endl;
		m.pret = new float[m.nrContainere];
		for (int i = 0; i < m.nrContainere; i++)
		{
			in >> m.pret[i];
		}
		return in;
	}

	//Operatorul index []
	float operator[](int poz)
	{
		if (poz >= 0 && poz < this->nrContainere)
		{
			return this->pret[poz];
		}
		else
		{
			return 0;
		}
	}

	//Operatorul de comparatie 
	bool operator>=(PortMaritim& m)
	{
		if (this->nrContainere >= m.nrContainere)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//Operatorul de autoasignare +=
	PortMaritim& operator+=(float pretNou)
	{
		PortMaritim copie = *this;
		delete[]this->pret;
		this->nrContainere++;
		this->pret = new float[this->nrContainere];
		for (int i = 0; i < copie.nrContainere; i++)
		{
			this->pret[i] = copie.pret[i];
		}
		this->pret[copie.nrContainere] = pretNou;
		return *this;
	}
	//fisiere binare
	void scriereBinar(fstream& file)
	{
		int nrLitereLocatie = this->locatie.size();
		file.write((char*)&nrLitereLocatie, sizeof(int));
		file.write(this->locatie.c_str(), nrLitereLocatie);
		file.write((char*)&this->capacitate, sizeof(float));
		file.write((char*)&this->nrContainere, sizeof(int));
		for (int i = 0; i < this->nrContainere; i++)
		{
			file.write((char*)&this->pret[i], sizeof(float));
		}
	}

	void citireBinar(fstream& file)
	{
		delete[]this->pret;
		int nrLitereLocatie;
		file.read((char*)&nrLitereLocatie, sizeof(int));
		string aux;
		aux.resize(nrLitereLocatie);
		file.read((char*)aux.c_str(), nrLitereLocatie);
		this->locatie = aux;
		file.read((char*)&this->capacitate, sizeof(float));
		file.read((char*)&this->nrContainere, sizeof(int));
		this->pret = new float[this->nrContainere];
		for (int i = 0; i < this->nrContainere; i++)
		{
			file.read((char*)&this->pret[i], sizeof(float));
		}
	}

};


	
	

	class PortMilitar 
	{
	protected:
		const int id;
		string tara;
		char* nume;
		bool controlSecuritate;
		int nrDocuri;
		static int contor;
		static float gravitatie;

	public:

		//Constructorul fara parametrii
		PortMilitar() :id(contor++)
		{
			this->tara = "Franta";
			this->nume = new char[strlen("Marseille") + 1];
			strcpy(this->nume, "Marseille");
			this->controlSecuritate = 1;
			this->nrDocuri = 50;

		}

		//Constructorul cu 2 parametrii
		PortMilitar(string tara, const char* nume) :id(contor++)
		{
			this->tara = tara;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
			this->controlSecuritate = 0;
			this->nrDocuri = 120;

		}

		//Constructorul cu toti parametrii
		PortMilitar(string tara, const char* nume, bool controlSecuritate, int nrDocuri) :id(contor++)
		{
			this->tara = tara;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
			this->controlSecuritate = controlSecuritate;
			this->nrDocuri = nrDocuri;
		}

		~PortMilitar()
		{
			if (this->nume != NULL)
			{
				delete[]this->nume;
			}
		}

		void afisare()
		{
			cout << "Portul militar este din tara: " << this->tara << " , numele este: " << this->nume << " , a trecut de controlul de securitate: " << this->controlSecuritate << " si are un numar de docuri: " << this->nrDocuri;
			cout << "in port este o gravitatie de: " << this->gravitatie;
			cout << endl;
		}

		static void setGravitatie(float gravitatie)
		{
			PortMilitar::gravitatie = gravitatie;
		}

		const int getId()
		{
			return this->id;
		}
		string getTara()
		{
			return this->tara;
		}
		const char* getnume()
		{
			return this->nume;
		}
		bool getcontrolSecuritate()
		{
			return this->controlSecuritate;
		}
		int getnrDocuri()
		{
			return this->nrDocuri;
		}

		void setTara(string TaraNoua)
		{
			this->tara = TaraNoua;
		}
		void setnume(const char* NumeNou)
		{
			if (this->nume != NULL)
			{
				delete[]this->nume;
			}
			this->nume = new char[strlen(NumeNou) + 1];
			strcpy(this->nume, NumeNou);
		}
		void setControlSecuritate(bool controlSecuritate)
		{
			this->controlSecuritate = controlSecuritate;
		}
		void setnrDocuri(int nrDocuriNou)
		{
			this->nrDocuri = nrDocuriNou;
		}

		//Constructorul de copiere
		PortMilitar(const PortMilitar& t) :id(contor++)
		{
			this->tara = t.tara;
			this->nume = new char[strlen(t.nume) + 1];
			strcpy(this->nume, t.nume);
			this->controlSecuritate = t.controlSecuritate;
			this->nrDocuri = t.nrDocuri;
		}

		//metoda 
		int cresterenrDocuri()
		{
			int DocuriConstruite;
			int rezultat;
			rezultat = this->nrDocuri + DocuriConstruite;
			return rezultat;
		}

		static float getGravitatie()
		{
			return PortMilitar::gravitatie;
		}

		//Operatorul<<
		friend ostream& operator<<(ostream& out, PortMilitar& t)
		{
			out << "Id: " << t.id << endl;
			out << "tara: " << t.tara << endl;
			out << "nume: " << t.nume << endl;
			out << "control de securitate " << t.controlSecuritate << endl;
			out << "numar docuri: " << t.nrDocuri << endl;
			return out;
		}

		//Operatorul>>
		friend istream& operator>>(istream& in, PortMilitar& t)
		{
			delete[]t.nume;
			in >> t.tara;
			cout << endl;
			char aux[50];
			in >> aux;
			t.nume = new char[strlen(aux) + 1];
			strcpy(t.nume, aux);
			cout << endl;
			in >> t.controlSecuritate;
			cout << endl;
			in >> t.nrDocuri;
			return in;
		}

		//Operatorul=
		PortMilitar& operator=(const PortMilitar& t)
		{
			if (this->nume != NULL)
			{
				delete[]this->nume;
			}
			this->tara = t.tara;
			this->nume = new char[strlen(t.nume) + 1];
			strcpy(this->nume, t.nume);
			this->controlSecuritate = t.controlSecuritate;
			this->nrDocuri = t.nrDocuri;
			return *this;
		}

		//Operatorul  !
		friend void operator!(PortMilitar& t)
		{
			if (t.controlSecuritate == 1)
			{
				t.controlSecuritate = 0;
			}
			else
			{
				t.controlSecuritate = 1;
			}
		}

		//Operatorul de cast la int
		operator int()
		{
			int nrDocuriModificat;
			nrDocuriModificat = this->nrDocuri / 2;
			return nrDocuriModificat;
		}

		//Operator de testare a egalitatii 
		bool operator==(PortMilitar& t)
		{
			if (this->nrDocuri == t.nrDocuri)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		//Operatorul functie 
		void operator()(int valoare)
		{
			this->nrDocuri = this->nrDocuri + valoare;
		}
		//fisiere text
		friend ofstream& operator<<(ofstream& file, PortMilitar& t)
		{
			file << t.tara << endl;
			file << t.nume << endl;
			file << t.controlSecuritate << endl;
			file << t.nrDocuri<< endl;
			return file;
		}

		friend ifstream& operator>>(ifstream& file, PortMilitar& t)
		{
			delete[]t.nume;
			file >> t.tara;
			char aux[50];
			file >> aux;
			t.nume = new char[strlen(aux) + 1];
			strcpy(t.nume, aux);
			file >> t.controlSecuritate;
			file >> t.nrDocuri;
			return file;
		}

		//fisiere binare
		void scriereBinar(fstream& file)
		{
			int nrLitereTara = this->tara.size();
			file.write((char*)&nrLitereTara, sizeof(int));
			file.write(this->tara.c_str(), nrLitereTara);
			int nrLitereNume = strlen(this->nume);
			file.write((char*)&nrLitereNume, sizeof(int));
			for (int i = 0; i < nrLitereNume; i++)
			{
				file.write((char*)&this->nume[i], sizeof(char));
			}
			file.write((char*)&this->controlSecuritate, sizeof(bool));
			file.write((char*)&this->nrDocuri, sizeof(int));
		}

		void citireBinar(fstream& file)
		{
			delete[] this->nume;
			int nrLitereNume;
			file.read((char*)&nrLitereNume, sizeof(int));
			string aux;
			aux.resize(nrLitereNume);
			file.read((char*)aux.c_str(), nrLitereNume);
			this->tara = aux;
			file.read((char*)&nrLitereNume, sizeof(int));
			this->nume= new char[nrLitereNume + 1];
			for (int i = 0; i < nrLitereNume; i++)
			{
				file.read((char*)&this->nume[i], sizeof(char));
			}
			this->nume[nrLitereNume] = '\0';
			file.read((char*)&this->controlSecuritate, sizeof(bool));
			file.read((char*)&this->nrDocuri, sizeof(int));
		}

		//redefinire 
		void printTara()
		{
			cout << "tara de care apartine portul militar este: " << this->tara << endl;
			cout << " clasa PortMilitar nu mai este clasa abstracta" << endl;
		}
		void printNrDocuri()
		{
			cout << "portul militar are : " << this->nrDocuri << endl;
			cout << "clasa PortMilitar nu mai este clasa abstracta" << endl;
		}
		void printPortMilitar()
		{
			cout << this->tara << endl;
			cout << this->nume << endl;
			cout << this->controlSecuritate << endl;
			cout << this->nrDocuri;
		}
	};

	class Nava {
		const int id;
		string denumire;
		int capacitate;
		int nrEchipaj;
		float* pret;
		static int contor;
		static float TVA;

	public:

		//Constructorul fara parametrii
		Nava() :id(contor++)
		{
			this->denumire = "Regina Maria";
			this->capacitate = 150;
			this->nrEchipaj = 0;
			this->pret = NULL;
		}

		//Constructorul cu doi parametri
		Nava(string denumire, int capacitate) :id(contor++)
		{
			this->denumire = denumire;
			this->capacitate = capacitate;
			this->nrEchipaj = 0;
			this->pret = NULL;
		}

		//Constructorul cu toti parametrii
		Nava(string denumire, int capacitate, int nrEchipaj, float* pret) :id(contor++)
		{
			this->denumire = denumire;
			this->capacitate = capacitate;
			this->nrEchipaj = nrEchipaj;
			this->pret = new float[this->nrEchipaj];
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				this->pret[i] = pret[i];
			}

		}

		~Nava()
		{
			if (this->pret != NULL)
			{
				delete[]this->pret;

			}
		}

		void afisare()
		{
			cout << "Denumirea navei este: " << this->denumire << " ,are o capacitate de : " << this->capacitate << " ,are echipaj format din " << this->nrEchipaj << " si are pretul de:  ";
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				cout << this->pret[i] << " ";

			}
			cout << "Prajitura are TVA-ul: " << this->TVA;
			cout << endl;

		}

		static void setTVA(float TVA)
		{
			Nava::TVA = TVA;
		}

		const int getId()
		{
			return this->id;
		}
		string getDenumire()
		{
			return this->denumire;
		}
		int getCapacitate()
		{
			return this->capacitate;
		}
		float getNrEchipaj()
		{
			return this->nrEchipaj;
		}
		float* getPret()
		{
			return this->pret;
		}

		void setDenumire(string denumireNoua)
		{
			this->denumire = denumireNoua;
		}
		void setCapacitate(int capacitateNoua)
		{
			this->capacitate = capacitateNoua;
		}
		void setEchipaj(int nrEchipajNou, float* pretNou)
		{
			this->nrEchipaj = nrEchipajNou;
			if (this->pret != NULL)
			{
				delete[]this->pret;

			}
			this->pret = new float[this->nrEchipaj];
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				this->pret[i] = pretNou[i];
			}
		}

		//Constructorul de copiere
		Nava(const Nava& n) :id(contor++)
		{
			this->denumire = n.denumire;
			this->capacitate = n.capacitate;
			this->nrEchipaj = n.nrEchipaj;
			this->pret = new float[this->nrEchipaj];
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				this->pret[i] = n.pret[i];
			}
		}

		static float getTVA() {
			return Nava::TVA;
		}

		//Operatorul<<
		friend ostream& operator<<(ostream& out, Nava& n)
		{
			cout << "Id: " << n.id << endl;
			cout << "Denumire: " << n.denumire << endl;
			cout << "capacitate: " << n.capacitate << endl;
			cout << "nr Echipaj: " << n.nrEchipaj << endl;
			cout << "Pret: " << endl;
			for (int i = 0; i < n.nrEchipaj; i++)
			{
				cout << n.pret[i] << endl;
			}
			return out;
		}

		//Operatorul>>
		friend istream& operator>>(istream& in, Nava& n)
		{
			delete[]n.pret;
			in >> n.denumire;
			cout << endl;
			in >> n.capacitate;
			cout << endl;
			in >> n.nrEchipaj;
			cout << endl;
			n.pret = new float[n.nrEchipaj];
			for (int i = 0; i < n.nrEchipaj; i++)
			{
				in >> n.pret[i];
			}
			return in;
		}

		//Operatorul=
		Nava& operator=(const Nava& n)
		{
			if (this->pret != NULL)
			{
				delete[]this->pret;
			}
			this->denumire = n.denumire;
			this->capacitate = n.capacitate;
			this->nrEchipaj = n.nrEchipaj;
			this->pret = new float[this->nrEchipaj];
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				this->pret[i] = n.pret[i];
			}
			return *this;
		}

		//Operatorul index []
		float operator[](int poz)
		{
			if (poz >= 0 && poz < this->nrEchipaj)
			{
				return this->pret[poz];
			}
			else
			{
				return 0;
			}
		}

		//Operatorul functie ()
		void operator()(int valoare)
		{
			this->capacitate = this->capacitate + valoare;
		}

		//Operatorul ++ preincrementare
		Nava& operator++()
		{
			this->capacitate++;
			return *this;
		}

		//postincrementare
		Nava& operator++(int)
		{
			Nava copie = *this;
			this->capacitate++;
			return copie;
		}
		//fisiere text
		friend ofstream& operator<<(ofstream& file,	Nava& n)
		{
			file <<n.denumire << endl;
			file <<n.capacitate << endl;
			file << n.nrEchipaj << endl;
			for (int i = 0; i < n.nrEchipaj; i++)
			{
				file << n.pret[i] << endl;
			}
			return file;
		}

		friend ifstream& operator>>(ifstream& file, Nava& n)
		{
			delete[]n.pret;
			file >> n.denumire;
			file >> n.capacitate;
			file >> n.nrEchipaj;
			n.pret = new float[n.nrEchipaj];
			for (int i = 0; i < n.nrEchipaj; i++)
			{
				file >> n.pret[i];
			}
			return file;
		}

		//fisiere binare
		void scriereBinar(fstream& file)
		{
			int nrLitereDenumire = this->denumire.size();
			file.write((char*)&nrLitereDenumire, sizeof(int));
			file.write(this->denumire.c_str(), nrLitereDenumire);
			file.write((char*)&this->capacitate, sizeof(int));
			file.write((char*)&this->nrEchipaj, sizeof(int));
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				file.write((char*)&this->pret[i], sizeof(float));
			}
		}

		void citireBinar(fstream& file)
		{
			delete[]this->pret;
			int nrLitereDenumire;
			file.read((char*)&nrLitereDenumire, sizeof(int));
			string aux;
			aux.resize(nrLitereDenumire);
			file.read((char*)aux.c_str(), nrLitereDenumire);
			this->denumire = aux;
			file.read((char*)&this->capacitate, sizeof(int));
			file.read((char*)&this->nrEchipaj, sizeof(int));
			this->pret = new float[this->nrEchipaj];
			for (int i = 0; i < this->nrEchipaj; i++)
			{
				file.read((char*)&this->pret[i], sizeof(float));
			}
		}


	};

	int PortMaritim::contor = 1;
	float PortMaritim::TVA = 0.19;
	int Nava::contor = 1;
	float Nava::TVA = 0.19;
	int PortMilitar::contor = 1;
	float PortMilitar::gravitatie = 9.8;
	// Clasa de bază abstractă pentru navă de război
	class NavaRazboi {
	public:
		virtual ~NavaRazboi() {}

		// Metode virtuale pure pentru funcționalitățile specifice unei nave de război
		virtual void ataca() = 0;
		virtual void activeazaScut() = 0;
		virtual void afiseazaStare() const = 0;
	};

	// Clasa derivată pentru o navă de război specifică
	class NavaRazboiTerestra : public NavaRazboi {
	private:
		int putereAtac;
		bool scutActivat;

	public:
		NavaRazboiTerestra() : putereAtac(50), scutActivat(false) {}

		// Implementare a metodelor virtuale pure din clasa de bază
		void ataca() override {
			if (scutActivat) {
				std::cout << "Atac respins de scut." << std::endl;
			}
			else {
				std::cout << "Atacul cu putere " << putereAtac << std::endl;
			}
		}

		void activeazaScut() override {
			scutActivat = true;
			std::cout << "Scut activat." << std::endl;
		}

		void afiseazaStare() const override {
			std::cout << "Stare Nava de Razboi Terestra - Atac: " << putereAtac;
			std::cout << ", Scut activat: " << (scutActivat ? "Da" : "Nu") << std::endl;
		}
	};


	class TaraPortuara
	{ 
		int nrPorturi;
		PortMilitar* vectorPorturiMilitare;
	

	public:

	


			//Constructor fara parametrii
			TaraPortuara()
			{
				this->nrPorturi = 0;
				this->vectorPorturiMilitare = NULL;
			}


			//Destructor
			~TaraPortuara()
			{
				if (this->vectorPorturiMilitare != NULL)
				{
					delete[]this->vectorPorturiMilitare;
				}
			}


			//Getteri si Setteri
			int getNrPorturi()
			{
				return this->nrPorturi;
			}
			PortMilitar* getPortMilitar()
			{
				return this->vectorPorturiMilitare;
			}

			

			
		};

		class Submarin :public PortMilitar
		{
			float nrSubmarine;

		public:
			Submarin() :PortMilitar()
			{
				this->nrSubmarine = 30;
			}
			Submarin(float nrSubmarine, string tara, const char* nume, bool controlSecuritate, int nrDocuri) :PortMilitar(tara, nume, controlSecuritate, nrDocuri)
			{
				this->nrSubmarine = nrSubmarine;
			}
			friend ostream& operator<<(ostream& out, const Submarin& sm)
			{
				out << (PortMilitar&)sm;
				out << sm.nrSubmarine;
				return out;
			}
			float getNrSubmarine()
			{
				return this->nrSubmarine;
			}
			void setNrSubmarine(float nrSubmarine)
			{
				this->nrSubmarine = nrSubmarine;
			}
			Submarin(const Submarin& sm) :PortMilitar(sm)
			{
				this->nrSubmarine = sm.nrSubmarine;
			}
			Submarin& operator=(const Submarin& sm)
			{
				PortMilitar::operator=(sm);
				this->nrSubmarine = sm.nrSubmarine;
				return *this;
			}

			~Submarin()
			{

			}
		};

		class PortAvion :public PortMilitar
		{
			int nrAvioane;
		public:
			PortAvion() :PortMilitar()
			{
				this->nrAvioane = 10;
			}
			PortAvion(int nrAvioane, string tara, const char* nume, bool controlSecuritate, int nrDocuri) :PortMilitar(tara, nume, controlSecuritate, nrDocuri)
			{
				this->nrAvioane = nrAvioane;
			}
			friend ostream& operator<<(ostream& out, const PortAvion& pa)
			{
				out << (PortMilitar&)pa;
				out << pa.nrAvioane;
				return out;
			}
			int getNRavioane()
			{
				return this->nrAvioane;
			}
			void setnrAVIOANE(int nrAvioaneNOU)
			{
				this->nrAvioane = nrAvioaneNOU;
			}
			PortAvion(const PortAvion& pa) :PortMilitar(pa)
			{
				this->nrAvioane = pa.nrAvioane;
			}
			PortAvion& operator=(const PortAvion& pa)
			{
				PortMilitar::operator=(pa);
				this->nrAvioane = pa.nrAvioane;
				return *this;
			}

			~PortAvion()
			{

			}
		};

	



		int main()
		{

			PortMaritim f;
			PortMaritim f1("CONSTANTA", 120);
			float vector1[] = { 20.5,19,10 };
			PortMaritim f2("ROTTERDAM", 150, 3, vector1);
			float vector3[] = { 4.9,6,10,5.6 };
			PortMaritim f3("SINGAPORE", 210, 4, vector3);

			f.afisare();
			cout << endl << endl;
			f1.afisare();
			cout << endl << endl;
			f2.afisare();
			cout << endl << endl;


			Nava n;
			Nava n1("Regele Ferdinad", 200);
			float vector2[] = { 12.5,53.3,22,110 };
			Nava n2("stelarion", 32, 44, vector2);
			float vector100[] = { 232,145,6.2,11,12,10.7 };
			Nava n3("LUNA", 24, 62, vector100);

			n.afisare();
			cout << endl << endl;
			n1.afisare();
			cout << endl << endl;
			n2.afisare();
			cout << endl << endl;

			PortMaritim::setTVA(0.5);
			f.afisare();
			cout << endl << endl;
			f1.afisare();
			cout << endl << endl;
			f2.afisare();
			cout << endl << endl;

			Nava::setTVA(0.4);
			n.afisare();
			cout << endl << endl;
			n1.afisare();
			cout << endl << endl;
			n2.afisare();
			cout << endl << endl;

			cout << "locatie: " << f.getLocatie() << endl;
			cout << "capacitate: " << f.getCapacitate() << endl;
			cout << "Numar container: " << f.getNrContainere() << endl;
			cout << "Pret pentru fiecare container: " << endl;
			for (int i = 0; i < f.getNrContainere(); i++)
			{
				cout << f.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;

			cout << "locatie: " << f1.getLocatie() << endl;
			cout << "capacitate: " << f1.getCapacitate() << endl;
			cout << "Numar containere: " << f1.getNrContainere() << endl;
			cout << "Pret pentru fiecare container: " << endl;
			for (int i = 0; i < f1.getNrContainere(); i++)
			{
				cout << f1.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;

			f3.setLocatie("Shanghai");
			f3.setCapacitate(2000);
			float vector6[] = { 45,8.3 };
			f3.setContainere(2, vector6);

			cout << "Locatie: " << f3.getLocatie() << endl;
			cout << "Suprafata: " << f3.getCapacitate() << endl;
			cout << "Numar containere: " << f3.getNrContainere() << endl;
			cout << "Pret pentru fiecare produs: " << endl;
			for (int i = 0; i < f3.getNrContainere(); i++)
			{
				cout << f3.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;

			PortMaritim f10;
			cout << "locatie: " << f10.getLocatie() << endl;
			cout << "capacitate: " << f10.getCapacitate() << endl;
			cout << "Numar produse: " << f10.getNrContainere() << endl;
			cout << "Pret pentru fiecare produs: " << endl;
			for (int i = 0; i < f10.getNrContainere(); i++)
			{
				cout << f10.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;
			cout << "Locatie: " << f10.getLocatie() << endl;
			cout << "capaciatate: " << f10.getCapacitate() << endl;
			cout << "Numar containere: " << f10.getNrContainere() << endl;
			cout << "Pret pentru fiecare container: " << endl;
			for (int i = 0; i < f10.getNrContainere(); i++)
			{
				cout << f10.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;

			cout << f3.mediePreturiContainere() << endl << endl;
			cout << f10.mediePreturiContainere() << endl << endl;


			cout << f1.getTVA() << endl << endl;
			cout << n1.getTVA() << endl << endl;


			cout << "Operator=" << endl << endl;
			cout << endl << endl;
			cout << "locatie: " << f10.getLocatie() << endl;
			cout << "capacitate: " << f10.getCapacitate() << endl;
			cout << "Numar containere: " << f10.getNrContainere() << endl;
			cout << "Pret pentru fiecare container: " << endl;
			for (int i = 0; i < f10.getNrContainere(); i++)
			{
				cout << f10.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;
			f10 = f3;
			cout << "locatie: " << f3.getLocatie() << endl;
			cout << "Suprafata: " << f3.getCapacitate() << endl;
			cout << "Numar produse: " << f3.getNrContainere() << endl;
			cout << "Pret pentru fiecare produs: " << endl;
			for (int i = 0; i < f3.getNrContainere(); i++)
			{
				cout << f3.getPret()[i] << ";" << endl;
			}
			cout << endl << endl;

			cout << "Operator<<" << endl << endl;
			cout << f3 << endl << endl;
			cout << f10 << endl << endl;

			cout << "Operatorul []" << endl << endl;
			cout << f10[0] << endl << endl;
			cout << f2[-2] << endl << endl;

			cout << "Operatorul de comparatie" << endl << endl;
			cout << f3.getNrContainere() << endl;
			cout << f10.getNrContainere() << endl;
			cout << (f3 >= f10) << endl << endl;

			cout << "Operatorul de autoasignare += " << endl << endl;
			cout << f10 << endl << endl;
			f10 += 12.6;
			cout << f10 << endl << endl;

			cout << "Operatorul<<" << endl << endl;
			cout << n3 << endl << endl;
			cout << n2 << endl << endl;


			cout << "Operatorul=" << endl << endl;
			cout << n3 << endl << endl;
			n2 = n3;
			cout << n2 << endl << endl;

			cout << "Operatorul()" << endl << endl;
			cout << n1 << endl << endl;
			n3(3);
			cout << n3 << endl << endl;

			cout << "Operator<<" << endl << endl;
			cout << n2 << endl << endl;
			cout << n1 << endl << endl;

			//Vectori de obiecte
			PortMaritim* vectorPorturi = new PortMaritim[4];
			vectorPorturi[0] = f1;
			vectorPorturi[1] = f2;
			vectorPorturi[2] = f3;
			cout << "Afisare vector porturi" << endl << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << vectorPorturi[i] << endl << endl;
			}

			Nava* vectorNave = new Nava[3];
			vectorNave[0] = n2;
			vectorNave[1] = n1;
			vectorNave[2] = n3;
			cout << "Afisare vector nave" << endl << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << vectorNave[i] << endl << endl;
			}

			//Matricea de obiecte
			PortMaritim* matriceMaritima = new PortMaritim[3];
			matriceMaritima[0] = f1;
			matriceMaritima[1] = f2;
			matriceMaritima[2] = f3;
			if (matriceMaritima) {
				delete[]matriceMaritima;
			}

			Nava* navadeRazboi = new Nava[3]{ n1,n2,n3 };
			delete[]navadeRazboi;


			Nava** nave2 = new Nava * [3];
			nave2[0] = &n1;
			nave2[1] = &n2;
			nave2[2] = &n3;

			delete[]nave2;


			Nava* pointerNava = new Nava();
			Nava* vector = new Nava[5];


			Nava** matrice = new Nava * [5];
			for (int i = 0; i < 5; i++) {
				matrice[i] = new Nava[5];
			}

			cout << *pointerNava;




			//dezalocare
			delete pointerNava;
			delete[]vector;
			delete[]matrice;

			bool alternativa = true;

			//!variabila;

			bool var1 = !alternativa;
			cout << endl << endl;
			cout << "Clasa Nave" << endl << endl;
			Nava vectorMilitare[] = { n1,n2,n3 };

			cout << "Apelare operatorul<<" << endl << endl;
			cout << n1 << endl << endl << endl;
			cout << n2 << endl << endl << endl;
			cout << n3 << endl << endl << endl;

			cout << "Apelare constructor de copiere" << endl << endl;

			Nava n4 = n2;
			cout << n4 << endl << endl;

			cout << "Apelare operatorul=" << endl << endl;

			n3 = n4;
			cout << n3 << endl << endl;

			cout << "Apelare operatorul[]" << endl << endl;

			cout << n2[0] << endl << endl;


			cout << "FISIERE" << endl << endl;
			ofstream file1("PortMARITIM.txt", ios::out);
			file1 << f1 << endl;
			file1.close();
			ifstream file2("PortMARITIM.txt", ios::in);
			file2 >> f;
			file2.close();

			fstream file3("PortMARITIM.bin", ios::binary | ios::out);
			f1.scriereBinar(file3);
			file3.close();
			fstream file4("PortMARITIM.bin", ios::binary | ios::in);
			f.citireBinar(file4);
			file4.close();

			ofstream file5("Nava.txt", ios::out);
			file5 << n3 << endl;
			file5.close();
			ifstream file6("Nava.txt", ios::in);
			file6 >> n;
			file6.close();

			fstream file7("Nava.bin", ios::binary | ios::out);
			n1.scriereBinar(file7);
			file7.close();
			fstream file8("Nava.bin", ios::binary | ios::in);
			n.citireBinar(file8);
			file8.close();
			cout << endl << endl;

			cout << n << endl << endl;
			cout << n1 << endl << endl;
			cout << n2 << endl << endl;
			cout << n3 << endl << endl;
			NavaRazboi* navaRazboi = new NavaRazboiTerestra();

			navaRazboi->ataca();
			navaRazboi->activeazaScut();
			navaRazboi->afiseazaStare();

			// elibereaza memoria alocată dinamic
			delete navaRazboi;
			return 0;
		}
	

