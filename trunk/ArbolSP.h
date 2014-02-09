#if !defined ARBOL_SP_H
#define ARBOL_SP_H
#include "ArbolBinario.h"
#include "Nodo.h"
#include "NodoT.h"
#include "NodoF.h"
#include "NodoV.h"
#include "Incrementador.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

class ArbolSP : public ArbolBinario
{
protected:
	string className;

public:
	ArbolSP(Nodo* valor, ArbolBinario* i, ArbolBinario* d);
	ArbolSP(ArbolSP &original);
	virtual ~ArbolSP();
	virtual double interpret(vector<Parametro*>*);
	Prototype* copiar();
	virtual void mostrar();
	virtual string mostrar(ofstream *out, Incrementador* inc);
	string getClassName();
};
#endif
