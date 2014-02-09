#include "NodoF.h"

NodoF::NodoF(char valor)
{
	this->valor=valor;  
	if (valor=='+' || valor=='-' || valor=='*' || valor=='/' || valor=='^'){
		unario=false;
	} else if (valor=='s' || valor=='c'){
		unario=true;
	}
}

NodoF::NodoF(NodoF &original){
	this->valor=original.valor;
	this->unario=original.unario;
}

NodoF::~NodoF(void){
}

char NodoF::getTipo(){
	return 'F';
}

char NodoF::getValor(){
	return this->valor;
}

bool NodoF::operator ==(const NodoF& a2){
	if (this->valor==a2.valor)
		return true;
	else return false;
}

bool NodoF::getUnario(){
	return unario;
}

string NodoF::toString(){
	stringstream aux;
	aux<<valor;
	return aux.str();
}

Prototype* NodoF::copiar(){
	return new NodoF(*this);
}
