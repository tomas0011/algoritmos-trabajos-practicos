#include <iostream>
#include <vector>

class Lista {
private:
    std::vector<int> elementos;

public:
    Lista() {}

    void agregar(int valor) {
        elementos.push_back(valor);
    }

    void insertarProductos() {
        if (elementos.size() < 2) return;

        std::vector<int> nuevaLista;
        for (size_t i = 0; i < elementos.size() - 1; ++i) {
            nuevaLista.push_back(elementos[i]);
            nuevaLista.push_back(elementos[i] * elementos[i + 1]);
        }
        nuevaLista.push_back(elementos.back());
        elementos = nuevaLista;
    }

    void imprimir() {
        for (size_t i = 0; i < elementos.size(); ++i) {
            std::cout << elementos[i];
            if (i < elementos.size() - 1) std::cout << ",";
        }
        std::cout << std::endl;
    }
};

void ejercicio1() {
    std::cout << "Ejercicio 1: Insertar productos entre pares de elementos" << std::endl;

    Lista lista;
    lista.agregar(2);
    lista.agregar(5);
    lista.agregar(4);
    lista.agregar(3);

    std::cout << "Lista original: ";
    lista.imprimir();

    lista.insertarProductos();

    std::cout << "Lista modificada: ";
    lista.imprimir();
}
