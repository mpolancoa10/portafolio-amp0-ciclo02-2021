// Marlon Bladimir Polanco Ayala - PA100417
#include <iostream>
#include <windows.h>

using namespace std;

int x, y, ini, medio, fin;
int multi;
int fini[14];
int medii[14];

// Secuencia para determinar los pasos a seguir en el proceso del calculo de MCD
string secuencia[10] = { "primer", "segundo", "tercer", "cuarto", "quinto", 
						 "sexto" , "septimo", "octavo", "noveno", "X"};

//Metodo para menu
int menu();

//Cambia los colores del texto de la consola
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void Euclides()
{
	cout << " Ingrese Numero 1: ";
	cin >> x;
	cout << " Ingrese Numero 2: ";
	cin >> y;
	
	if(x >= y)
	{
		ini = x;
		medio = y;
		multi = ini / medio;
		fin = ini%medio;
	}
	else
	{
		ini = y;
		medio = x;
		multi = ini / medio;
		fin = ini%medio;
	}
}

void cambios()
{
	int cuenta;
	int nulo = 0;
	
	for(cuenta = 0; cuenta < 15; cuenta++)
	{
		fini[cuenta] = fin;
		medii[cuenta] = medio;
	
		if (cuenta >= 10)
		{
			nulo++;
		}
		
		cout << " Este es el " << secuencia[cuenta-nulo] << " paso.\n";
		cout << " " << ini << " = " << medio << " (" << multi << ") + " << fin << "\n";
		
		if(fin == 0)
		{
			int variable = ini%medio;
			
			SetConsoleTextAttribute(h,2);  // Cambia a color verde
			
			cout << endl;
			
			// Resultado de calculo
			if(variable != 0)
			{
				cout << " El maximo comun divisor es: " << fini[cuenta-1] << " \n\n";
			}
			else if(variable == 0)
			{
				cout << " El maximo comun divisor es: " << medii[cuenta] <<" \n\n";
			}

			SetConsoleTextAttribute(h,7);  // Vuelve a cambiar a color original 
			
			break;
		}
		
		ini = medio;
		medio = fin;
		multi = ini / medio; // realizamos division
		fin = ini%medio; // obtenemos el residuo
	}
}

int main()
{
	int opcional;
	int pOpcion = 0;
	
	//Cambiar el titulo de la consola
	SetConsoleTitleA("Algoritmo Extendido Euclides"); 
	
	//Student name
	cout << " Nombre: Marlon Bladimir Polanco Ayala" << endl;
	cout << " Carnet: PA100417" << endl;
	cout << "\n";
	
	pOpcion = menu();
		
	while (pOpcion != 0)
	{
		if (pOpcion == 1){
			cout << " --------------------------------" << endl;
			cout << " ALGORITMO EXTENDIDO DE EUCLIDES " << endl;
			cout << " --------------------------------" << endl;
			
			Euclides();
			cout << endl;
			cambios();
		}

		pOpcion = menu();
	}
}

// Menu para calcular varias veces el MCD en la misma ejecucion de la consola
int menu()
{
	int opcion;
	
	cout << " --------------------------------" << endl;
	cout << "            M E N U              " << endl;
	cout << " --------------------------------" << endl;
	cout << " 1 - Algoritmo de Euclides.\n 0 - Salir del programa." << endl << endl;
	cout << " Opcion: ";
	cin >> opcion;
	cout << endl;

	return opcion;
}
