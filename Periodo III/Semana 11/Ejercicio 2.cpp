// Marlon Bladimir Polanco Ayala - PA100417
#include <ctime>
#include <iostream>
#include <windows.h>	

using namespace std;

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class Persona {
	public: // public functions
		Persona(string pNombres, string pApellidos, int pAnioNacimiento); // Metodo constructor
		string nombreCompleto(); // devolver los nombres concatenados con un espacio en blanco y con los apellidos de la persona.
		int edad(); //  devolverá el resultado de restar el año de nacimiento del año actual
	private: // private data
		string nombres;
		string apellidos;
		int anioNacimiento;
};

int main(){
	//Cambiar titulo
	SetConsoleTitle("Ejercicio 2 - Clases y Objetos");
	
	string nombres, apellidos;
	int anioNacimiento;
	
	cout << "----------------------------------------" << endl;
	cout << " P A R A M E T R O S  I N I C I A L E S " << endl;
	cout << "----------------------------------------" << endl << endl;
	
	cout << "Ingrese Nombres: ";
	getline(cin, nombres);
	cout << "Ingrese Apellidos: ";
	getline(cin, apellidos);
	
	// Validar que anño no sea negativo
	do {
	  cout << "Ingrese Anio de Nacimiento: ";
	  cin >> anioNacimiento;
	}
	while (anioNacimiento < 0);
	
	// Llena metodo constructor con la informacion solicitada
	Persona per(nombres, apellidos, anioNacimiento);
	
	SetConsoleTextAttribute(h,2);  // Cambia a color verde
	cout << endl;
	cout << per.nombreCompleto() << endl;
	cout << "Edad: " << per.edad() << " anios" << endl;
	SetConsoleTextAttribute(h,7);  // Cambia a color original
	
	return 0;
}

//Implementacion de las funciones
Persona::Persona(string pNombres, string pApellidos, int pAnioNacimiento){
	nombres = pNombres;
	apellidos = pApellidos;
	anioNacimiento = pAnioNacimiento;
}

string Persona::nombreCompleto(){
	return "Nombre Completo: " + nombres + " " + apellidos;
}

int Persona::edad(){
	int year, edad;
	time_t current_time;
	current_time = time(NULL);
	
	// Año actual
	year = 1970 + current_time / 31537970;
	
	if (anioNacimiento <= year){
		edad = year - anioNacimiento;
	} else {
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		cout << "El anio no debe ser mayor al actual" << endl;
		edad = 0;
	}
	
	return edad;
}
