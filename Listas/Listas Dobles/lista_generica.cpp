#include<iostream>

using namespace std;

template<typename T>
struct tnodo {
    T dato;
    tnodo<T>* sig;  // Puntero al siguiente nodo
    tnodo<T>* ant;  // Puntero al nodo anterior
};

template<typename T>
struct tlista{
    tnodo<T>* inicio;
    tnodo<T>* fin;
    int contador;
};

template<typename T>
void IniciarLista(tlista<T> &lista){
    lista.inicio = NULL;
    lista.fin = NULL;
    lista.contador = 0;
}

template<typename T>
void CrearNodo(tnodo<T>* &nuevo, T valor){
    nuevo = new tnodo<T>;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

template<typename T>
bool EstaVacia(tlista<T> lista){
    return lista.contador == 0;
}

template<typename T>
void AgregarNodo(tlista<T> &lista, tnodo<T> nuevo){
    tnodo<T> i;
    if(EstaVacia(lista)){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        for(i=lista.inicio; i != NULL && nuevo->dato > i->dato; i = i->sig);
        if(i == NULL){
            lista.fin->sig = nuevo;
            nuevo->ant = lista.fin;
            lista.fin = nuevo;
        }
        else{
            nuevo->sig = i->sig;
            nuevo->ant = i->ant;
            (i->ant)->sig = nuevo;
            (i->sig)->ant = nuevo;
        }

    }
    lista.contador++;
}

template<typename T>
void MostrarLista(tlista<T> lista){
    if(!EstaVacia(lista)){
        tnodo<T> i;
        for(i = lista.inicio; i != NULL; i = i->sig){
            cout << i->dato << " " << end;
        }
        cout << endl;
    }
}

int main(){
    tnodo<int>* nuevo;
    tlista<int> lista;
    IniciarLista(lista);
    CrearNodo<int>(nuevo, 1);
    AgregarNodo<int>(lista, *nuevo);

    MostrarLista(lista);
    return 0;
}
