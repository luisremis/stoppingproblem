#if !defined TERMINAL_H
#define TERMINAL_H
#include "ArbolSP.h"

class Terminal : public ArbolSP
{
public:
	Terminal(Nodo* v, ArbolBinario *i, ArbolBinario *d);
	Terminal(Terminal& original);
	~Terminal(void);
	double interpret(vector<Parametro*> *parametros);
	Prototype* copiar();
};
#endif