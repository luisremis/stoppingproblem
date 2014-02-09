#include <iostream>
#include "CttesSP.h"
#include "Constantes.h"
#include "Generador.h"
#include "Poblacion.h"
#include "FactorySP.h"
#include "EvalSP.h"
#include "Individuo.h"
#include "GArbolSP.h"

#include "Arquitectura.h"
#include "Genetico.h"
#include "SUS.h"
#include "Cruzamiento.h"
#include "Mutacion.h"
#include "SelElite.h"
#include "Estadisticas.h"

#include <vector>
using namespace std;

#define Generaciones    100
#define CantPoblacion   50
#define CantidadTiradas 10
#define TamanoTirada    100
#define ArbolMax        2
#define ArbolMin        0
#define PorcEvaluacion  100
#define PorcSeleccion   100
#define PorcCruzamiento 65
#define PorcMutacion    15
#define PorcElite       1


void inicializar(){
        // Generador para todo el algoritmo
        Generador *g = new Generador();
        
        //Se crea la tirada modelo.
        CttesSP::tirada=new Tirada(CantidadTiradas,TamanoTirada);

        // Seteo del Factory
		Constantes::factory     =new FactorySP();
		Constantes::gArbol      =new GArbolSP(g);
        
	// Carga de tablas
	// Funciones: SUMA, RESTA, MULTI, DIVISION
		CttesSP::tablaFunciones->agregarItem('+', 0.25);
		CttesSP::tablaFunciones->agregarItem('-', 0.25);
		CttesSP::tablaFunciones->agregarItem('*', 0.25);
        CttesSP::tablaFunciones->agregarItem('/', 0.25);
        //CttesSP::tablaFunciones->agregarItem('s', 0.16);
        //CttesSP::tablaFunciones->agregarItem('c', 0.16);
           
	// Terminales: M=Mover, I=Girar Izquierda, D=Girar Derecha
		CttesSP::tablaTerminales->agregarItem(1, 0.2);
        CttesSP::tablaTerminales->agregarItem(2, 0.2);
        CttesSP::tablaTerminales->agregarItem(3, 0.2);
		CttesSP::tablaTerminales->agregarItem(5, 0.2);
        CttesSP::tablaTerminales->agregarItem(7, 0.2);

      //Variales: x
        CttesSP::tablaVariables->agregarItem("x", 1);
        
        // Parametros del ArbolBinario
        ArbolBinario::ALTURA_MIN=ArbolMin;
        ArbolBinario::ALTURA_MAX=ArbolMax;
         
        // Parametros del Genetico
        Arquitectura *a = new Arquitectura(PorcEvaluacion, PorcSeleccion, PorcCruzamiento, PorcMutacion, PorcElite);
		Genetico *genetico = Genetico::getGenetico();
		genetico->setGeneraciones(Generaciones);
		genetico->setArquitectura(a);
		genetico->setOEval(new EvalSP());
		genetico->setOSel(new SUS(a->getPorcentajeSeleccion(), g));
		genetico->setOCross(new Cruzamiento(a->getPorcentajeCruzamiento(), 100, g));
		genetico->setOMut(new Mutacion(a->getPorcentajeMutacion(), g));
		genetico->setOElites(new SelElite(double(a->getPorcentajeElite())));

}

int main(){
		inicializar();
        
		Poblacion *p = new Poblacion();
        p->generar(CantPoblacion, "grow", ArbolBinario::ALTURA_MIN, ArbolBinario::ALTURA_MAX);
                
        Genetico *genetico = Genetico::getGenetico();
        genetico->iniciar(p);
                
        Poblacion *final = genetico->getInitPop();
		genetico->getOEval()->operar(final);
		SelElite *mejor = new SelElite(1);
		Poblacion *mejorIndividuo = mejor->operar(final);
		mejorIndividuo->getIndividuos()->at(0)->mostrar();
		cout<<"Fitness: "<<mejorIndividuo->getIndividuos()->at(0)->getFitness()<<endl;

       Estadisticas::getInstancia()->exportar();
		
	   getchar();
       return 0;
}