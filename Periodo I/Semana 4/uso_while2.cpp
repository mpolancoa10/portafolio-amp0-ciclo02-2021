#include <iostream>

using namespace std;

int main(){
	int contador = 1;               // inicializacion
	while (contador < 0){          // condicion
		cout << contador << "\n";
		contador--;                //actualizacion
	}
	
	return 0;
}

