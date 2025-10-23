#include<iostream>
using namespace std;

typedef struct Arco *parco;
typedef struct Vertice *pvertice;

typedef struct Arco{
    float peso;
    pvertice destino;
    parco sig_arco;
};

typedef struct Vertice{
    int id;
    pvertice sig_vertice;
    parco lista_arco;
};

void iniciar_grafo(pvertice &grafo){
    grafo = nullptr;
}