#include "Coseno.h"
#include <cmath>

Coseno::Coseno(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Coseno::Coseno(Coseno& original):ArbolSP(original){
}

Coseno::~Coseno(void)
{
}

double Coseno::interpret(vector<Parametro*> *parametros){
return cos(izq->interpret(parametros));
}

Prototype* Coseno::copiar(){
	return new Coseno(*this);
}