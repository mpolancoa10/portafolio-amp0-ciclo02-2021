#include <iostream>

using namespace std;

int main(){
	int x;
	int y;
	
	cin >> x;
	cin >> y;
	
	x += y;         //equivale a x = x + 3
	cout << x << endl;
	
	
	x -= y;        //equivale a x = x - 3
	cout << x << endl;
	
	x *= y;        //equivale a x = x * 3
	cout << y << endl;
	
	x /= y;        //equivale a x = x % 3
	cout << y << endl;
	
	return 0;
}
