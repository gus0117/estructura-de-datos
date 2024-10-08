#include<iostream>

using namespace std;

typedef struct tnodo *pnodo;

struct tnodo{
    int dato;
    pnodo siguiente;
};

/*
    Crea una instancia de nodo en memoria.
*/
void crear_nodo(pnodo &nodo, int valor){
    nodo = new tnodo;
    if(nodo == NULL){
        cout<<"Error al crear nodo"<<endl;
    }
    else{
        nodo->dato = valor;
        nodo->siguiente = NULL;
    }
}

/*
    Muestra el dato contenido por un nodo.
*/
void mostrar_nodo(pnodo nodo){
    if(nodo != NULL){
        cout<<"Dato: "<< nodo->dato <<endl;
    }
}

/*
    Inicializa la lista
*/
void iniciar_lista(pnodo &lista){
    lista = NULL;
}

/*
    Pregunta si la lista est� vacia
*/
bool esta_vacia(pnodo lista){
    return lista == NULL;
}

/*
    Agrega un nodo al inicio de la lista
*/
void agregar_inicio(pnodo &lista, pnodo nuevoNodo){
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
}

/*
    Agrega un nodo al final de la lista
*/
void agregar_final(pnodo &lista, pnodo nuevoNodo){
    pnodo i;
    if(esta_vacia(lista)){
        lista = nuevoNodo;
    }
    else{
        for(i=lista; i->siguiente != NULL; i=i->siguiente);
        i->siguiente = nuevoNodo;
    }
}

/*
    Agrega un elemento a la lista de manera que
    los datos se agrupen de menor a mayor.

    Precondicion: La lista debe estar previamente ordenada.
*/
void agregar_ordenado(pnodo &lista, pnodo nuevoNodo){
    pnodo i;
    if(esta_vacia(lista)){
        lista = nuevoNodo;
    }
    else{
        if(lista->dato > nuevoNodo->dato){
            agregar_inicio(lista, nuevoNodo);
        }
        else{
            for(i=lista; i->siguiente != NULL && (i->siguiente)->dato < nuevoNodo->dato;i = i->siguiente);
            nuevoNodo->siguiente = i->siguiente;
            i->siguiente = nuevoNodo;
        }
    }
}

pnodo eliminar_inicio(pnodo &lista){
    pnodo borrado;
    if(esta_vacia(lista)){
        borrado = NULL;
    }
    else{
        borrado = lista;
        lista = borrado->siguiente;
        borrado->siguiente = NULL;
    }
    return borrado;
}

pnodo eliminar_final(pnodo &lista){
    pnodo borrado, i;
    if(esta_vacia(lista)){
        borrado = NULL;
    }
    else{
        if(lista->siguiente == NULL){
            borrado = lista;
            lista = NULL;
        }
        else{
            for(i=lista; (i->siguiente)->siguiente != NULL; i=i->siguiente);
            borrado = i->siguiente;
            i->siguiente = NULL;
        }
    }
    return borrado;
}

/*
    Precondicion: el valor debe estar en la lista
    Postcondicion: devuelve el nodo con el valor,
    y la lista con el nodo especifico eliminado
*/
pnodo eliminar_nodo(pnodo &lista, int valor){
    pnodo borrado, i;
    if(esta_vacia(lista)){
        borrado = NULL;
    }
    else{
        if(lista->dato == valor){
            eliminar_inicio(lista);
        }
        else{
            for(i=lista; i->siguiente != NULL && (i->siguiente)->dato != valor; i=i->siguiente);
            if(i->siguiente != NULL){
                borrado = i->siguiente;
                i->siguiente = borrado->siguiente;
                borrado->siguiente = NULL;
            }
            else{
                cout << "Valor no encontrado" << endl;
            }
        }
    }
    return borrado;
}

/*
    Muestra el contenido de la lista
*/
void mostrar_lista(pnodo lista){
    pnodo i;
    for(i=lista; i != NULL; i=i->siguiente){
        mostrar_nodo(i);
    }
}

bool buscar_valor(pnodo lista, int valor){
    bool encontrado = false;
    pnodo i;
    if(lista != NULL){
        for(i=lista; i != NULL && !encontrado; i=i->siguiente){
            if(i->dato == valor){
                encontrado = true;
            }
        }
    }
    return encontrado;
}


int main(){

    pnodo lista;
    pnodo nuevoNodo;
    iniciar_lista(lista);

    crear_nodo(nuevoNodo, 3);
    agregar_ordenado(lista, nuevoNodo);

    crear_nodo(nuevoNodo, 1);
    agregar_ordenado(lista, nuevoNodo);

    crear_nodo(nuevoNodo, 5);
    agregar_ordenado(lista, nuevoNodo);

    mostrar_lista(lista);
    cout << "Despues de eliminar" << endl;

    pnodo aux = eliminar_nodo(lista, 3);

    if(aux == NULL){
        cout << "La lista esta vacia" << endl;
    }

    if(buscar_valor(lista, 3)){
        cout<<"El valor est� en la lista"<<endl;
    }
    else{
        cout<<"El valor no est� en la lista"<<endl;
    }
    mostrar_lista(lista);
    return 0;
}
