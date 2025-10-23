#include <iostream>
using namespace std;

//Usando directorio de nodos
typedef struct Ruta *pruta;

//Arcos o Aristas
struct Ruta{
    float distancia;
    int tipoCamino;
    pruta ruta_sig;
};

//Vertices
struct Ciudad{
    string nombre;
    string localidad;
    string provincia;
    int codigoPostal;
    pruta lista_rutas;
};

typedef Ciudad g_ciudades[20];

void iniciar_ciudad(g_ciudades &ciudades){
    for(int i = 0; i < 20; i++){
        ciudades[i].lista_rutas = nullptr;
    }
}