#include<iostream>
#include<conio.h>
#include<string>
#include<cmath>
#include<stdio.h>
#include<windows.h>
#include<winuser.h>

//teclas direccionales
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

//ocultar cursor 
void OcultarCursor();

//funcion principal
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hcon, dwPos);
}
//ocultar cursor
void OcultarCursor(){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize= 50;
	cci.bVisible=FALSE;
	
	SetConsoleCursorInfo(hcon,&cci);
}

using namespace std;

//void menu_principal();
int menu(const char* titulo, const char *subtitulo, const char *opciones[], int n);
//programa 1
void menu_operaciones();
void suma();
void resta();
void multiplicacion();
void division();
//2
void par_impar();
//3
void menu_conversiones();
void kmam();
void maplg();
void lbakil();
//4
void palindromo();
//5
void num_romanos();
//6
void num_letras();
//7 decimales a letras
void decimales();
//8
void multiplicar();
//9
void multiplicar2();
//10 multiplicacion grafica
void mult_grafica();
//11 num binarios
void binario(int n){
    if(n>1)
        binario(n/2);
        cout<<n%2;
}
void binarios();
//12
void hexadecimales();
//13 figuras geometricas
void geometricas();
//14 punto en la pantalla
void punto();
//15
void cajero();
//16
void hipotenusa();
//17
void click();
//18
void trivia();
//19
void nums();
//20
void reproductor();

char opcion;
int x=50, y=15;

//coso para flechas direccionales
int menu(const char* titulo, const char *subtitulo, const char *opciones[], int n){
	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;
	
	do{
		system("cls");
		gotoxy(48,13 + opcionSeleccionada);
		cout<<">";
		
		gotoxy(80,10);
		cout<<titulo;
		gotoxy(73,12);
		cout<<subtitulo;
		for(int i=0; i<n; i++){
			gotoxy(50, 14 + i);
			cout<<i + 1<<". "<<opciones[i];
		}
		do{
			tecla = getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=ENTER);
		
		switch(tecla){
			case TECLA_ARRIBA:
				opcionSeleccionada--;
				
				if(opcionSeleccionada == 0){
					opcionSeleccionada = n;
				}
				break;
			case TECLA_ABAJO:
				opcionSeleccionada++;
				
				if(opcionSeleccionada > n){
					opcionSeleccionada = 1;
				}
				break;
			case ENTER:
				repite = false;
				break;	
		}

	}while(repite);
	return opcionSeleccionada;
}

int main(){
	OcultarCursor();
	system("color 5E");
	bool repite = true;
	int opcion;
	const char *titulo = "Menu Principal";
	const char *subtitulo = "Seleccione la opcion que desee";
	const char *opciones[]= {"Suma, Resta, Multiplicacion y Division de dos numeros", "Determinar si un numero es par o impar", "Convertir de kilometros a millas, metros a pulgadas, de libras a kilos y viceversa","Determinar si una palabra o un numero es palindromo", "Conversion de numeros arabigos a romanos (minimo 1,000)", "Conversion de numeros enteros a letras", "Conversion de numeros enteros con decimal a letras", "tabla de multiplicar", "tablas de multiplicar del 1 al 10", "Multiplicacion grafica", "Conversion de numeros decimales a binario", "Conversion de numeros decimales a hexadecimales", "Crear Figuras Geometricas Basicas", "Mover un punto en toda la pantalla(teclas w,a,s,d)", "Simulacion de un Cajero (Automata)", "Calcular la hipotenusa ", "Posicion del cursor", "Trivia del dia", "Identificar numeros negativos y positivos", "Mini reproductor de musica","Salir"};
	int n = 21;
	
	do{
		opcion = menu(titulo,subtitulo,opciones,n);
		
		switch(opcion){
			case 1:
				menu_operaciones();
				break;
			case 2:
				par_impar();
				break;
			case 3:
				menu_conversiones();
				break;
			case 4:
				palindromo();
				break;
			case 5:
				num_romanos();
				break;
			case 6:
				num_letras();
				break;
			case 7:
				decimales();
				break;
			case 8:
				multiplicar();
				break;
			case 9:
				multiplicar2();
				break;
			case 10:
				mult_grafica();
				break;
			case 11:
				binarios();
				break;
			case 12:
				hexadecimales();
				break;
			case 13:
				geometricas();
				break;
			case 14:
				punto();
				break;
			case 15:
				cajero();
				break;
			case 16:
				hipotenusa();
				break;
			case 17:
				click();
				break;
			case 18:
				trivia();
				break;
			case 19:
				nums();
				break;
			case 20:
				reproductor();
				break;
			case 21: 
				repite = false;
				break;
		}
		
	}while(repite);
	
	system("pause");
	getch();
	return 0;
}

