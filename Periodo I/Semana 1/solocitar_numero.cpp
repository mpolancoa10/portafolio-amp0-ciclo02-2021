#include <iostream>

using namespace std;

int main(){
	int unNumero;
	
	cout << "Por favor ingrese un numero: ";
	cin >> unNumero;
	cin.ignore();
	cout << "Ingreso el numero: " << unNumero << "\n";
	cin.get();
	
	return 0;
}
