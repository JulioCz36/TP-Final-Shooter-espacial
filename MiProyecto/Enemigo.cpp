#include "Enemigo.h"
#include "Personaje.h"

Enemigo::Enemigo(int posX, int posY, int vida, int color, string objet, int velocidad):Personaje(posX, posY, vida,color, objet, velocidad){
	if (posX == 12) {
		direccion = 1; 
	} else if (posX == 36) {
		direccion = -1;
	}
}
void Enemigo::mover() {
	x += direccion;
}
bool Enemigo::disparar() {}



