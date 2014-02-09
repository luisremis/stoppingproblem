/*	Nodos dedicados a las variables (nodos hojas del arbol, que son reemplazados por algun valor)
*/

#pragma once
#include "Nodo.h"
#include <string>
using namespace std;

class NodoV : public Nodo
{
private:
	string variable;
public:
	NodoV(string);
	NodoV(NodoV &original);
	virtual ~NodoV(void);
	virtual char getTipo();
	string getValor();
	bool operator==(const NodoV&);
	virtual string toString();
	virtual Prototype* copiar();
};
