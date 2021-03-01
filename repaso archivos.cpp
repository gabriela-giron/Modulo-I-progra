#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<sstream>

using namespace std;

const char*nombre_archivo = "archivo2.dat";
const char*auxi = "auxiliar.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
};

void ingresar_estudiante();
void abrir_estudiante();//leer registro
void modificar_estudiante();
void buscar_datos();//busca registros en el archivo
void buscar_codigo();
void eliminar_dato();

int main(){
	int opc;
	
	cout<<"seleccione la opcion que desee realizar: "<<endl;
	cout<<"1) Ingresar datos"<<endl;
	cout<<"2) leer archivos"<<endl;
	cout<<"3) Modificar datos del archivo"<<endl;
	cout<<"4) Buscar datos"<<endl;
	cout<<"5) Buscar codigo"<<endl;
	cout<<"6) Eliminar datos"<<endl;
	
	cin>>opc;
	
	switch(opc){
		case 1:
			ingresar_estudiante();
			break;
		case 2:
			abrir_estudiante();
			break;
		case 3:
			modificar_estudiante();
			break;
		case 4:
			buscar_datos();
			break;
		case 5:
			buscar_codigo();
			break;
		case 6:
			eliminar_dato();
			break;
	}
	
	getch();
	return 0;
}

void ingresar_estudiante(){
	char continuar;
	
	FILE* archivo = fopen(nombre_archivo,"ab");//ab = añadir binary
	
	Estudiante estudiante;
	string nombre,apellido;
	
	do{
		fflush(stdin);
		
		cout<<"Ingrese el codigo: "<<endl;
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"ingrese el nombre: "<<endl;
		getline(cin,nombre);
		strcpy(estudiante.nombre, nombre.c_str());
		
		cout<<"ingrese los apellidos: "<<endl;
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str());
		
		cout<<"ingrese el telefono: "<<endl;
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite(&estudiante, sizeof(Estudiante),1,archivo);
		
		cout<<"Desea agregar otro registro? s/n: "<<endl;
		cin>>continuar;
	}while((continuar=='s') || (continuar=='S'));
	
	fclose(archivo);
	abrir_estudiante();
}

void abrir_estudiante(){
	system("cls");
	
	FILE* archivo = fopen(nombre_archivo,"rb" );//abre un fichero existente para lectura
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");//crea un archivo para lectura
	}
	Estudiante estudiante;
	int registro = 0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"_________________________________________________________________________________________"<<endl;
	cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<" "<<"Apellidos"<<" "<<"Telefono"<<" "<<endl;
	do{
		cout<<"______________________________________________________________________________________________"<<endl;
		cout<<registro<<" | "<<estudiante.codigo<<" | "<<estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<" "<<endl;
		
		fread(&estudiante, sizeof(Estudiante),1,archivo);
		registro += 1;
	}while(feof(archivo) == 0);//para saber cuando se llega al final del archivo
	
	cout<<endl;
	
	fclose(archivo);
	
}

void modificar_estudiante(){
	FILE* archivo = fopen(nombre_archivo,"r+b");//r+b abre un archivo existente para lectura o escritura
	
	int id;
	string nombre, apellido;
	Estudiante estudiante;
	
	cout<<"ingrese el id que desee modificar: "<<endl;
	cin>>id;
	
	fseek(archivo, id*sizeof(Estudiante),SEEK_SET);
	
	cout<<"Ingrese el codigo: "<<endl;
	cin>>estudiante.codigo;
	cin.ignore();
	
	cout<<"Ingrese el nombre: "<<endl;
	getline(cin,nombre);
	strcpy(estudiante.nombre, nombre.c_str());
	
	cout<<"Ingrese los apellidos: "<<endl;
	getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str());
	
	cout<<"ingrese el telefono: "<<endl;
	cin>>estudiante.telefono;
	cin.ignore();
	
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	fclose(archivo);
	system("pause");
	
}

void buscar_datos(){
	FILE* archivo = fopen(nombre_archivo,"rb");//archivo para lectura
	
	int pos = 0;
	cout<<"Que registro desea leer?: "<<endl;
	cin>>pos;
	
	cout<<"--------------------------"<<pos<<"----------------------------------"<<endl;
	fseek(archivo,pos* sizeof(Estudiante), SEEK_SET);
	
	Estudiante estudiante;
	
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombre: "<<estudiante.nombre<<endl;
	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	cout<<endl;
	
	fclose(archivo);
}

void buscar_codigo(){
	FILE* archivo = fopen(nombre_archivo,"rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"Ingrese el codigo que desee encontrar: "<<endl;
	cin>>cod;
	Estudiante estudiante;
	
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	
	do{
		if(estudiante.codigo == cod){
			pos = indice;
		}
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	indice += 1;
	}while(feof(archivo) == 0);
	
	cout<<"---------------------------"<<pos<<"----------------------------"<<endl;
	fseek(archivo,pos*sizeof(Estudiante),SEEK_SET);
	
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombre: "<<estudiante.nombre<<endl;
	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	cout<<endl;
	
	fclose(archivo);
	system("pause");
}

void eliminar_dato(){
	char continuar;
	string nombre,apellido;
	FILE* archivo = fopen(nombre_archivo,"r+b");//para lectura y escritura
	FILE* archivoa = fopen(auxi, "r+b");
	
	if(nombre_archivo!=NULL){
		int indice=0,pos=0,cod=0;
		cout<<"Ingrese el codigo que desee eliminar: "<<endl;
		cin>>cod;
		Estudiante estudiante;
		
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		
		do{
			if(estudiante.codigo == cod){
				pos = indice;
			}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		indice += 1;
		}while(feof(archivo) == 0);
		
		do{
		cout<<"---------------------------"<<pos<<"----------------------------"<<endl;
		fseek(archivo,pos*sizeof(Estudiante),SEEK_SET);
		
		fread(&estudiante, sizeof(Estudiante),1,archivo);
		
		cout<<"Codigo: "<<estudiante.codigo<<endl;
		cout<<"Nombre: "<<estudiante.nombre<<endl;
		cout<<"Apellidos: "<<estudiante.apellido<<endl;
		cout<<"Telefono: "<<estudiante.telefono<<endl;
		cout<<endl;
		
		cout<<"Desea eliminar este registro? s/n"<<endl;
		cin>>continuar;
		}while((continuar=='n') || (continuar=='N'));
		
		while(feof(archivo) == 0){
			fseek(archivo,pos*sizeof(Estudiante),SEEK_SET);
			fread(&estudiante, sizeof(Estudiante),1,archivo);
			if(estudiante.codigo == cod){
				cout<<"el registro fue eliminado correctamente."<<endl;
				getch();
			}else{
				cout<<"\t\t"<<estudiante.codigo<<"\t\t"<<estudiante.nombre<<"\t\t"<<estudiante.apellido<<"\t\t"<<estudiante.telefono<<"\t\t"<<endl;
				fwrite(&estudiante, sizeof(Estudiante),1,archivoa);
			}
		fread(&estudiante, sizeof(Estudiante),1,archivo);
		}
		fclose(archivo);
		fclose(archivoa);
	}else{
		cout<<"Hubo un error, intentelo de nuevo"<<endl;
	}
	remove("archivo2.dat");
	rename("auxiliar.dat","archivo2.dat");
}





