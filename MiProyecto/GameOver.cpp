#include "GameOver.h"
#include "Estado.h"

GameOver::GameOver(int tamano,int pun): Estado(tamano, pun){
}

void GameOver::actualizar() {
	clrscr();
	gotoxy(10, 5);
	textcolor(RED);
	cout << "GAME OVER!";
	
	gotoxy(10, 7);
	textcolor(WHITE);
	cout << "Puntos obtenidos: " << puntos;
	
	gotoxy(10, 9);
	cout << "Presiona ESC para salir...";
	
	while (true) {
		if (kbhit()) {
			int tecla = getch();
			if (tecla == 27) {
				return;
			}
		}
	}
}

