#ifndef PANTALLA_H
#define PANTALLA_H
#include "Nave.h"
#include "Personaje.h"
#include "Meteorito.h"
#include "Estado.h"

class Pantalla:public Estado {
	Personaje* nave;
	Personaje* meteorito;
	Personaje* enemigo1;
	int posY;
public:
	Pantalla(int tamano, int pun);
	~Pantalla();
	
	void VerHeader();
	void VerPantalla();
	void VerVidasYPuntos();
	
	bool TerminoPartida() override;
	
	void actualizar() override;
	bool hayColision(Personaje* obejto1, Personaje* objeto2);

};

#endif

