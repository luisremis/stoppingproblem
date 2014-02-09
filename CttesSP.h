#if !defined CTTES_SP_H
#define CTTES_SP_H

#include <vector>
#include "Tabla.h"
#include "Tirada.h"
using namespace std;

class CttesSP
{

public:
	CttesSP();
	virtual ~CttesSP();
	static Tabla<char> *tablaFunciones;
	static Tabla<char> *tablaTerminales;
        static Tabla<string> *tablaVariables;
        static Tirada *tirada;
};
#endif
