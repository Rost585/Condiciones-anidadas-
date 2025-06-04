#include <iostream>
using namespace std;

void situacion1() {
	int decision1, decision2, decision3;
	
	cout << "Situación 1: Aventura en el bosque\n";
	cout << "1. Adentrarse en el bosque\n2. Quedarse en el campamento\n";
	cin >> decision1;
	
	if (decision1 == 1) {
		cout << "Has encontrado un rio. ¿Nadas o buscas un puente?\n";
		cout << "1. Nadar\n2. Buscar puente\n";
		cin >> decision2;
		
		if (decision2 == 1) {
			cout << "Te caíste en una corriente fuerte, pero logras salir con vida.\n";
		} else if (decision2 == 2) {
			cout << "Has cruzado el río sin problemas.\n";
		}
	} else if (decision1 == 2) {
		cout << "Pasas la noche tranquilo, pero no encuentras comida.\n";
	}
	
	cout << "¿Sigues el sendero o exploras una zona desconocida?\n";
	cout << "1. Seguir el sendero\n2. Explorar la zona desconocida\n";
	cin >> decision3;
	
	if (decision3 == 1) {
		cout << "Has llegado a un pueblo y pides ayuda.\n";
	} else if (decision3 == 2) {
		cout << "Te encuentras con un animal salvaje, pero logras escapar.\n";
	}
}

void situacion2() {
	int decision1, decision2, decision3;
	
	cout << "Situación 2: Viaje espacial\n";
	cout << "1. Lanzar la nave a la luna\n2. Lanzar la nave a Marte\n";
	cin >> decision1;
	
	if (decision1 == 1) {
		cout << "La nave aterriza sin problemas en la luna.\n";
	} else if (decision1 == 2) {
		cout << "La nave aterriza de forma forzada debido a una tormenta en Marte.\n";
	}
	
	cout << "¿Exploras una cueva o un campo de rocas?\n";
	cout << "1. Cueva\n2. Campo de rocas\n";
	cin >> decision2;
	
	if (decision2 == 1) {
		cout << "Has encontrado un mineral valioso.\n";
	} else if (decision2 == 2) {
		cout << "Te encuentras con una extraña criatura.\n";
	}
	
	cout << "¿Regresas a la nave o sigues explorando?\n";
	cout << "1. Regresar\n2. Explorar más\n";
	cin >> decision3;
	
	if (decision3 == 1) {
		cout << "Un fallo técnico te obliga a hacer una reparación urgente.\n";
	} else if (decision3 == 2) {
		cout << "Has encontrado una base secreta abandonada.(>o<)\n";
	}
}

int main() {
	int situacion;
	
	cout << "Elige una situación:\n";
	cout << "1. Aventura en el bosque\n";
	cout << "2. Viaje espacial\n";
	cin >> situacion;
	
	if (situacion == 1) {
		situacion1();
	} else if (situacion == 2) {
		situacion2();
	}
	
	return 0;
}