/*void menu_principal(){
	int opc;
	
	cout<<"Bienvenido, selecciona alguna de las siguientes opciones: "<<endl;
	cout<<"1) Suma, Resta, Multiplicacion y Division de dos numeros"<<endl;
	cout<<"2) Determinar si un número es par o impar"<<endl;
	cout<<"3) Convertir de kilómetros a millas, metros a pulgadas, de libras a kilos y viceversa"<<endl;
	cout<<"4) Determinar si una palabra o un número es palindromo."<<endl;
	cout<<"5) Conversión de números arábigos a romanos (mínimo 1,000)"<<endl;
	cout<<"6) Conversión de números enteros a letras"<<endl;
	cout<<"7) Conversión de números enteros con decimal a letras"<<endl;
	cout<<"8) Una tabla de multiplicar "<<endl;
	cout<<"9) Todas las tablas de multiplicar del 1 al 10 "<<endl;
	cout<<"10) Crear de forma gráfica la multiplicación manual "<<endl;
	cout<<"11) Conversión de números decimales a binario "<<endl;
	cout<<"12) Conversión de números decimales a hexadecimales "<<endl;
	cout<<"13) Crear Figuras Geométricas Básicas. "<<endl;
	cout<<"14) Mover un punto en toda la pantalla "<<endl;
	cout<<"15) Simulación de un Cajero (Autómata) "<<endl;
	cout<<"16) Calcular la hipotenusa "<<endl;
	cout<<"17) Cursor en la pantalla "<<endl;
	cout<<"18) trivia "<<endl;
	cout<<"19) identificar numeros negativos y positivos "<<endl;
	cout<<"20) Mini reproductor de musica "<<endl;
	cout<<"0) salir "<<endl;
	
	cin>>opc;
	
	switch(opc){
		case 1:
			menu_operaciones();
			break;
		case 2:
			par_impar();
			break;
		case 3:
			menu_conversiones();
			break;
		case 4:
			palindromo();
			break;
		case 5:
			num_romanos();
			break;
		case 6:
			num_letras();
			break;
		case 7:
			cout<<"decimales a letras"<<endl;
			break;
		case 8:
			multiplicar();
			break;
		case 9:
			multiplicar2();
			break;
		case 10:
			cout<<"multiplicacion manual"<<endl;
			break;
		case 11:
			binarios();
			break;
		case 12:
			hexadecimales();
			break;
		case 13:
			cout<<"figuras geometricas"<<endl;
			break;
		case 14:
			cout<<"puntito en la pantalla"<<endl;
			break;
		case 15:
			cajero();
			break;
		case 16:
			hipotenusa();
			break;
		case 17:
			click();
			break;
		case 18:
			trivia();
			break;
		case 19:
			nums();
			break;
		case 20:
			cout<<"reproductor"<<endl;
			break;
		case 21:
			break;
	}
}*/


void menu_operaciones(){
	system("cls");
	int n1, n2, opcion;
	
	cout<<"Seleccione la operacion que quiere realizar"<<endl;
	cout<<"1) Suma"<<endl;
	cout<<"2) Resta"<<endl;
	cout<<"3) Multiplicacion"<<endl;
	cout<<"4) Division"<<endl;
	cout<<"0) regresar"<<endl;
	cout<<"\n";
	
	cin>>opcion;
	
	switch(opcion){
		case 1: suma();
		break;
		case 2: resta();
		break;
		case 3: multiplicacion();
		break;
		case 4: division();
		break;
		case 0: break;
	}
	
}
void suma(){
	int n1, n2, r;
	system("cls");
	
	cout<<"ingrese el primer numero: "<<endl;
	cin>>n1;
	
	cout<<"ingrese el segundo numero: "<<endl;
	cin>>n2;
	
	r=n1+n2;
	
	cout<<"el resultado es: "<<r<<endl;
	system("pause");
}

void resta(){
	int n1, n2, r;
	system("cls");
	
	cout<<"ingrese el primer numero: "<<endl;
	cin>>n1;
	
	cout<<"ingrese el segundo numero: "<<endl;
	cin>>n2;
	
	r=n1-n2;
	
	cout<<"el resultado es: "<<r<<endl;
	system("pause");
}

