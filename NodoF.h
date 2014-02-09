/*	Nodos dedicados a las funciones (nodos internos del arbol)
*/

#pragma once
#include "Nodo.h"
#include <string>
#include <sstream>
using namespace std;

class NodoF : public Nodo
{
private:
	char valor;	// +, -, /, *, etc
	bool unario;
public:
	NodoF(char);
	NodoF(NodoF &original);
	virtual ~NodoF(void);
	virtual char getTipo();
	char getValor();
	bool operator==(const NodoF&);
	bool getUnario();
	virtual string toString();
	virtual Prototype* copiar();
};
