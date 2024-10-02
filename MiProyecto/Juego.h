#ifndef JUEGO_H
#define JUEGO_H
#include "Estado.h"


class Juego {
	Estado *pantalla;
	bool jugando = false;
public:
	Juego();
	~Juego();
	void jugar();
	void mostrarMenu();
};

#endif