void multiplicacion(){
	int n1, n2, r;
	system("cls");
	
	cout<<"ingrese el primer numero: "<<endl;
	cin>>n1;
	
	cout<<"ingrese el segundo numero: "<<endl;
	cin>>n2;
	
	r=n1*n2;
	
	cout<<"el resultado es: "<<r<<endl;
	system("pause");
}

void division(){
	int n1, n2, r;
	system("cls");
	
	cout<<"ingrese el primer numero: "<<endl;
	cin>>n1;
	
	cout<<"ingrese el segundo numero: "<<endl;
	cin>>n2;
	
	r=n1/n2;
	
	cout<<"el resultado es: "<<r<<endl;
	system("pause");
}

void par_impar(){
	system("cls");
	int n;
	
	cout<<"ingrese un numero: "<<endl;
	cin>>n;
	
	if(n%2==0){
		cout<<"El numero "<<n<<" es par"<<endl;
	}
	else{
		cout<<"El numero "<<n<<" es impar"<<endl;
	}
	system("pause");
}

void menu_conversiones(){
	system("cls");
	int n1, n2, opcion;
	
	cout<<"Seleccione la operacion que quiere realizar"<<endl;
	cout<<"1) Convertir kilometros a millas y viceversa"<<endl;
	cout<<"2) Convertir metros a pulgadas y viceversa"<<endl;
	cout<<"3) Convertir libras a kilos y viceversa"<<endl;
	cout<<"0) regresar"<<endl;
	cout<<"\n";
	
	cin>>opcion;
	
	switch(opcion){
		case 1: kmam();
		break;
		case 2: maplg();
		break;
		case 3: lbakil();
		break;
		case 0: break;
	}
}

void kmam(){
	int n1, r, opcion;
	system("cls");
	
	cout<<"Que conversion desea hacer?"<<endl;
	cout<<"1) kilometros a millas"<<endl;
	cout<<"2) millas a kilometros"<<endl;
		
	cin>>opcion;
	switch(opcion) {
		case 1: 
			system("cls");
			cout<<"ingrese los kilometros"<<endl;
			cin>>n1;
				
			r=n1* 0.62137;
				
			cout<<"El resultado es de "<<r<<" millas";
		break;
		case 2: 
			system("cls");
			cout<<"ingrese las millas"<<endl;
			cin>>n1;
					
			r=n1/0.62137;
					
			cout<<"El resultado es de "<<r<<" kilometros";
		break;
	}
}

void maplg(){
	int n1, r, opcion;
	system("cls");
	
	cout<<"Que conversion desea hacer?"<<endl;
	cout<<"1) metros a pulgadas"<<endl;
	cout<<"2) pulgadas a metros"<<endl;
		
	cin>>opcion;
	switch(opcion) {
		case 1: 
			system("cls");
			cout<<"ingrese los metros"<<endl;
			cin>>n1;
				
			r=n1* 39.370;
				
			cout<<"El resultado es de "<<r<<" pulgadas";
		break;
		case 2: 
			system("cls");
			cout<<"ingrese las pulgadas"<<endl;
			cin>>n1;
					
			r=n1/39.370;
					
			cout<<"El resultado es de "<<r<<" metros";
		break;
	}
}

void lbakil(){
	int n1, r, opcion;
	system("cls");
	
	cout<<"Que conversion desea hacer?"<<endl;
	cout<<"1) libras a kilos"<<endl;
	cout<<"2) kilos a libras"<<endl;
		
	cin>>opcion;
	switch(opcion) {
		case 1: 
			system("cls");
			cout<<"ingrese las libras"<<endl;
			cin>>n1;
				
			r=n1/2.2046;
				
			cout<<"El resultado es de "<<r<<" kilos";
		break;
		case 2: 
			system("cls");
			cout<<"ingrese los kilos"<<endl;
			cin>>n1;
					
			r=n1*2.2046;
					
			cout<<"El resultado es de "<<r<<" libras";
		break;
	}
}

void palindromo(){
	system("cls");
	char cadena[100], copia[100];
	
	cout<<"ingrese una palabra o un numero: "<<endl;
	cin>>cadena;
	
	for(int i=(strlen(cadena)-1);i>=0;i--){
		copia[strlen(cadena)-1-i]=cadena[i];
	}
	copia[strlen(cadena)]='\0';

	if(strcmp(cadena,copia)==0){
		cout<<"es palindromo"<<endl;
	}else{
		cout<<"no es palindromo"<<endl;
	}
	system("pause");
}

