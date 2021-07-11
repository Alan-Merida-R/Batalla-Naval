//main principal que llama a todas las funciones
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define verdad 1
#define falso 0
//Programas
#include"FuncionesEstructurales.cpp"
usuarios **bajarDatosAListaCircular();
int main()
{
	usuarios *prim=(usuarios*)malloc(sizeof(usuarios));
	prim=NULL;
	usuarios *ulti=(usuarios*)malloc(sizeof(usuarios));
	usuarios **indice=NULL;
	//poner un switch
	
	/*indice=ingresarUsuario(prim,ulti,5,"Alan 5","cinco",0,55,0,0,0);
	prim=indice[0];
	ulti=actual[1];*/
	/*
	actual=ingresarUsuario(prim,ulti,1,"Alan 1","uno",0,11,0,0,0);
	prim=actual[0];
	ulti=actual[1];
	actual=ingresarUsuario(prim,ulti,2,"Alan 2","dos",0,22,0,0,0);
	prim=actual[0];
	ulti=actual[1];
	actual=ingresarUsuario(prim,ulti,3,"Alan 3","tres",0,33,0,0,0);
	prim=actual[0];
	ulti=actual[1];
	actual=ingresarUsuario(prim,ulti,4,"Alan 4","cuatro",0,44,0,0,0);
	prim=actual[0];
	ulti=actual[1];
	printf("Primero:\n");
	mostrarUsuarios(prim);
	printf("Ultimo:\n");
	mostrarUsuarios(ulti);
	printf("[%s]|[%s]",actual[0]->ingreso->usuario,actual[1]->ingreso->usuario);*/

	indice=bajarDatosAListaCircular();
	//subirUsuario(prim);
	prim=indice[0];
	ulti=indice[1];
		printf("\n\n2.primero:%s|Segundo%s\n\n",prim->ingreso->usuario,ulti->ingreso->usuario);
		mostrarUsuarios(prim);
	return 0;
}

