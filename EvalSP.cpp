#include "EvalSP.h"
#include "Estadisticas.h"

EvalSP::EvalSP(){

}

EvalSP::~EvalSP(){

}

Poblacion* EvalSP::operar(Poblacion* p){
    
        Tirada* tiradita=new Tirada(*CttesSP::tirada);
        vector<Individuo*>* inds = p->getIndividuos();
        vector<Parametro*> *parametros = new vector<Parametro*>();
        Estadisticas *estadisticas = Estadisticas::getInstancia();
        
        for (unsigned int nInd=0; nInd<inds->size(); nInd++){

            double prom=0;
            for (unsigned int i=0; i<tiradita->getTirada()->size(); i++){

                float caras=0,cecas=0;
                for(unsigned int j=0;j< tiradita->getTirada()->at(i)->size();j++){

                    if(tiradita->getTirada()->at(i)->at(j)=='A')
                            caras++;
                        else
                            cecas++;

                    parametros->push_back(new Argumento("x",caras+cecas));

                    if ((caras/(caras+cecas))>=inds->at(nInd)->getArbolBinario()->interpret(parametros))
                    {
                            delete parametros->at(0);
                            parametros->clear();
                            break;
                    }

                    //Importante eliminar el argumento creado, sino se rompe todo!
                    delete parametros->at(0);
                    parametros->clear();
                }
                prom=prom+caras/(caras+cecas);
            }

            //cout<<prom/tiradita->getTirada()->size()<<endl;
            inds->at(nInd)->setFitness(prom/tiradita->getTirada()->size());
            estadisticas->compararMejor(prom/tiradita->getTirada()->size());
            estadisticas->agregarAvg(prom/tiradita->getTirada()->size());
	}
              
    estadisticas->nuevaGeneracion();
	return p;
}
