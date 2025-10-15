#include <iostream>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

void inorden(Nodo* raiz, int& contador, int k, int& resultado) {
    if (raiz == nullptr || contador >= k) {
        return;
    }

    inorden(raiz->izquierdo, contador, k, resultado);

    contador++;
    if (contador == k) {
        resultado = raiz->dato;
        return;
    }

    inorden(raiz->derecho, contador, k, resultado);
}

int kEsimoMenor(Nodo* raiz, int k) {
    int contador = 0;
    int resultado = -1;
    inorden(raiz, contador, k, resultado);
    return resultado;
}

void ejercicio3() {
    std::cout << "Ejercicio 3: K-esimo elemento mas pequeno" << std::endl;

    // Crear un ABB de ejemplo
    Nodo* raiz = new Nodo(15);
    raiz->izquierdo = new Nodo(6);
    raiz->derecho = new Nodo(20);
    raiz->izquierdo->izquierdo = new Nodo(3);
    raiz->izquierdo->derecho = new Nodo(9);
    raiz->derecho->izquierdo = new Nodo(18);
    raiz->derecho->derecho = new Nodo(24);
    raiz->izquierdo->izquierdo->izquierdo = new Nodo(1);
    raiz->izquierdo->izquierdo->derecho = new Nodo(4);
    raiz->izquierdo->derecho->izquierdo = new Nodo(7);
    raiz->izquierdo->derecho->derecho = new Nodo(12);
    raiz->derecho->izquierdo->izquierdo = new Nodo(17);

    int k = 5;
    int elemento = kEsimoMenor(raiz, k);
    std::cout << "El " << k << "-esimo elemento mas pequeno es: " << elemento << std::endl;

    // Liberar memoria (simplificado)
    delete raiz->izquierdo->izquierdo->izquierdo;
    delete raiz->izquierdo->izquierdo->derecho;
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho->izquierdo;
    delete raiz->izquierdo->derecho->derecho;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->izquierdo->izquierdo;
    delete raiz->derecho->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(h + k) donde h es la altura del arbol y k es el elemento buscado." << std::endl;
}