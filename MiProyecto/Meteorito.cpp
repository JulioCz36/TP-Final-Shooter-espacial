#include "Meteorito.h"
#include <conio2.h>
#include <ctime>

Meteorito::Meteorito(int posX, int posY, int vida, int color, string objet):Personaje(posX, posY, vida,color, objet) {
}

void Meteorito::mover() {
	 y++;
	
	if (y > 25) {
		y = 0; 
		x = rand() % 79 + 1;
	}
}

