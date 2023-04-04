#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

struct libros //estructura para los libros, que servira para ingresar y imprimir
{
	int codigo;
	char nomlib[60];
   char autor[60];
   int adeEdi;
	char edit[60];
}libros;

struct personas //estructura que se utilizara para registrar los prestamos asi como imprimir cuales fueron
{
	char nomPres[60];
   char apePres[60];
   int ident;
   int tiemPres;
   char libad[60];
}prestamo;

void reglibros();//funcion para registrar los libros
void ModEliBus();// funcion para ver los libros registrados en la biblioteca
void ReaPres();//funcion para registrar los prestamos
void MosPres();//funcion para imprimir los prestamos
void libreg();// funcio para modificar los datos, eliminar y buscar

int main()////////programa principal
{
	int opcion;
	do{
		for(int x=10; x<60; x++)
		{
		gotoxy(x,3); cout<<"*";gotoxy(x,28); cout<<"*";
      }
			for(int y=3; y<28; y++)
			{
			gotoxy(10,y); cout<<"*";gotoxy(59,y); cout<<"*";
      	}
			gotoxy(30,4); cout<<"BIENVENIDO"<<endl;
			gotoxy(24,5); cout<<"CONTROL DE BIBLIOTECA"<<endl;
			gotoxy(15,7); cout<<"Digite su opcion"<<endl;
			gotoxy(15,9); cout<<"1. Registro de libros"<<endl;
			gotoxy(15,12); cout<<"2. Libros registrados"<<endl;
			gotoxy(15,15); cout<<"3. Realizar prestamos"<<endl;
			gotoxy(15,18); cout<<"4. Prestamos realizados"<<endl;
			gotoxy(15,21); cout<<"5. Buscar"<<endl;
         gotoxy(15,24); cout<<"6. Salir"<<endl;
			gotoxy(25,26); cout<<"Ingrese la opcion que desea: ";
         cin>>opcion;
         system("cls");
         switch(opcion)
				{
					case 1:
               	reglibros();
               	system("cls");
              	   break;
               case 2:
               	libreg();
                  system("cls");
                  break;
               case 3:
               ReaPres();
               system("cls");
               break;
               case 4:
               	MosPres();
               	system("cls");
               	break;
               case 5:
               	ModEliBus();
                  system("cls");
                  break;
               default:
						if(opcion>=7)
                  {
                  	system("cls");
							gotoxy(12,28);cout<<"\nOpcion Invalida, porfavor ingrese una opcion valida"<<endl;
						}
						break;
            }
	}while(opcion!=6);
}

void reglibros()//funcion para registrar los libros
{
	char s;
	FILE *fp;
   do{
		fp=fopen("ControlBiblioteca.txt","a+b");
		clrscr();
      	gotoxy(30,4); cout<<"Registro de libros"<<endl;
         cout<<"\nIngrese codigo del libro: ";
         cin>>libros.codigo;
			cout<<"Nombre del libro: ";
			gets(libros.nomlib);
			cout<<"Autor del libro: ";
			gets(libros.autor);
      	cout<<"A�o de edicion: ";
      	cin>>libros.adeEdi;
      	cout<<"Editorial: ";
      	gets(libros.edit);
		fwrite(&libros,sizeof(libros),1,fp);
		fclose(fp);
      cout<<"Si desea ingresar un libro prescione 1, 0 para salir: ";
      cin>>s;
   }while(s != '0');
}

void libreg()// funcion para ver los libros registrados en la biblioteca
{
	FILE *fp;
	fp=fopen("ControlBiblioteca.txt","r+b");
	clrscr();
   gotoxy(30,4); cout<<"Libros registrados"<<endl;
   cout<<"\n";
   gotoxy(5,6);
 	while (!feof(fp))
  	{
  		fread(&libros,sizeof(libros),1,fp);
      cout<<"\nCodigo de libro: ";
      cout<<libros.codigo;
   	cout<<"\nNombre del libro: ";
  		cout<<libros.nomlib;
  		cout<<"\nAutor del libro: ";
  		cout<<libros.autor;
  		cout<<"\nA�o de edicion: ";
      cout<<libros.adeEdi;
      cout<<"\nEditorial: ";
      cout<<libros.edit;
      cout<<"\n";
      cout<<"\n";
   }
   fclose(fp);
   cout<<"Prescione <Cualquier tecla> para regresar al menu principal";
	getch();
}

void ReaPres() ////funcion para realizar prestamo
{
	char a;
   int libroadquirir,bandera=0;
	FILE *fp;
	fp=fopen("ControlBiblioteca.txt","r+b");
	clrscr();
   gotoxy(30,4); cout<<"Realizar prestamo"<<endl;
   do
   {
   gotoxy(4,6);
   cout<<"Ingrese el codigo del libro que se va adquirir: ";
   cin>>libroadquirir;
	while (!feof(fp))
	{
	fread(&libros,sizeof(libros),1,fp);
	if (libroadquirir==libros.codigo)
	{
   	cout<<"\n";
		cout<<"Libro encontrado";
  		cout<<"\n";
  		bandera=1;
  }
  }
	if(bandera==0)
	cout<<"\nLibro no encontrado\n";
	fclose(fp);
   FILE *att;
   att=fopen("ControlPrestamos.txt","a+b");
         if(bandera==1)
		{
      	cout<<"Nombre de la persona: ";
			gets(prestamo.nomPres);
			cout<<"Apellido de la persona: ";
			gets(prestamo.apePres);
      	cout<<"Identificacion: ";
      	cin>>prestamo.ident;
      	cout<<"Tiempo del prestamos: ";
      	cin>>prestamo.tiemPres;
         cout<<"Libro adquirido: ";
         gets(prestamo.libad);
			fwrite(&prestamo,sizeof(prestamo),1,fp);
         cout<<"\n";
  		}
      fclose(att);
  		cout<<"\nPara registrar otro prestamo prescione 1 de lo contrario 0 para salir:  ";
   	cin>>a;
   }while(a != '0');
}

