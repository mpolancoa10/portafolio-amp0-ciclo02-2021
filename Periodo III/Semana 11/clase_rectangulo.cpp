// ejemplo de clase
#include <iostream>

using namespace std;

class Rectangulo {
	int ancho, alto;
	public:
		void set_valores(int,int);
		int area() {return ancho*alto;}
};

void Rectangulo::set_valores (int x, int y){
	ancho = x;
	alto = y;
}

int main () {
	Rectangulo rect;
	rect.set_valores (3,4);
	cout << "area: " << rect.area();
	
	return 0;
}
