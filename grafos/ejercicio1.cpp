#include <iostream>
#include <vector>

void ejercicio1() {
    std::cout << "Ejercicio 1: Representacion y grado de vertices" << std::endl;

    int n, m;
    std::cout << "Ingrese numero de vertices: ";
    std::cin >> n;
    std::cout << "Ingrese numero de aristas: ";
    std::cin >> m;

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n, 0));

    std::cout << "Ingrese las aristas (u v):" << std::endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--; v--; // Ajustar a indices 0-based
        matriz[u][v] = 1;
        matriz[v][u] = 1; // Grafo no dirigido
    }

    std::cout << "Matriz de adyacencia:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Grados de los vertices:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int grado = 0;
        for (int j = 0; j < n; ++j) {
            grado += matriz[i][j];
        }
        std::cout << "Vertice " << (i + 1) << ": " << grado << std::endl;
    }
}
