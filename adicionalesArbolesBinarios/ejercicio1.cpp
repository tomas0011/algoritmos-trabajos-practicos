#include <iostream>
#include <algorithm>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

int calcularAltura(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int alturaIzq = calcularAltura(raiz->izquierdo);
    int alturaDer = calcularAltura(raiz->derecho);
    return 1 + std::max(alturaIzq, alturaDer);
}

bool esAVL(Nodo* raiz) {
    if (raiz == nullptr) {
        return true;
    }

    int alturaIzq = calcularAltura(raiz->izquierdo);
    int alturaDer = calcularAltura(raiz->derecho);

    if (std::abs(alturaIzq - alturaDer) > 1) {
        return false;
    }

    return esAVL(raiz->izquierdo) && esAVL(raiz->derecho);
}

void ejercicio1() {
    std::cout << "Ejercicio 1: Verificacion de AVL" << std::endl;

    // Crear un arbol AVL de ejemplo
    Nodo* raiz = new Nodo(10);
    raiz->izquierdo = new Nodo(5);
    raiz->derecho = new Nodo(15);
    raiz->izquierdo->izquierdo = new Nodo(3);
    raiz->izquierdo->derecho = new Nodo(7);
    raiz->derecho->izquierdo = new Nodo(12);
    raiz->derecho->derecho = new Nodo(18);

    bool esAvl = esAVL(raiz);
    std::cout << "El arbol es AVL: " << (esAvl ? "Si" : "No") << std::endl;

    // Liberar memoria
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos, ya que calcula la altura para cada nodo." << std::endl;
}