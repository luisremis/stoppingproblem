#include "NodoT.h"

NodoT::NodoT(double valor)
{
	this->valor=valor;
}

NodoT::NodoT(NodoT &original){
	this->valor=original.valor;
}

NodoT::~NodoT(void)
{
}

char NodoT::getTipo(){
	return 'T';
}

double NodoT::getValor(){
	return this->valor;
}

bool NodoT::operator ==(const NodoT& a2){
	if (this->valor==a2.valor)
		return true;
	else return false;
}

string NodoT::toString(){
	stringstream aux;
	aux<<valor;
	return aux.str();
}

Prototype* NodoT::copiar(){
	return new NodoT(*this);
}