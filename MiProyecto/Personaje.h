#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <ctime>
#include <string>
#include <conio2.h>
#include <iostream>
using namespace std;

class Personaje {
	clock_t tempo;
	clock_t paso;
	int vidas;
	int col;
	string objeto;
	
protected:
	int x, y;
	
public:
	Personaje(int posX, int posY, int vida, int color, string objet, int velocidad);
	
	virtual void mover()=0;
	void perderVida();
	
	void dibujar();
	void borrar();
	void actualizar();
	
	//Metodos para tener más info
	int VerX();
	int VerY();
	int VerVidas();
	int cambiarColor(int color);
	

};

#endif

