#include<iostream>
using namespace std;

typedef struct tnodo* pnodo;
struct tnodo{
    int dato;
    pnodo izq;
    pnodo der;
    int altura;
};

void crearNodo(pnodo &nuevo, int dato){
    nuevo->dato = dato;
    nuevo->der = nullptr;
    nuevo->izq = nullptr;
    nuevo->altura = 0;
}

int calcularAltura(pnodo arbol){
	if(arbol == nullptr)
		return 0;
	else
		return 1 + max(calcularAltura(arbol->der), calcularAltura(arbol->izq));
}

int calcularBalance(pnodo arbol){
	if(arbol == nullptr)
		return 0;
	else
		return (arbol->der)->altura - (arbol->izq)->altura;
}

void rebalanceo(pnodo &arbol){
	
}

void insertar(pnodo &arbol, pnodo nuevo){
    if(arbol == nullptr){
        arbol = nuevo;
    }
    else{
        if(nuevo->dato > arbol->dato)
            insertar(arbol->der, nuevo);
        else
            insertar(arbol->izq, nuevo);
        arbol->altura = calcularAltura(arbol);
        int balance = calcularBalance(arbol);
    }
}

int main(){

    return 0;
}
