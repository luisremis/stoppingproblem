#include "Multiplicacion.h"

Multiplicacion::Multiplicacion(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Multiplicacion::Multiplicacion(Multiplicacion& original):ArbolSP(original){
}

Multiplicacion::~Multiplicacion(void)
{
}

double Multiplicacion::interpret(vector<Parametro*> *parametros){
return izq->interpret(parametros) * der->interpret(parametros);
}

Prototype* Multiplicacion::copiar(){
	return new Multiplicacion(*this);
}