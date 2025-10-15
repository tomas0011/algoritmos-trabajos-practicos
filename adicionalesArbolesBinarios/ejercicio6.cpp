#include <iostream>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

void espejo(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }

    // Intercambiar hijos izquierdo y derecho
    Nodo* temp = raiz->izquierdo;
    raiz->izquierdo = raiz->derecho;
    raiz->derecho = temp;

    // Recursivamente hacer espejo de los subarboles
    espejo(raiz->izquierdo);
    espejo(raiz->derecho);
}

void inorden2(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden2(raiz->izquierdo);
    std::cout << raiz->dato << " ";
    inorden2(raiz->derecho);
}

void ejercicio6() {
    std::cout << "Ejercicio 6: Arbol espejo" << std::endl;

    // Crear un arbol de ejemplo
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);
    raiz->izquierdo->izquierdo = new Nodo(4);
    raiz->izquierdo->derecho = new Nodo(5);
    raiz->derecho->derecho = new Nodo(6);

    std::cout << "Arbol original (inorden): ";
    inorden2(raiz);
    std::cout << std::endl;

    espejo(raiz);

    std::cout << "Arbol espejo (inorden): ";
    inorden2(raiz);
    std::cout << std::endl;

    // Liberar memoria
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos." << std::endl;
}
