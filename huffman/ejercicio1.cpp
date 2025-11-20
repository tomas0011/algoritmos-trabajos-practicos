#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct NodoHuffman {
    char caracter;
    int frecuencia;
    NodoHuffman* izquierdo;
    NodoHuffman* derecho;

    NodoHuffman(char c, int f) : caracter(c), frecuencia(f), izquierdo(nullptr), derecho(nullptr) {}
};

struct Comparador {
    bool operator()(NodoHuffman* a, NodoHuffman* b) {
        return a->frecuencia > b->frecuencia;
    }
};

void asignarCodigos(NodoHuffman* raiz, string codigo, map<char, string>& codigos) {
    if (!raiz) return;
    if (raiz->caracter != '\0') {
        codigos[raiz->caracter] = codigo;
        return;
    }
    asignarCodigos(raiz->izquierdo, codigo + "0", codigos);
    asignarCodigos(raiz->derecho, codigo + "1", codigos);
}

void ejercicio1() {
    cout << "Ejercicio 1: Crear el Arbol de Huffman" << endl;

    // Frecuencias de caracteres
    vector<pair<char, int>> frecuencias = {
        {'A', 25},
        {'B', 20},
        {'C', 15},
        {'D', 15},
        {'E', 10},
        {'F', 15}
    };

    cout << "Frecuencias de caracteres:" << endl;
    for (auto& p : frecuencias) {
        cout << p.first << ": " << p.second << "%" << endl;
    }

    // Construir el arbol de Huffman con impresion paso a paso
    priority_queue<NodoHuffman*, vector<NodoHuffman*>, Comparador> pq;
    for (auto& p : frecuencias) {
        pq.push(new NodoHuffman(p.first, p.second));
    }

    cout << "\nConstruccion del arbol de Huffman paso a paso:" << endl;
    int paso = 1;
    while (pq.size() > 1) {
        cout << "Paso " << paso << ":" << endl;

        NodoHuffman* izq = pq.top(); pq.pop();
        NodoHuffman* der = pq.top(); pq.pop();

        cout << "Combinando: ";
        if (izq->caracter != '\0') cout << izq->caracter << "(" << izq->frecuencia << ")";
        else cout << "(" << izq->frecuencia << ")";
        cout << " y ";
        if (der->caracter != '\0') cout << der->caracter << "(" << der->frecuencia << ")";
        else cout << "(" << der->frecuencia << ")";
        cout << " -> nuevo nodo (" << izq->frecuencia + der->frecuencia << ")" << endl;

        NodoHuffman* nuevo = new NodoHuffman('\0', izq->frecuencia + der->frecuencia);
        nuevo->izquierdo = izq;
        nuevo->derecho = der;
        pq.push(nuevo);
        paso++;
    }

    NodoHuffman* raiz = pq.top();

    // Asignar codigos binarios
    map<char, string> codigos;
    asignarCodigos(raiz, "", codigos);

    cout << "\nCodigos binarios asignados:" << endl;
    for (auto& p : codigos) {
        cout << p.first << ": " << p.second << endl;
    }

    // Calcular longitud total en bits para 100 caracteres
    int totalBits = 0;
    cout << "\nCalculo de longitud total para 100 caracteres:" << endl;
    for (auto& p : frecuencias) {
        int numChars = p.second; // porcentaje directamente como numero de caracteres
        int len = codigos[p.first].length();
        int bits = numChars * len;
        totalBits += bits;
        cout << p.first << ": " << numChars << " caracteres * " << len << " bits = " << bits << " bits" << endl;
    }
    cout << "Longitud total: " << totalBits << " bits" << endl;
}