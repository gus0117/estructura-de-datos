#include <iostream>

using namespace std;

/*
    TDA Lista implementado del tipo nodo y el puntero a este
    inicio es un puntero que indica el primer nodo de la lista
    final es un puntero que indica el último nodo de la lista
*/
typedef struct tnodo *pnodo;

typedef struct tnodo{
    int dato;
    pnodo siguiente;
};

typedef struct tlista{
    pnodo inicio;
    pnodo final;
};

void iniciar_lista(tlista &lista){
    lista.inicio = NULL;
    lista.final = NULL;
}

void agregar_final(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.final = nuevo;
    }
    else{
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
}

pnodo eliminar_final(tlista &lista){
    pnodo borrado, i;
    if(lista.inicio == NULL){
        borrado = NULL;
    }
    else{
        if(lista.inicio == lista.final){
            borrado = lista.inicio;
            lista.inicio = NULL;
            lista.final = NULL;
        }
        else{
            for(i = lista.inicio; (i->siguiente)->siguiente != NULL; i=i->siguiente);
            borrado = lista.final;
            lista.final = i;
            lista.final->siguiente = NULL;

        }
    }
    return borrado;
}

int main(){

    return 0;
}