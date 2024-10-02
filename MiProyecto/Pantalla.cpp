#include "Pantalla.h"
#include "Nave.h"
#include "Personaje.h"
#include "Enemigo.h"

Pantalla::Pantalla(int tamano, int pun): Estado(tamano,pun){
	nave = new Nave(23, 11, 5, RED, "[ ]", 30);
	int randomX = rand() % (34 - 11 + 1) + 11;
	meteorito = new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
	
	// Generar posición inicial del enemigo
	if (rand() % 2 == 0) {
		posY = rand() % (18 - 5 + 1) + 5;
		enemigo1 = new Enemigo(12, posY, 1, RED, "X", 6);
	} else {
		posY = rand() % (18 - 5 + 1) + 5;
		enemigo1 = new Enemigo(36, posY, 1, RED, "X", 6);
	}

}
Pantalla::~Pantalla(){
	delete nave, meteorito;
}

void Pantalla::actualizar() {
	// Mostrar interfaz
	VerHeader();
	VerPantalla();
	nave->actualizar();
	enemigo1->actualizar();
	meteorito->actualizar();
	
	// Verificar colisión
	if (hayColision(nave, meteorito)) {
		nave->perderVida();
		
		meteorito->borrar();
		delete meteorito;
		int randomX = rand() % (34 - 11 + 1) + 11;
		meteorito=new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
		
	}
	
	
	if (meteorito->VerY() >= 18) {
		meteorito->borrar();
		delete meteorito;
		int randomX = rand() % (34 - 11 + 1) + 11;
		meteorito = new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
	}
	
	if ((enemigo1->VerX() == 11 && enemigo1->VerY() == posY) || 
		(enemigo1->VerX() == 37 && enemigo1->VerY() == posY)) {
		enemigo1->borrar(); 
		delete enemigo1; 
		
		if (rand() % 2 == 0) {
			posY = rand() % (18 - 5 + 1) + 5;
			enemigo1 = new Enemigo(12, posY, 1, RED, "X", 6);
		} else {
			posY = rand() % (18 - 5 + 1) + 5;
			enemigo1 = new Enemigo(36, posY, 1, RED, "X", 6);
		}
	}
	
	VerVidasYPuntos();
	
	// Incrementar puntos (por ejemplo, por cada ciclo de juego)
	puntos++;
}


bool Pantalla::hayColision(Personaje* obejto1, Personaje* objeto2) {
	return (obejto1->VerX() == objeto2->VerX() && obejto1->VerY() == objeto2->VerY());
}

bool Pantalla::TerminoPartida() { 
	if(nave->VerVidas()==0){
		delete nave;
		return true;
	}
	return false; 
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
	
	gotoxy(10 + 27 + 3, 6);
	cout << "Puntos: " << puntos;
	
	
	gotoxy(10 + 27 + 3, 7);
	cout << "                          ";
	gotoxy(10 + 27 + 3, 7);
	cout << "Vidas: ";
	
	for (int i = 0; i < nave->VerVidas(); i++) {
		cout << " * ";
	}
	
	cout << "( " << nave->VerVidas() << " )   ";
}


