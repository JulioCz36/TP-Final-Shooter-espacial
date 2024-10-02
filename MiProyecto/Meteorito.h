#ifndef METEORITO_H
#define METEORITO_H
#include <conio2.h>
#include <cstdlib>
#include <ctime>
#include "Personaje.h"
using namespace std;

class Meteorito: public Personaje {
public:
	Meteorito(int posX, int posY, int vida, int color, string objet, int velocidad);
	
	void mover() override;
	bool disparar()override;
};

#endif

