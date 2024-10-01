#include <iostream>
#include <conio2.h>
#include <ctime>
#include "Nave.h"
#include "Meteorito.h"
#include "Personaje.h"

using namespace std;



int main(int argc, char *argv[]) {
	
	Personaje *p1 = new Nave(40, 10, 5, YELLOW, "[ ]");
	Personaje *p2 = new Meteorito(30, 10, 1, RED, "0");
	
	while(true){
		p1->actualizar();
		p2->actualizar();
	}
	return 0;
}
