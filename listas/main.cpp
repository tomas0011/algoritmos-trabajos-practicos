#include <iostream>

void ejercicio1();
void ejercicio2();
void ejercicio3();

int main() {
    std::cout << "Ejercicios de listas:" << std::endl;
    std::cout << "1. Ejercicio 1" << std::endl;
    std::cout << "2. Ejercicio 2" << std::endl;
    std::cout << "3. Ejercicio 3" << std::endl;

    int opcion;
    std::cout << "Seleccione un ejercicio (1-3): ";
    std::cin >> opcion;

    if (opcion == 1) {
        ejercicio1();
    } else if (opcion == 2) {
        ejercicio2();
    } else if (opcion == 3) {
        ejercicio3();
    } else {
        std::cout << "Opcion invalida." << std::endl;
    }

    return 0;
}
