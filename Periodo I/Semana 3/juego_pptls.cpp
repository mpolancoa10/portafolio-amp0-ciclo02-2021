#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

// Prototipos
void infoEstudiante();
int menu();
string generarMovimientoComputadora();
string obtenerMovimientoJugador();
void determinarGanador(string computadora, string jugador);
void procesarEntradaJugadorPiedra(string computadora);
void procesarEntradaJugadorPapel(string computadora);
void procesarEntradaJugadorTijera(string computadora);
void procesarEntradaJugadorLagarto(string computadora);
void procesarEntradaJugadorSpock(string computadora);
void formasDeGanar();

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	int opcionMenu;
	string movimientoComputadora;
	string movimientoJugador;
	
	infoEstudiante();
	opcionMenu = menu();
	
	while (opcionMenu != 0)
	{
		if (opcionMenu == 1)
		{
			movimientoJugador = obtenerMovimientoJugador();
			movimientoComputadora = generarMovimientoComputadora();
			determinarGanador(movimientoComputadora, movimientoJugador);
			cout << "\n";
		}
		else if (opcionMenu == 2){
			formasDeGanar();
		}
		
		opcionMenu = menu();
	}
	
	return 0;
}

// Implementacion
void infoEstudiante(){
	//Change title
	SetConsoleTitle("Piedra, Papel o Tijera + Lagarto - Spock");
	
	//Student name
	cout << " Nombre: Marlon Bladimir Polanco Ayala" << endl;
	cout << " Carnet: PA100417" << endl;
	cout << "\n";
}

// Menu para jugar varias veces en la misma ejecucion de la consola
int menu()
{
	int opcion;
	
	cout << "--------------------------------------------" << endl;
	cout << "                   M E N U                  " << endl;
	cout << "--------------------------------------------" << endl;
	cout << " 1 - Jugar una partida" << endl << " 2 - Formas de Ganar" << endl << " 0 - Salir \n" << endl << " Opcion: ";
	cin >> opcion;
	cout << "\n";

	while (opcion < 0 || opcion > 2)
	{
		if (opcion < 0 || opcion > 2)
		{
			cout << endl << "Opcion no valida" << endl << endl;
		}
		cout << "1 - Jugar una partida" << endl << "2 - Formas de Ganar" << endl << "0 - Salir \n" << endl << "Opcion: ";
		
		cin >> opcion;
	}

	return opcion;
}

string generarMovimientoComputadora(){
	string movimiento;
	int numeroAleatorio;
	
	// Genero numero aleatorio
	srand(time(0));
	numeroAleatorio = rand() % 5 + 1;
	
	switch (numeroAleatorio){
		case 1:
			movimiento = "piedra";
			break;
		case 2:
			movimiento = "papel";
			break;
		case 3:
			movimiento = "tijera";
			break;
		case 4:
			movimiento = "lagarto";
			break;
		case 5:
			movimiento = "spock";
			break;
	}
	
	cout << " Computadora: " << movimiento << "\n";
	
	return movimiento;
}

string obtenerMovimientoJugador(){
	string movimiento;
	
	cout << " Juguemos a Piedra, Papel o Tijera + Lagarto - Spock \n\n";
	cout << " - piedra \n - papel \n - tijera \n - lagarto  \n - spock \n\n";
			
	cout << " Selecciona tu movimiento: ";
	cin >> movimiento;
	
	return movimiento;
}


void determinarGanador(string computadora, string jugador){
	if (computadora == jugador){
		SetConsoleTextAttribute(h,14);  //cambia a color amarillo
		cout << " Empate!\n";
	}
	else if (jugador == "piedra"){
		procesarEntradaJugadorPiedra(computadora);
	}
	else if (jugador == "papel"){
		procesarEntradaJugadorPapel(computadora);
	}
	else if (jugador == "tijera"){
		procesarEntradaJugadorTijera(computadora);
	}
	else if (jugador == "lagarto"){
		procesarEntradaJugadorLagarto(computadora);
	}
	else if (jugador == "spock"){
		procesarEntradaJugadorSpock(computadora);
	}
	else {
		cout << " Entrada no valida. Ingrese piedra, papel, tijera, lagarto o spock.\n";
	}
	
	SetConsoleTextAttribute(h,7);  // Vuelve a cambiar a color original 
}

void procesarEntradaJugadorPiedra(string computadora){
	if (computadora == "papel"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Papel cubre piedra.\n";
	}
	else if (computadora == "spock"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Spock desintegra la piedra.\n";
	}
	else if (computadora == "tijera"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Piedra rompe tijera.\n";
	}
	else if (computadora == "lagarto"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Piedra aplasta a lagarto.\n";
	}
}

void procesarEntradaJugadorPapel(string computadora){
	if (computadora == "tijera"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Tijera corta papel.\n";
	}
	else if (computadora == "lagarto"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Lagarto devora el papel.\n";
	}
	else if (computadora == "piedra"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Papel envuelve a piedra.\n";
	}
	else if (computadora == "spock"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Papel desaprueba a Spock.\n";
	}
}

void procesarEntradaJugadorTijera(string computadora){
	if (computadora == "piedra"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Piedra aplasta a tijera.\n";
	}
	else if (computadora == "spock"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Spock aplasta a tijera.\n";
	}
	else if (computadora == "papel"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Tijera corta papel.\n";
	}
	else if (computadora == "lagarto"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Tijera decapitan al lagarto.\n";
	}
}

void procesarEntradaJugadorLagarto(string computadora){
	if (computadora == "piedra"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Piedra aplasta al lagarto.\n";
	}
	else if (computadora == "tijera"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Tijeras decapitan al lagarto.\n";
	}
	else if (computadora == "spock"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Lagarto envenena a Spock.\n";
	}
	else if (computadora == "papel"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Lagarto devora el papel.\n";
	}
}

void procesarEntradaJugadorSpock(string computadora){
	if (computadora == "lagarto"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Lagarto envenena a Spock.\n";
	}
	else if (computadora == "papel"){
		SetConsoleTextAttribute(h,4);  //cambia a color rojo
		cout << " La computadora gana. Papel desaprueba a Spock.\n";
	}
	else if (computadora == "piedra"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Spock desintegra la piedra.\n";
	}
	else if (computadora == "tijera"){
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		cout << " Usted gana. Spock aplasta las tijeras.\n";
	}
}

void formasDeGanar(){
	cout << "\n Pagar ganar debes cumplir alguna de las siguientes condiciones:" << endl;
	cout << " - Las tijeras cortan el papel." << endl;
	cout << " - El papel envuelve la piedra." << endl;
	cout << " - La piedra aplasta al lagarto." << endl;
	cout << " - El lagarto envenena a Spock." << endl;
	cout << " - Spock aplasta las tijeras." << endl;
	cout << " - Las tijeras decapitan al lagarto." << endl;
	cout << " - El lagarto devora el papel." << endl;
	cout << " - El papel desaprueba a Spock." << endl;
	cout << " - Spock desintegra la piedra." << endl;
	cout << " - La piedra aplasta las tijeras.\n" << endl;
}
