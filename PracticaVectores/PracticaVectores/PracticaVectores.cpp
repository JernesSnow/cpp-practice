// PracticaVectores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

void buscarNota(const std::vector<int>& notas) {
    int n = 0;
    std::cout << "Digite la nota que desea buscar: " << std::endl;
    std::cin >> n;
    auto resultado = std::find(notas.begin(), notas.end(),n);
    auto cantidad = std::count(notas.begin(), notas.end(), n);
    if (resultado != notas.end()) {
        std::cout<< "La nota existe" << std::endl;
        auto posicion = resultado - notas.begin();
        std::cout << "La nota esta en la posicion: " <<posicion+1<< std::endl;

            if (cantidad > 1) {
                std::cout << "la nota aparece un total de: " << cantidad << std::endl;
            }
            else {
                std::cout << "La nota aparece una sola vez" << std::endl;
            }
    }
    else {
        std::cout << "La nota no existe" << std::endl;
    }
    
}
void mostrarNotas(const std::vector<int>& notas) {
    std::cout << "notas: " << std::endl;
    for (int n : notas) {
        std::cout << n << std::endl;
     }
}
void mostrarExtremos(const std::vector<int>& notas) {
    if (notas.empty()) {
        std::cout << "no existen notas";
    }
    else {
        auto menor = std::min_element(notas.begin(), notas.end());
        auto posicionmenor = menor - notas.begin();
        auto mayor = std::max_element(notas.begin(), notas.end());
        std::cout << "La nota menor es: " << *menor << std::endl;
        std::cout << "La nota " << *menor << " esta en la posicion: "<< posicionmenor+1 <<std::endl;
        auto posicionMayor = mayor - notas.begin();
        std::cout << "La nota mayor es: " << *mayor << std::endl;
        std::cout << "La nota " << *mayor << " esta en la posicion: " << posicionMayor+1 << std::endl;

    }

}
float calcularPromedio( const std::vector<int>& notas) {
    float promedio=0.0;
    if (notas.empty()) {
        std::cout << "no hay notas registradas para sacar el promedio"<<std::endl;
    }else{
        float suma = std::accumulate(notas.begin(), notas.end(), 0.0f);
        /*for (int n : notas) {
            suma += n;
        }*/
         promedio = suma / notas.size();
    
    }
    
    return promedio;

}
std::vector<int> buscarPosicion(const std::vector<int>& notas, int notaElegida) {
    std::vector<int>posiciones;
    auto inicio = notas.begin();
    while (inicio != notas.end()) {
        auto resultado = std::find(inicio, notas.end(), notaElegida);
        if (resultado == notas.end()) {
            break;
        }
        auto posicion = resultado - notas.begin();
        posiciones.push_back(posicion);
        inicio = resultado + 1;

    }
    return posiciones;
}
void eliminarNota(std::vector<int>& notas) {
    int notaElegida = 0, eleccion = 0;
    std::cout << "Digite la nota que desea eliminar: "; std::cin >> notaElegida;
    auto posicion = buscarPosicion(notas, notaElegida);
    if (posicion.empty()) {
        std::cout << "No existe la nota ingresada" << std::endl;
        
    }
    else {
        for (int n : posicion) {
            std::cout << "coincidencia en la posicion: " << n + 1 << std::endl;
        }
        std::cout << "cual desea eliminar: ";std::cin >> eleccion;
        if (eleccion >= 1 && eleccion <= notas.size()) {
            auto indice = eleccion - 1;
            auto notaIndice = std::find(posicion.begin(), posicion.end(), indice);
            if (notaIndice != posicion.end()) {
                std::cout << "usted esta eliminando la posicion: " << indice + 1 << std::endl;
                notas.erase(notas.begin() + indice);

            }
            else {
                std::cout << "no hay nota para eliminar";
            }

        }
        else {
            std::cout << "Opcion fuera de rango" << std::endl;
        }
    }
    
    
}

int main()
{
    int cantidad = 0;
    std::vector<int> notas;
    std::cout << "Cuantas notas desea ingresar?" << std::endl;
    std::cout << "Cantidad: "; std::cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        int nota = 0;
        std::cout << "Ingrese la nota numero " << i + 1 << ": ";
        std::cin >> nota;
        notas.push_back(nota);

    }
    mostrarNotas(notas);
    if (!notas.empty()) {
        std::cout << "\nel promedio es de: " << calcularPromedio(notas) << std::endl;

    }
    int op = 0;
    do {

        std::cout << "Presione"<<std::endl<<" 1 para agregar una nota\n2 para eliminar ultima nota\n3 para buscar una nota\n4 para eliminar una nota\n5 para salir"<<std::endl;
        std::cout << "Opcion: ";
        std::cin >> op;

        switch (op) {
            case 1: {
                int nota = 0;
                std::cout << "Ingrese la nueva nota: "; std::cin >> nota;
                notas.push_back(nota);
                break;
            }
            case 2:
                if (notas.empty()) {
                    std::cout << "No hay notas para eliminar" << std::endl;
                }else{
                    std::cout << "Eliminando la ultima nota" << std::endl;
                    notas.pop_back();
                
                }
                
                break;
            case 3:
                buscarNota(notas);
                break;
            case 4:{
                
                eliminarNota(notas);
                mostrarNotas(notas);
            }
                
                break;
            case 5:
                std::cout << "saliendo" << std::endl;
                break;
            default:
                std::cout << "La opcion digitada no existe" << std::endl;
                break;
        }
    } while (op != 5);

    
    std::cout << "a continuacion se muestran el ranking de notas"<<std::endl;
    std::sort(notas.begin(), notas.end(),std::greater<int>());
    mostrarNotas(notas);
    if(!notas.empty()){
        std::cout << "\nel promedio es de: " << calcularPromedio(notas) << std::endl;
        mostrarExtremos(notas);

    }
}