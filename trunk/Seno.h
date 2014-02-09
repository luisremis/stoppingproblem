#if !defined SENO_H
#define SENO_H
#include "ArbolSP.h"

class Seno : public ArbolSP
{
public:
	Seno(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Seno(Seno& original);
	~Seno(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};

#endif