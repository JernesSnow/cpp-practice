#include <iostream>

using namespace std;

int main()
{

	float suma = 0.0, promedio = 0.0;
	int notas[5] = {};
	

	for (int i = 0; i < 5; i++) {
		cout << "Ingrese las notas para el estudiante " << i+1<<": ";
		cin >> notas[i];
		
	}

	int mayor = notas[0];
	int menor = notas[0];

	for (int i = 1; i < 5;i++) {
		if (mayor < notas[i]) {
			mayor = notas[i];
		}
		if (menor > notas[i]) {
			menor = notas[i];
		}
	}
	for (int i = 0; i < 5;i++) {
		cout << "El estudiante " << i+1 << " tiene una nota de: " << notas[i] << endl;
	}

	for (int i = 0; i < 5;i++) {
		suma += notas[i];
	}

	promedio = suma / 5;
	cout << "El promedio es de: " << promedio<<endl;
	cout << "el mayor es: " << mayor << endl;
	cout << "El menor es: " << menor << endl;
}

