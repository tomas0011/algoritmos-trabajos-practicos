#include <iostream>
#include <climits>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

bool esABB(Nodo* raiz, int min = INT_MIN, int max = INT_MAX) {
    if (raiz == nullptr) {
        return true;
    }

    if (raiz->dato <= min || raiz->dato >= max) {
        return false;
    }

    return esABB(raiz->izquierdo, min, raiz->dato) &&
           esABB(raiz->derecho, raiz->dato, max);
}

void ejercicio5() {
    std::cout << "Ejercicio 5: Validacion de ABB" << std::endl;

    // Crear un arbol que es ABB
    Nodo* raiz = new Nodo(10);
    raiz->izquierdo = new Nodo(5);
    raiz->derecho = new Nodo(15);
    raiz->izquierdo->izquierdo = new Nodo(3);
    raiz->izquierdo->derecho = new Nodo(7);
    raiz->derecho->izquierdo = new Nodo(12);
    raiz->derecho->derecho = new Nodo(18);

    bool esAbb = esABB(raiz);
    std::cout << "El arbol es ABB: " << (esAbb ? "Si" : "No") << std::endl;

    // Liberar memoria
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos." << std::endl;
}
