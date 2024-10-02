#ifndef JUEGO_H
#define JUEGO_H
#include "Personaje.h"
#include "Nave.h"
#include "Meteorito.h"
#include "Enemigo.h"
#include "Pantalla.h"

class Juego {
	Pantalla pantalla;
public:
	Juego();
	void jugar(){
		while(true){
			pantalla.actualizar();
		}
	}

};

#endif

