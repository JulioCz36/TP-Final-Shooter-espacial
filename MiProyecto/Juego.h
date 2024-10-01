#ifndef JUEGO_H
#define JUEGO_H
#include "Personaje.h"
#include "Nave.h"
#include "Meteorito.h"
#include "Enemigo.h"

class Juego {
	Personaje *nave;
	Personaje *enemigo;
	Personaje *meteorito;
public:
	Juego();
	void jugar(){
		while(true){
		nave->actualizar();
		meteorito->actualizar();
		enemigo->actualizar();
		}
	}

};

#endif

