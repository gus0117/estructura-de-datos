#include<iostream>

using namespace std;


/*
    TDA BICOLA implementado con registro
    Entrada restringida
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
};

int next(int indice){
    indice = indice + 1;
    if(indice == MAX){
        indice = 0;
    }
    return indice;
}

/*
    Retorna el valor anterior al indice
*/
int previous(int indice){
    indice = indice - 1;
    if(indice == 0){
        indice = MAX - 1;
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

/*
    Quita un elemento de la cola y lo retorna
    Si la cola está vacía devuelve un valor arbitrario
    op = 1 : Quitar por frente
    op = 2: Quitar por final
*/
int pop_queue(t_cola &c, int op){
    int extraido;
    if(is_empty_queue(c)){
        cout<<"La cola está vacía"<<endl;
        extraido = -999; //Valor arbitrario
    }
    else{
        if(op == 1){
            c.frente = next(c.frente);
            extraido = c.datos[c.frente];
        }
        else{
            extraido = c.datos[c.fin];
            c.fin = previous(c.fin);
        }
        
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


int main(){
    t_cola c;
    init_queue(c);
    push_queue(c, 4);
    push_queue(c, 2);
    push_queue(c, 10);

    cout<<pop_queue(c, 1)<<endl;
    cout<<pop_queue(c, 2)<<endl;
    //cout<<top_queue(c)<<endl;
    //cout<<bottom_queue(c)<<endl;
    return 0;
}