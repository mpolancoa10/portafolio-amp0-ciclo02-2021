#include <iostream>

using namespace std;

int main(){
	int x = 5;
	int y = 2;
	
	cout << x + y << endl; //Suma dos valores x + y
	cout << x - y << endl; //Resta un valor de otro x - y
	cout << x * y << endl; //Multiplica dos valores x * y
	
	
	x = 12;
	y = 3;
	cout << x / y << endl; //Divide un valor por otro x / y
	
	x= 5;
	y = 2;
	cout << x % y << endl; //Devluelve el residuo de la division x % y
	
	++x;                   //Aumenta el valor de una variable en 1
	cout << x << endl; 
	
	x = 5;
	--x;                   //Disminuye el valor de una variable en 1
	cout << x << endl;
	
	return 0;
}
