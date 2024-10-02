#include "Pantalla.h"
#include "Nave.h"

Pantalla::Pantalla(int tamano):tamanoPantalla(tamano), puntos(0)  {
	nave = new Nave(40, 10, 5, RED, "[ ]");
}

