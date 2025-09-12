#include<iostream>
using namespace std;

typedef struct tnodo* pnodo;
struct tnodo{
    int dato;
    pnodo izq;
    pnodo der;
    int altura;
};

void iniciarArbol(pnodo &arbol){
    arbol = nullptr;
}

void crearNodo(pnodo &nuevo, int dato){
    nuevo = new tnodo;
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
		return calcularAltura(arbol->der) - calcularAltura(arbol->izq);
}

// Hay problemas en la rotación
void rotacionII(pnodo &p){
    cout << "Rotacion II" << endl;
    pnodo q = p->izq;
    p->izq = q->der;
    q->izq = p;

    p->altura = calcularAltura(p);
    q->altura = calcularAltura(q);
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

        // Rotación II
        if(balance < -1 && nuevo->dato < (arbol->izq)->dato)
            rotacionII(arbol);
        
    }
}

void mostrarPreorden(pnodo nodo){
    if(nodo == nullptr){
        return;
    }
    else{
        cout << nodo->dato << " ";
        mostrarPreorden(nodo->izq);
        mostrarPreorden(nodo->der);
    }
}

int main(){
    pnodo arbol;
    iniciarArbol(arbol);
    pnodo nuevo;

    crearNodo(nuevo, 45);
    insertar(arbol, nuevo);
    mostrarPreorden(arbol);
    cout << endl;
    
    crearNodo(nuevo, 32);
    insertar(arbol, nuevo);
    mostrarPreorden(arbol);
    cout << endl;

    //cout << "Creando desbalance" << endl;
    crearNodo(nuevo, 11);
    insertar(arbol, nuevo);
    mostrarPreorden(arbol);
    cout << endl;

    return 0;
}
