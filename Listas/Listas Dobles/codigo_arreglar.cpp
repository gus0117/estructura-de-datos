/*
    Este código fue recuperado pero le faltan 
    partes importantes para poder funcionar
    
    * no me salvó la Virgen de Guadalupe. *
*/

#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

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

void Agregar(tlista &lista, pnodo nuevo)
{
    //CODIGO FALTANTE
}


void MostrarLista(tlista lista, string nombre, int op)
{
    if(lista.inicio != NULL){
        pnodo i;

        if(op == 1){
            cout << "\n\t"<<nombre<<" en orden IZQUIERDA a DERECHA \t";
            //CODIGO FALTANTE
        }
        else if(op == 2){
            cout << "\n\t"<<nombre<<" en orden DERECHA a IZQUIERDA \t";
            //CODIGO FALTANTE
        }
    }
}

void CargarListaConNumeros(tlista &lista){

    int desde, hasta;
    cout << "\n\tDigite los valores DESDE y HASTA donde quiere cargar la lista\n\t";
    cin >> desde >> hasta;
    cout << endl;

    // CODIGO FALTANTE
}

void CombinarListas(tlista &resultante, tlista lista1, tlista lista2){
    if(lista1.inicio != NULL & lista2.inicio != NULL){
        pnodo i, nuevo;
        IniciarLista(resultante);
        
        //CODIGO FALTANTE

    }
}

main()
{
    tlista listaCombinada, lista1, lista2;

    pnodo nuevo;

    system("cls"); //Comando de limpieza de la pantalla
    system("color 70"); //Comando de configuración de color
    cout << endl;
    cout << "\n\tPROGRAMA QUE REALIZA ALGUNAS OPERACIONES CON LISTA ENLAZADA\n";
    cout << "\t-----------------------------------------------------------\n";


    CargarListaConNumeros(lista1);
    CargarListaConNumeros(lista2);

    CombinarListas(listaCombinada, lista1, lista2);

    cout << "\n\tImprimir Listas\n";
    cout << "\t------------------------------------------------------\n";

    MostrarLista(lista1, "Lista 1", 1);
    MostrarLista(lista2, "Lista 2", 2);
    MostrarLista(listaCombinada, "Lista combinada", 1);
    cout << "\n\t------------------------------------------------------\n";
    cout << endl << endl;
    cout << "\t";
    system("pause");
    return 0;
}
