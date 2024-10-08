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
void IniciarLista(pnodo &inicio)
{
    inicio = NULL;
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
void AgregarInicio(pnodo &inicio, pnodo nuevo)
{
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        nuevo -> sig = inicio;
        inicio -> ant = nuevo;
        inicio = nuevo;
    }
}
void AgregarFinal(pnodo &inicio, pnodo nuevo)
{
    pnodo i;
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        for(i = inicio; i -> sig != NULL; i = i -> sig);
        i -> sig = nuevo;
        nuevo -> ant = i;
    }
}
void AgregarOrden(pnodo &inicio, pnodo nuevo)
{
    pnodo i;
    if(inicio == NULL){
        inicio = nuevo;
    }
    else{
        if(nuevo -> dato < inicio -> dato)
        {
            nuevo -> sig = inicio;
            inicio -> ant = nuevo;
            inicio = nuevo;
        }
        else{
            for(i = inicio; i -> sig != NULL && (i -> sig) -> dato < nuevo -> dato; i = i -> sig);
            if(i -> sig != NULL){
                nuevo -> sig = i -> sig;
                nuevo -> ant = i;
                (i -> sig) -> ant = nuevo;
                i -> sig = nuevo;
            }
            else{
                i -> sig = nuevo;
                nuevo -> ant = i;
            }
        }
    }
}
pnodo QuitarInicio(pnodo &inicio)
{
    pnodo extraido;
    if(inicio == NULL)
    {
        extraido = NULL;
    }
    else{
        if(inicio -> sig == NULL)
        {
            extraido = inicio;
            inicio = NULL;
        }
        else{
            extraido = inicio;
            inicio = inicio -> sig;
            inicio -> ant = NULL;
            extraido -> sig = NULL;
        }
    }
    return extraido;
}
pnodo QuitarFinal(pnodo &inicio)
{
    pnodo extraido, i;
    if(inicio == NULL)
    {
        extraido = NULL;
    }
    else{
        for(i = inicio; i -> sig != NULL; i = i -> sig);
        extraido = i;
        (i -> ant) -> sig = NULL;
        i -> ant = NULL;
    }
    return extraido;
}
pnodo QuitarNodo(pnodo &inicio, int valor)
{
    pnodo extraido, i;
    if(inicio == NULL)
    {
        extraido = NULL;
    }
    else{
        if(inicio -> dato == valor)
        {
            extraido = inicio;
        }
        for(i = inicio; i != NULL && i -> dato != valor; i = i -> sig);
        if(i != NULL){
            extraido = i;
            (i -> ant) -> sig = i -> sig;
            i -> sig = i -> ant;
            extraido -> sig = NULL;
            extraido -> ant = NULL;
        }
    }
    return extraido;
}
void MostrarLista(pnodo inicio)
{
    pnodo i;
    if(inicio != NULL)
    {
        for(i = inicio; i != NULL; i = i -> sig){
            cout << i -> dato << endl;
        }
    }
}
main()
{
    pnodo inicio, nuevo;
    IniciarLista(inicio);
    for(int i = 0; i < 6; i++){
        CrearNodo(nuevo, i);
        //AgregarInicio(inicio, nuevo);
        //AgregarFinal(inicio, nuevo);
        AgregarOrden(inicio, nuevo);
    }
    MostrarLista(inicio);
    pnodo borrado = QuitarNodo(inicio, 5);//QuitarFinal(inicio);//QuitarInicio(inicio);
    cout << "Quitado: " << borrado -> dato << endl;
    MostrarLista(inicio);
}
