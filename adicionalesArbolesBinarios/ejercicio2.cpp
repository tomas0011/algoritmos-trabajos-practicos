#include <iostream>
#include <algorithm>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

int calcularAltura2(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int alturaIzq = calcularAltura2(raiz->izquierdo);
    int alturaDer = calcularAltura2(raiz->derecho);
    return 1 + std::max(alturaIzq, alturaDer);
}

int diametro2(Nodo* raiz, int& maxDiametro) {
    if (raiz == nullptr) {
        return 0;
    }

    int alturaIzq = diametro2(raiz->izquierdo, maxDiametro);
    int alturaDer = diametro2(raiz->derecho, maxDiametro);

    int diametroActual = alturaIzq + alturaDer + 1;
    maxDiametro = std::max(maxDiametro, diametroActual);

    return 1 + std::max(alturaIzq, alturaDer);
}

int calcularDiametro(Nodo* raiz) {
    int maxDiametro = 0;
    diametro2(raiz, maxDiametro);
    return maxDiametro;
}

void ejercicio2() {
    std::cout << "Ejercicio 2: Diametro del arbol" << std::endl;

    // Crear un arbol de ejemplo
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);
    raiz->izquierdo->izquierdo = new Nodo(4);
    raiz->izquierdo->derecho = new Nodo(5);
    raiz->derecho->derecho = new Nodo(6);
    raiz->izquierdo->izquierdo->izquierdo = new Nodo(7);
    raiz->izquierdo->izquierdo->derecho = new Nodo(8);

    int diam = calcularDiametro(raiz);
    std::cout << "Diametro del arbol: " << diam << std::endl;

    // Liberar memoria (simplificado)
    delete raiz->izquierdo->izquierdo->izquierdo;
    delete raiz->izquierdo->izquierdo->derecho;
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos, ya que visita cada nodo una vez." << std::endl;
}
