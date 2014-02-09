#include "NodoV.h"

NodoV::NodoV(string variable)
{
	this->variable=variable;
}

NodoV::NodoV(NodoV &original){
	this->variable=original.variable;
}

NodoV::~NodoV(void)
{
}

char NodoV::getTipo(){
	return 'V';
}

string NodoV::getValor(){
	return this->variable;
}

bool NodoV::operator ==(const NodoV& a2){
	if (this->variable.compare(a2.variable)==0)
		return true;
	else return false;
}

string NodoV::toString(){
	return variable;
}

Prototype* NodoV::copiar(){
	return new NodoV(*this);
}