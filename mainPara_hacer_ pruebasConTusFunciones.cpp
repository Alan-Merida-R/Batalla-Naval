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
int main()
{
	balas *listaDeBalas=(balas*)malloc(sizeof(balas));
	listaDeBalas=NULL;

	usuarios **actual=(usuarios**)malloc(sizeof(usuarios*));
	usuarios *primeroPrincipal=(usuarios*)malloc(sizeof(usuarios));
 	usuarios *ultimoPrincipal=(usuarios*)malloc(sizeof(usuarios));
 	usuarios *buscadoEnMain=(usuarios*)malloc(sizeof(usuarios));
	char *usuarioBajar=(char*)malloc(sizeof(char));
	char *contraBajar=(char*)malloc(sizeof(char));
	char *idLetra=(char*)malloc(sizeof(char));
	char *puntosLetra=(char*)malloc(sizeof(char));
	char *vidasLetra=(char*)malloc(sizeof(char));
	char *rectangularLetra=(char*)malloc(sizeof(char));
	char *cuadradaLetra=(char*)malloc(sizeof(char));
	char *atomicaLetra=(char*)malloc(sizeof(char));

	int idBajar,puntosBajar,vidasBajar,rectangularBajar,cuadradaBajar,atomicaBajar;
	int x=0;

	x=CantidadDeRenglones(ArchivoUsuarios);
	printf("[%i]\n",x);
	for(int i=1;i<x;i++){
		if(i==1){
			primeroPrincipal=NULL;
			ultimoPrincipal=NULL;
			actual=NULL;
		}
		idLetra=LeerArchivo(ArchivoUsuarios,i,1);
		usuarioBajar=LeerArchivo(ArchivoUsuarios,i,2);
		contraBajar=LeerArchivo(ArchivoUsuarios,i,3);
		puntosLetra=LeerArchivo(ArchivoUsuarios,i,4);
		vidasLetra=LeerArchivo(ArchivoUsuarios,i,5);
		rectangularLetra=LeerArchivo(ArchivoUsuarios,i,6);
		cuadradaLetra=LeerArchivo(ArchivoUsuarios,i,7);
		atomicaLetra=LeerArchivo(ArchivoUsuarios,i,8);


		idBajar=atoi(idLetra);
		puntosBajar=atoi(puntosLetra);
		vidasBajar=atoi(vidasLetra);
		rectangularBajar=atoi(rectangularLetra);
		cuadradaBajar=atoi(cuadradaLetra);
		atomicaBajar=atoi(atomicaLetra);
		
		actual=ingresarUsuario(primeroPrincipal,ultimoPrincipal,idBajar,usuarioBajar,contraBajar,puntosBajar,vidasBajar,rectangularBajar,cuadradaBajar,atomicaBajar);
   		primeroPrincipal=actual[0];
   		ultimoPrincipal=actual[1];
	}
	
	primeroPrincipal=modificarUsuarios(primeroPrincipal,6,"Alan 6 Modi","Modi6",6,6,6,6,6);
	buscadoEnMain=buscarUsuarios(primeroPrincipal,6);
	printf("%s",buscadoEnMain->ingreso->usuario);
	//poner un switch
	x=CantidadDeRenglones(ArchivoBalas);
	printf("[%i]\n",x);
	listaDeBalas=BajarBalas(listaDeBalas);
	printf("[%s]\n",listaDeBalas->siguiente->grafico);
	//final subirNuevoDoc
	enviarNuevaLista(primeroPrincipal);
	
	
	return 0;
}
	
