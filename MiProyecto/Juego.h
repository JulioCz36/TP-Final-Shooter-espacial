#ifndef JUEGO_H
#define JUEGO_H
#include "Personaje.h"
#include "Nave.h"
#include "Meteorito.h"
#include "Enemigo.h"
#include "Pantalla.h"

class Juego {
	Pantalla pantalla;
	bool jugando = false;
public:
	Juego();
	void jugar() {
		mostrarMenu();
		while (true) {
			if (kbhit()) {
				int tecla = getch();
				switch (tecla) {
				case 'p':
					jugando = true;
					clrscr();
					while (jugando) {
						pantalla.actualizar();
					}
					break;
				case 27:					
					return ; 
				}
			}
		}
	}
	void mostrarMenu();

};

#endif

