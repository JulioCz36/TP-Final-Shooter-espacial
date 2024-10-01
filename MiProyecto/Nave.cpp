#include "Nave.h"
#include "conio2.h"
#include <vector>
#include <iostream>
using namespace std;


Nave::Nave() : x(40), y(20), vidas(5) {
	paso=CLOCKS_PER_SEC/30;
	tempo=clock();
}

void Nave::start(){
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();
		mover();
		dibujar();
		tempo=clock();
	}
}

void Nave::borrar(){
	gotoxy(x,y);
	textcolor(7);
	cprintf("   ");
	textcolor(col);
	
}
void Nave::dibujar(){
	gotoxy(x,y);
	cprintf("[ ]"); 
}
void Nave::mover() {
	if (kbhit()) {
		int tecla = getch();
		
		switch (tecla) {
		case 'a':  // izquierda
			if (x > 1) x--;
			break;
		case 'd':  // derecha
			if (x < 79) x++;
			break;
		case 'w':  // arriba
			if (y > 1) y--;
			break;
		case 's':  // abajo
			if (y < 25) y++;
			break;
		}
	}
}


void Nave::disparar(vector<int>& balasX, vector<int>& balasY) {
	balasX.push_back(x);
	balasY.push_back(y - 1);
}




void Nave::perderVida() { vidas--; }

int Nave::VerX() { return x; }
int Nave::VerY() { return y; }
int Nave::VerVidas() { return vidas; }

