#include <iostream>
#include<string>
#include<limits>

using namespace std;


string  obtenerResultado(int nota) {
    if (nota >= 90) {
         return  "Excelente";
    }
    if (nota >=80) {
         return "Muy bueno";

    }
    if (nota >= 70) {
         return  "Aprobado";

    }
    
         return "Reprobado";

}

void mostrarResultado(const string& nombre, int nota,  const string& resultado) {
    cout << "Estudiante: " << nombre;
    cout << "\nNota: " << nota;
    cout << "\nResultado: " << resultado << endl;
}

int main()
{
    string nombre = "", resultado="";
    int nota = 0, op = 0;

    do {

        do  {
            cout << "===== SISTEMA DE CALIFICACIONES =====" << endl;
            cout << "Ingrese el nombre del estudiante: "; getline(cin, nombre);
            cout << "\nIngrese la nota(0 - 100) : "; 
            cin >> nota;
                while (cin.fail()) {
                    cout << "ha ingresado un dato erroneo" << endl;
                    cin.clear();//restaurar el estado de cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');// ignoramos caracteres, limite de numeros, del tamanno de un stream, tomamos el maximo hasta llegar a encontrar un enter con \n
                    cout << "\nIngrese la nota(0 - 100) : "; cin >> nota;
                }
          


            if (nota > 100 || nota < 0)
                cout << "Ingrese una nota valida"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (nota > 100 || nota < 0);
        
            resultado= obtenerResultado(nota);
            mostrarResultado(nombre, nota, resultado );
       

        do {
            cout << "\nDesea ingresar otro estudiante?" << endl
                << "1. Si\n"
                << "2. No\n";
            
            cin >> op;
            while (cin.fail()) {
                cout << "ha ingresado un dato erroneo" << endl;
                cin.clear();//restaurar el estado de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> op;
            }

            cin.ignore(1000, '\n');

            if (op > 2 || op < 1) {
                cout << "la opcion digitada no existe, eliga 1 para continuar o 2 para salir"<<endl;
            }
        } while (op > 2 || op < 1);
        
    } while (op!= 2);
}


