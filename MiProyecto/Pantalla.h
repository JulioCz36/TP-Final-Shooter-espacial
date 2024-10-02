#ifndef PANTALLA_H
#define PANTALLA_H
#include "Nave.h"
#include "Personaje.h"

class Pantalla {
	Personaje* nave;
	int puntos;                     
	int tamanoPantalla;
public:
	Pantalla(int tamano);
	
	void VerHeader() {
		textcolor(BLUE);
		gotoxy(1, 1);
		cout << "Teclas Movimiento: A,D,W,S";
		gotoxy(1, 2);
		cout << "Disparar: L";
		gotoxy(1, 3);
		cout << "Debes disparar a las X, Evita los meteoritos!";
	}
	void VerPantalla() {
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
	void VerVidasYPuntos() {
		textcolor(BLUE);
		gotoxy(10+27+3, 6 );
		cout << "Vidas: " << nave->VerVidas();
		
		gotoxy(10+27+3, 6 + 1);
		cout << "Puntos: " << puntos;
	}
	void actualizar() {
		// Mostrar interfaz
		VerHeader();
		VerPantalla();
		nave->actualizar();
		VerVidasYPuntos();
		
		// Incrementar puntos (por ejemplo, por cada ciclo de juego)
		puntos++;
	}

};

#endif

