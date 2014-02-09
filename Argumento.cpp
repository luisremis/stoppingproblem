#include "Argumento.h"


Argumento::Argumento(string n)
{
	this->nombre=n;
	this->valor=0;
}

Argumento::Argumento(string n, double v)
{
	this->nombre=n;
	this->valor=v;
}

Argumento::~Argumento(void)
{
}

bool Argumento::operator ==(const Argumento& a2){
	if (this->nombre.compare(a2.nombre)==0)
		return true;
	else return false;
}

Argumento& Argumento::operator =(const Argumento& a2){
	this->valor = a2.valor;
	return *this;
}

double Argumento::getValor(){
	return valor;
}

string Argumento::getNombre(){
	return nombre;
}

ostream& operator<<(ostream& out, const Argumento &arg){
	out << arg.nombre << ": " << arg.valor;
	return out;
}