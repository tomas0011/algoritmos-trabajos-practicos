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

    void separarContiguosDivisibles() {
        if (elementos.size() < 2) return;

        std::vector<int> nuevaLista;
        for (size_t i = 0; i < elementos.size(); ++i) {
            nuevaLista.push_back(elementos[i]);
            if (i < elementos.size() - 1 && elementos[i] % elementos[i + 1] == 0) {
                nuevaLista.push_back(elementos[i] / elementos[i + 1]);
            }
        }
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

void ejercicio2() {
    std::cout << "Ejercicio 2: Separar contiguos divisibles" << std::endl;

    Lista lista;
    lista.agregar(20);
    lista.agregar(10);
    lista.agregar(6);
    lista.agregar(3);

    std::cout << "Lista original: ";
    lista.imprimir();

    lista.separarContiguosDivisibles();

    std::cout << "Lista modificada: ";
    lista.imprimir();
}
