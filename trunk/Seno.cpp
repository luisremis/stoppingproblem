#include "Seno.h"
#include <cmath>
Seno::Seno(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Seno::Seno(Seno& original):ArbolSP(original){
}

Seno::~Seno(void)
{
}

double Seno::interpret(vector<Parametro*> *parametros){
return sin(izq->interpret(parametros));
}

Prototype* Seno::copiar(){
	return new Seno(*this);
}