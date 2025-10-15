#include <iostream>

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

void ejercicio2() {
    std::cout << "Ejercicio 2: Calcular altura de un arbol binario" << std::endl;

    // Crear un arbol de ejemplo
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);
    raiz->izquierdo->izquierdo = new Nodo(4);
    raiz->izquierdo->derecho = new Nodo(5);
    raiz->derecho->derecho = new Nodo(6);

    int altura = calcularAltura(raiz);
    std::cout << "Altura del arbol: " << altura << std::endl;

    // Liberar memoria (simplificado)
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos, ya que visita cada nodo una vez." << std::endl;
}
