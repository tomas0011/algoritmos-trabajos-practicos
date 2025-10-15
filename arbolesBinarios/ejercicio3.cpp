#include <iostream>
#include <stack>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

void inordenIterativo(Nodo* raiz) {
    if (raiz == nullptr) return;

    std::stack<Nodo*> pila;
    Nodo* actual = raiz;

    while (actual != nullptr || !pila.empty()) {
        while (actual != nullptr) {
            pila.push(actual);
            actual = actual->izquierdo;
        }

        actual = pila.top();
        pila.pop();
        std::cout << actual->dato << " ";

        actual = actual->derecho;
    }
}

void ejercicio3() {
    std::cout << "Ejercicio 3: Recorrido inorden iterativo" << std::endl;

    // Crear un arbol de ejemplo
    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);
    raiz->izquierdo->izquierdo = new Nodo(4);
    raiz->izquierdo->derecho = new Nodo(5);
    raiz->derecho->derecho = new Nodo(6);

    std::cout << "Recorrido inorden: ";
    inordenIterativo(raiz);
    std::cout << std::endl;

    // Liberar memoria (simplificado)
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    std::cout << "Complejidad: O(n) donde n es el numero de nodos, ya que visita cada nodo una vez. Espacio O(h) donde h es la altura del arbol." << std::endl;
}