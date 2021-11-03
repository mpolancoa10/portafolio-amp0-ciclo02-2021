// Marlon Bladimir Polanco Ayala - PA100417
#include <iostream>
#include <windows.h>	

using namespace std;

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


int menu();

class Personaje {
	public: // public functions
		Personaje(string pNombre, int  pPuntosVida); // Metodo constructor
		string recibirGolpe(int puntosPerdidos); // representa la cantidad de puntos a sustraer de los puntosVida como resultado de que el personaje reciba un golpe sin defenderse.
		bool estaVivo(); // devolverá true si los puntos de vida son mayores a cero y false, en caso contrario.
		int getPuntosVida(); // devuelve el valor del atributo privado puntosVida
		string getNombre(); // devuelve el valor del atributo privado nombre
		string comer(double puntosGanados); // es lo opuesto a recibirGolpe
	private: // private data
		string nombre;
		int puntosVida;
};

int main(){
	//Cambiar titulo
	SetConsoleTitle("Ejercicio 3 - Clases y Objetos");
	
	int opcionMenu, pPuntosVida = -1;
	string pNombre;
	int pPuntos;
	
	cout << "----------------------------------------" << endl;
	cout << " P A R A M E T R O S  I N I C I A L E S " << endl;
	cout << "----------------------------------------" << endl << endl;
	
	cout << "Ingrese Nombre: ";
	getline(cin, pNombre);
	
	// Validar que puntos de vida no sea negativo
	do {
	  cout << "Ingrese Puntos de Vida: ";
	  cin >> pPuntosVida;
	}
	while (pPuntosVida < 0);
	
	// Llena metodo constructor con la informacion solicitada
	Personaje per(pNombre, pPuntosVida);
	
	opcionMenu = menu();
	while (opcionMenu != 0)
	{
		if (opcionMenu == 1)
		{	cout << "Ingrese Puntos de Golpe: ";
			cin >> pPuntos;
			
			cout << per.recibirGolpe(pPuntos) << endl;
			SetConsoleTextAttribute(h,14);  //cambia a color amarillo
			cout << endl;
			cout << "Nombre de Personaje: " << per.getNombre() << endl;
			
			if(per.estaVivo()) 
				cout << "Esta Vivo: true" << endl;
			else 
				cout << "Esta Vivo: false" << endl;
				
			cout << "Puntos de Vida: " << per.getPuntosVida() << endl; 			
			SetConsoleTextAttribute(h,7);  // Cambia a color original
		} else if (opcionMenu == 2){
			cout << "Ingrese Puntos de Comida: ";
			cin >> pPuntos;
			
			cout << endl << per.comer(pPuntos) << endl;
			SetConsoleTextAttribute(h,14);  //cambia a color amarillo
			cout << endl;
			cout << "Nombre de Personaje: " << per.getNombre() << endl;
			
			if(per.estaVivo()) 
				cout << "Esta Vivo: true" << endl;
			else 
				cout << "Esta Vivo: false" << endl;
			
			cout << "Puntos de Vida: " << per.getPuntosVida() << endl; 			
			SetConsoleTextAttribute(h,7);  // Cambia a color original
		}

		opcionMenu = menu();
	}
	
	return 0;
}

int menu()
{
	int opcion;
	
	cout << endl;
	cout << "--------------------------------------------" << endl;
	cout << "                   M E N U                  " << endl;
	cout << "--------------------------------------------" << endl;
	cout << " 1 - Recibir Golpe" << endl << " 2 - Dar de Comer" << endl << " 0 - Salir \n" << endl << " Opcion: ";
	cin >> opcion;
	cout << "\n";

	while (opcion < 0 || opcion > 2)
	{
		if (opcion < 0 || opcion > 2)
		{
			cout << endl << "Opcion no valida" << endl << endl;
		}
		cout << "1 - Recibir Golpe" << endl << "2 - Dar de Comer" << endl << "0 - Salir \n" << endl << "Opcion: ";
		
		cin >> opcion;
	}

	return opcion;
}

// Implementacion de las funciones
Personaje::Personaje(string pNombre, int  pPuntosVida){
	nombre = pNombre;
	puntosVida = pPuntosVida;
}

string Personaje::recibirGolpe(int puntosPerdidos){
	string pResultado;
	
	if (puntosPerdidos < 0){
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		pResultado = "Los puntos perdidos deben ser mayores a 0";
	} else {
		puntosVida -= puntosPerdidos;
	
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo	
		pResultado = nombre + " ha recibido un golpe";
	}
	
	return pResultado;
}

bool Personaje::estaVivo(){
	bool pResultado;
	
	if (puntosVida > 0){
		pResultado = true;
	} else {
		pResultado = false;
	}
	
	return pResultado;
}

int Personaje::getPuntosVida(){
	return puntosVida;
}

string Personaje::getNombre(){
	return nombre;
}

string Personaje::comer(double puntosGanados){
	string pResultado;
	
	if (puntosGanados < 0){
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		pResultado = "Los puntos ganados deben ser mayores a 0";
	} else {
		if (estaVivo()){
			puntosVida += puntosGanados;
	
			SetConsoleTextAttribute(h,2);  // Cambia a color verde
			pResultado = nombre + " ha recibido comida";
		} else {
			SetConsoleTextAttribute(h,4);  // Cambia a color rojo
			pResultado = nombre + " ha fallecido, no se puede revivir a un personaje fallecido";
		}	
	}
	
	return pResultado;
}
