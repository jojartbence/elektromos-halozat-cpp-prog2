#include "Vegpontok.h"
#include "Tarolok.h"
#include "Menu.h"

#include <iostream>
#include <fstream>
#include <string>

extern Halozat h;

void Menu::menukiir()
{
	std::cout << "1: Halozat betoltese fajlbol" << std::endl;
	std::cout << "1: Meglevo halozat modositasa" << std::endl;
	std::cout << "2: Uj halozat keszitese" << std::endl;
	std::cout << "3: Szimulacio betoltott halozattal" << std::endl;
	std::cout << "4: Kilepes a programbol" << std::endl;
	menupontolvas();
}
void Menu::menupontolvas()
{
	int m = 0;
	std::cin >> m;
	if (m == 1) halozatbetoltes();
	if (m == 2) halozatmodositas();
	if (m == 3) halozatkeszites();
	if (m == 4) szimulacio();
	if (m == 5) kilepes();
	if (m < 1 || m>5) std::cerr << "1-5-ig irj be egy szamot!" << std::endl;
}
void Menu::halozatbetoltes()
{
	std::cout << std::endl << "A betoltheto halozatok:" << std::endl;
	std::system("dir Halozatok /B");
	std::cout << "Ird be a fajl nevet, amelyiket be szeretned tolteni!" << std::endl;
	std::string nev;
	std::cin >> nev;
	std::cout << std::endl;
	h.load(nev);
	h.kiir();
	std::cout << std::endl;
	menukiir();
}
void Menu::halozatmodositas()
{
	std::cout << std::endl << "Tolts be egy halozatot!" << std::endl;
	std::cout << "A betoltheto halozatok:" << std::endl;
	std::system("dir Halozatok /B");
	std::cout << "Ird be a fajl nevet, amelyiket be szeretned tolteni!" << std::endl;
	std::string nev;
	std::cin >> nev;
	std::cout << std::endl;
	h.load(nev);
	h.kiir();
	std::cout << std::endl;
	std::cout << "Mit szeretnel csinalni a halozattal?" << std::endl;
	std::cout << "1: Uj fogyaszto hozzaadasa" << std::endl;
	std::cout << "2: Uj eromu hozzadasa" << std::endl;
	std::cout << "3: Fogyaszto/eromu torlese a halozatbol" << std::endl;
	std::cout << "4: A halozat torlese" << std::endl;
	std::cout << "5: Az elkeszult halozat mentese" << std::endl;
	int m = 0;
	std::cin >> m;
	if (m == 1) Halozatmodositas::fogyasztohozzaadas();
	if (m == 2) Halozatmodositas::eromuhozzaadas();
	if (m == 3) Halozatmodositas::vegponttorles();
	if (m == 4) Halozatmodositas::halozattorles();
	if (m == 5) Halozatmodositas::halozatmentes();
	if (m < 0 || m>5) std::cerr << "1-5-ig irj be egy szamot!" << std::endl;
	menukiir();
}
void Menu::halozatkeszites()
{

}

void Menu::szimulacio()
{

}
void Menu::kilepes()
{
	h.clear();
	h.var.clear();
	h.be.clear();
}


void Halozatmodositas::fogyasztohozzaadas()
{
	std::string nev;
	int teljesitmeny;
	std::cout << "Ird be a fogyaszto nevet: ";
	std::cin >> nev;
	std::cout << "Ird be a teljesitmenyet: ";
	std::cin >> teljesitmeny;
	h.push(new Fogyaszto(nev, teljesitmeny));
	Menu::halozatmodositas();
}
void Halozatmodositas::eromuhozzaadas()
{
	std::string nev;
	int teljesitmeny;
	std::cout << "Ird be az eromu nevet: ";
	std::cin >> nev;
	std::cout << "Ird be a teljesitmenyet: ";
	std::cin >> teljesitmeny;
	if (!std::cin)
	{
		std::cerr << "HIBA!!! Az eromu neveben nem lehet szokoz, ill. szamot irj be telejsitmenynek!" << std::endl;
		eromuhozzaadas();
	}
	h.push(new Eromu(nev, teljesitmeny));
	Menu::halozatmodositas();
}
void Halozatmodositas::vegponttorles()
{

}
void Halozatmodositas::halozattorles()
{

}
void Halozatmodositas::halozatmentes()
{

}

