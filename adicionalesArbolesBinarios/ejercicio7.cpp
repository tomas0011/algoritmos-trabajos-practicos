#include <iostream>
#include <sstream>
#include <queue>

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
};

std::string serializar(Nodo* raiz) {
    if (raiz == nullptr) {
        return "null";
    }

    std::string resultado = std::to_string(raiz->dato) + ",";
    resultado += serializar(raiz->izquierdo) + ",";
    resultado += serializar(raiz->derecho);

    return resultado;
}

Nodo* deserializar(std::istringstream& iss) {
    std::string token;
    if (!std::getline(iss, token, ',')) {
        return nullptr;
    }

    if (token == "null") {
        return nullptr;
    }

    Nodo* raiz = new Nodo(std::stoi(token));
    raiz->izquierdo = deserializar(iss);
    raiz->derecho = deserializar(iss);

    return raiz;
}

Nodo* deserializar(std::string datos) {
    std::istringstream iss(datos);
    return deserializar(iss);
}

void inorden3(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden3(raiz->izquierdo);
    std::cout << raiz->dato << " ";
    inorden3(raiz->derecho);
}

void ejercicio7() {
    std::cout << "Ejercicio 7: Serializacion y deserializacion de ABB" << std::endl;

    // Crear un ABB de ejemplo
    Nodo* raiz = new Nodo(10);
    raiz->izquierdo = new Nodo(5);
    raiz->derecho = new Nodo(15);
    raiz->izquierdo->izquierdo = new Nodo(3);
    raiz->izquierdo->derecho = new Nodo(7);
    raiz->derecho->izquierdo = new Nodo(12);
    raiz->derecho->derecho = new Nodo(18);

    std::cout << "Arbol original (inorden): ";
    inorden3(raiz);
    std::cout << std::endl;

    // Serializar
    std::string serializado = serializar(raiz);
    std::cout << "Arbol serializado: " << serializado << std::endl;

    // Deserializar
    Nodo* raizDeserializada = deserializar(serializado);
    std::cout << "Arbol deserializado (inorden): ";
    inorden3(raizDeserializada);
    std::cout << std::endl;

    // Liberar memoria
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->derecho;
    delete raiz;

    delete raizDeserializada->izquierdo->izquierdo;
    delete raizDeserializada->izquierdo->derecho;
    delete raizDeserializada->izquierdo;
    delete raizDeserializada->derecho->izquierdo;
    delete raizDeserializada->derecho->derecho;
    delete raizDeserializada->derecho;
    delete raizDeserializada;

    std::cout << "Complejidad: Serializacion O(n), deserializacion O(n) donde n es el numero de nodos." << std::endl;
}
