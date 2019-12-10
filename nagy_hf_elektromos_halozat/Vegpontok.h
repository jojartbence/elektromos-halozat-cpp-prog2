#ifndef VEGPONTOK_H
#define VEGPONTOK_H

template <class T>
class Tarolo;
class Halozat;
class Varolista;
class Becsatlakozott;

enum Status { off, varolistan, on };

#include <iostream>
#include <string>

class Vegpont
{
public:
	const std::string nev;
	const double teljesitmeny;
	Status status;

	Vegpont(std::string n, double t) : nev(n), teljesitmeny(t), status(off) {}
	void kiir() const { std::cout << nev << ' ' << teljesitmeny << " watt" << std::endl; };
	virtual std::string fajlban_nev() = 0;

	virtual bool csatlakozas(Halozat* h) = 0;
	virtual bool lecsatlakozas(Halozat* h) = 0;
};

class Eromu : public Vegpont
{
public:
	Eromu(std::string n, double t) : Vegpont(n, t) {}
	std::string fajlban_nev() { return "Eromu"; }

	bool csatlakozas(Halozat* h);
	bool lecsatlakozas(Halozat* h);
};

class Fogyaszto : public Vegpont
{
public:
	std::string tipus;

	Fogyaszto(std::string n, double t) : Vegpont(n, t) {}
	std::string fajlban_nev() { return "Fogyaszto"; }

	bool csatlakozas(Halozat* h);
	bool lecsatlakozas(Halozat* h);
};

#endif