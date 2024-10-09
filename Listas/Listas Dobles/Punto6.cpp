#include<iostream>
#include<stdlib.h>
#include<stddef.h>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
typedef struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };
void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}
void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}
void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL)
    {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo -> sig = lista.inicio;
        lista.inicio -> ant = nuevo;
        lista.inicio = nuevo;
    }
}
void AgregarFinal(tlista &lista, pnodo nuevo)
{
    if(lista.fin == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin -> sig = nuevo;
        nuevo -> ant = lista.fin;
        lista.fin = nuevo;
    }
}
void AgregarOrden(tlista &lista, pnodo nuevo)
{
    pnodo i;
    if(lista.inicio == NULL)
    {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        if(lista.inicio -> dato < nuevo -> dato)
        {
            nuevo -> sig = lista.inicio;
            lista.inicio -> ant = nuevo;
            lista.inicio = nuevo;
        }
        else{
            if(lista.fin -> dato > nuevo -> dato){
                lista.fin -> sig = nuevo;
                nuevo -> ant = lista.fin;
                lista.fin = nuevo;
            }
            else{
                for(i = lista.inicio -> sig; i != lista.fin && i -> dato < nuevo -> dato; i = i -> sig);
                nuevo -> sig = i;
                nuevo -> ant = i -> ant;
                (i -> ant) -> sig = nuevo;
                i -> ant = nuevo;
            }
        }
    }
}
pnodo QuitarInicio(tlista &lista)
{
    pnodo extraido;
    if(lista.inicio == NULL){
        extraido = NULL;
    }
    else{
        if(lista.inicio -> sig == NULL){
            extraido = lista.inicio;
            lista.inicio = NULL;
            lista.fin = NULL;
        }
        else{
            extraido = lista.inicio;
            lista.inicio = lista.inicio -> sig;
            lista.inicio -> ant = NULL;
            extraido -> sig = NULL;
        }
    }
}
pnodo QuitarFinal(tlista &lista)
{
    pnodo extraido;
    if(lista.fin == NULL){
        extraido = NULL;
    }
    else{
        if(lista.inicio -> sig == NULL)
        {
            extraido = lista.fin;
            lista.fin = NULL;
            lista.inicio = NULL;
        }
        else{
            extraido = lista.fin;
            lista.fin = lista.fin -> ant;
            extraido -> ant = NULL;
            lista.fin -> sig = NULL;
        }
    }
    return extraido;
}
pnodo QuitarNodo(tlista &lista, int valor)
{
    pnodo extraido, i;
    if(lista.inicio == NULL){
        extraido = NULL;
    }
    else{
        //extraido = QuitarInicio(lista);
        if(lista.inicio -> dato == valor)
        {
            if(lista.inicio == lista.fin){
                extraido = lista.inicio;
                lista.inicio = NULL;
                lista.fin = NULL;
            }
            else{
                extraido = lista.inicio;
                lista.inicio = lista.inicio -> sig;
                lista.inicio -> ant = NULL;
                extraido -> sig = NULL;
            }
        }
        else{
            //extraido = QuitarFinal(lista);
            if(lista.fin -> dato == valor){
                if(lista.fin == lista.inicio){
                    extraido = lista.fin;
                    lista.inicio = NULL;
                    lista.fin = NULL;
                }
                else{
                    extraido = lista.fin;
                    lista.fin = lista.fin -> ant;
                    lista.fin -> sig = NULL;
                    extraido -> ant = NULL;
                }
            }
            else{
                //Valor se encuentra en medio de la lista
                for(i = lista.inicio; i != lista.fin && i -> dato != valor; i = i -> sig);
                if(i != lista.fin){
                    extraido = i;
                    (i -> ant) -> sig = i -> sig;
                    (i -> sig) -> ant = i -> ant;
                    extraido -> sig = NULL;
                    extraido -> ant = NULL;
                }
                else{
                    extraido = NULL;
                }
            }
        }
    }
    return extraido;
}
bool BuscarNodo(tlista lista, int valor)
{
    pnodo i;
    bool encontrado = false;
    if(lista.inicio == NULL)
    {
        cout << "Lista Vacia" << endl;
    }
    else{
        for(i = lista.inicio; i != NULL && i -> dato != valor; i = i -> sig);
        if(i != NULL)
            encontrado = true;
    }
    return encontrado;
}

void MostrarLista(tlista lista)
{
    pnodo i;
    if(lista.inicio != NULL)
    {
        for(i = lista.inicio; i != NULL; i = i -> sig){
            cout << i -> dato << endl;
        }
    }
}



void ObtenerBinario(){
    int num = 117;
    tlista lista;
    pnodo nuevo;
    IniciarLista(lista);
    int resto;
    while(num > 0){
        resto = num % 2;
        CrearNodo(nuevo, resto);
        AgregarInicio(lista, nuevo);
        num = num / 2;
    }
    for(pnodo i = lista.inicio; i != NULL; i = i->sig){
        cout << i->dato;
    }
    cout << endl;
}

bool EstaVacia(tlista lista){

    return lista.inicio == NULL;
}

void MostrarListaMejorado(tlista lista, int op){
    if(EstaVacia(lista)){
        cout << "Lista vacia" << endl;
        return;
    }
    pnodo i;
    if(op == 1){
        for(i = lista.inicio; i != NULL; i = i->sig){
            cout << i->dato << " ";
        }
    }
    else if(op == 2){
        for(i = lista.fin; i != NULL; i = i->ant){
            cout << i->dato << " ";
        }
    }
    cout << endl;
}
main()
{
    tlista lista;
    pnodo nuevo;
    IniciarLista(lista);
    for(int i = 1; i <= 5; i++){
        CrearNodo(nuevo, i);
        //AgregarInicio(lista, nuevo);
        //AgregarFinal(lista, nuevo);
        AgregarFinal(lista, nuevo);
    }
    cout << "Lista en orden ";
    MostrarListaMejorado(lista, 1);
    cout << "Lista invertida ";
    MostrarListaMejorado(lista, 2);

}
