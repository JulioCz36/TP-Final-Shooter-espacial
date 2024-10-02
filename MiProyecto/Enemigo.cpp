#include "Enemigo.h"
#include "Personaje.h"

Enemigo::Enemigo(int posX, int posY, int vida, int color, string objet, int velocidad):Personaje(posX, posY, vida,color, objet, velocidad){
	
}
void Enemigo::mover() {
	x++;
	if (x > 25) {
		x = 0; 
		y = rand() % 79 + 1;
	}
}


