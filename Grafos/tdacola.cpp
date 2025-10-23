#include <iostream>

using namespace std;

const int MAX = 500;

typedef char Contenedor[MAX]; // Definimos un tipo de dato Contenedor como un arreglo de enteros de tamaño MAX   
struct Cola{
    Contenedor datos; // Arreglo de enteros que almacena los elementos de la cola
    int frente; // Indica el índice del primer elemento de la cola
    int fin; // Indica el índice del último elemento de la cola
};

void initQueue(Cola &c) {
    c.frente = 0; // Inicializa el índice del frente de la cola en 0
    c.fin = 0; // Inicializa el índice del fin de la cola en 0
}

int next(int indice){
    indice++;
    if(indice == MAX){
        indice = 0;
    }
    return indice;
}

bool isEmptyQueue(Cola &c) {
    return c.frente == c.fin; // Devuelve true si la cola está vacía (frente y fin son iguales)
}

bool isFullQueue(Cola &c){
    return c.frente == next(c.fin);
}

void pushQueue(Cola &c, char nuevo){
    if(isFullQueue(c)){
        cout << "Cola llena" << endl;
    }
    else{
        c.fin = next(c.fin);
        c.datos[c.fin] = nuevo; // Agrega un nuevo elemento al final de la cola
    }
}

char popQueue(Cola &c){
    int extraido;
    if(isEmptyQueue(c)){
        extraido = -999;
    }
    else{
        c.frente = next(c.frente); // Mueve el índice del frente de la cola al siguiente elemento
        extraido = c.datos[c.frente]; // Extrae el elemento del frente de la cola
    }
    return extraido;
}

char topQueue(Cola c){
    int frente;
    if(isEmptyQueue(c)){
        frente = -999; // Devuelve -999 si la cola está vacía
    }
    else{
        frente = c.datos[next(c.frente)]; // Devuelve el elemento del frente de la cola sin extraerlo
    }
    return frente;
}

char bottomQueue(Cola c){
    int fin;
    if(isEmptyQueue(c)){
        fin = -999; // Devuelve -999 si la cola está vacía
    }
    else{
        fin = c.datos[c.fin]; // Devuelve el elemento del final de la cola sin extraerlo
    }
    return fin;
}

void printQueue(Cola c){
    if(isEmptyQueue(c)){
        cout << "Cola vacia" << endl; // Imprime un mensaje si la cola está vacía
        return;
    }
    int i = next(c.frente);
    while(i != next(c.fin)){ 
        cout << c.datos[i] << " ";
        i = next(i);
    }
    cout << endl; // Imprime una nueva línea al final
}
