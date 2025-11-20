#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

const int INF = std::numeric_limits<int>::max();

void dijkstra() {
    const int N = 7;
    std::vector<std::vector<int>> graph = {
        {0, 10, 0, 0, 6, 0, 0},
        {0, 0, 5, 2, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9, 1},
        {0, 0, 2, 3, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0}
    };

    int source = 0; // Nodo 1 (índice 0)
    std::vector<int> dist(N, INF);
    std::vector<int> prev(N, -1);
    std::vector<bool> visited(N, false);
    dist[source] = 0;

    // Priority queue: pair<distance, node>
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, source});

    std::cout << "Algoritmo de Dijkstra desde el nodo 1 (índice 0):\n";
    std::cout << "Paso inicial:\n";
    std::cout << "Distancias: ";
    for (int i = 0; i < N; ++i) {
        if (dist[i] == INF) std::cout << "INF ";
        else std::cout << dist[i] << " ";
    }
    std::cout << "\nVisitados: ninguno\n";
    std::cout << "Predecesores: ";
    for (int i = 0; i < N; ++i) {
        if (prev[i] == -1) std::cout << "- ";
        else std::cout << prev[i] + 1 << " ";
    }
    std::cout << "\n\n";

    int step = 1;
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        std::cout << "Paso " << step << ": Procesando nodo " << u + 1 << " (distancia " << cost << ")\n";
        std::cout << "Distancias: ";
        for (int i = 0; i < N; ++i) {
            if (dist[i] == INF) std::cout << "INF ";
            else std::cout << dist[i] << " ";
        }
        std::cout << "\nVisitados: ";
        for (int i = 0; i < N; ++i) {
            if (visited[i]) std::cout << (i + 1) << " ";
        }
        std::cout << "\nPredecesores: ";
        for (int i = 0; i < N; ++i) {
            if (prev[i] == -1) std::cout << "- ";
            else std::cout << prev[i] + 1 << " ";
        }
        std::cout << "\n\n";

        for (int v = 0; v < N; ++v) {
            if (graph[u][v] > 0 && !visited[v]) {
                int alt = dist[u] + graph[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.push({alt, v});
                }
            }
        }
        step++;
    }

    // Imprimir caminos mínimos
    std::cout << "Caminos mínimos desde el nodo 1:\n";
    for (int target = 0; target < N; ++target) {
        if (dist[target] == INF) {
            std::cout << "No hay camino a nodo " << target + 1 << "\n";
        } else {
            std::stack<int> path;
            int current = target;
            while (current != -1) {
                path.push(current + 1);
                current = prev[current];
            }
            std::cout << "Camino a nodo " << target + 1 << ": ";
            while (!path.empty()) {
                std::cout << path.top();
                path.pop();
                if (!path.empty()) std::cout << " -> ";
            }
            std::cout << " (distancia: " << dist[target] << ")\n";
        }
    }
}