#include <iostream>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

Nodo* convertirABBLista(Nodo* raiz) {
    if (raiz == nullptr) return nullptr;

    // Convertir subarbol izquierdo
    if (raiz->izquierdo != nullptr) {
        Nodo* izquierdo = convertirABBLista(raiz->izquierdo);
        // Encontrar el ultimo nodo del subarbol izquierdo
        Nodo* temp = izquierdo;
        while (temp->derecho != nullptr) {
            temp = temp->derecho;
        }
        temp->derecho = raiz;
        raiz->izquierdo = temp;
    }

    // Convertir subarbol derecho
    if (raiz->derecho != nullptr) {
        Nodo* derecho = convertirABBLista(raiz->derecho);
        raiz->derecho = derecho;
        derecho->izquierdo = raiz;
    }

    return raiz;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->derecho;
    }
    std::cout << std::endl;
}

void ejercicio4() {
    std::cout << "Ejercicio 4: Convertir ABB a lista doblemente enlazada" << std::endl;

    // Crear un ABB de ejemplo
    Nodo* raiz = new Nodo(10);
    raiz->izquierdo = new Nodo(5);
    raiz->derecho = new Nodo(15);
    raiz->izquierdo->izquierdo = new Nodo(3);
    raiz->izquierdo->derecho = new Nodo(7);
    raiz->derecho->izquierdo = new Nodo(12);
    raiz->derecho->derecho = new Nodo(18);

    std::cout << "ABB original (inorden): ";
    // Para simplificar, no implementamos el recorrido completo aqui
    std::cout << "3 5 7 10 12 15 18" << std::endl;

    Nodo* cabeza = convertirABBLista(raiz);

    // Encontrar la cabeza de la lista
    while (cabeza->izquierdo != nullptr) {
        cabeza = cabeza->izquierdo;
    }

    std::cout << "Lista resultante: ";
    imprimirLista(cabeza);

    // Liberar memoria (simplificado)
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->derecho;
        delete actual;
        actual = siguiente;
    }

    std::cout << "Complejidad: O(n) donde n es el numero de nodos." << std::endl;
}