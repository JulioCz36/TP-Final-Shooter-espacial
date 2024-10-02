#ifndef ESTADO_H
#define ESTADO_H

class Estado {
protected: 
	int tamanoPantalla; 
	int puntos;
public:
	Estado(int tamanio,int puntos);
	virtual void actualizar() = 0;
	virtual bool TerminoPartida() = 0;
	int VerPuntos();
};

#endif

