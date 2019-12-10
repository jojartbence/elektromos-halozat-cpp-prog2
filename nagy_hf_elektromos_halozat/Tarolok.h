#ifndef TAROLOK_H
#define TAROLOK_H

#include <iostream>
#include <string>

class Vegpont;
class Eromu;
class Fogyaszto;

// általános tároló, az összes tárolót ebbõl az osztályból származtatjuk
// MÛKÖDIK
template <class T>
class Tarolo
{
	T* head;
	int n;
public:
	Tarolo() : n(0), head(NULL) {}
	Tarolo(Tarolo<T> const & t)
	{
		n = t.getLength();
		head = new T[n];
		for (int i = 0; i < n; i++)
		{
			head[i] = t[i];
		}
	}
	Tarolo operator= (Tarolo<T> const &t)
	{
		if (this == t) return *this;
		this->clear();
		return Tarolo(t);
	}

	int getLength() const { return n; }
	void push(T t)
	{
		T* temp=new T[n + 1];
		for (int i = 0; i < n; i++)
		{
			temp[i] = head[i];
		}
		delete[] head;
		head = temp;
		head[n] = t;
		n++;
	}
	T operator[] (const int i) const
	{
		if (i>=0 && i<n) return head[i];
		else
		{
			std::cout << "ERROR";
			return T();
		}
	}
	bool pop(const int j)
	{
		if (j < 0 || j >= n) return false;
		if (n > 0)
		{
			T* temp = new T[n - 1];
			for (int i = 0; i < j; i++)
			{
				temp[i] = head[i];
			}
			for (int i = j; i < n - 1; i++)
			{
				temp[i] = head[i + 1];
			}
			delete[] head;
			head = temp;
			n--;
		}
		if (n == 0)
		{
			delete[] head;
			head = NULL;
			n = 0;
		}
		return true;
	}
	void clear()
	{
		while (n != 0)
		{
			this->pop(0);
		}
	}
	virtual void kiir() const
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << (*this)[i] << std::endl;
		}
	}

	virtual ~Tarolo() { this->clear(); }

	int listabankeres(T const pvegpont) const
	{
		for (int i = 0; i < getLength(); i++)
		{
			if ((*this)[i] == pvegpont) return i;
		}
		return -1;
	}
};

//a fogyasztók várólistája, az újakat a sor végére pakoljuk, és az eleje felõl veszünk ki
class Varolista : public Tarolo<Fogyaszto*>
{
public:
	Varolista() : Tarolo() {}
	~Varolista() { this->clear(); }

	void kiir() const
	{
		for (int i = 0; i < this->getLength(); i++)
		{
			(*(*this)[i]).kiir();
		}
	}
};

//a becsatlakozott végpontok listája
class Becsatlakozott : public Tarolo<Vegpont*>
{
public:
	Becsatlakozott() : Tarolo() {}
	void kiir() const
	{
		for (int i = 0; i < this->getLength(); i++)
		{
			(*(*this)[i]).kiir();
		}
	}
	~Becsatlakozott() { this->clear(); }
};

//tárolja az összes végpontot
//MÛKÖDIK
class Halozat : public Tarolo<Vegpont*>
{
public:
	double kapacitas;
	
	Halozat() : Tarolo(), kapacitas(0) {}
	void kiir() const
	{
		for (int i = 0; i < this->getLength(); i++)
		{
			(*(*this)[i]).kiir();
		}
	}
	bool save(std::string fajlnev) const;
	bool load(std::string fajlnev);
	~Halozat() { this->clear(); }

	Varolista var;
	Becsatlakozott be;

	bool csatlakozas(std::string nev);
	bool lecsatlakozas(std::string nev);
};

#endif