void num_romanos(){
	system("cls");
	int n, u, d, c, m;
	
	cout<<"Ingrese el numero que desee cambiar: "<<endl;
	cin>>n;
	
	u = n%10; n /=10;//para unidades
	d = n%10; n /=10;//para decenas
	c = n%10; n /=10;//para centenas
	m = n%10; n /=10;//para millar
	
	switch(m){
		case 1: cout<<"M";
			break;
		case 2: cout<<"MM";
			break;
		case 3: cout<<"MMM";
			break;
	}
	
	switch(c){
		case 1: cout<<"C";
			break;
		case 2: cout<<"CC";
			break;
		case 3: cout<<"CCC";
			break;
		case 4: cout<<"CD";
			break;
		case 5: cout<<"D";
			break;
		case 6: cout<<"DC";
			break;
		case 7: cout<<"DCC";
			break;
		case 8: cout<<"DCCC";
			break;
		case 9: cout<<"CM";
			break;
	}
	
	switch(d){
		case 1: cout<<"X";
			break;
		case 2: cout<<"XX";
			break;
		case 3: cout<<"XXX";
			break;
		case 4: cout<<"XL";
			break;
		case 5: cout<<"L";
			break;
		case 6: cout<<"LX";
			break;
		case 7: cout<<"LXX";
			break;
		case 8: cout<<"LXXX";
			break;
		case 9: cout<<"XC";
			break;
	}
	
	switch(u){
		case 1: cout<<"I";
			break;
		case 2: cout<<"II";
			break;
		case 3: cout<<"III";
			break;
		case 4: cout<<"IV";
			break;
		case 5: cout<<"V";
			break;
		case 6: cout<<"VI";
			break;
		case 7: cout<<"VII";
			break;
		case 8: cout<<"VIII";
			break;
		case 9: cout<<"IX";
			break;
	}
	system("pause");
}

