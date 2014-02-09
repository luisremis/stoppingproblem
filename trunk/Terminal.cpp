#include "Terminal.h"

Terminal::Terminal(Nodo* v, ArbolBinario *i, ArbolBinario *d):ArbolSP(v,i,d){
}

Terminal::Terminal(Terminal& original):ArbolSP(original){
}

Terminal::~Terminal(void)
{
}

double Terminal::interpret(vector<Parametro*> *parametros){
	NodoT *esteNodo = (NodoT*) valor;
	return esteNodo->getValor();
}

Prototype* Terminal::copiar(){
	return new Terminal(*this);
}