#include <iostream>

void ejercicio1();
void ejercicio2();

int main() {
    std::cout << "Ejercicios de Huffman:" << std::endl;
    std::cout << "1. Ejercicio 1" << std::endl;
    std::cout << "2. Ejercicio 2" << std::endl;

    int opcion;
    std::cout << "Seleccione un ejercicio (1-2): ";
    std::cin >> opcion;

    if (opcion == 1) {
        ejercicio1();
    } else if (opcion == 2) {
        ejercicio2();
    } else {
        std::cout << "Opcion invalida." << std::endl;
    }

    return 0;
}