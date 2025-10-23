#include<iostream>
using namespace std;

const int NODOS = 100;

typedef struct Arco{
    float peso;
    bool existe;
};

typedef Arco matady[NODOS][NODOS];

void iniciar_grafo(matady &grafo){
    for(int i = 0; i < NODOS; i++){
        for(int j = 0; j < NODOS; j++){
            grafo[i][j].existe = false;
            grafo[i][j].peso = 0.0;
        }
    }
}