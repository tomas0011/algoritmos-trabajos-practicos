#include <iostream>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* insertar(Nodo* raiz, int val) {
    if (raiz == nullptr) return new Nodo(val);
    if (val < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, val);
    } else {
        raiz->derecho = insertar(raiz->derecho, val);
    }
    return raiz;
}

Nodo* encontrarMinimo(Nodo* raiz) {
    while (raiz->izquierdo != nullptr) raiz = raiz->izquierdo;
    return raiz;
}

Nodo* eliminar(Nodo* raiz, int val) {
    if (raiz == nullptr) return raiz;

    if (val < raiz->dato) {
        raiz->izquierdo = eliminar(raiz->izquierdo, val);
    } else if (val > raiz->dato) {
        raiz->derecho = eliminar(raiz->derecho, val);
    } else {
        if (raiz->izquierdo == nullptr) {
            Nodo* temp = raiz->derecho;
            delete raiz;
            return temp;
        } else if (raiz->derecho == nullptr) {
            Nodo* temp = raiz->izquierdo;
            delete raiz;
            return temp;
        }

        Nodo* temp = encontrarMinimo(raiz->derecho);
        raiz->dato = temp->dato;
        raiz->derecho = eliminar(raiz->derecho, temp->dato);
    }
    return raiz;
}

void imprimirArbol5(Nodo* raiz, int espacio = 0, int altura = 10) {
    if (raiz == nullptr) return;

    espacio += altura;

    imprimirArbol5(raiz->derecho, espacio);

    std::cout << std::endl;
    for (int i = altura; i < espacio; ++i) std::cout << " ";
    std::cout << raiz->dato << std::endl;

    imprimirArbol5(raiz->izquierdo, espacio);
}

void liberarArbol5(Nodo* raiz) {
    if (raiz == nullptr) return;
    liberarArbol5(raiz->izquierdo);
    liberarArbol5(raiz->derecho);
    delete raiz;
}

void ejercicio5() {
    std::cout << "Ejercicio 5: Eliminar nodo en ABB" << std::endl;

    // Construir el ABB inicial
    Nodo* raiz = nullptr;
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 6);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 3);
    raiz = insertar(raiz, 9);
    raiz = insertar(raiz, 18);
    raiz = insertar(raiz, 24);
    raiz = insertar(raiz, 1);
    raiz = insertar(raiz, 4);
    raiz = insertar(raiz, 7);
    raiz = insertar(raiz, 12);
    raiz = insertar(raiz, 17);

    std::cout << "Arbol original:" << std::endl;
    imprimirArbol5(raiz);

    std::cout << "Eliminando el nodo 6:" << std::endl;
    raiz = eliminar(raiz, 6);

    std::cout << "Arbol resultante:" << std::endl;
    imprimirArbol5(raiz);

    liberarArbol5(raiz);
}