void num_letras(){
	system("cls");
	int x;
    cout<<"ingrese un numero"<<endl;
    cin>>x;
    if((x<1)||(x>2999)){
        cout<<"Ingresa un nÃºmero del 1 al 2999"<<endl;
    }else{
    if(x>=2900)   {cout<<"Dos mil novecientos " ;x=x-2900;}
       else if(x>=2800)   {cout<<"Dos mil ochocientos " ;x=x-2800;}
       else if(x>=2700)   {cout<<"Dos mil  setecientos " ;x=x-2700;}
       else if(x>=2600)   {cout<<"Dos mil seiscientos " ;x=x-2600;}
       else if(x>=2500)   {cout<<"Dos mil  quinientos "  ;x=x-2500;}
       else if(x>=2400)   {cout<<"Dos mil cuatrocientos "   ;x=x-2400;}
       else if(x>=2300)   {cout<<"Dos mil  trescientos " ;x=x-2300;}
       else if(x>=2200)   {cout<<"Dos mil doscientos "  ;x=x-2200;}
       else if(x>2100)    {cout<<"Dos mil  cien "  ;x=x-2100;}
       else if(x==2000)  {cout<<"Dos mil ";x=x-2000;}
        if(x>=1900)   {cout<<"Mil novecientos " ;x=x-1900;}
           else if(x>=1800)   {cout<<"Mil ochocientos " ;x=x-1800;}
           else if(x>=1700)   {cout<<"Mil setecientos " ;x=x-1700;}
           else if(x>=1600)   {cout<<"Mil seiscientos " ;x=x-1600;}
           else if(x>=1500)   {cout<<"Mil quinientos "  ;x=x-1500;}
           else if(x>=1400)   {cout<<"Mil cuatrocientos "   ;x=x-1400;}
           else if(x>=1300)   {cout<<"Mil trescientos " ;x=x-1300;}
           else if(x>=1200)   {cout<<"Mil doscientos "  ;x=x-1200;}
           else if(x>1100)    {cout<<"Mil cien "  ;x=x-1100;}
           else if(x==1000)  {cout<<"Mil";x=x-1000;}
                if(x>=900)   {cout<<"Novecientos " ;x=x-900;}
               else if(x>=800)   {cout<<"Ochocientos " ;x=x-800;}
               else if(x>=700)   {cout<<"Setecientos " ;x=x-700;}
               else if(x>=600)   {cout<<"Seiscientos " ;x=x-600;}
               else if(x>=500)   {cout<<"Quinientos "  ;x=x-500;}
               else if(x>=400)   {cout<<"Cuatrocientos "   ;x=x-400;}
               else if(x>=300)   {cout<<"Trescientos " ;x=x-300;}
               else if(x>=200)   {cout<<"Doscientos "  ;x=x-200;}
               else if(x>100)    {cout<<"Ciento "  ;x=x-100;}
               else if(x==100)  {cout<<"Cien"     ;x=x-100;}
                if(x>90) {cout<<"Noventa y "   ;x=x-90; }
                    if(x==90)   {cout<<"Noventa"  ;x=x-90; }  
                    if(x>80) {cout<<"Ochenta y "   ;x=x-80; }
                    if(x==80)   {cout<<"Ochenta"  ;x=x-80; }
                    if(x>70) {cout<<"Setenta y "   ;x=x-70; }
                    if(x==70)   {cout<<"Setenta"  ;x=x-70; }
                    if(x>60) {cout<<"Sesenta y "   ;x=x-60; }
                    if(x==60)   {cout<<"Sesenta"  ;x=x-60; }
                    if(x>50) {cout<<"Cincuenta y " ;x=x-50; }
                    if(x==50)   {cout<<"Cincuenta"    ;x=x-50; }
                    if(x>40) {cout<<"Cuarenta y  "  ;x=x-40; }
                    if(x==40)   {cout<<"Cuarenta" ;x=x-40; }
                    if(x>30) {cout<<"Treinta y "   ;x=x-30; }
                    if(x==30)   {cout<<"Treinta"  ;x=x-30; }
                    if(x>20) {cout<<"Veinti"       ;x=x-20; }
                    if(x==20)   {cout<<"Veinte"       ;x=x-20; }
                        if(x>=16)    {cout<<"Dieci"        ;x=x-10; }
                       else if(x==15)   {cout<<"Quince"       ;x=x-15; }
                       else if(x==14)   {cout<<"Catorce"  ;x=x-14; }
                       else if(x==13)   {cout<<"Trece"        ;x=x-13; } 
                       else if(x==12)   {cout<<"Doce"     ;x=x-12; }
                       else if(x==11)   {cout<<"Once"     ;x=x-11; }
                       else if(x==10)   {cout<<"Diez"     ;x=x-10; }      
                        if(x==9)    {cout<<"Nueve"        ;x=x-9;  }
                        if(x==8)    {cout<<"Ocho"     ;x=x-8;  }
                        if(x==7)    {cout<<"Siete"        ;x=x-7;  }
                            if(x==6)    {cout<<"Seis"     ;x=x-6;  }
                       else if(x==5)    {cout<<"Cinco"        ;x=x-5;  }
                       else if(x==4)    {cout<<"Cuatro"       ;x=x-4;  }
                       else if(x==3)    {cout<<"Tres"     ;x=x-3;  }
                       else if(x==2)    {cout<<"Dos"      ;x=x-2;  }
                       else if(x==1)    {cout<<"uno"      ;x=x-1;  }
               }
    system("pause");
}

void decimales(){
	int n;
    cout<<"ingrese un numero decimal(entre 0.1-0.9): "<<endl;
    cin>>n;
    
    if(n<=-1){
        cout<<"No pueden ingresarse numeros negativos"<<endl;
    }else{
    if(n==0.9){cout<<"punto nueve"; n=n-0.9;}
        else if(n==0.8){cout<<"punto ocho"; n=n-0.8;}
        else if(n==0.7){cout<<"punto siete"; n=n-0.7;}
        else if(n==0.6){cout<<"punto seis"; n=n-0.6;}
        else if(n==0.5){cout<<"punto cinco"; n=n-0.5;}
        else if(n==0.4){cout<<"punto cuatro"; n=n-0.4;}
        else if(n==0.3){cout<<"punto tres"; n=n-0.3;}
        else if(n==0.2){cout<<"punto dos"; n=n-0.2;}
        else if(n==0.1){cout<<"punto uno"; n=n-0.1;}
        }
	system("pause");
}

void multiplicar(){
	system("cls");
    int r, i=2;
    
    for(int n=0; n<=10;n++){
        r=i*n;
        cout<<i<<"*"<<n<<"="<<r<<endl;
    }
    system("pause");
}

