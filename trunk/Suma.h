#if !defined SUMA_H
#define SUMA_H
#include "ArbolSP.h"

class Suma: public ArbolSP
{
public:
	Suma(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Suma(Suma& original);
	~Suma(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};
#endif
