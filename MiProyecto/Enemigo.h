#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

class Enemigo: public Personaje {
	int direccion;
public:
	Enemigo(int posX, int posY, int vida, int color, string objet, int velocidad);
	
	void mover() override;
};

#endif

