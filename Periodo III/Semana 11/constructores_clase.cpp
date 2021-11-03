//ejemplo : constructor de clase
#include <iostream>

using namespace std;

class Rectangulo{
	int ancho, alto;
	public:
		Rectangulo(int,int);
		int area () {return ancho*alto;}
};

Rectangulo::Rectangulo (int x, int y){
	ancho = x;
	alto = y;
}

int main () {
	Rectangulo rect (3,4);
	Rectangulo rectb (5,6);
	cout << "rect area: " << rect.area () << endl;
	cout << "rectb area: " << rectb.area () << endl;
	
	return 0;
}
