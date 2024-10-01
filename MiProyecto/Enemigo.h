#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

class Enemigo: public Personaje {
public:
	Enemigo(int posX, int posY, int vida, int color, string objet);
	
	void mover() override;
};

#endif

