#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

struct Estudiante{
	int codigo, fila = 0, columna = 0, nota;
	char nombre[30];
}estudiante, **pestudiante;

void pedir();
void mostrar(Estudiante **);

int main(){
	pedir();
	mostrar(pestudiante);
	//-> señala posiciones en struct

	return 0;
}

void pedir(){
	cout<<"Cuantos estudiantes desea ingresar: "<<endl;
	cin>>pestudiante->fila;
	cout<<"Cuantas notas desea ingresar?"<<endl;
	cin>>pestudiante->columna;
	
	pestudiante = new int *[pestudiante->fila];
	for(int i = 0;i<pestudiante->fila;i++){
		pestudiante[i] = new int *[pestudiante->columna];
	}	
	cout<<"------------------Ingrese Notas-------------------------"<<endl;
	for(int i = 0;i<fila;i++){
		for(int x = 0;x<columna;x++){
			cout<<"Estudiante: ["<<i<<", Nota: ["<<x<<"] :"<<endl;
			cin>>*(*(pestudiante+i)+x);//para filas y columnas
		}
		cout<<"---------------------------------------------------------"<<endl;
	}
}

void mostrar(Estudiante **pestudiante){
	cout<<"---------------------Mostrar Notas: -----------------------"<<endl;
		for(int i = 0;i<fila;i++){
		for(int x = 0;x<columna;x++){
			cin>>*(*(pestudiante+i)+x);
		}
		cout<<"-----------------------------------------------------------"<<endl;
	}
	for(int i = 0;i<fila;i++){
		delete[] pestudiante[i];
	}
	delete[] pestudiante;
}














