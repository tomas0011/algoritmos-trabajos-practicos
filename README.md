# algoritmos-trabajos-practicos

Es un repositorio donde están todos los ejercicios de la cursada de Algoritmos en Unahur.

## Estructura del Proyecto

El proyecto está organizado en varios directorios, cada uno correspondiente a un tema específico de algoritmos y estructuras de datos:

### listas/
Contiene ejercicios sobre listas enlazadas y operaciones básicas:
- **ejercicio1.cpp**: Insertar productos entre pares de elementos en una lista.
- **ejercicio2.cpp**: Separar contiguos divisibles en una lista.
- **ejercicio3.cpp**: Eliminar y retornar elementos en posiciones impares.

### arbolesBinarios/
Contiene ejercicios sobre árboles binarios:
- **ejercicio1.cpp**: Contar nodos en un árbol binario.
- **ejercicio2.cpp**: Calcular la altura de un árbol binario.
- **ejercicio3.cpp**: Recorrido inorden iterativo.
- **ejercicio4.cpp**: Construir árbol a partir de recorridos preorden e inorden.
- **ejercicio5.cpp**: Eliminar nodo en un ABB.

### adicionalesArbolesBinarios/
Contiene ejercicios adicionales sobre árboles binarios:
- **ejercicio1.cpp**: Verificación de AVL.
- **ejercicio2.cpp**: Diámetro del árbol.
- **ejercicio3.cpp**: K-ésimo elemento más pequeño en ABB.
- **ejercicio4.cpp**: Convertir ABB a lista doblemente enlazada.
- **ejercicio5.cpp**: Validación de ABB.
- **ejercicio6.cpp**: Árbol espejo.
- **ejercicio7.cpp**: Serialización y deserialización de ABB.

### grafos/
Contiene ejercicios sobre grafos:
- **ejercicio1.cpp**: Representación con matriz de adyacencia y cálculo de grados.
- **ejercicio2.cpp**: Recorridos BFS y DFS.
- **ejercicio3.cpp**: Árbol de expansión mínimo (Kruskal y Prim).
- **ejercicio4.cpp**: Componentes conexas y detección de ciclos.

### punteros/
Contiene ejercicios sobre punteros en C++:
- **ejercicio1.cpp**: Imprimir mensaje de "Ejercicio 1".
- **ejercicio2.cpp**: Imprimir mensaje de "Ejercicio 2".
- **main.cpp**: Programa principal que integra los ejercicios.

## Compilación y Ejecución

Cada directorio contiene un `Makefile` para compilar los programas. Para compilar y ejecutar:

```bash
cd <directorio>
make
./<ejecutable>
```

Donde `<directorio>` es el nombre del directorio correspondiente y `<ejecutable>` es el nombre del programa compilado (generalmente coincide con el nombre del directorio).

## Requisitos

- Compilador C++ (g++)
- Para grafos/: C++17 (para structured bindings en Prim)
- Para otros directorios: C++11

## Contribuciones

Este repositorio contiene trabajos prácticos de la materia Algoritmos en la Universidad Nacional de Hurlingham (UNAHUR).
