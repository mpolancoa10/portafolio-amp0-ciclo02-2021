#include <iostream>
#include <stack>

using namespace std;

int main() {
	// Haciendo uso de La estructura stack == pila
	// Last In First Out - LIFO
	stack <int> s;
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	s.push(15);
	s.push(16);
	s.push(17);
	s.push(18);
	s.push(19);
	s.push(20);
	cout << "Tamanio de la pila o stack: " << s.size() << endl;
	cout << "Parte superior o Top del stack: " << s.top() <<endl;
	stack <int> s1;
	s1 = s;
	
	while(!s1.empty()){
		cout << s1.top() << endl;
		s1.pop();
	}
	
	return 0;
}
