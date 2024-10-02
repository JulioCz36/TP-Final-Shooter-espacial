#include "Juego.h"
#include "Pantalla.h"
#include "GameOver.h"

Juego::Juego(){
	pantalla = new Pantalla(80,0);
	//enemigo = new Meteorito(30, 10, 1, RED, "0");
}

void Juego::jugar() {
	mostrarMenu();
	while (true) {
		if (kbhit()) {
			int tecla = getch();
			switch (tecla) {
			case 'p':
				jugando = true;
				clrscr();
				while (jugando) {
					pantalla->actualizar();
					if (pantalla->TerminoPartida()) {
						int puntos = pantalla->VerPuntos();
						delete pantalla;
						pantalla = new GameOver(80,puntos);
						pantalla->actualizar();
						jugando = false; 
					}
				}
				break;
			case 27:					
				return ; 
			}
		}
	}
}

void Juego::mostrarMenu() {
	textcolor(BLUE);
	gotoxy(14, 5);  
	cout << "*********************";
	gotoxy(14, 6);  
	cout << "*Un Shooter espacial*";
	gotoxy(14, 7);  
	cout << "*********************";
	gotoxy(11, 10);
	cout << "- Presiona 'P' para jugar -";
	gotoxy(10, 11);
	cout << "- Presiona 'ESC' para salir -";
}
