//ejemplo : clases e inicializacion uniforme
#include <iostream>

using namespace std;

class Circulo{
	double radius;
	public:
		Circulo(double r) { radius = r;}
		double circunf () { return 2*radius*3.14159265;}
};

int main() {
	Circulo foo (10.0); // forma funcional
	Circulo bar = 20.0; // inicializacion por asignación
	Circulo baz {30.0}; // inicialización uniforme
	Circulo qux = {40.0}; // POD like (Plain Old Data)
	cout << "Circunferencia de foo: " << foo.circunf () << "\n";
	cout << "Circunferencia de bar: " << bar.circunf () << "\n";
	cout << "Circunferencia de baz : " << baz.circunf () << "\n";
	cout << "Circunferencia de qux : " << qux.circunf () << endl;
	
	return 0;
}
