#include "Pantalla.h"
#include "Nave.h"
#include "Personaje.h"
#include "Enemigo.h"

Pantalla::Pantalla(int tamano, int pun): Estado(tamano,pun){
	mensajes = {"Nice shoot", "Good one","Great shot!","Nice hit!","Fantastic aim!","Direct hit!","Well done!"};
	nave = new Nave(23, 11, 5, RED, "[ ]", 30);
	
	meteorito = GenerarMetioritos();

	enemigo1 = GenerarEnemigos(CYAN,6);
	enemigo2 = GenerarEnemigos(GREEN,8);
	enemigo3 = GenerarEnemigos(MAGENTA,10);

}
Pantalla::~Pantalla(){
	delete nave, meteorito;
	delete enemigo1,enemigo2, enemigo3;
}

void Pantalla::actualizar() {
	// Mostrar interfaz
	VerHeader();
	VerPantalla();
	nave->actualizar();
	enemigo1->actualizar();
	enemigo2->actualizar();
	enemigo3->actualizar();
	meteorito->actualizar();
	
	// Verificar colisión
	if (hayColision(nave, meteorito)) {
		nave->perderVida();
		
		meteorito->borrar();
		delete meteorito;
		meteorito = GenerarMetioritos();
		
	}
	
	// Veo si elimino a los enemigos
	if (hayColision(nave, enemigo1)) {
		if (nave->disparar()) {
			enemigo1->borrar();
			delete enemigo1; 
			puntos+=10;
			mensaje();
			enemigo1 = GenerarEnemigos(CYAN,6);
		}
	}
	if (hayColision(nave, enemigo2)) {
		if (nave->disparar()) {
			enemigo2->borrar();
			delete enemigo2; 
			puntos+=20;
			mensaje();
			enemigo2 = GenerarEnemigos(GREEN,8);
		}
	}
	if (hayColision(nave, enemigo3)) {
		if (nave->disparar()) {
			enemigo3->borrar();
			delete enemigo3; 
			puntos+=30;
			mensaje();
			enemigo3 = GenerarEnemigos(MAGENTA,10);
		}
	}
	
	//Veo si chocan contra la pered todos
	if (meteorito->VerY() >= 18) {
		meteorito->borrar();
		delete meteorito;
		meteorito = GenerarMetioritos();
	}
	
	if ((enemigo1->VerX() == 11) || (enemigo1->VerX() == 37)) {
		enemigo1->borrar(); 
		delete enemigo1; 
		enemigo1 = GenerarEnemigos(CYAN,6);
	}
	if ((enemigo2->VerX() == 11) || (enemigo2->VerX() == 37)) {
		enemigo2->borrar(); 
		delete enemigo2; 
		enemigo2 = GenerarEnemigos(GREEN,8);
	}
	if ((enemigo3->VerX() == 11) || (enemigo3->VerX() == 37)) {
		enemigo3->borrar(); 
		delete enemigo3; 
		enemigo3 = GenerarEnemigos(MAGENTA,10);
	}
	
	VerVidasYPuntos();
}

Personaje* Pantalla::GenerarEnemigos(int color, int velocidad){
	if (rand() % 2 == 0) {
		int posY = rand() % (18 - 5 + 1) + 5;
		return new Enemigo(12, posY, 1, color, "X", velocidad);
	} else {
		int posY = rand() % (18 - 5 + 1) + 5;
		return new Enemigo(36, posY, 1, color, "X", velocidad);
	}
}

Personaje* Pantalla::GenerarMetioritos(){
	int randomX = rand() % (34 - 11 + 1) + 11;
	return new Meteorito(randomX, 7, 1, YELLOW, "0", 6);
}

void Pantalla::mensaje(){
	int indiceAleatorio = rand() % mensajes.size();
	string mensajeAleatorio = mensajes[indiceAleatorio];
	textcolor(RED);
	gotoxy(18, 20);
	cout << mensajeAleatorio;
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


