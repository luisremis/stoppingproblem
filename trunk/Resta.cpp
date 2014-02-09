#include "Resta.h"

Resta::Resta(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d)
{
}

Resta::Resta(Resta& original):ArbolSP(original){
}

Resta::~Resta(void)
{
}

double Resta::interpret(vector<Parametro*> *parametros){
return izq->interpret(parametros) - der->interpret(parametros);
}

Prototype* Resta::copiar(){
	return new Resta(*this);
}