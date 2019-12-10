#include "Vegpontok.h"
#include "Tarolok.h"

#include <iostream>
#include <fstream>
#include <string>

bool Halozat::save(std::string fajlnev) const
{
	std::ofstream os;
	fajlnev = "Halozatok/" + fajlnev;
	os.open(fajlnev);
	for (int i = 0; i < getLength(); i++)
	{
		os << (*this)[i]->fajlban_nev() << ' ' << (*this)[i]->nev << ' '<< (*this)[i]->teljesitmeny << std::endl;
	}
	os.close();
	std::cout << "Halozat mentve a '" << fajlnev << "' fajlba" << std::endl;
	return true;
}

bool Halozat::load(std::string fajlnev)
{
	clear();
	std::ifstream is;
	fajlnev = "Halozatok/" + fajlnev;
	is.open(fajlnev);
	std::string tipus;
	std::string nev;
	double kapacitas;
	while (is >> tipus)
	{
		if (tipus == (std::string)"Eromu")
		{
			is >> nev;
			if (!is) return false;
			is >> kapacitas;
			if (!is) return false;
			push(new Eromu(nev, kapacitas));
		}
		if (tipus == (std::string)"Fogyaszto")
		{
			is >> nev;
			if (!is) return false;
			is >> kapacitas;
			if (!is) return false;
			push(new Fogyaszto(nev, kapacitas));
		}
		if ((tipus != (std::string)"Eromu") && (tipus != (std::string)"Fogyaszto"))
		{
			std::cerr << "HIBA!!!" << std::endl;
			return false; 
		}
	}
	is.close();
	std::cout << "Halozat betoltve a '" << fajlnev << "' fajlbol" << std::endl;
	return true;
}

bool Halozat::csatlakozas(std::string nev)
{
	for (int i = 0; i < getLength(); i++)
	{
		if ((*this)[i]->nev == nev)
		{
			return ((*this)[i])->csatlakozas(this);
		}
	}
	return false;
}

bool Halozat::lecsatlakozas(std::string nev)
{
	for (int i = 0; i < getLength(); i++)
	{
		if ((*this)[i]->nev == nev)
		{
			return ((*this)[i])->lecsatlakozas(this);
		}
	}
	return false;
}