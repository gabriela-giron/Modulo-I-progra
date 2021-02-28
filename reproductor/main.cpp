#include <iostream>
#include<windows.h>
#include<Mmsystem.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main(){
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
	
	return 0;
}

