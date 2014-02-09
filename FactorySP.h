#if !defined FACTORY_SP_H
#define FACTORY_SP_H

#include "AbstractFactory.h"
#include "IndSP.h"
#include "ArbolSP.h"

class FactorySP : public AbstractFactory
{

public:
	FactorySP();
	virtual ~FactorySP();

	Individuo* crearIndividuo();
	ArbolBinario* crearArbol();

};
#endif
