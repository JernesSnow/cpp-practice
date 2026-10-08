#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string nombre = "";
	int vocales = 0;
	int consonantes = 0;
	int espacios = 0;
	int palabras = 0;
	cout << "Introducir el texto: ";
	getline(cin, nombre);
	cout << "el nombre tiene " << nombre.length() << " caracteres" << endl;
	for (int j = 0; j < nombre.length();j++) {
		char caracter = nombre[j];
		caracter = tolower(caracter);

		if (caracter =='a'|| caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
			vocales ++;
		}else if (caracter == ' ') {
			espacios++;
		}
		else if (isalpha(caracter)) {
			consonantes++;
		}
	}
	for (int i = 0; i < nombre.length(); i++) {
		char caracter = nombre[i];
		if (isalpha(caracter)){
			if (i == 0) {
				palabras++;
			}
			else if (!isalpha(nombre[i - 1]) ) {
				palabras++;
			}
		
		}
		
	}
	cout << "la cantidad de vocales son de: " << vocales<<endl;
	cout << "la cantidad de espacios son de: " << espacios<<endl;
	cout << "la cantidad de consonantes que no vocales son de: " << consonantes<<endl;
	cout << "la cantidad de palabras son de: " << palabras << endl;


}


