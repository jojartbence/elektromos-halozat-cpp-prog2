#ifndef MENU_H
#define MENU_H

#include "Vegpontok.h"
#include "Tarolok.h"

#include <iostream>
#include <fstream>
#include <string>

extern Halozat h;
class Halozatmodositas;
class Menu;

class Menu
{
public:
	static void menukiir();
	static void menupontolvas();
	static void halozatbetoltes();
	static void halozatmodositas();
	static void halozatkeszites();
	static void szimulacio();
	static void kilepes();
};

class Halozatmodositas
{
public:
	static void fogyasztohozzaadas();
	static void eromuhozzaadas();
	static void vegponttorles();
	static void halozattorles();
	static void halozatmentes();
};


#endif
