//
// lista_generica.hpp
// lista_generica
//
// Created by Marlon Polanco on 02/11/2021
//

#ifndef lista_generica_hpp
#define lista_generica_hpp

#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

template <typename TIPODATO>
class Lista {
	private:
		int cuenta;
		int capacidad;
		TIPODATO *items;
		void agrandar();
	public:
		Lista(int capacidad);
		Lista();
		~Lista();
		Lista(const Lista &otra); // Construir una Lista a partir de otra en una direccion.
		bool estaVacia();
		int tamano();
		void insertar (int indice, TIPODATO item);
		void adjuntar (TIPODATO item);
		TIPODATO obtener (int indice);
		bool contiene(TIPODATO item);
		TIPODATO remover(int indice);
		string comoCadena();
};

// Constructor
template <typename TIPODATO>
Lista<TIPODATO>::Lista(int capacidad){
	
	// Creando una lista vacia
	this->cuenta = 0;
	this->capacidad = capacidad;
	// Capacidad de elementos de la lista
	this->items = new TIPODATO[capacidad];	
}

// Constructor con tamaño por defecto, en este caso 4
template <typename TIPODATO>
Lista<TIPODATO>::Lista():Lista(4){}

// Destructor de la Lista
template <typename TIPODATO>
Lista<TIPODATO>::~Lista(){
	// Destruyendo la lista
	delete[] items;
}

// Construir una Lista a partir de otra
template <typename TIPODATO>
Lista<TIPODATO>::Lista(const Lista<TIPODATO>&otra) {
	// Copiando una lista desde otra
	this->cuenta = otra.cuenta;
	this->capacidad=otra.capacidad;
	this->items = new TIPODATO[capacidad];
	for (int i = 0; i < this->cuenta; i++)
		this->items[i] = otra.items[i];
}

// Esta la Lista vacia?
template <typename TIPODATO>
	bool Lista<TIPODATO>::estaVacia() {
	// Comprobando si la lista esta vacia
	return this->cuenta == 0;
}

// Tamano de la lista
template <typename TIPODATO>
int Lista<TIPODATO>::tamano() {
	// Obteniendo el tamano de la lista
	return this->cuenta;
}

template <typename TIPODATO>
void Lista<TIPODATO>::agrandar() {
	// Duplicando el tamano de la lista
	TIPODATO *temp = this->items;
	this->capacidad *= 2;
	this->items = new TIPODATO[capacidad];
	
	for (int i = 0; i < cuenta; i++) {
		this->items[i] = temp[i];
	}
	
	delete[] temp;
}

// Insertar un elemento en un indice especifico
template <typename TIPODATO>
void Lista<TIPODATO>::insertar(int indice, TIPODATO item) {
	// Validar el indice
	if (indice < 0 || indice > this->cuenta) throw "Indice fuera de rango";
	
	// Agrandar la lista si el elemento no cabe
	if (this->cuenta >= this->capacidad) this->agrandar();
	
	// Desplazar elementos a partir del indice a la derecha
	for (int i = cuenta - 1; i >= indice; i--) {
		// Desplazando elemento items[i] del indice i al indice (i+1)
		this->items[i+1] = this->items[i];
	}
	
	// Insertar nuevo elemento
	this->items[indice] = item;

	// Incrementar la cuenta de elementos
	this->cuenta++;
}

// Agregar un elemento al final
template <typename TIPODATO>
void Lista<TIPODATO>::adjuntar(TIPODATO item) {
	this->insertar(this->cuenta,item);
}

// Valor del elemento en la posicion indice
template <typename TIPODATO>
TIPODATO Lista<TIPODATO>::obtener(int indice) {
	// Validar el indice
	if (indice < 0 || indice >= this->cuenta) throw "Indice fuera de rango";
	if (this->estaVacia()) throw "No se pued recuperar elementos de una lista vacia";
	
	// "Recuperando elemento en el indice
	return this->items[indice];
}

// Esta el item en la Lista?
template <typename TIPODATO>
bool Lista<TIPODATO>::contiene(TIPODATO item) {
	for (int i = 0; i < this->cuenta; i++) {
		// Recorriendo elemento con indice i
		if (this->items[i] == item)
				return true;
	}
	
	return false;
}

// Remover elemento en el indice indice
template <typename TIPODATO>
TIPODATO Lista<TIPODATO>::remover(int indice) {
	// Validar el indice
	if (this->estaVacia()) throw "No se puede remover elementos de una lista vacia";
	if (indice < 0 || indice >= this->cuenta) throw "Indice fuera de rango";

	// Removiendo el elemento con indice "indice"
    // Lee el valor en el indice y desplaza elementos a la izquierda
	TIPODATO valor = this->items[indice];
	for (int i = indice; i < cuenta - 1; i++) {
		// Desplazando elemento items[i] del indice (i+1) al indice i
		this->items[i] = this->items[i+1];
	}
	
	// Reducir la cuenta de elementos
	this->cuenta--;
	return valor;
}

template <typename TIPODATO>
string Lista<TIPODATO>::comoCadena() {
	ostringstream s;
	s << "[";
	for (int i = 0; i < (this->cuenta); i++) {
		s << this->items[i];
		if (i < this->cuenta-1) 
			s << ". ";
		}
		s << "]";	
	return s.str();
}
#endif /* Lista generica hpp */
