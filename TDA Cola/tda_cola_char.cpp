#include<iostream>

using namespace std;


/*
    TDA COLA implementado con registro y array
    Prioriza velocidad de procesamiento
*/

const int MAX = 100;

typedef char contenedor[MAX];

/*
    frente: indica el próximo en salir
    fin: indica el último que se agrego
*/
typedef struct t_cola{
    contenedor datos;
    int frente;
    int fin;
};

int next(int indice){
    indice = indice + 1;
    if(indice == MAX){
        indice = 0;
    }
    return indice;
}


/*
    Inicializa la cola como vacia
*/
void init_queue(t_cola &c){
    c.frente = 0;
    c.fin = 0;
}

bool is_empty_queue(t_cola c){
    return c.frente == c.fin;
}

bool is_full_queue(t_cola &c){
    return c.frente == next(c.fin);
}

void push_queue(t_cola &c, char nuevo){
    if(is_full_queue(c)){
        cout<<"La cola está llena"<<endl;
    }
    else{
        c.fin = next(c.fin);
        c.datos[c.fin] = nuevo;
    }
}

char pop_queue(t_cola &c){
    int extraido;
    if(is_empty_queue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido = -999; //Valir arbitrario
    }
    else{
        c.frente = next(c.frente);
        extraido = c.datos[c.frente];
    }
    return extraido;
}

/*
    Retorna el valor apuntado por el indice frente
 */
char top_queue(t_cola c){
    char extraido;
    if(is_empty_queue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido = '*';
    }
    else{
        extraido = c.datos[next(c.frente)];
    }
    return extraido;
}

/*
    Retorna el valor apuntado por el indice fin
 */
char bottom_queue(t_cola c){
    char extraido;
    if(is_empty_queue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido =  '*';
    }
    else{
        extraido = c.datos[c.fin];
    }
    return extraido;
}

/*
    Elimina los espacios en blanco de una frase
*/
void eliminar_espacios(string palabra){
    t_cola c;
    init_queue(c);
    for(int i = 0; i < palabra.size(); i++){
        if(palabra[i] != ' '){
            push_queue(c,palabra[i]);
        }
    }
    string sin_espacios = "";
    while(!is_empty_queue(c)){
        sin_espacios += pop_queue(c);
    }
    cout<<sin_espacios<<endl;
}

int main(){
    eliminar_espacios("Estructura de datos");    
    return 0;
}