#include "FactorySP.h"


FactorySP::FactorySP(){

}

FactorySP::~FactorySP(){

}

Individuo* FactorySP::crearIndividuo(){
	return new IndSP();
}

ArbolBinario* FactorySP::crearArbol(){
	return new ArbolSP(NULL, NULL, NULL);
}