void MosPres()/////FUncion que muestra o imprime los prestamos realizados
{
   FILE *fp;
	fp=fopen("ControlPrestamos.txt","r+b");
	clrscr();
   gotoxy(30,4); cout<<"Prestamos registrados"<<endl;
   cout<<"\n";
   gotoxy(4,6);
 	while (!feof(fp))
  	{
  		fread(&prestamo,sizeof(prestamo),1,fp);
   	cout<<"\nNombre de la persona: ";
      cout<<prestamo.nomPres;
      cout<<"\nApellido de la persona: ";
      cout<<prestamo.apePres;
      cout<<"\nIdentificacion: ";
      cout<<prestamo.ident;
      cout<<"\nTiempo del prestamos: ";
      cout<<prestamo.tiemPres;
      cout<<"\nLibro adquirido: ";
      cout<<prestamo.libad;
      cout<<"\n";
      cout<<"\n";
   }
   fclose(fp);
   cout<<"Prescione <Cualquier tecla> para regresar al menu principal";
	getch();
}

void ModEliBus()// funcio para buscar libro o si una persona ha realizado un prestamo
{
	void Blibro();
   void Bprestamo();
   int opcion1;
   do
   {
   	gotoxy(11,1);cout<<"Busqueda de datos"<<endl;
      cout<<"\n 1. Buscar libro"<<endl;
      cout<<" 2. Buscar prestamo"<<endl;
      cout<<" 3. Salir"<<endl;
      gotoxy(6,8); cout<<"Ingrese la opcion que desea: ";
		cin>>opcion1;
		system("cls");
		switch(opcion1)
      {
       case 1:
       	Blibro();
       	system("cls");
       	break;
       case 2:
       	Bprestamo();
         system("cls");
         break;
       default:
				if(opcion1>=4)
				{
					cout<<"ERROR!"<<endl;
					cout<<"El numero ingresado no corresponde a ninguno de las opciones"<<endl;
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU PRINCIPAL"<<endl;
					getch();
					system("cls");
				}
				system("cls");
		}
	}while(opcion1!=3);

}

void Blibro() /////funcion para buscar libro
{
	int libbus;
   char aaa;
   int bandera=0;
	FILE *fp;
	fp=fopen("ControlBiblioteca.txt","r+b");
	clrscr();
   do
   {
   	gotoxy(11,1);cout<<"Busqueda de datos"<<endl;
		gotoxy(5,3);cout<< "Ingrese el codigo del libro a buscar: ";
		cin>>libbus;
		while (!feof(fp))
		{
			fread(&libros,sizeof(libros),1,fp);
			if (libbus==libros.codigo)
      	{
				cout<<"\n Nombre del libro: ";
  				cout<<libros.nomlib;
  				cout<<"\n Autor del libro: ";
  				cout<<libros.autor;
  				cout<<"\n A�o de edicion: ";
      		cout<<libros.adeEdi;
      		cout<<"\n Editorial: ";
      		cout<<libros.edit;
  				cout<<"\n";
  				bandera=1;
  			}
		}
		if(bandera==0)
		cout<<"Libro no encontrado";
		fclose(fp);
   	cout<<"\nPara realizar otra busqueda prescione 1 de lo contrario 0 para salir:  ";
   	cin>>aaa;
   }while(aaa != '0');
}

void Bprestamo()/////funcion para ver si una persona ha realizado un prestamo
{
	int busnumident;
   int bandera=0;
	FILE *fp;
	fp=fopen("ControlPrestamos.txt","r+b");
	clrscr();
   	gotoxy(11,1);cout<<"Busqueda de datos"<<endl;
		gotoxy(5,3);cout<< "Ingrese su numero de identificacion de la persona que realizo el prestamo: ";
		cin>>busnumident;
		while (!feof(fp))
		{
			fread(&prestamo,sizeof(prestamo),1,fp);
			if (busnumident==prestamo.ident)
      	{
				cout<<"\n Nombre de la persona: ";
      		cout<<prestamo.nomPres;
      		cout<<"\n Apellido de la persona: ";
      		cout<<prestamo.apePres;
      		cout<<"\n Tiempo del prestamos: ";
      		cout<<prestamo.tiemPres;
      		cout<<"\n Libro adquirido: ";
      		cout<<prestamo.libad;
      		cout<<"\n";
  				cout<<"\n";
  				bandera=1;
  			}
		}
		if(bandera==0)
		cout<<"\nPersona no encontrada";
		fclose(fp);
   	cout<<"\nPrescione <Cualquier tecla> para regresar al menu principal";
	getch();
}