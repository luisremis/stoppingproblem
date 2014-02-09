#include "Tirada.h"

Tirada::Tirada(void)
{
	this->tirada=new vector<vector <char>* >();
}

Tirada::Tirada(int cantidad, int tiradas)
{
	this->tirada=new vector<vector <char>* >();
	this->generar(cantidad, tiradas);
}

Tirada::Tirada(Tirada& original){
        this->tirada=new vector<vector <char>* >();
    
	for (unsigned int i=0; i<original.tirada->size(); i++){
		this->tirada->push_back(new vector<char>());
		for (unsigned int j=0; j<original.tirada->at(i)->size(); j++){
			this->tirada->at(i)->push_back(original.tirada->at(i)->at(j));
		}
	}
}

Tirada::~Tirada(void){
    delete tirada;
}

void Tirada::generar(int cantidad, int tiradas){
    
	Generador *g = new Generador();
        for(int j=0;j<tiradas;j++){
            
            vector<char> *aux = new vector<char>();
            
            aux->push_back('C');//La primera siempre es Ceca
            for(unsigned int i=1; i<cantidad; i++){
                        if(g->random()>0.5)
                            aux->push_back('A'); //Representa las Caras
                        else
                            aux->push_back('C'); //Representa las Cecas
            }
            
            tirada->push_back(aux);
        }
}

vector <vector<char >*> *Tirada::getTirada(){
	return this->tirada;
}
/*
char Tirada::operator [](int i){
	return this->tirada->at(i);
}*/

void Tirada::mostrar(){
    for (unsigned int i=0; i<tirada->size(); i++){
        
            cout<<"Tirada: "<<i<<endl;
            for (unsigned int j=0; j< tirada->at(i)->size(); j++){
                cout<<tirada->at(i)->at(j)<<" ";
            }
            cout<<endl;
        }
}
