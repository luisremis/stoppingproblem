#if !defined DIVISION_H
#define DIVISION_H
#include "ArbolSP.h"

class Division : public ArbolSP
{
public:
	Division(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Division(Division& original);
	~Division(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};
#endif