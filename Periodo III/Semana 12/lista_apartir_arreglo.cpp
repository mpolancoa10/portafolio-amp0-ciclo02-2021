#include <iostream>

using namespace std;

class ListaEnteros {
	private:
		int cuenta;
		int capacidad;
		int	*items;
		void agrandar();
	public:
		ListaEnteros (int capacidad);
		ListaEnteros();
		~ListaEnteros();
		ListaEnteros(const ListaEnteros &otra);
		bool estaVacia();
		int tamano();
		void insertar(int indice, int item);
		void adjuntar (int item);
		int obtener (int indice);
		bool contiene(int item);
		int remover(int indice);	
};

// Constructor
ListaEnteros::ListaEnteros(int capacidad){
	this->cuenta = 0;
	this->capacidad	= capacidad;
	this->items	= new int[capacidad];
}

// Esta la lista vacia?
bool ListaEnteros::estaVacia(){
	return this->cuenta == 0;
}

// Tamano de la lista
int ListaEnteros::tamano() {
	return this->cuenta;
}

// Valor del elemento en la posicion indice
int ListaEnteros::obtener (int indice) {
	if (indice < 0 || indice >= this->cuenta) throw "Indice fuera de rango";
	if (this->estaVacia()) throw "No se puede recuperar elementos de una lista vacia";
	return this->items[indice];
}

// Insertar un elemento en un indice especifico
void ListaEnteros::insertar (int indice, int item) {
	if (indice < 0 || indice > this->cuenta) throw "Indice fuera de rango"; // Validar indice
	if (this->cuenta >= this->capacidad) this->agrandar(); // Ampliar capacidad (mas info en breve)
	
	// Desplazar elementos a partir del indice a la derecha
	for (int i = cuenta - 1; i >= indice; i--)
	this->items[i+1 ]= this->items[i];
	this->items[indice] = item; // Sobrescribe el valor en indice
	this->cuenta++; // Actualiza la cuenta de elementos
}

void ListaEnteros::agrandar() {
	int *temp = this->items;
	this->capacidad *= 2;
	this->items = new int[capacidad];
	for (int i = 0; i < this->cuenta; i++)
		this->items[i] = temp[i];
	delete[] temp;
}

// Agregar un elemento al final
void ListaEnteros::adjuntar(int item){
	this->insertar(this->cuenta, item);
}

// Esta el item en la lista?
bool ListaEnteros::contiene(int item){
	for (int i = 0; i < this->cuenta; i++){
		if(this->items[i] == item) return true;
	}
	
	return false;
}

// Remover elemento en el indice "indice"
int ListaEnteros::remover(int indice) {
	if (this->estaVacia()) throw "No se puede remover elementos de una lista vacia";
	if (indice < 0 || indice >= this->cuenta) throw "Indice fuera de rango";
	
	// Lee el valor en el indice y desplaza elementos a la izquierda
	int valor = this->items[indice];
	for (int i = indice; i < cuenta - 1; i++)
		this->items[i] = this->items[i+1];
		
	this->cuenta--;
	return valor;
}

int main(){
	return 0;
}


