#include "Variable.h"

Variable::Variable(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Variable::Variable(Variable& original):ArbolSP(original){
}

Variable::~Variable(void)
{
}

double Variable::interpret(vector<Parametro*> *parametros){

    NodoV *esteNodo = (NodoV*) valor;

for (unsigned int i=0; i<parametros->size();i++){
	if (esteNodo->getValor().compare(parametros->at(i)->getNombre())==0)
		return parametros->at(i)->getValor();
}
return 0; //No Deberia pasar este caso
}

Prototype* Variable::copiar(){
	return new Variable(*this);
}