void multiplicar2(){
	system("cls");
	int n,r;

    cout<<"ingrese un numero: "<<endl;
    do{
        cin>>n;
        cout<<"el numero debe ser mayor a 1 y menor a 10"<<endl;
        cout<<"intentelo de nuevo"<<endl;
    }while((n<1)||(n>10));
    
    for(int i=1;i<=10;i++){
        r=i*n;
        cout<<i<<"*"<<n<<"="<<r<<endl;
    }
    system("pause");
}

void mult_grafica(){
	system("cls");
	int opc;
	do{
	int numero1,numero2,num,unidad,decena,centena,milecima,m1,m2,m3,m4,multiplicacion;
        cout<<"Ingrese el primer numero: "<<endl;
        cin>>numero1;
        cout<<"Ingrese el segundo numero: "<<endl;
        cin>>numero2;
        num=numero2;
        cout<<endl<<endl;
        unidad= numero2%10; numero2/=10;
        decena= numero2%10; numero2/=10;
        centena= numero2%10; numero2/=10;
        milecima= numero2%10; numero2/=10;
        m1=unidad*numero1;
        m2=decena*numero1;
        m3=centena*numero1;
        m4=milecima*numero1;
        multiplicacion=numero1*num;

        if(numero1 >= 10000 || numero2 >= 10000)
        {
            cout<<"El numero ingresado sobrepasa el limite"<<endl;
            system("pause");
        }
        else{
            cout<<"\t\t\t\t"<<numero1<<endl;
            cout<<"\t\tX\t\t"<<num<<endl;
            cout<<"\t\t______________________"<<endl;
            cout<<"\t\t\t\t     "<<m1<<endl;
                cout<<"\t\t\t\t    "<<m2<<endl;
            cout<<"\t\t\t           "<<m3<<endl;
            cout<<"\t\t\t        "<<m4<<endl;
            cout<<" \t\t______________________"<<endl;
            cout<<"\t\t\t\t    "<<multiplicacion<<endl;
        }
    printf("\n\n\t\tDesea realizar otra multiplicacion? || 1 = Si || 2 = No || ");
	scanf("%i",&opc);	fflush(stdin);
	system("cls");
	}while(opc!=2);  fflush(stdin);
}
void binarios(){
	system("cls");
	int n;
    
        do{
            cout<<"ingrese el numero a convertir: "<<endl;
            cin>>n;
            
            if(n<0)
                cout<<"numero invalido"<<endl;
        }while(n<0);
        
        cout<<"numero: "<<n<<endl;
        cout<<"forma binaria: ";
        binario(n);
        cout<<endl;
    system("pause");
}

void hexadecimales(){
	system("cls");
	int digitoh[20];
    int decimal, residuo, resultado, i = 0;
    
    cout<<"Introduzca el numero decimal a convertir: "<<endl;
    cin>>decimal;
    
    do{
        residuo = decimal % 16;
        resultado = decimal / 16;
        digitoh[i] = residuo;
        decimal = resultado;
        i++;
    }while(resultado > 15);
    
    digitoh[i] = resultado;
    
    cout<<"El equivalente en hexadecimal es: ";
    
    for(int x=1;x>=0;x--){
        if(digitoh[x] == 10){
            cout<<"A";
        }else if(digitoh[x] == 11){
            cout<<"B";
        }else if(digitoh[x] == 12){
            cout<<"C";
        }else if(digitoh[x] == 13){
            cout<<"D";
        }else if(digitoh[x] == 14){
            cout<<"E";
        }else if(digitoh[x] == 15){
            cout<<"F";
        }else{
            cout<<digitoh[x];
        }
    }
    system("pause");
}

void geometricas(){
	system("cls");
	int opc;
	int x;
	do{
	cout<<"Ingrese el ancho del triangulo"<<endl;
	 cin>>x;
	for( int i=1 ; i<=x ; i++ ){ 
	for( int j=1 ; j<=i ; j++ ){
		cout<<"*";
		}
        cout<<"\n";
    }
    for( int i=(x-1) ; i > 0 ; i-- ){
    for( int j=1 ; j<=i ; j++ ){	
    cout<<"*";	
     }
        cout<<"\n";
    }	
    printf("\n\n\t\tDesea realizar de nuevo el proceso? || 1 = SI || 2 = NO || ");
	scanf("%i",&opc);	fflush(stdin);
	system("CLS");
	}while(opc!=2);  fflush(stdin);
}

