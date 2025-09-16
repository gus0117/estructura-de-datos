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
    pnodo q = p->izq;   // Q es el hijo izquierdo
    p->izq = q->der;    // el subárbol derecho de Q pasa a ser hijo izquierdo de P
    q->der = p;         // P pasa a ser hijo derecho de q
    p->altura = calcularAltura(p);
    q->altura = calcularAltura(q);
    p = q;              // actualizar raíz local
}

void rotacionDD(pnodo &p){
    cout << "Rotacion DD" << endl;
    pnodo q = p->der;   // Q es el hijo derecho
    p->der = q->izq;    // el subárbol izquierdo de Q pasa a ser hijo derecho de P
    q->izq = p;         // P pasa a ser hijo izquierdo de Q

    p->altura = calcularAltura(p);
    q->altura = calcularAltura(q);
    p = q;              // actualizar raíz local
}

void rotacionID(pnodo &p){
    cout << "Rotacion ID" << endl;
    rotacionDD(p->izq);
    rotacionII(p);
}

void rotacionDI(pnodo &p){
    cout << "Rotacion DI" << endl;
    //rotacionII(p->der);
    //rotacionDD(p);
    pnodo q = p->der;
    pnodo r = q->izq;
    p->der = r->izq;
    q->izq = r->der;
    r->izq = p;
    r->der = q;
    p->altura = calcularAltura(p);
    q->altura = calcularAltura(q);
    r->altura = calcularAltura(r);
    p = r;
}

// Insertar un nodo en el arbol AVL
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
        else if(balance > 1 && nuevo->dato > (arbol->der)->dato)
            rotacionDD(arbol);
        else if(balance < -1 && nuevo->dato > (arbol->izq)->dato)
            rotacionID(arbol);
        else if(balance > 1 && nuevo->dato < (arbol->der)->dato)
            rotacionDI(arbol);
        
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


//Funcion auxiliar para probar las inserciones
void agregarValor(pnodo &arbol, int valor){
	pnodo nuevo;
	crearNodo(nuevo, valor);
    insertar(arbol, nuevo);
    mostrarPreorden(arbol);
	cout << endl;
}

int main(){
    pnodo arbol;
    iniciarArbol(arbol);
    
    agregarValor(arbol, 21);
    agregarValor(arbol, 25);
    agregarValor(arbol, 28);
    agregarValor(arbol, 33);
    agregarValor(arbol, 46);
    agregarValor(arbol, 22);
    agregarValor(arbol, 20);
}
