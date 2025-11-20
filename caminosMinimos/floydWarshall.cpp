#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void floydWarshall() {
    const int N = 7;
    std::vector<std::vector<int>> dist = {
        {0, 10, 0, 0, 6, 0, 0},
        {0, 0, 5, 2, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9, 1},
        {0, 0, 2, 3, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0}
    };

    // Inicializar dist: 0 si hay arista, INF si no
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = INF;
            }
        }
    }

    // Matriz de predecesores para reconstruir caminos
    std::vector<std::vector<int>> next(N, std::vector<int>(N, -1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] != INF) {
                next[i][j] = j;
            }
        }
    }

    std::cout << "Algoritmo de Floyd-Warshall:\n";
    std::cout << "Matriz inicial de distancias:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] == INF) std::cout << "INF ";
            else std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // Floyd-Warshall
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }

        std::cout << "Después de considerar el nodo " << k + 1 << " como intermediario:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] == INF) std::cout << "INF ";
                else std::cout << dist[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    // Imprimir caminos mínimos
    std::cout << "Caminos mínimos entre todos los pares:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (dist[i][j] == INF) {
                std::cout << "No hay camino de " << i + 1 << " a " << j + 1 << "\n";
            } else {
                std::cout << "Camino de " << i + 1 << " a " << j + 1 << ": " << i + 1;
                int current = next[i][j];
                while (current != j) {
                    std::cout << " -> " << current + 1;
                    current = next[current][j];
                }
                std::cout << " -> " << j + 1 << " (distancia: " << dist[i][j] << ")\n";
            }
        }
    }
}