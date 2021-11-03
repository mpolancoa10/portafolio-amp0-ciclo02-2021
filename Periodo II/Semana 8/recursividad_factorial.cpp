#include <iostream>

using namespace std;

unsigned long long int factorial(int n)
{	
	if(n < 0)
	{
		return (-1); /*Valor incorrecto*/
	}
	else if(n == 0)
	{
		return (1); /*Condicion final*/
	}
	else
	{
		cout << " n = " << n << endl;
		
		return (n*factorial(n-1));
	}
}

int main()
{
	int value;
	
	cout << "Encuentre el factorial de un numero: ";
	cin >> value;
	cout << "El factorial del numero dado es : " << factorial(value) << endl;
	
	return 0;
}
