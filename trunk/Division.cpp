#include "Division.h"

Division::Division(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Division::Division(Division& original):ArbolSP(original){
}

Division::~Division(void)
{
}
double Division::interpret(vector<Parametro*> *parametros){
    return izq->interpret(parametros) / der->interpret(parametros);
}

Prototype* Division::copiar(){
	return new Division(*this);
}
