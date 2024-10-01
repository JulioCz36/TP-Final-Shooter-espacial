#ifndef NAVE_H
#define NAVE_H

#include "conio2.h"
#include <conio.h>
#include <vector>
#include <ctime>
using namespace std;

class Nave {
private:
	clock_t tempo;
	clock_t paso;
	int x, y;
	int vidas;
	int col = WHITE;
	
public:
	Nave();
	void start();
	
	void disparar(vector<int>& balasX, vector<int>& balasY);
	void perderVida();
	
	int VerX();
	int VerY();
	int VerVidas();
	
	void borrar();
	void dibujar();
	void mover();
};

#endif

