#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>

using namespace std;

const char*nom_archivo = "archivo.dat";
const char*aux_archivo = "auxiliar.dat";

struct Empleado{
	int codigo_empleado;
	char nombre[50];
	char apellido[50];
	char puesto[30];
	int sueldo_b, sueldo_t;
	int bonif = 250;
};

void menu();
void ingresar_datos();
void lectura();
void buscar();
void modificar();
void eliminar();

int main(){
	menu();
	
	getch();
	return 0;
}

void menu(){
	system("cls");
	int opcion;
	
	cout<<"Seleccione alguna de las opciones"<<endl;
	cout<<"1) Ingreso de datos"<<endl;
	cout<<"2) Leer datos"<<endl;
	cout<<"3) Buscar por codigo"<<endl;
	cout<<"4) Modificar registro"<<endl;
	cout<<"5) Eliminar registro"<<endl;
	cout<<"0) Salir"<<endl;
	
	cin>>opcion;
	
	switch(opcion){
		case 1: ingresar_datos();
			break;
		case 2: lectura();
			break;
		case 3: buscar();
			break;
		case 4: modificar();
			break;
		case 5: eliminar();
			break;
		case 0:
			break;
	}
}

void ingresar_datos(){
	system("cls");
	char next;
	
	FILE* archivo = fopen(nom_archivo,"ab");
	
	Empleado empleado;
	string nombre, apellido, puesto;
	
	do{
		fflush(stdin);
		
		cout<<"Ingrese su codigo de empleado: "<<endl;
		cin>>empleado.codigo_empleado;
		cin.ignore();
		
		cout<<"Ingrese su nombre: "<<endl;
		getline(cin,nombre);
		strcpy(empleado.nombre, nombre.c_str());
		
		cout<<"Ingrese su apellido: "<<endl;
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str());
		
		cout<<"Ingrese su puesto de trabajo: "<<endl;
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"Ingrese su sueldo: "<<endl;
		cin>>empleado.sueldo_b;
		
		empleado.sueldo_t = empleado.sueldo_b+empleado.bonif;
		
		fwrite(&empleado, sizeof(Empleado),1,archivo);
		
		cout<<"Desea agregar otro registro? "<<endl;
		cin>>next;
	}while((next == 'S' || next == 's'));
	
	fclose(archivo);
	getch();
	menu();
}

void lectura(){
	system("cls");
	
	FILE* archivo = fopen(nom_archivo,"rb");
	
	if(!archivo){
		archivo = fopen(nom_archivo, "w+b");
	}
	Empleado empleado;
	int id = 0;
	
	fread(&empleado, sizeof(Empleado),1,archivo);
	cout<<"id "<<"|"<<"  codigo  "<<"|"<<"Nombres\t\t\t"<<"|"<<"Apellidos\t\t\t"<<"|"<<"puesto\t\t\t"<<"|"<<"sueldo total\t\t"<<endl;
	do{
		cout<<"____________________________________________________________________________________________________________________________"<<endl;
		cout<<id<<"\t|"<<empleado.codigo_empleado<<"\t|"<<empleado.nombre<<"\t\t\t|"<<empleado.apellido<<"\t\t\t|"<<empleado.puesto<<"\t\t\t|"<<empleado.sueldo_t<<" "<<endl;
		
		fread(&empleado, sizeof(Empleado),1,archivo);
		id += 1;
	}while(feof(archivo) == 0);
	
	cout<<endl;
	fclose(archivo);
	getch();
	menu();	
}

void buscar(){
	system("cls");
	FILE *archivo = fopen(nom_archivo,"rb");
	
	int indice = 0, pos = 0, codigo = 0;
	
	cout<<"Ingrese el codigo que desea encontrar: "<<endl;
	cin>>codigo;
	
	Empleado empleado;
	fread(&empleado,sizeof(Empleado),1,archivo);
	
	do{
		if(empleado.codigo_empleado == codigo){
			pos = indice;
		}
		fread(&empleado,sizeof(Empleado),1,archivo);
		indice += 1;
	}while(feof(archivo) == 0);
	
	cout<<"**********************"<<pos<<"**************************"<<endl;
	fseek(archivo,pos*sizeof(Empleado),SEEK_SET);
	
	fread(&empleado, sizeof(Empleado),1,archivo);
	
	cout<<"Codigo: "<<empleado.codigo_empleado<<endl;
	cout<<"Nombres: "<<empleado.nombre<<endl;
	cout<<"Apellidos: "<<empleado.apellido<<endl;
	cout<<"Puesto de trabajo: "<<empleado.puesto<<endl;
	cout<<"Sueldo total: "<<empleado.sueldo_t<<endl;
	cout<<endl;
	
	fclose(archivo);
	getch();
	menu();
}
	
void modificar(){
	system("cls");
	FILE *archivo = fopen(nom_archivo, "r+b");
	
	int id;
	string nombre, apellido, puesto;
	Empleado empleado;
	
	cout<<"Ingrese el id que desee modificar: "<<endl;
	cin>>id;
	
	fseek(archivo, id*sizeof(Empleado), SEEK_SET);
	
	cout<<"Ingrese su codigo de empleado: "<<endl;
	cin>>empleado.codigo_empleado;
	cin.ignore();
		
	cout<<"Ingrese su nombre: "<<endl;
	getline(cin,nombre);
	strcpy(empleado.nombre, nombre.c_str());
		
	cout<<"Ingrese su apellido: "<<endl;
	getline(cin,apellido);
	strcpy(empleado.apellido, apellido.c_str());
		
	cout<<"Ingrese su puesto de trabajo: "<<endl;
	getline(cin,puesto);
	strcpy(empleado.puesto, puesto.c_str());
		
	cout<<"Ingrese su sueldo: "<<endl;
	cin>>empleado.sueldo_b;

	empleado.sueldo_t = empleado.sueldo_b+empleado.bonif;
	
	fwrite(&empleado, sizeof(Empleado),1,archivo);
	fclose(archivo);
	lectura();
	getch();
	menu();
}
	
void eliminar(){
	char next;
	int id;
	string nombre,apellido;
	FILE* archivo = fopen(nom_archivo,"r+b");//para lectura y escritura
	FILE* archivoa = fopen(aux_archivo, "r+b");
	Empleado empleado;
	
	if(nom_archivo!=NULL){
		cout<<"Ingrese el id que desee eliminar: "<<endl;
		cin>>id;
		
		fseek(archivo, id*sizeof(Empleado),SEEK_SET);
		
		fread(&empleado, sizeof(Empleado),1,archivo);
	
		cout<<"Codigo: "<<empleado.codigo_empleado<<endl;
		cout<<"Nombres: "<<empleado.nombre<<endl;
		cout<<"Apellidos: "<<empleado.apellido<<endl;
		cout<<"Puesto de trabajo: "<<empleado.puesto<<endl;
		cout<<"Sueldo total: "<<empleado.sueldo_t<<endl;
		cout<<endl;
		
		fwrite(&empleado, sizeof(Empleado),1,archivoa);
		fclose(archivo);
		fclose(archivoa);
	}else{
		cout<<"Hubo un error, intentelo de nuevo"<<endl;
	}
	remove("archivo.dat");
	rename("auxiliar.dat","archivo.dat");
	menu();
}
	





















