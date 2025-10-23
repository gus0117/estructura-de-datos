#include<iostream>
using namespace std;

const int NODOS = 100;

typedef struct Arco *parco;
typedef struct Arco{
    float peso;
    parco sig;
    parco sig_arco;
};

typedef parco dirnodos[NODOS];

void iniciar_grafo(dirnodos &grafo){
    for(int i = 0; i < NODOS; i++){
        grafo[i] = nullptr;
    }
}