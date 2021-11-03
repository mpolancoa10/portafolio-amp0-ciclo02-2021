#include <iostream>

using namespace std;

int main(){
	int a = 5;
	for (int i = 0; i <= 10; i++){
		cout << "a: " << a << endl;
		cout << "i: " << i << endl;
		
		if(i % 2 == 0)
			continue;
		a = a + i;
		if (a > 20)
			break;
		cout << "a + i: " << a << endl;
	}
	
	return 0;
}
