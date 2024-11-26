#include <stdio.h>
#include <stdlib.h>

// Definición del nodo de la lista
typedef struct Nodo {
    int valor;
    struct Nodo* next; // Apunta al siguiente nodo
} Nodo;

// Función para crear un nodo nuevo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

// Agregar un nodo al inicio de la lista
void agregarAlInicio(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->next = *cabeza;
    *cabeza = nuevoNodo;
}

// Imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->next;
    }
    printf("\n");
}

// Liberar la memoria de la lista
void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->next;
        free(temp);
    }
}

int main() {
    Nodo* cabeza = NULL; // Inicializar la lista vacía

    // Generar los primeros 10 números pares en orden inverso
    for (int i = 10; i > 0; i--) {
        agregarAlInicio(&cabeza, i * 2);
    }

    // Imprimir la lista
    printf("Lista de los primeros 10 números pares en orden inverso:\n");
    imprimirLista(cabeza);

    // Liberar la memoria
    liberarLista(cabeza);

    return 0;
}
