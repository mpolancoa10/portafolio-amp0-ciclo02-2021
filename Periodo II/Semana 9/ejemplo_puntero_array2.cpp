#include <iostream>

using namespace std;

int main()
{
	int c[5] = {1, 2, 3, 4, 5};
	int *p3;
	
	p3 = &c[1]; //Obtiene la direcci�n de este elemento
	cout << "*p3 = " << *p3 << endl;
	
	p3 = p3 + 2; //Apunta 2 elementos adelante
	cout << "*p3 = " << *p3 << endl;								
		
	return 0;
}
