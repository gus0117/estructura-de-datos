#include<iostream>

using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
    int dato;
    pnodo sig;
};

struct tlista{
    pnodo inicio;
    pnodo fin;
    int contador;
};

bool esta_vacia(tlista lista){
    return lista.inicio == NULL && lista.fin == NULL;
}

void crear_nodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->sig = NULL;
    }
    else{
        cout<<"Memoria insuficiente"<<endl;
    }
}

void iniciar_lista(tlista &lista){
    lista.inicio = NULL;
    lista.fin = NULL;
    lista.contador = 0;
}

void agregar_inicio(tlista &lista, pnodo nuevo){
    if(esta_vacia(lista)){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio = nuevo;
    }
    lista.contador++;
}

void agregar_final(tlista &lista, pnodo nuevo){
    if(esta_vacia(lista)){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        lista.fin = nuevo;
    }
    lista.contador++;
}

void agregar_ordenado(tlista &lista, pnodo nuevo){
    if(esta_vacia(lista)){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        if(lista.inicio->dato > nuevo->dato){
            nuevo->sig = lista.inicio;
            lista.inicio = nuevo;
        }
        else{
            pnodo i;
            for(i=lista.inicio; (i->sig)->sig != NULL && (i->sig)->dato < nuevo->dato; i = i->sig);
            nuevo->sig = i->sig;
            i->sig = nuevo;
        }
    }
    lista.contador++;
}

pnodo eliminar_inicio(tlista &lista){
    pnodo borrado;
    if(esta_vacia(lista)){
        borrado = NULL;
    }
    else{
        borrado = lista.inicio;
        if(lista.inicio->sig == NULL){
            lista.inicio = NULL;
            lista.fin = NULL;
        }
        else{
            lista.inicio = lista.inicio->sig;
            borrado->sig = NULL;
        }
        lista.contador--;
    }
    return borrado;
}

pnodo eliminar_final(tlista &lista){
    pnodo borrado;
    if(esta_vacia(lista)){
        borrado = NULL;
    }
    else{
        borrado = lista.fin;
        if(lista.inicio->sig == NULL){
            lista.inicio = NULL;
            lista.fin = NULL;
        }
        else{
            pnodo i;
            for(i=lista.inicio; (i->sig)->sig != NULL; i=i->sig);
            borrado = i->sig;
            i->sig = NULL;
            lista.fin = i;
        }
        lista.contador--;
    }
    return borrado;
}

pnodo eliminar_nodo(tlista &lista, int valor){
    pnodo borrado;
    if(esta_vacia(lista)){
        borrado = NULL;
    }
    else{
        if(lista.inicio->dato == valor){
            borrado = eliminar_inicio(lista);
        }
        else{
            pnodo i;
            for(i=lista.inicio; i->sig != NULL && (i->sig)->dato != valor; i=i->sig);
            if(i->sig != NULL){
                if((i->sig)->sig == NULL){
                    borrado = eliminar_final(lista);
                }
                else{
                    borrado = i->sig;
                    i->sig = borrado->sig;
                    borrado->sig = NULL;
                }
            }
            else{
                borrado = NULL;
            }
            
        }
        lista.contador--;
    }
    return borrado;
}

void mostrar_lista(tlista lista){
    if(esta_vacia(lista)){
        cout << "Lista vacia" << endl;
    }
    else{
        pnodo i;
        for(i = lista.inicio; i != NULL; i = i->sig){
            cout << "Dato: " << i->dato << endl;
        }
    }
}

int obtener_cantidad(tlista lista){
    return lista.contador;
}

int main(){
    tlista lista;
    iniciar_lista(lista);

    pnodo nuevoNodo;
    crear_nodo(nuevoNodo, 9);
    agregar_ordenado(lista, nuevoNodo);

    crear_nodo(nuevoNodo, 4);
    agregar_ordenado(lista, nuevoNodo);

    crear_nodo(nuevoNodo, 6);
    agregar_ordenado(lista, nuevoNodo);

    crear_nodo(nuevoNodo, 5);
    agregar_ordenado(lista, nuevoNodo);

    crear_nodo(nuevoNodo, 11);
    agregar_final(lista, nuevoNodo);

    //eliminar_nodo(lista, 11);

    mostrar_lista(lista);

    cout << "Cantidad= "<<obtener_cantidad(lista) << endl;

    return 0;
}