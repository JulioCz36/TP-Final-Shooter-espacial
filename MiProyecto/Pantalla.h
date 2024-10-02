#ifndef PANTALLA_H
#define PANTALLA_H
#include "Nave.h"
#include "Personaje.h"
#include "Meteorito.h"

class Pantalla {
	Personaje* nave;
	Personaje* meteorito;
	int puntos;                     
	int tamanoPantalla;
public:
	Pantalla(int tamano);
	
	void VerHeader();
	void VerPantalla();
	void VerVidasYPuntos();
	
	void actualizar() {
		// Mostrar interfaz
		VerHeader();
		VerPantalla();
		nave->actualizar();
		meteorito->actualizar();
		if (meteorito->VerY() == 17) {
			meteorito->borrar();
			delete meteorito;
			int randomX = rand() % (34 - 11 + 1) + 11;
			meteorito=new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
		}
		VerVidasYPuntos();
		
		// Incrementar puntos (por ejemplo, por cada ciclo de juego)
		puntos++;
	}

};

#endif

