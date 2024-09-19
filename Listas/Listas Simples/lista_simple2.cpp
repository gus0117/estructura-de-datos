#include<iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
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

void CrearNodo(pnodo &nuevo)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        cout << "Ingrese dato: ";
        cin >> nuevo -> dato;
        nuevo -> sig = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL)
    {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else
    {
        nuevo -> sig = lista.inicio;
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
        lista.fin = nuevo;
    }
}
void AgregarOrden(tlista &lista, pnodo nuevo)
{
    pnodo i;
    if(lista.inicio == NULL)
    {
        AgregarInicio(lista, nuevo);
    }
    else
    {
        if(nuevo -> dato <= lista.inicio -> dato){
            nuevo -> sig = lista.inicio;
            lista.inicio = nuevo;
        }
        else{
            if(nuevo -> dato >= lista.fin -> dato){
                lista.fin -> sig = nuevo;
                lista.fin = nuevo;
            }
            else{
                for(i = lista.inicio; (i -> sig) -> sig != NULL && nuevo -> dato <= (i -> sig) -> dato; i = i -> sig);
                nuevo -> sig = i -> sig;
                i -> sig = nuevo;
            }
        }
    }
}
pnodo QuitarInicio(tlista &lista)
{
    pnodo extraido;
    extraido = lista.inicio;
    lista.inicio = lista.inicio -> sig;
    return extraido;
}
pnodo QuitarFinal(tlista &lista)
{
    pnodo extraido, i;
    if(lista.fin == NULL){
        extraido = NULL;
    }
    else{
        for(i = lista.inicio; (i -> sig) -> sig != NULL; i = i -> sig);
        extraido = i -> sig;
        i -> sig = NULL;
        lista.fin = i;
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
        for(i = lista.inicio; i -> sig != lista.fin && valor != (i -> sig) -> dato; i = i -> sig);
        extraido = i -> sig;
        i -> sig = NULL;
        lista.fin = i;
    }
    return extraido;
}
bool BuscarNodo(tlista lista, int valor)
{
    pnodo i;
    bool encontrado;
    for(i = lista.inicio; i != NULL && i -> dato != valor; i = i -> sig);
    encontrado = i == NULL;
    return encontrado;
}
void MostrarLista(tlista lista)
{
    pnodo i;
    for(i = lista.inicio; i != NULL; i = i -> sig){
        cout << i->dato << endl;
    }
}
main()
{
    tlista lista;
    pnodo nuevo;
    IniciarLista(lista);
    for(int i = 0; i < 5; i++){
        CrearNodo(nuevo);
        //AgregarInicio(lista, nuevo);
        //AgregarFinal(lista, nuevo);
        AgregarOrden(lista, nuevo);
    }

    //pnodo borrado = QuitarInicio(lista);
    //pnodo borrado = QuitarFinal(lista);
    //pnodo borrado = QuitarNodo(lista, 5);
    //cout << "Borrado: " << borrado -> dato << endl;
    MostrarLista(lista);
}
