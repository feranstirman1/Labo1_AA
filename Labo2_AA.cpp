
#include <iostream>

using namespace std;

struct Nodo {
	int valor;
	Nodo* sig;
}*inicio,*inicioPila;



class Cola {
	private:
		Nodo* crearNodo(int valor) {
			Nodo* n = new Nodo;
			n->valor = valor;
			n->sig = nullptr;
			return n;
		}
	public:
		Cola() {
			inicio = nullptr;
		}

		void push(int valor) {
			Nodo* n = crearNodo(valor),*temp;
			if (!inicio) {
				inicio = n;
			}
			else {
				for (temp = inicio; temp->sig; temp = temp->sig); //nos lleva al ultimo valor de la cola
				temp->sig = n;
			}
		}

		void mostrarCola() {
			Nodo* temp = inicio;
			while (temp) {
				cout << temp->valor << ", ";
				temp = temp->sig;
			}
			cout << endl;
		}

		void invertirCola() {
			if (!inicio) {
				cout << "no hay cola para invertir" << endl;
			}
			else if(!inicio->sig->sig){ //revisa si solo hay dos elementos en la cola, solo se necesita un puntero de ayuda
				Nodo* temp = inicio->sig;
				inicio->sig = nullptr;
				temp->sig = inicio;
				inicio = temp;
			}
			else {
				Nodo* temp = inicio->sig; //segundo elemento de la cola
				Nodo* temp2 = temp->sig; //tercer elemento de la cola

				inicio->sig = nullptr;
				temp->sig = inicio;

				while (temp2) { //mientras el tercer puntero siempre apunte a algo
					
					inicio = temp; //inicio pasar a ser el siguiente elemento de la cola
					temp = temp2; //inicio pasa a la posicion donde estaba el puntero final
					temp2 = temp2->sig; //el puntero final pasa al siguiente
					temp->sig = inicio; //el primer puntero apunta hacia el elemento anterior
				}

				inicio = temp; //luego de que el ultimo puntero no apunte a nada,el primer puntero esta en la posicion final, la cual sera la nueva poiscion inicial, aqui empezar inicio


			}
		}


};

class Pila {
private:
	Nodo* crearNodo(int valor) {
		Nodo* n = new Nodo;
		n->valor = valor;
		n->sig = nullptr;
		return n;
	}
public:

	Pila() {
		inicioPila = nullptr;
	}

	void push(int valor) {
		Nodo* n = crearNodo(valor);
		//cout << n->valor << " ha sido insertado a la pila" << endl;
		if (!inicioPila) {
			inicioPila = n;
		}
		else {
			n->sig = inicioPila;
			inicioPila = n;
		}
	}

	void mostrarPila() {
		Nodo* temp = inicioPila;
		while (temp) {
			cout << temp->valor << ", ";
			temp = temp->sig;
		}
		cout << endl;
	}

};

void llenarPila(Pila pila) {
	Nodo* temp = inicio;
	while (temp) {
		pila.push(temp->valor);
		//cout << "el valor insertado fue " << temp->valor << endl;
		temp = temp->sig;
	}
}

int main() {

	Cola miCola;

	miCola.push(1);
	miCola.push(2);
	miCola.push(3);
	miCola.push(4);
	miCola.push(5);
	miCola.push(6);
	miCola.push(7);

	cout << endl;

	cout << "************* CONTENIDOS DE LA COLA ANTES DE INVERTIR **************" << endl;
	cout << endl;
	miCola.mostrarCola();
	cout << endl;

	miCola.invertirCola();
	cout << "************* CONTENIDOS DE LA COLA INVERTIDA **************" << endl;
	cout << endl;

	miCola.mostrarCola();
	cout << endl;


	cout << "************* CONTENIDOS DE LA PILA **************" << endl;
	cout << endl;

	Pila miPila;
	llenarPila(miPila);
	miPila.mostrarPila();
	cout << endl;
}




