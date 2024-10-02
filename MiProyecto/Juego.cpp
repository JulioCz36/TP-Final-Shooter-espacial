#include "Juego.h"

Juego::Juego(): pantalla(80) {
	//enemigo = new Meteorito(30, 10, 1, RED, "0");
}

void Juego::mostrarMenu() {
	textcolor(BLUE);
	gotoxy(10, 5);  
	cout << "*********************";
	gotoxy(10, 6);  
	cout << "*Un Shooter espacial*";
	gotoxy(10, 7);  
	cout << "*********************";
	gotoxy(10, 10);
	cout << "Presiona 'P' para jugar.";
	gotoxy(10, 11);
	cout << "Presiona 'ESC' para salir.";
}
