#include "Suma.h"

Suma::Suma(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Suma::Suma(Suma& original):ArbolSP(original){
}

Suma::~Suma(void)
{
}

double Suma::interpret(vector<Parametro*> *parametros){
return izq->interpret(parametros) + der->interpret(parametros);
}

Prototype* Suma::copiar(){
	return new Suma(*this);
}