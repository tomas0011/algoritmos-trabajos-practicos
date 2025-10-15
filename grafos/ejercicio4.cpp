#include <iostream>
#include <vector>

void dfs(int actual, int padre, const std::vector<std::vector<int>>& adj, std::vector<bool>& visitado, bool& tieneCiclo) {
    visitado[actual] = true;

    for (int vecino : adj[actual]) {
        if (!visitado[vecino]) {
            dfs(vecino, actual, adj, visitado, tieneCiclo);
        } else if (vecino != padre) {
            tieneCiclo = true;
        }
    }
}

void ejercicio4() {
    std::cout << "Ejercicio 4: Componentes conexas y deteccion de ciclos" << std::endl;

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

    std::vector<bool> visitado(n, false);
    int componentes = 0;
    bool tieneCiclo = false;

    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            componentes++;
            dfs(i, -1, adj, visitado, tieneCiclo);
        }
    }

    std::cout << "Numero de componentes conexas: " << componentes << std::endl;
    std::cout << "El grafo " << (tieneCiclo ? "tiene" : "no tiene") << " ciclos." << std::endl;
}