#if !defined RESTA_H
#define RESTA_H
#include "ArbolSP.h"

class Resta : public ArbolSP
{
public:
	Resta(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Resta(Resta& original);
	~Resta(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};

#endif