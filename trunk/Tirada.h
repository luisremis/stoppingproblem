#ifndef TIRADA_H
#define TIRADA_H
#include "Parametro.h"
#include "Generador.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Tirada : public Parametro
{
private:
	vector <vector<char >*> *tirada;
public:
	Tirada(void);
	Tirada(int, int);
	Tirada(Tirada& original);
	virtual ~Tirada(void);
	void generar(int , int);
	vector <vector<char >*> *getTirada();
	//char operator[] (const int i);
    void mostrar();
};
#endif
