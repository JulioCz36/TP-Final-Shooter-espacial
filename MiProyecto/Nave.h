#ifndef NAVE_H
#define NAVE_H

#include "conio2.h"
#include <conio.h>
#include <vector>
#include <ctime>
#include "Personaje.h"
using namespace std;

class Nave: public Personaje {
	bool disparoActual;
public:
	Nave(int posX, int posY, int vida, int color, string objet, int velocidad);
	
	bool disparar();
	void mover() override;
};

#endif

