#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

const int ELEMENTOS = 5;

int main () {
	array<int, ELEMENTOS> arr = {32, 27, 64, 18, 95};
	
	cout << "Elemento" << setw(13) << "Valor" << endl;
	
	// Mostrar el valor de cada elemento
	for (size_t i = 0; i < arr.size(); i++)
		cout << setw(8) << i << setw(13) << arr[i] << endl;
		
	return 0;
}
