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
		
		// Verificar colisión
		if (hayColision(nave, meteorito)) {
			nave->perderVida();
			
			meteorito->borrar();
			delete meteorito;
			int randomX = rand() % (34 - 11 + 1) + 11;
			meteorito=new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
			
		}
		
		//Destrulle si llega al borde
		if (meteorito->VerY() >= 18) {
			meteorito->borrar();
			delete meteorito;
			int randomX = rand() % (34 - 11 + 1) + 11;
			meteorito=new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
		}
		
		VerVidasYPuntos();
		
		// Incrementar puntos (por ejemplo, por cada ciclo de juego)
		puntos++;
	}
	bool hayColision(Personaje* obejto1, Personaje* objeto2);

};

#endif

