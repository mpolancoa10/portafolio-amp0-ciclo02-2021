//
// pila.h
// pila
//
// Created by Marlon Polanco on 02/11/2021
//

#ifndef PILA_H
#define PILA_H
#include "lista_generica.hpp"
#include <string>

template <typename TIPODATO>
class Pila : private Lista<TIPODATO> {
	public:
		// Constructor
		Pila();
		// Agregar un elemento en la parte superior
		push (TIPODATO item);
		// Remover un elemento de la parte superior
		TIPODATO pop();
		// Remover un elemento al inicio de la pila
		TIPODATO top();
		bool estaPilaVacia();
		string pilaComoCadena();
		// Primer registro de pila
		TIPODATO primero();
};

template<typename TIPODATO>
Pila<TIPODATO>::Pila(){
	Lista<TIPODATO> Lista;
}

template<typename TIPODATO>
Pila<TIPODATO>::push(TIPODATO item){
	this->adjuntar(item);
}

template<typename TIPODATO>
TIPODATO Pila<TIPODATO>::pop() {
	return this->remover(this->tamano() - 1);
}

template<typename TIPODATO>
bool Pila<TIPODATO>::estaPilaVacia(){
	return this->estaVacia();
}

template<typename TIPODATO>
string Pila<TIPODATO>::pilaComoCadena(){
	return this->comoCadena();
}

template<typename TIPODATO>
TIPODATO Pila<TIPODATO>::top() {
	return this->remover(0);
}

template<typename TIPODATO>
TIPODATO Pila<TIPODATO>::primero() {
	return this->obtener(this->tamano() - 1);
}
#endif
