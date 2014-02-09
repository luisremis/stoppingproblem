#include "GArbolSP.h"
#include <iostream>

GArbolSP::GArbolSP(Generador *g) : GArbol(g) {
}

GArbolSP::~GArbolSP() {
}

ArbolBinario* GArbolSP::getFuncion(double random) {
    ArbolSP *abNuevo = NULL;
    char aux = CttesSP::tablaFunciones->getRandom(random);
    NodoF *auxF = new NodoF(aux);
    
    switch (aux) {
        case '+':
            abNuevo = new Suma(auxF, NULL, NULL);
            abNuevo->setUnario(false);
            break;
        case '-':
            abNuevo = new Resta(auxF, NULL, NULL);
            abNuevo->setUnario(false);
            break;
        case '/':
            abNuevo = new Division(auxF, NULL, NULL);
            abNuevo->setUnario(false);
            break;
        case '*':
            abNuevo = new Multiplicacion(auxF, NULL, NULL);
            abNuevo->setUnario(false);
            break; 
        case 's':
            abNuevo = new Seno(auxF, NULL, NULL);
            abNuevo->setUnario(true);
            break;
        case 'c':
            abNuevo = new Coseno(auxF, NULL, NULL);
            abNuevo->setUnario(true);
            break;
    }
    return abNuevo;
}

ArbolBinario* GArbolSP::getTerminal(double random) {
    
    double probV = 0.5;
    double tipo = g->random();
    ArbolSP *abNuevo = NULL;

    if (tipo<probV) {
        NodoT* auxT = new NodoT(CttesSP::tablaTerminales->getRandom(random));
        abNuevo = new Terminal(auxT, NULL, NULL);
    } else {
        
        NodoV* auxV = new NodoV(CttesSP::tablaVariables->getRandom(random));
        abNuevo = new Variable(auxV, NULL, NULL);
    }
    return abNuevo;
   
}


