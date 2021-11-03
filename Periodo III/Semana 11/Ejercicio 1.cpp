// Marlon Bladimir Polanco Ayala - PA100417
#include <iostream>
#include <windows.h>	

using namespace std;

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


int menu();

class CuentaBancaria {
	public: // public functions
		CuentaBancaria(string pNumeroCuenta, string pNombreTitular, double pSaldo); // Metodo constructor
		double getSaldo(); // devuelve el saldo disponible en la cuenta bancaria
		string getNumeroCuenta(); // devuelve el numeroCuenta asociado a la cuenta bancaria
		string getNombreTitular(); // devuelve el nombreTitular asociado a la cuenta bancaria
		string depositar(double importeDeposito); // deberá sumarse al saldo de la cuenta
		string retirar(double importeRetiro); // deberá restarse del saldo de la cuenta
	private: // private data
		string numeroCuenta;
		string nombreTitular;
		double saldo;
};

int main(){
	//Cambiar titulo
	SetConsoleTitle("Ejercicio 1 - Clases y Objetos");
	
	int opcionMenu;
	string pNumeroCuenta, pNombreTitular;
	double pSaldo = -1, importe;
	
	cout << "----------------------------------------" << endl;
	cout << " P A R A M E T R O S  I N I C I A L E S " << endl;
	cout << "----------------------------------------" << endl << endl;
	
	cout << "Ingrese Numero de Cuenta: ";
	getline(cin, pNumeroCuenta);
	cout << "Ingrese Nombre de Titular: ";
	getline(cin, pNombreTitular);

	// Validar que saldo no sea negativo
	do {
	  cout << "Ingrese Saldo Inicial: ";
	  cin >> pSaldo;
	}
	while (pSaldo < 0);
		
	// Llena metodo constructor con la informacion solicitada
	CuentaBancaria cuenta(pNumeroCuenta, pNombreTitular, pSaldo);
	
	opcionMenu = menu();
	while (opcionMenu != 0)
	{
		if (opcionMenu == 1)
		{	cout << "Ingrese Importe a Depositar: ";
			cin >> importe;
			
			SetConsoleTextAttribute(h,14);  //cambia a color amarillo
			cout << endl;
			cout << "Nombre de Titular:" << cuenta.getNombreTitular() << endl;
			cout << "Numero de Cuenta:" << cuenta.getNumeroCuenta() << endl;
			cout << endl << cuenta.depositar(importe) << endl;
			SetConsoleTextAttribute(h,7);  // Cambia a color original
		} else if (opcionMenu == 2){
			cout << "Ingrese Importe a Retirar: ";
			cin >> importe;
			
			SetConsoleTextAttribute(h,14);  //cambia a color amarillo
			cout << endl;
			cout << "Nombre de Titular:" << cuenta.getNombreTitular() << endl;
			cout << "Numero de Cuenta:" << cuenta.getNumeroCuenta() << endl;
			cout << endl << cuenta.retirar(importe) << endl;
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
	cout << " 1 - Depositar" << endl << " 2 - Retirar" << endl << " 0 - Salir \n" << endl << " Opcion: ";
	cin >> opcion;
	cout << "\n";

	while (opcion < 0 || opcion > 2)
	{
		if (opcion < 0 || opcion > 2)
		{
			cout << endl << "Opcion no valida" << endl << endl;
		}
		cout << "1 - Depositar" << endl << "2 - Retirar" << endl << "0 - Salir \n" << endl << "Opcion: ";
		
		cin >> opcion;
	}

	return opcion;
}

// Implementacion de las funciones
CuentaBancaria::CuentaBancaria(string pNumeroCuenta, string pNombreTitular, double pSaldo){
	numeroCuenta = pNumeroCuenta;
	nombreTitular = pNombreTitular;
	saldo = pSaldo;
}

double CuentaBancaria::getSaldo(){
	return saldo;
}

string CuentaBancaria::getNumeroCuenta(){
	return numeroCuenta;
}

string CuentaBancaria::getNombreTitular(){
	return nombreTitular;
}

string CuentaBancaria::depositar(double importeDeposito){
	string pResultado;
	
	if (importeDeposito < 0){
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		pResultado = "El importe a depositar debe ser mayor a 0";
	} else{
		saldo += importeDeposito;
		SetConsoleTextAttribute(h,2);  // Cambia a color verde
		pResultado = "Se ha depasitado el importe. Su nuevo saldo es: $" + to_string(getSaldo());
	}
	
	return pResultado;
}

string CuentaBancaria::retirar(double importeRetiro){
	string pResultado;
	double nuevoSaldo = 0.00;
	
	if (importeRetiro < 0){
		SetConsoleTextAttribute(h,4);  // Cambia a color rojo
		pResultado = "El importe a retirar debe ser mayor a 0";
	} else {
		nuevoSaldo = saldo - importeRetiro;
	
		if (nuevoSaldo >= 0){
			saldo = nuevoSaldo;
			SetConsoleTextAttribute(h,2);  // Cambia a color verde
			pResultado = "Se ha retirmado el monto satisfactoriamente. Su nuevo saldo es: $" + to_string(getSaldo());
		} else{
			SetConsoleTextAttribute(h,4);  // Cambia a color rojo
			pResultado = "El monto a retirar es mayor al dispible. Su saldo es de: $" + to_string(getSaldo());
		}	
	}
	
	return pResultado;	
}
