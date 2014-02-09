#include "IndSP.h"

IndSP::IndSP(){

       FactorySP *fsp = new FactorySP();
	ab = fsp->crearArbol();
	valorFitness = 0;
        probabilidad = 0;
	acumulada = 0;
        representa=0;
	delete fsp;

}

IndSP::IndSP(IndSP &original){
        if (original.ab!=NULL) this->ab = (ArbolBinario*)original.ab->copiar();
	else this->ab=NULL;
	valorFitness = original.valorFitness;
	probabilidad = original.probabilidad;
	acumulada = original.acumulada;
        representa= original.representa;
	
}

IndSP::~IndSP(){
	delete ab;
}

Prototype *IndSP::copiar(){
	return new IndSP(*this);
}
