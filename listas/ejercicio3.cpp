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

    Lista* EliminarYRetornarImpares() {
        Lista* impares = new Lista();
        std::vector<int> nuevaLista;

        for (size_t i = 0; i < elementos.size(); ++i) {
            if ((i + 1) % 2 == 0) {  // Posiciones impares (1-based)
                impares->agregar(elementos[i]);
            } else {
                nuevaLista.push_back(elementos[i]);
            }
        }

        elementos = nuevaLista;
        return impares;
    }

    void imprimir() {
        for (size_t i = 0; i < elementos.size(); ++i) {
            std::cout << elementos[i];
            if (i < elementos.size() - 1) std::cout << ",";
        }
        std::cout << std::endl;
    }
};

void ejercicio3() {
    std::cout << "Ejercicio 3: Eliminar y retornar impares" << std::endl;

    Lista lista;
    lista.agregar(2);
    lista.agregar(5);
    lista.agregar(4);
    lista.agregar(3);

    std::cout << "Lista original: ";
    lista.imprimir();

    Lista* impares = lista.EliminarYRetornarImpares();

    std::cout << "Lista modificada: ";
    lista.imprimir();

    std::cout << "Elementos eliminados (impares): ";
    impares->imprimir();

    delete impares;
}
