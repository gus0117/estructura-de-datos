#include<iostream>
using namespace std;
const int MAX = 4;

//TDA Cola que prioriza espacio de almacenamiento
class TDACola{
private:
	int contenedor[MAX];
	int frente;
	int fin;
	int cantidad;
public:
	TDACola(){
		frente = 0;
		fin = 0;
		cantidad = 0;
	}
	int next(int index){
		index++;
		if(index == MAX)
			index = 0;
		return index;
	}
	bool isFull(){
		return cantidad == MAX;
	}
	bool isEmpty(){
		return cantidad == 0;
	}
	void push(int valor){
		if(isFull()){
			cout << "La cola esta llena" << endl;
			return;
		}
		contenedor[fin] = valor;
		fin = next(fin);
		cantidad++;
	}
	int pop(){
		if(isEmpty()){
			return -999;
		}
		int aux = contenedor[frente];
		frente = next(frente);
		cantidad--;
		return aux;
	}
	int top(){
		if(isEmpty()){
			return -999;
		}
		int aux = contenedor[frente];
		return aux;
	}
	int bottom(){
		if(isEmpty()){
			return -999;
		}
		int aux = contenedor[fin];
		return aux;
	}
};

int main(){
	TDACola c;
	c.push(12);
	c.push(42);
	c.push(1);
	c.push(54);
	c.push(17);
	
	while(!c.isEmpty()){
		cout << c.pop() << endl;
	}

}
