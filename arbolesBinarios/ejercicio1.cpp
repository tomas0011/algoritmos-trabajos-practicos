#include <iostream>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}

void ejercicio1() {
    std::cout << "Ejercicio 1: Contar nodos de un arbol binario" << std::endl;

    // Crear un arbol de ejemplo
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);
    raiz->izquierdo->izquierdo = new Nodo(4);
    raiz->izquierdo->derecho = new Nodo(5);
    raiz->derecho->derecho = new Nodo(6);

    int numNodos = contarNodos(raiz);
    std::cout << "Numero de nodos: " << numNodos << std::endl;

    // Liberar memoria (simplificado)
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos, ya que visita cada nodo una vez." << std::endl;
}