void punto(){
		while(opcion!='k'){
		system("cls");//limpiar la pantalla con cada movimiento
		gotoxy(x,y);
		cout<<"****";
		opcion=getch();
		
		switch(opcion){
			case 'w': y--; 
			break;
			case 's': y++;
			break;
			case 'a': x--;
			break;
			case 'd': x++;
			break;
		}
	}
}

void cajero(){
	system("cls");
	string pin;
    int s_inicial = 5000, ahorro =  1000, opc;
    float extra, retiro, saldo = 0;
    
    do{
        cout<<"Ingrese su pin: "<<endl;//pin = 1234
        cin>>pin;
        cout<<"El pin es incorrecto, intÃ©ntelo de nuevo"<<endl;
        cout<<"(pista: 10011010010 en decimal)"<<endl;
    }while(pin!="1234");
    
    cout<<"\tBienvenido a su Cajero AutomÃ¡tico"<<endl;
    cout<<"1) Ingresar dinero en su cuenta"<<endl;
    cout<<"2) Retirar dinero de la cuenta"<<endl;
    cout<<"3) Consultar saldo"<<endl;
    cout<<"4) Consultar cuenta de ahorro"<<endl;
    cout<<"0) regresar"<<endl;
    
    cin>>opc;
    
    switch(opc){
        case 1:
            cout<<"Digite la cantidad de dinero a ingresar: "<<endl;
            cin>>extra;
            saldo = s_inicial + extra;
            cout<<"Dinero en cuenta: "<<saldo<<endl;
            break;
        case 2:
            cout<<"Digite la cantidad de dinero que va a retirar: "<<endl;
            cin>>retiro;
            
            if(retiro > s_inicial){
                cout<<"lo sentimos, usted no posee esa cantidad de dinero"<<endl;
            }else{
                saldo = s_inicial - retiro;
                cout<<"Su dinero en cuenta es: "<<saldo<<endl;
            }
            break;
        case 3: cout<<"su saldo es de: Q"<<s_inicial<<endl;
            break;
        case 4: cout<<"usted tiene Q"<<ahorro<<" en su cuenta de ahorro"<<endl;
            break;
        case 0:
            break;
    }
}

void hipotenusa(){
	system("cls");
	float c,a,b,a2,b2, raiz;
    
    cout<<"ingrese el primer numero: "<<endl;   
    cin>>a;
    cout<<"ingrese el segundo numero: "<<endl;
    cin>>b;
    
    a2=a*a;
    b2=b*b;
    
    c=a2+b2;
    
    raiz =  sqrt(c);
    
    cout<<"el resultado es de "<<raiz<<endl;
    
    system("pause");
}

void click(){
	system("cls");
		//variables para las posiciones
	int x,y;
	
	//bucle para que se actualizen las coordenadas sin cerrarse el programa
	while(1){
		Sleep(1000);
		//variable de tipo cursor
		POINT cursor;
		
		//obtenemos la posición y la guardamos en la variable de arriba
		GetCursorPos(&cursor);
		//actualizamos los valores
		x = cursor.x;
		y = cursor.y;
		//imprimimos la posicion x & y
		printf("\r X = %i, Y = %i", x, y);
	}
}

