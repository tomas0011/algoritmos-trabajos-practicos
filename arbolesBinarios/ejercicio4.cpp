#include <iostream>
#include <vector>
#include <string>

struct Nodo {
    char dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(char val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

int buscarIndice(const std::vector<char>& arr, char val, int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (arr[i] == val) return i;
    }
    return -1;
}

Nodo* construirArbol(const std::vector<char>& preorden, const std::vector<char>& inorden, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    char raiz = preorden[preStart];
    Nodo* nodoRaiz = new Nodo(raiz);

    int indiceRaiz = buscarIndice(inorden, raiz, inStart, inEnd);

    int tamIzq = indiceRaiz - inStart;

    nodoRaiz->izquierdo = construirArbol(preorden, inorden, preStart + 1, preStart + tamIzq, inStart, indiceRaiz - 1);
    nodoRaiz->derecho = construirArbol(preorden, inorden, preStart + tamIzq + 1, preEnd, indiceRaiz + 1, inEnd);

    return nodoRaiz;
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierdo);
    postorden(raiz->derecho);
    std::cout << raiz->dato << " ";
}

void imprimirArbol(Nodo* raiz, int espacio = 0, int altura = 10) {
    if (raiz == nullptr) return;

    espacio += altura;

    imprimirArbol(raiz->derecho, espacio);

    std::cout << std::endl;
    for (int i = altura; i < espacio; ++i) std::cout << " ";
    std::cout << raiz->dato << std::endl;

    imprimirArbol(raiz->izquierdo, espacio);
}

void liberarArbol(Nodo* raiz) {
    if (raiz == nullptr) return;
    liberarArbol(raiz->izquierdo);
    liberarArbol(raiz->derecho);
    delete raiz;
}

void ejercicio4() {
    std::cout << "Ejercicio 4: Construir arbol a partir de recorridos" << std::endl;

    std::string preStr = "TEUIBMCLDZKNH";
    std::string inStr = "IUBETLDCZMKHN";

    std::vector<char> preorden(preStr.begin(), preStr.end());
    std::vector<char> inorden(inStr.begin(), inStr.end());

    std::cout << "Preorden: ";
    for (char c : preorden) std::cout << c << " ";
    std::cout << std::endl;

    std::cout << "Inorden: ";
    for (char c : inorden) std::cout << c << " ";
    std::cout << std::endl;

    Nodo* raiz = construirArbol(preorden, inorden, 0, preorden.size() - 1, 0, inorden.size() - 1);

    std::cout << "Arbol reconstruido:" << std::endl;
    imprimirArbol(raiz);

    std::cout << "Postorden: ";
    postorden(raiz);
    std::cout << std::endl;

    liberarArbol(raiz);
}
