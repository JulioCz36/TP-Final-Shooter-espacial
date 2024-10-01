#include "Nave.h"
#include "conio2.h"
#include <vector>
#include <iostream>
using namespace std;

Nave::Nave(int posX, int posY, int vida, int color, string objet):Personaje(posX, posY, vida,color, objet) {
	
}
void Nave::mover() {
	if (kbhit()) {
		int tecla = getch();
		
		switch (tecla) {
		case 'a':  // izquierda
			if (x> 1) x--;
			break;
		case 'd':  // derecha
			if (x < 79) x++;
			break;
		case 'w':  // arriba
			if (y > 1) y--;
			break;
		case 's':  // abajo
			if (y < 25) y++;
			break;
		}
	}
}

void Nave::disparar() {
}


