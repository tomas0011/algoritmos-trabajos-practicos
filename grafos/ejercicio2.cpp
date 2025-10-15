#include <iostream>
#include <vector>
#include <queue>

void bfs(int origen, const std::vector<std::vector<int>>& adj) {
    int n = adj.size();
    std::vector<bool> visitado(n, false);
    std::queue<int> cola;

    visitado[origen] = true;
    cola.push(origen);

    std::cout << "BFS desde " << (origen + 1) << ": ";
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        std::cout << (actual + 1) << " ";

        for (int vecino : adj[actual]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola.push(vecino);
            }
        }
    }
    std::cout << std::endl;
}

void dfs(int actual, std::vector<bool>& visitado, const std::vector<std::vector<int>>& adj) {
    visitado[actual] = true;
    std::cout << (actual + 1) << " ";

    for (int vecino : adj[actual]) {
        if (!visitado[vecino]) {
            dfs(vecino, visitado, adj);
        }
    }
}

void ejercicio2() {
    std::cout << "Ejercicio 2: Recorridos BFS y DFS" << std::endl;

    int n, m;
    std::cout << "Ingrese numero de vertices: ";
    std::cin >> n;
    std::cout << "Ingrese numero de aristas: ";
    std::cin >> m;

    std::vector<std::vector<int>> adj(n);

    std::cout << "Ingrese las aristas (u v):" << std::endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--; v--; // Ajustar a indices 0-based
        adj[u].push_back(v);
        adj[v].push_back(u); // Grafo no dirigido
    }

    int origen;
    std::cout << "Ingrese vertice origen (1-" << n << "): ";
    std::cin >> origen;
    origen--; // Ajustar a indices 0-based

    bfs(origen, adj);

    std::vector<bool> visitado(n, false);
    std::cout << "DFS desde " << (origen + 1) << ": ";
    dfs(origen, visitado, adj);
    std::cout << std::endl;
}
