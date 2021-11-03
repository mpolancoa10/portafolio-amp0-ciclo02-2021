//
// problema2.cpp
// problema2
//
// Created by Marlon Polanco on 02/11/2021
//
#include <iostream>
#include <string>
#include <windows.h>
#include <regex> // para validaciones de espacios en blanco, etc.
#include "cola.h"
#include "pila.h"

using namespace std;

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// Metodo para saber si la palabra es un palindromo
bool esUnPalindromo(string palabra){
	// Instancia a clase de colas
	Cola<char> cola;
	
	// Instancia a clase de pila
	Pila<char> pila;
	
	// Agregar palabra a cola
	for (size_t i = 0; i < palabra.length(); i++) {
		cola.enqueue(palabra[i]);
	}
	
	cout << "Cola como cadena: " << cola.colaComoCadena() << endl;
	
	// Invertir palabra
    string inverso (palabra.rbegin(), palabra.rend());    
	
	// Agregar palabra a pila orden inverso
	for (size_t i = 0; i < inverso.length(); i++) {
		char caracter = inverso[i];
		pila.push(caracter);
	}
	
	cout << "Pila como cadena: " << pila.pilaComoCadena() << endl;

	// Comparar pares
	for (size_t i = 0; i < palabra.length(); i++) { 
		string pLetraCola, pLetraPila;
		
		pLetraCola = cola.dequeue();
		pLetraPila = pila.top();
		
		if (pLetraPila != pLetraCola)
			return false;
	}
	
	return true;
}

int main(){
	//Cambiar el titulo de la consola
	SetConsoleTitleA("Problema 2 - Palabra es un Palindromo"); 
	
	string palabra;
	bool pResultado;
	cout << "Ingrese una palabra: ";
	getline(cin, palabra);
	
	// Aplicacion de validaciones del formato de palabra
	cout << endl;
	cout << "Elimiando espacios en blanco..." << endl; 
	palabra.erase(remove(palabra.begin(), palabra.end(), ' '), palabra.end());
	cout << palabra << endl;
	cout << "Elimiando numeros..." << endl; 
	palabra.erase(std::remove_if(palabra.begin(), palabra.end(), [](int ch) { return std::isdigit(ch); }), palabra.end()); 
	cout << palabra << endl;
	cout << "Elimiando caracteres no alfanumericos..." << endl; 
	palabra.erase(std::remove_if(palabra.begin(), palabra.end(), [](char c) { return !std::isalnum(c); }), palabra.end());
	cout << palabra << endl;
	cout << "Elimiando signos de puntuacion..." << endl; 
	palabra.erase(std::remove_if(palabra.begin(), palabra.end(), [](unsigned char c) { return std::ispunct(c); }), palabra.end());
	
	cout << endl;
	// validar longitud de palabra
	if (palabra.length() > 1){
		pResultado = esUnPalindromo(palabra);
		
		cout << endl;
		if (pResultado){
			SetConsoleTextAttribute(h,2);  // Cambia a color verde
			cout << "La palabra " << palabra << " es un palindromo";
		} else {
			SetConsoleTextAttribute(h,4);  // Cambia a color rojo
			cout << "La palabra " << palabra << " no es un palindromo";
		}
	}
	else {
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		cout << "Palabra ingresada no cumple los requisitos para validar si es un palindromo" << endl;
	}
	
	SetConsoleTextAttribute(h,7);  // Cambia a color original
	
	return 0;
}


