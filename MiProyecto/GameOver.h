#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <conio2.h>
#include <iostream>
#include "Estado.h"
using namespace std;

class GameOver:public Estado {
public:
	GameOver(int tamano,int pun);
	
	void actualizar() override;
	bool TerminoPartida() {return false;};
};

#endif

