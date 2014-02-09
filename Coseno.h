#if !defined COSENO_H
#define COSENO_H
#include "ArbolSP.h"

class Coseno : public ArbolSP
{
public:
	Coseno(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Coseno(Coseno& original);
	~Coseno(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};
#endif