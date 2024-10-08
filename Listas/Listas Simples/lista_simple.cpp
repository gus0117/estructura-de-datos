#include <iostream>

using namespace std;

//Alamacen de dato "generico"
typedef int tdato;

typedef struct tnodo *pnodo;
//Implementación de nodo utilizando punteros
typedef struct tnodo{
    int dato;
    pnodo siguiente;
};

/*
    Inicializa la lista
*/
void iniciar_lista(pnodo &lista){
    lista = NULL;
}

/*
    Agrega un nodo al principio de la lista
*/
void agregar_inicio(pnodo &lista, pnodo nuevo){
    nuevo->siguiente = lista;
    lista = nuevo;
}

/*
    Crea un nuevo nodo
*/
void crear_nodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo -> dato = valor;
        nuevo -> siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

/*
    Agrega un nodo al final de la lista
*/
void agregar_final(pnodo &lista, pnodo nuevo){
    pnodo i;
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        for(i = lista; i->siguiente != NULL; i=i->siguiente);
        i->siguiente = nuevo;
    }
}

/*
    Agrega un nodo de manera ordenada
    de forma creciente (menor a mayor)
*/
void agregar_ordenado(pnodo &lista, pnodo nuevo){
    pnodo i;
    if(lista == NULL){
        lista = nuevo;
    }
    else{
        if(nuevo->dato < lista->dato){
            nuevo->siguiente = lista;
            lista = nuevo;
        }
        else{
            for(i=lista; i->siguiente!=NULL && nuevo->dato > (i->siguiente)->dato; i=i->siguiente);
            nuevo->siguiente = i->siguiente;
            i->siguiente = nuevo;
        }
    }
}

/*
    Elimina el nodo del inicio de la lista
*/
pnodo eliminar_inicio(pnodo &lista){
    pnodo borrado;
    if(lista==NULL){
        borrado = NULL;
    }
    else{
        borrado = lista;
        lista = lista->siguiente;
        borrado->siguiente = NULL;
    }
    return borrado;
}

/*
    Eliminar el nodo del final de la lista
*/
pnodo eliminar_final(pnodo &lista){
    pnodo borrado, i;
    if(lista == NULL){
        borrado = NULL;
    }
    else{
        if(lista->siguiente == NULL){
            borrado=lista;
            lista=NULL;
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
    Elimina un nodo especifico de la lista
*/
pnodo eliminar_nodo(pnodo &lista, int valor){
    pnodo borrado, i;
    if(lista == NULL){
        borrado = NULL;
    }
    else{
        if(lista->dato == valor){
            borrado = lista;
            lista = borrado->siguiente;
            borrado->siguiente = NULL;
        }
        else{
            for(i=lista; i->siguiente != NULL && valor!=(i->siguiente)->dato; i=i->siguiente);
            if(i->siguiente != NULL){
                borrado = i->siguiente;
                i->siguiente = borrado->siguiente;
                borrado->siguiente = NULL;
            }
            else{
                borrado=NULL;
            }
        }
    }
    return borrado;
}

/*
    Muestra los elementos de la lista por pantalla
*/
void mostrar_lista(pnodo lista){
    pnodo i;
    if(lista != NULL){
        for(i = lista; i != NULL; i = i->siguiente){
            cout <<  "Nodo: " << i->dato << endl;
        }
    }
    else{
        cout << "Lista vacía";
    }
}

/*
    Busca un valor dentro de la lista
    Retorna true si el valor está dentro de la lista
    y false si no lo está.
*/
bool buscar_nodo(pnodo lista, int valor){
    pnodo i;
    bool encontrado = false;
    if(lista != NULL){
        for(i=lista; i != NULL && encontrado == false; i=i->siguiente){
            if(i->dato == valor){
                encontrado = true;
            }
        }
    }
    return encontrado;
}

int main(){
    pnodo lista;
    pnodo nodo;
    //iniciar_lista(lista);
    crear_nodo(nodo, 2);
    agregar_inicio(lista, nodo);
    crear_nodo(nodo, 5);
    agregar_final(lista, nodo);
    crear_nodo(nodo, 6);
    agregar_ordenado(lista, nodo);

    mostrar_lista(lista);

    return 0;
}
