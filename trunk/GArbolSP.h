#ifndef GARBOLSP_H
#define	GARBOLSP_H

#include "GArbol.h"
#include "ArbolSP.h"
#include "CttesSP.h"
#include "Suma.h"
#include "Resta.h"
#include "Division.h"
#include "Seno.h"
#include "Coseno.h"
#include "Multiplicacion.h"
#include "Variable.h"
#include "Terminal.h"

class GArbolSP : public GArbol{
public:
    GArbolSP(Generador *g);
    virtual ~GArbolSP();
protected:
    virtual ArbolBinario* getFuncion(double random);
    virtual ArbolBinario* getTerminal(double random);

};

#endif

