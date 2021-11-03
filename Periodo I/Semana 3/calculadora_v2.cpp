#include <iostream>

using namespace std;

float operar(float x, float y, char op){
	float r = 0;
	switch(op){
		case '+':
			r = x + y;
			break;
		case '-':
			r = x - y;
			break;
		case '*':
			r = x * y;
			break;
		case '/':
			r = x / y;
			break;
		default:
			cout << "Operador no valido" << endl;
	}
	return r;
}

int main(){
	float x; // El primero numero
	float y; // El segundo numero
	float r; // El resultado
	char op; // Operador matematico a usar
	
	cout << "Calculadora sencilla" << endl;
	cout << "Numero 1: ";
	cin >> x;
	cout << "Numero 2: ";
	cin >> y;
	cout << "Operacion (+|-|*|/): ";
	cin >> op;
	
	r = operar(x, y, op);
	
	cout << "x " << op << " y = " << r << endl;
		
	return 0;
}
