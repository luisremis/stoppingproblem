#if !defined EVAL_SP_H
#define EVAL_SP_H

#include "Operador.h"
#include "Poblacion.h"
#include "CttesSP.h"
#include "Individuo.h"
#include "Argumento.h"
#include "SP.h"
#include <vector>

class EvalSP : public Operador
{
public:
	EvalSP();
	virtual ~EvalSP();
	Poblacion* operar(Poblacion* p);
};
#endif
