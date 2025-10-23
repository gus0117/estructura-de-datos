#include <iostream>
#include "tda_grafo_matriz.cpp";
#include "tdacola.cpp";

using namespace std;

void recorridoAmplitud(matady grafo){
    Cola c;
    initQueue(c);
    bool visitados[NODOS] = {false};

    int inicio = 0; // Nodo de inicio para el recorrido
    visitados[inicio] = true;
    pushQueue(c, inicio);

    while(!isEmptyQueue(c)){
        int nodoActual = popQueue(c);
        cout << "Nodo visitado: " << nodoActual << endl;

        for(int j = 0; j < NODOS; j++){
            if(grafo[nodoActual][j].existe && !visitados[j]){
                visitados[j] = true;
                pushQueue(c, j);
            }
        }
    }
}

void recorridoProfundidad(matady grafo){
    bool visitados[NODOS] = {false};
}