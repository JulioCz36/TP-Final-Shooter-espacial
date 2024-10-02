#include "Personaje.h"
#include <ctime>
using namespace std;

Personaje::Personaje(int posX, int posY, int vida, int color, string objet, int velocidad) {
	paso=CLOCKS_PER_SEC/velocidad;
	tempo=clock();
	x = posX;
	y = posY;
	vidas = vida;
	col = color;
	objeto = objet;
}

void Personaje::perderVida(){
	vidas--;
}

void Personaje::dibujar(){
	gotoxy(x,y);
	cout<<objeto; 
}
void Personaje::borrar(){
	gotoxy(x,y);
	textcolor(7);
	cprintf("   ");
	textcolor(col);
}

void Personaje::actualizar(){
	textcolor(col);
	if(tempo+paso<clock()){
		borrar();
		mover();
		dibujar();
		tempo=clock();
	}
}
	
//Metodos para tener más info
int Personaje::VerX(){ return x; };
int Personaje::VerY(){ return y; };
int Personaje::VerVidas(){ return vidas; };
int Personaje::cambiarColor(int color){ col = color; };



