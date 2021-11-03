//
// problema1.cpp
// problema1
//
// Created by Marlon Polanco on 02/11/2021
//
#include <iostream>
#include <string>
#include <windows.h>
#include <regex> 
#include <list>
#include "pila.h"

using namespace std;

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

bool validarFormatoHTML(string estructura){
	//instanciar clase de lista
	list<string> lista;
	
	//instanciar clase Pila
    Pila<string> pila;
    
	//Aplicar expresiones regulares para obtener las etiquetas HTML
	regex self_regex("REGULAR EXPRESSIONS", regex_constants::ECMAScript | regex_constants::icase);
    regex word_regex("(<\\w+>|</\\w+>)");
    auto words_begin =  sregex_iterator(estructura.begin(), estructura.end(), word_regex);
    auto words_end = sregex_iterator();
    
    //Almacenar estructura en lista
    for (sregex_iterator i = words_begin; i != words_end; ++i) 
	{
		 smatch match = *i;
		 lista.push_back(match.str());
	}
	
	cout << "Etiquetas encontradas: " << lista.size() << endl;
	
	// Validar si lista esta vacia
	if (!lista.empty()){		
		for (list<string>::iterator i = lista.begin(); i != lista.end(); i++) {
			string etiqueta = *i;
			
			// Validar si la etiqueta es de apertura
	 	    if (etiqueta.substr(0,2) != "</") {
	 	    	pila.push(etiqueta);
			} else {
				// Validar si pila esta vacia
				if(pila.estaPilaVacia()) {
					return false;
				}
				
				// Buscar elemento de cierre en pila
				string etiq = pila.primero();
				
				string pPrimero = etiq;
				pPrimero.erase(0, 1);
				pPrimero.erase(pPrimero.size() - 1);
				
				if (etiqueta.find(pPrimero) != std::string::npos)
				{
					//Concatenar etiqueta de apertura con su cierre.	
					cout << "Etiqueta inicio: " << etiq << " | " << "Etiqueta cierre: " << etiqueta << endl;
					//Quitar etiqueta de la pila
					pila.pop();
				}
			}
		}	
		
	}
	else
	{
		return false;
	}
    
	return pila.estaPilaVacia();
}

int main(){
	//Cambiar el titulo de la consola
	SetConsoleTitleA("Problema 1 - Validar Etiquetas HTML"); 
	
	string estructura;
	bool pResultado;
	cout << "Ingrese HTML: ";
	getline(cin, estructura);
	
	cout << endl;
	pResultado = validarFormatoHTML(estructura);
	cout << endl;
	if (pResultado){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << "La estructura HTML tiene las etiquetas de apertura y cierre correctamente" << endl;
	}
	else{
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		cout << "La estructura HTML no tiene las etiquetas de apertura y cierre correctamente" << endl;
	}
	
	SetConsoleTextAttribute(h,7);  // Cambia a color original
		
	return 0;
}
