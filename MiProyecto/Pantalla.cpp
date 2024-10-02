#include "Pantalla.h"
#include "Nave.h"

Pantalla::Pantalla(int tamano):tamanoPantalla(tamano), puntos(0)  {
	nave = new Nave(23, 11, 5, RED, "[ ]", 30);
		int randomX = rand() % (34 - 11 + 1) + 11;
		meteorito=new Meteorito(randomX, 7, 1, YELLOW, "0", 6);

}
void Pantalla::VerHeader() {
	textcolor(BLUE);
	gotoxy(1, 1);
	cout << "Teclas Movimiento: A,D,W,S";
	gotoxy(1, 2);
	cout << "Disparar: L";
	gotoxy(1, 3);
	cout << "Debes disparar a las X, Evita los meteoritos!";
}
void Pantalla::VerPantalla() {
	textcolor(WHITE);
	for (int i = 0; i <= 27; i++) {
		gotoxy(10 + i, 5);  // Borde superior
		cout << "#";
		gotoxy(10 + i, 18);  // Borde inferior
		cout << "#";
	}
	for (int i = 0; i <= 11; i++) {
		gotoxy(10, 6 + i);  // Borde izquierdo
		cout << "#";
		gotoxy(10 + 27, 6 + i);  // Borde derecho
		cout << "#";
	}
}
void Pantalla::VerVidasYPuntos() {
	textcolor(BLUE);
	gotoxy(10+27+3, 6);
	cout << "Puntos: " << puntos;
	
	gotoxy(10+27+3, 6 + 1);
	cout << "Vidas: ";
	for (int i = 0; i <nave->VerVidas(); i++) {
		cout << " * ";
	}
	cout << "( "<<nave->VerVidas()<<" )";
	
}

