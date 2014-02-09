/*	Nodos dedicados a las terminales (nodos hojas del arbol)
*/

#pragma once
#include "Nodo.h"
#include <string>
#include <sstream>
using namespace std;

class NodoT :
	public Nodo
{
private:
	double valor;
public:
	NodoT(double);
	NodoT(NodoT &original);
	virtual ~NodoT(void);
	virtual char getTipo();
	double getValor();
	bool operator==(const NodoT&);
	virtual string toString();
	virtual Prototype* copiar();
};
