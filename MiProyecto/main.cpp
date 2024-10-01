#include <iostream>
#include <conio2.h>
#include <ctime>
#include "Nave.h"

using namespace std;



int main(int argc, char *argv[]) {
	
	Nave *p1 = new Nave();
	
	while(true){
		p1->start();
	}
	return 0;
}
