#include "Vegpontok.h"
#include "Tarolok.h"
#include "Menu.h"

#include <iostream>
#include <string>

Halozat h;


int main()
{
	Menu::menukiir();

	h.push(new Eromu("Paks", 2000));
	h.push(new Eromu("Szazhalombatta", 1290));
	h.push(new Eromu("Visonta", 950));
	h.push(new Fogyaszto("Bela", 5));
	h.push(new Fogyaszto("Jani", 20));
	h.push(new Fogyaszto("Pityu", 2));
	h.save("Halozat.txt");
	h.csatlakozas("Paks");
	h.csatlakozas("Jani");
	h.csatlakozas("Pityu");
	h.lecsatlakozas("Jani");
	h.lecsatlakozas("Paks");
	h.csatlakozas("Bela");
	h.csatlakozas("Paks");
	h.lecsatlakozas("Paks");
}