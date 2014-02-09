#if !defined MULTIPLICACION_H
#define MULTIPLICACION_H
#include "ArbolSP.h"

class Multiplicacion : public ArbolSP
{
public:
	Multiplicacion(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Multiplicacion(Multiplicacion& original);
	~Multiplicacion(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};

#endif