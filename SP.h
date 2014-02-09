#if !defined SP_H
#define SP_H

#include <string>
#include "Parametro.h"
#include "Tirada.h"

using namespace std;

class SP : public Parametro
{

public:
	SP();
	virtual ~SP();


private:
	char orientacion;
	int posI;
	int posJ;
};
#endif 
