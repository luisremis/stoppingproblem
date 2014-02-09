/*!	ESTA CLASE SE USA PARA DARLE VALORES A LAS VARIABLES EN EL MOMENTO DE EVALUAR UNA FUNCION
*/

#pragma once
#include <iostream>
#include <string>
#include "Parametro.h"
using namespace std;

class Argumento : public Parametro
{
private:
	string nombre;	// Nombre de la variable
	double valor;	// Valor que toma
public:
	Argumento(string);
	Argumento(string, double);
	~Argumento();
	bool operator==(const Argumento&);	// Sobrecarga de operador de comparacion, compara solo el nombre de la variable
	Argumento& operator=(const Argumento&);	// Sobrecarga de operador de asignacion, asigna solo el valor
	friend ostream& operator<<(ostream&, const Argumento&);	// Sobrecarga de operador de insercion, usado para mostrar por pantalla o escribir en un archivo
	double getValor();
	string getNombre();
};
