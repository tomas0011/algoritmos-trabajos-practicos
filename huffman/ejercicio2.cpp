#include <iostream>
#include <string>

using namespace std;

struct NodoHuffman {
    char caracter;
    int frecuencia;
    NodoHuffman* izquierdo;
    NodoHuffman* derecho;

    NodoHuffman(char c, int f) : caracter(c), frecuencia(f), izquierdo(nullptr), derecho(nullptr) {}
};

void ejercicio2() {
    cout << "Ejercicio 2: Decodificar un Mensaje" << endl;

    // Construir el árbol de Huffman según la descripción
    NodoHuffman* raiz = new NodoHuffman('\0', 0);
    NodoHuffman* izq = new NodoHuffman('\0', 0);
    izq->izquierdo = new NodoHuffman('A', 0);
    NodoHuffman* sub = new NodoHuffman('\0', 0);
    sub->izquierdo = new NodoHuffman('B', 0);
    sub->derecho = new NodoHuffman('C', 0);
    izq->derecho = sub;
    raiz->izquierdo = izq;
    NodoHuffman* der = new NodoHuffman('\0', 0);
    der->izquierdo = new NodoHuffman('D', 0);
    der->derecho = new NodoHuffman('E', 0);
    raiz->derecho = der;

    // Mensaje codificado
    string mensaje = "011001110010110";
    cout << "Mensaje codificado: " << mensaje << endl;

    // Decodificar el mensaje paso a paso
    string decodificado = "";
    NodoHuffman* actual = raiz;
    cout << "Proceso de decodificación:" << endl;
    for (size_t i = 0; i < mensaje.length(); ++i) {
        char bit = mensaje[i];
        cout << "Bit " << i << ": " << bit;
        if (bit == '0') {
            actual = actual->izquierdo;
            cout << " -> izquierda";
        } else {
            actual = actual->derecho;
            cout << " -> derecha";
        }
        if (actual->caracter != '\0') {
            cout << " -> caracter: " << actual->caracter << endl;
            decodificado += actual->caracter;
            actual = raiz;
        } else {
            cout << endl;
        }
    }

    cout << "Mensaje decodificado: " << decodificado << endl;
}