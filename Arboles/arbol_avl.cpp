#include<iostream>
using namespace std;

typedef struct tnodo* pnodo;
struct tnodo{
    int dato;
    pnodo izq;
    pnodo der;
    int balance;
};

void crearNodo(pnodo &nuevo, int dato){
    nuevo->dato = dato;
    nuevo->der = nullptr;
    nuevo->izq = nullptr;
    nuevo->balance = 0;
}

void calcularBalance(pnodo arbol){

}

void insertar(pnodo &arbol, pnodo nuevo){
    if(arbol == nullptr){
        arbol = nuevo;
        //Calcular balance
    }
    else{
        
        if(nuevo->dato > arbol->dato)
            insertar(arbol->der, nuevo);
        else
            insertar(arbol->izq, nuevo);
    }
}

int main(){

    return 0;
}