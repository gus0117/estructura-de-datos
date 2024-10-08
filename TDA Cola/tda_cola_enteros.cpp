#include<iostream>

using namespace std;


/*
    TDA COLA implementado con registro y array
    Prioriza velocidad de procesamiento
*/

const int MAX = 10;

typedef int contenedor[MAX];

/*
    frente: indica el próximo en salir
    fin: indica el último que se agrego
*/
typedef struct t_cola{
    contenedor datos;
    int frente;
    int fin;
    int cantidad;
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

void push_queue(t_cola &c, int nuevo){
    if(is_full_queue(c)){
        cout<<"La cola está llena"<<endl;
    }
    else{
        c.fin = next(c.fin);
        c.datos[c.fin] = nuevo;
    }
}

int pop_queue(t_cola &c){
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
int top_queue(t_cola c){
    int extraido;
    if(is_empty_queue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido =  -999;
    }
    else{
        extraido = c.datos[next(c.frente)];
    }
    return extraido;
}

/*
    Retorna el valor apuntado por el indice fin
 */
int bottom_queue(t_cola c){
    int extraido;
    if(is_empty_queue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido =  -999;
    }
    else{
        extraido = c.datos[c.fin];
    }
    return extraido;
}

void incognita(int t){
    int num = 2, aux, temp;
    t_pila p;
    init_stack(p);
    push_stack(p, 1);
    push_stack(p, 1);
    while(num < t){
        aux = 0;
        temp = 0;
        temp = top_stack(p);
        aux += pop_stack(p);
        aux += pop_stack(p);
        push_stack(p, temp);
        push_stack(p, aux);
        num++;
    }
    cout<<top_stack(p)<<endl;
}

int main(){
    t_cola c;
    init_queue(c);
    incognita(17);
    return 0;
}
