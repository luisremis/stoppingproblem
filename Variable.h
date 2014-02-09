#if !defined VARIABLE_H
#define VARIABLE_H
#include "ArbolSP.h"
#include "Parametro.h"

class Variable : public ArbolSP
{
public:
	Variable(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Variable(Variable& original);
	~Variable(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};
#endif