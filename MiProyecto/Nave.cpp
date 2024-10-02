#include "Nave.h"
#include "conio2.h"
#include <vector>
#include <iostream>
using namespace std;

Nave::Nave(int posX, int posY, int vida, int color, string objet, int velocidad):Personaje(posX, posY, vida,color, objet, velocidad) {
	
}
void Nave::mover() {
	if (kbhit()) {
		int tecla = getch();
		
		switch (tecla) {
		case 'a':  // izquierda
			if (x> 11) x--;
			break;
		case 'd':  // derecha
			if (x < 34) x++;
			break;
		case 'w':  // arriba
			if (y > 6) y--;
			break;
		case 's':  // abajo
			if (y < 17) y++;
			break;
		case 'l':
			disparar();
			break;
		}
	}
}

void Nave::disparar() {
	this->cambiarColor(WHITE);
}


