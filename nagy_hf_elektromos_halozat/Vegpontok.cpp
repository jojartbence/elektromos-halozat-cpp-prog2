#include "Vegpontok.h"
#include "Tarolok.h"

#include <iostream>
#include <fstream>
#include <string>

bool Eromu::csatlakozas(Halozat* h)
{
	if (status == off)
	{
		h->be.push(this);
		h->kapacitas += teljesitmeny;
		std::cout << "Eromu csatlakoztatva: ";
		kiir();
		status = on;
		
		// várólista vizsgálata, hogy valakit vissza tudunk -e csatlakoztatni a megnövekedett kapacitás miatt
		for (int i = 0; i < h->var.getLength(); i++)
		{
			if (h->var[i]->teljesitmeny < h->kapacitas)
			{
				Fogyaszto *fogyaszto = h->var[i];
				h->var.pop(h->var.listabankeres(fogyaszto));
				h->be.push(fogyaszto);
				std::cout << "Fogyaszto a varolistarol csatlakoztatva: ";
				fogyaszto->kiir();
				fogyaszto->status = on;
				h->kapacitas -= fogyaszto->teljesitmeny;
				i--;
			}
		}
		return true;
	}
	if (status == varolistan)
	{
		std::cerr << "HIBA!!!";
		return false;
	}
	if (status == on)
	{
		std::cout << "Eromu mar csatlakoztatva volt: ";
		kiir();
		return true;
	}
}

bool Eromu::lecsatlakozas(Halozat* h)
{
	if (status == off)
	{
		std::cout << "Eromu mar le volt csatlakoztatva: ";
		kiir();
		return true;
	}
	if (status == varolistan)
	{
		std::cerr << "HIBA!!!";
		return false;
	}
	if (status == on)
	{
		h->be.pop(h->be.listabankeres(this));
		h->kapacitas -= teljesitmeny;
		std::cout << "Eromu lecsatlakoztatva: ";
		kiir();
		status = off;

		// becsatlakozottak vizsgálata, hogy valakit le kell -e csatlakoztatni a lecsökkent kapacitás miatt, és átrakni a várólistára
		int i = 0;
		while (h->kapacitas < 0)
		{
			Fogyaszto* fogyaszto = dynamic_cast<Fogyaszto*>(h->be[i]);
			if ((fogyaszto->fajlban_nev()) == (std::string)"Eromu")
			{
				i++;
			}
			if (fogyaszto->fajlban_nev() == (std::string)"Fogyaszto")
			{
				h->be.pop(i);
				h->var.push(fogyaszto);
				std::cout << "Fogyaszto lecsatlakoztatva es a varolistara helyezve: ";
				fogyaszto->kiir();
				h->kapacitas += fogyaszto->teljesitmeny;
				fogyaszto->status = varolistan;
			}
			
		}

		return true;
	}
}

bool Fogyaszto::csatlakozas(Halozat* h)
{
	if (status == off)
	{
		if (h->kapacitas < teljesitmeny)
		{
			h->var.push(this);
			std::cout << "Fogyaszto a varolistahoz adva: ";
			kiir();
			status = varolistan;
			return true;
		}
		else
		{
			h->be.push(this);
			std::cout << "Fogyaszto csatlakoztatva: ";
			kiir();
			h->kapacitas -= teljesitmeny;
			status = on;
			return true;
		}
	}
	if (status == varolistan)
	{
		std::cout << "A fogyaszto már a várolistan van: ";
		kiir();
		return true;
	}
	if (status == on)
	{
		std::cout << "A fogyaszto mar csatlakoztatva van: ";
		kiir();
		return true;
	}
}

bool Fogyaszto::lecsatlakozas(Halozat* h)
{
	if (status == off)
	{
		std::cout << "Fogyaszto mar le volt csatlakoztatva: ";
		kiir();
		return true;
	}
	if (status == varolistan)
	{
		h->var.pop(h->var.listabankeres(this));
		std::cout << "Fogyasztó lecsatlakoztatva a varolistarol: ";
		kiir();
		status = off;
		return true;
	}
	if (status == on)
	{
		h->be.pop(h->be.listabankeres(this));
		h->kapacitas += teljesitmeny;
		std::cout << "Fogyaszto lecsatlakoztatva: ";
		kiir();
		status = off;

		// várólista vizsgálata, hogy valakit vissza tudunk -e csatlakoztatni a megnövekedett kapacitás miatt
		for (int i = 0; i < h->var.getLength(); i++)
		{
			if (h->var[i]->teljesitmeny < h->kapacitas)
			{
				Fogyaszto *fogyaszto = h->var[i];
				h->var.pop(h->var.listabankeres(fogyaszto));
				h->be.push(fogyaszto);
				std::cout << "Fogyaszto a varolistarol csatlakoztatva: ";
				fogyaszto->kiir();
				fogyaszto->status = on;
				h->kapacitas -= fogyaszto->teljesitmeny;
				i--;
			}
		}

		return true;
	}
}