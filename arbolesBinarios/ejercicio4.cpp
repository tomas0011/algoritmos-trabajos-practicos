#include <iostream>

void ejercicio4() {
    std::cout << "Ejercicio 4: Construir arbol a partir de recorridos" << std::endl;

    std::cout << "Preorden: T E U I B M C L D Z K N H" << std::endl;
    std::cout << "Inorden: I U B E T L D C Z M K H N" << std::endl;

    std::cout << "Arbol reconstruido:" << std::endl;
    std::cout << "        T" << std::endl;
    std::cout << "      /   \\" << std::endl;
    std::cout << "     E     U" << std::endl;
    std::cout << "    / \\   / \\" << std::endl;
    std::cout << "   I   B M   L" << std::endl;
    std::cout << "      / \\     \\" << std::endl;
    std::cout << "     C   D     Z" << std::endl;
    std::cout << "    / \\         \\" << std::endl;
    std::cout << "   K   H         N" << std::endl;

    std::cout << "Postorden: I B C K H D Z L M U E N T" << std::endl;
}
