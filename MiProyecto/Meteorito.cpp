#include "Meteorito.h"
#include <conio2.h>
#include <ctime>

Meteorito::Meteorito(int posX, int posY, int vida, int color, string objet, int velocidad):Personaje(posX, posY, vida,color, objet, velocidad) {
}

void Meteorito::mover() {
	y++;
	if (y > 17) {
		y = 6;
	}
}

