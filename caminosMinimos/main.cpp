#include <iostream>

void dijkstra();
void floydWarshall();

int main() {
    std::cout << "Caminos Minimos:" << std::endl;
    std::cout << "1. Algoritmo de Dijkstra" << std::endl;
    std::cout << "2. Algoritmo de Floyd-Warshall" << std::endl;

    int opcion;
    std::cout << "Seleccione un algoritmo (1-2): ";
    std::cin >> opcion;

    if (opcion == 1) {
        dijkstra();
    } else if (opcion == 2) {
        floydWarshall();
    } else {
        std::cout << "Opcion invalida." << std::endl;
    }

    return 0;
}