#include "Enemigo.h"
#include "Personaje.h"

Enemigo::Enemigo(int posX, int posY, int vida, int color, string objet, int velocidad):Personaje(posX, posY, vida,color, objet, velocidad){
	if (posX == 12) {
		direccion = 1;  // Va a la derecha
	} else if (posX == 36) {
		direccion = -1; // Va a la izquierda
	}
}
void Enemigo::mover() {
	x += direccion;
}



