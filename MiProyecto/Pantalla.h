#ifndef PANTALLA_H
#define PANTALLA_H
#include "Nave.h"
#include "Personaje.h"
#include "Meteorito.h"
#include "Estado.h"
#include "Enemigo.h"

class Pantalla:public Estado {
	Personaje* nave;
	Personaje* meteorito;
	Personaje* enemigo1;
	Personaje* enemigo2;
	Personaje* enemigo3;
public:
	Pantalla(int tamano, int pun);
	~Pantalla();
	
	void VerHeader();
	void VerPantalla();
	void VerVidasYPuntos();
	
	bool TerminoPartida() override;
	
	void actualizar() override;
	Personaje* GenerarEnemigos(int color, int velocidad);
	Personaje* GenerarMetioritos();
	bool hayColision(Personaje* obejto1, Personaje* objeto2);

};

#endif

