#include "ArbolSP.h"

ArbolSP::ArbolSP(Nodo* v, ArbolBinario* i, ArbolBinario* d) : ArbolBinario(v, i, d) {
    className = "ArbolSP";
}

ArbolSP::ArbolSP(ArbolSP &original) {
    if (original.valor != NULL) this->valor = (Nodo*) original.valor->copiar();
    else this->valor = NULL;
    if (original.izq != NULL) {
        this->izq = (ArbolSP*) original.izq->copiar();
        this->izq->setPadre(this);
    } else {
        this->izq = NULL;
    }
    if (original.der != NULL) {
        this->der = (ArbolSP*) original.der->copiar();
        this->der->setPadre(this);
    } else {
        this->der = NULL;
    }
    if (original.padre == NULL) this->padre = NULL;
    this->nivel = original.nivel;
    this->nivelesPorAbajo = original.nivelesPorAbajo;
    this->className = original.className;
}

ArbolSP::~ArbolSP() {
    delete izq;
    delete der;
    delete valor;
}

double ArbolSP::interpret(vector<Parametro*>*) {
    return 0;
}

Prototype *ArbolSP::copiar() {
    return new ArbolSP(*this);
}

void ArbolSP::mostrar() {
    // Muestra solo este arbol
    ofstream *out = new ofstream("temp.dot");
    *out << "graph Temp {" << endl;
    mostrar(out, new Incrementador());
    *out << "}" << endl;
    out -> close();
    //system("dot -Tpng -o temp.png temp.dot"); //FOR UNIX
    //system("shotwell temp.png"); //FOR UNIX

    //system("/Applications/Graphviz.app/Contents/MacOS/Graphviz temp.dot &"); //FOR MAC
    //system("/usr/local/graphviz-2.12/bin/dot -Tpng temp.png temp.dot &"); //FOR MAC
    //system("open -a Preview temp.png"); //For Mac

    //system("\"C:\\Program Files\\Graphviz 2.28\\bin\\dot.exe\" -Tjpg temp.dot -o temp.jpg");//FOR WINDOWS
    //system("mspaint temp.jpg"); //FOR WINDOWS
}

string ArbolSP::mostrar(ofstream *out, Incrementador *inc) {
        
    string hijoIzq="";
	string hijoDer="";
	if (!esHoja()){
		if (izq!=NULL) hijoIzq = izq->mostrar(out, inc);
		if (der!=NULL) hijoDer = der->mostrar(out, inc);
	}
	
	string label="";
	string color="";
	if (valor!=NULL){
	if (valor->getTipo()=='F'){
		stringstream aux;
		aux<<"\""<<((NodoF*)valor)->getValor()<<"\"";
		label=aux.str();
		color="tomato";
	} else if (valor->getTipo()=='T'){
		stringstream aux;
		aux<<((NodoT*)valor)->getValor();
		label=aux.str();
		color="darkslateblue";
	} else if (valor->getTipo()=='V'){
		label=((NodoV*)valor)->getValor();
		color="darkgreen";
	}
	}
	
	stringstream sAux;
	sAux << "Nodo_" << inc->getNumero();
	string esteNodo = sAux.str();
	string nodo = esteNodo;
	nodo.append("[label=").append(label).append(", color=").append(color).append("]");
	*out << nodo << ";"<< endl;
	if (!esHoja()){
		if (izq!=NULL) *out << esteNodo << " -- " << hijoIzq << ";" << endl;
		if (der!=NULL) *out << esteNodo << " -- " << hijoDer << ";" << endl;
	}
	return esteNodo;
}

string ArbolSP::getClassName() {
    return className;
}
