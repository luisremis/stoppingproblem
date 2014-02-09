#if !defined IND_SP_H
#define IND_SP_H

#include "ArbolSP.h"
#include "FactorySP.h"
#include "Generador.h"

class IndSP : public Individuo
{

public:
	IndSP();
	IndSP(IndSP &original);
	virtual ~IndSP();
	Prototype* copiar();
        float representa;
};
#endif
