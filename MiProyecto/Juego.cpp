#include "Juego.h"

Juego::Juego() {
	nave = new Nave(40, 10, 5, YELLOW, "[ ]");
	enemigo = new Meteorito(30, 10, 1, RED, "0");
	meteorito = new Enemigo(20, 10, 1, BLUE, "X");
}

