#include <iostream>

using namespace std;

int main(){
	int x;
	int y;
	
	cin >> x;
	cin >> y;
	
	bool var1 = true;
	bool var2 = false;
	
	cout << var1 << endl;
	cout << var2 << endl;
	// 0 = false y 1 = true
	
	cout << (x < y) << endl;         //Menor que
	cout << (x > y) << endl;         //Mayor que
	cout << (x <= y) << endl;        //Menor o igual que
	cout << (x >= y) << endl;        //Mayor o igual que
	cout << (x != y) << endl;        // Diferente que
	cout << (x == y) << endl;        //Igual que
	
	return 0;
}