void trivia(){
	system("cls");
	char respuesta1;
	char respuesta2;
	char respuesta3;
	
	cout<<"Bienvenido al Juego de Preguntas de hoy!"<<endl;
	cout<<"Mi nombre es Keren y espero te diviertas con esta serie de preguntas :)"<<endl;
	cout<<"Responde a las preguntas dadas, Mucha suerte!"<<endl;
	cout<<"Recuerda: son preguntas de opcion multiple, como respuesta solo escribe en mayuscula la letra que contenga la respuesta correcta"<<endl;
	cout<<"1. Aproximadamente, cuantos huesos tiene el cuerpo humano?"<<endl;
	cout<<"A)40"<<endl;
	cout<<"B)390"<<endl;
	cout<<"C)206"<<endl;
	
	do {
		cin>>respuesta1;
		switch(respuesta1) {
			case 'A': cout<<"Upps! Incorrecto, Pensaste bien tu respuesta?"<<endl;
			break;
			case 'B': cout<<"Cerca...pero no, es incorrecto"<<endl; 
			break;
			case 'C': cout<<"Perfecto! Respuesta correcta"<<endl;
			break;
			default: cout<<"Yuju, esta no esta entre las opciones!"<<endl;
		}
	}while (respuesta1!='C');
	
	cout<<"2. Cual es la capital de Hungria?"<<endl;
	cout<<"A)Viena"<<endl;
	cout<<"B)Budapest"<<endl;
	cout<<"C)Praga"<<endl;
	
	do {
		cin>>respuesta2;
		switch(respuesta2) {
			case 'A': cout<<"Upps! Incorrecto, Pensaste bien tu respuesta?"<<endl;
			break;
			case 'B': cout<<"Perfecto! Respuesta correcta"<<endl; 
			break;
			case 'C': cout<<"Cerca...pero no, es incorrecto"<<endl;
			break;
			default: cout<<"Yuju, esta no esta entre las opciones!"<<endl;
		}
	}while (respuesta2!='B');
		
	cout<<"3. Orgullo y Prejuicio fue un libro escrito por..."<<endl;
	cout<<"A)Jane Austen"<<endl;
	cout<<"B)Oscar Wilde"<<endl;
	cout<<"C)Miguel Cervantes de Saavedra"<<endl;
	
	do {
		cin>>respuesta3;
		switch(respuesta3) {
			case 'A': cout<<"Perfecto! Respuesta correcta"<<endl;
			break;
			case 'B': cout<<"Upps! Incorrecto, Pensaste bien tu respuesta?"<<endl; 
			break;
			case 'C': cout<<"Cerca...pero no, es incorrecto"<<endl;
			break;
			default: cout<<"Yuju, esta no esta entre las opciones!"<<endl;
		}
	}while (respuesta2!='A');
}

void nums(){
	system("cls");
	int numero;
	
	cout<<"ingrese un numero: "; 
	cin>>numero;

	if (numero == 0)
	{
		cout << "\nEl numero es 0" << endl;
	}
	else if (numero > 0)
	{
		cout << "El numero ingresado es positivo" << endl;
	}
	else
	{
		cout << "El numero ingresado es negativo" << endl;
	}
	system("pause");
}

void reproductor(){
	system("cls");
	system("color 05");
	int opc;
	
	cout<<"Escoje el tipo de musica que desees escuchar: "<<endl;
	cout<<"PD. Cuando quieras darle play a la cancion, da click sobre la pantalla"<<endl;
	cout<<"Cuando quieras dejar de escucharla, solo presiona cualquier tecla. Disfruta ;)"<<endl;
	cout<<"1) Pop"<<endl;
	cout<<"2) K-pop"<<endl;
	cout<<"3) Folk"<<endl;
	cout<<"4) Reggaeton"<<endl;
	cout<<"5) Electronica"<<endl;
	cout<<"6) Latino"<<endl;
	cout<<"7) Clasica"<<endl;
	
	cin>>opc;
	
	switch(opc){
		case 1: 
			do{
				system("cls");
				cout<<"Too Good"<<endl;
				cout<<"Drake ft. Rihanna"<<endl;
				PlaySound(TEXT("too good.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
			case 2: 
			do{
				system("cls");
				cout<<"Crazy Over You"<<endl;
				cout<<"BLACKPINK"<<endl;
				PlaySound(TEXT("Crazy Over You.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
			case 3: 
			do{
				system("cls");
				cout<<"Quiero"<<endl;
				cout<<"Ed Maverick"<<endl;
				PlaySound(TEXT("Quiero.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
			case 4: 
			do{
				system("cls");
				cout<<"Mañana es Too Late"<<endl;
				cout<<"Jesse & Joy ft. J Balvin"<<endl;
				PlaySound(TEXT("Mañana es too late.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
			case 5: 
			do{
				system("cls");
				cout<<"Something Comforting"<<endl;
				cout<<"Porter Robinson"<<endl;
				PlaySound(TEXT("something comforting.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
			case 6: 
			do{
				system("cls");
				cout<<"Alguien Mas"<<endl;
				cout<<"Jesse & Joy"<<endl;
				PlaySound(TEXT("alguien mas.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
			case 7: 
			do{
				system("cls");
				cout<<"Zapateado"<<endl;
				cout<<"Pablo Sarasate"<<endl;
				PlaySound(TEXT("Zapateado.wav"), NULL, SND_ASYNC);
			}while(!kbhit());
			
			PlaySound(NULL,0,0);
			break;
	}
}
