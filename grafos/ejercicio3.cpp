#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

struct Arista {
    int u, v, peso;
};

bool comparar(const Arista& a, const Arista& b) {
    return a.peso < b.peso;
}

int encontrar(std::vector<int>& padre, int i) {
    if (padre[i] == i) return i;
    return padre[i] = encontrar(padre, padre[i]);
}

void unir(std::vector<int>& padre, std::vector<int>& rango, int x, int y) {
    int raizX = encontrar(padre, x);
    int raizY = encontrar(padre, y);

    if (rango[raizX] < rango[raizY]) {
        padre[raizX] = raizY;
    } else if (rango[raizX] > rango[raizY]) {
        padre[raizY] = raizX;
    } else {
        padre[raizY] = raizX;
        rango[raizX]++;
    }
}

std::vector<Arista> kruskal(std::vector<Arista>& aristas, int n) {
    std::sort(aristas.begin(), aristas.end(), comparar);

    std::vector<int> padre(n), rango(n, 0);
    for (int i = 0; i < n; ++i) padre[i] = i;

    std::vector<Arista> mst;
    for (const auto& arista : aristas) {
        int raizU = encontrar(padre, arista.u);
        int raizV = encontrar(padre, arista.v);

        if (raizU != raizV) {
            mst.push_back(arista);
            unir(padre, rango, raizU, raizV);
        }
    }

    return mst;
}

std::vector<Arista> prim(std::vector<std::vector<std::pair<int, int>>>& grafo, int n) {
    std::vector<bool> visitado(n, false);
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;

    visitado[0] = true;
    for (auto& vecino : grafo[0]) {
        pq.push({vecino.second, 0, vecino.first});
    }

    std::vector<Arista> mst;
    while (!pq.empty()) {
        auto [peso, u, v] = pq.top();
        pq.pop();

        if (visitado[v]) continue;

        visitado[v] = true;
        mst.push_back({u, v, peso});

        for (auto& vecino : grafo[v]) {
            if (!visitado[vecino.first]) {
                pq.push({vecino.second, v, vecino.first});
            }
        }
    }

    return mst;
}

void ejercicio3() {
    std::cout << "Ejercicio 3: Arbol de expansion minima" << std::endl;

    std::vector<Arista> aristas = {
        {0, 1, 4}, {0, 2, 2}, {1, 2, 5}, {1, 3, 10}, {2, 3, 3}, {2, 4, 4}, {3, 4, 11}
    };

    int n = 5; // Vértices A, B, C, D, E

    // Kruskal
    std::vector<Arista> mstKruskal = kruskal(aristas, n);
    int costoKruskal = 0;
    std::cout << "MST con Kruskal:" << std::endl;
    for (const auto& arista : mstKruskal) {
        std::cout << char('A' + arista.u) << "-" << char('A' + arista.v) << " (" << arista.peso << ")" << std::endl;
        costoKruskal += arista.peso;
    }
    std::cout << "Costo total: " << costoKruskal << std::endl;

    // Prim
    std::vector<std::vector<std::pair<int, int>>> grafo(n);
    for (const auto& arista : aristas) {
        grafo[arista.u].push_back({arista.v, arista.peso});
        grafo[arista.v].push_back({arista.u, arista.peso});
    }

    std::vector<Arista> mstPrim = prim(grafo, n);
    int costoPrim = 0;
    std::cout << "MST con Prim:" << std::endl;
    for (const auto& arista : mstPrim) {
        std::cout << char('A' + arista.u) << "-" << char('A' + arista.v) << " (" << arista.peso << ")" << std::endl;
        costoPrim += arista.peso;
    }
    std::cout << "Costo total: " << costoPrim << std::endl;
}
