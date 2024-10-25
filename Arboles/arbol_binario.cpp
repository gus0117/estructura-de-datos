#include<iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo izquierdo;
    pnodo derecho;
};

void iniciar_arbol(pnodo &arbol){
    arbol = NULL;
}

void crear_nodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->izquierdo = NULL;
        nuevo->derecho = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

//Recorrido
void preorden(pnodo a){

    if(a != NULL){
        cout << a->dato << " ";
        preorden(a->izquierdo);
        preorden(a->derecho);
    }
}

void enorden(pnodo a){
    if(a != NULL){
        enorden(a->izquierdo);
        cout<<a->dato << " ";
        enorden(a->derecho);
    }
}

void posorden(pnodo a){
    if(a != NULL){
        posorden(a->izquierdo);
        posorden(a->derecho);
        cout << a->dato << " ";
    }
}

void insercion(pnodo &a, pnodo nuevo){
    if(a == NULL)
        a=nuevo;
    else
        if(nuevo->dato < a->dato)
            insercion(a->izquierdo, nuevo);
        else
            insercion(a->derecho, nuevo);
}

bool busqueda(pnodo arbol, int buscado){
    bool encontrado = false;
    if(arbol!=NULL){
        if(arbol->dato == buscado)
            encontrado = true;
        else
            if(buscado < arbol->dato)
                encontrado=busqueda(arbol->izquierdo, buscado);
            else
                encontrado=busqueda(arbol->derecho, buscado);
    }
    return encontrado;
}

pnodo menor_mayores(pnodo elegido, pnodo &menor){
    pnodo aux;
    if(menor->izquierdo != NULL)
        aux = menor_mayores(elegido, menor->izquierdo);
    else{
        elegido->dato = menor->dato;
        aux = menor;
        menor = menor->derecho;
    }
    return aux;
}

pnodo eliminar(pnodo &arbol, int valor){
    pnodo aux;
    if(arbol == NULL)
        return NULL;
    else
        if(arbol->dato > valor)
            aux=eliminar(arbol->izquierdo, valor);
        else
            if(arbol->dato < valor)
                aux=eliminar(arbol->derecho, valor);
            else
            {
                aux = arbol;
                if(arbol->izquierdo == NULL)
                    arbol=arbol->derecho;
                else
                    if(arbol->derecho == NULL)
                        arbol=arbol->izquierdo;
                    else
                        aux = menor_mayores(arbol, arbol->derecho);
            }
    return aux;
}

int main(){
    pnodo arbol;
    pnodo nuevo;
    iniciar_arbol(arbol);

    crear_nodo(nuevo, 21);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 12);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 33);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 6);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 15);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 14);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 19);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 51);
    insercion(arbol, nuevo);
    crear_nodo(nuevo, 42);
    insercion(arbol, nuevo);

    cout << "\n\trecorrido preorden\t\t";
    preorden(arbol);
    cout << "\n\trecorrido enorden\t\t";
    enorden(arbol);
    cout << "\n\trecorrido posorden\t\t";
    posorden(arbol);
    cout << endl;

    int valor = 4;
    if(busqueda(arbol, valor)){
        cout << "\n\tEncontrado\n";
    }
    else{
        cout << "\n\tNo encontrado\n";
    }

    valor = 100;
    if(busqueda(arbol, valor))
        cout << "\n\tEliminado " <<eliminar(arbol, valor)->dato << endl;
    else
        cout << "\n\tValor: "<<valor<<" no encontrado"<<endl;
    system("pause");
    return 0;
}
