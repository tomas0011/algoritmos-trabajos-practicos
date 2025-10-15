#include <iostream>

void ejercicio5() {
    std::cout << "Ejercicio 5: Eliminar nodo en ABB" << std::endl;

    std::cout << "Arbol original:" << std::endl;
    std::cout << "            15" << std::endl;
    std::cout << "      /             \\" << std::endl;
    std::cout << "     6              20" << std::endl;
    std::cout << "  /     \\            /   \\" << std::endl;
    std::cout << " 3      9        18   24" << std::endl;
    std::cout << "/\\     /\\        /" << std::endl;
    std::cout << "1 4  7 12  17" << std::endl;

    std::cout << "Eliminando el nodo 6:" << std::endl;
    std::cout << "El nodo 6 tiene dos hijos, asi que se reemplaza con el sucesor inorden (9)." << std::endl;
    std::cout << "El subarbol izquierdo de 9 (7,12) se mueve al lugar del 9 eliminado." << std::endl;

    std::cout << "Arbol resultante:" << std::endl;
    std::cout << "            15" << std::endl;
    std::cout << "      /             \\" << std::endl;
    std::cout << "     9              20" << std::endl;
    std::cout << "  /     \\            /   \\" << std::endl;
    std::cout << " 3      12        18   24" << std::endl;
    std::cout << "/\\     /\\        /" << std::endl;
    std::cout << "1 4  7  17" << std::endl;
}