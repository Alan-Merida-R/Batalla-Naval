#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Batalla_Naval.cpp"
#include "FuncionesEstructurales.cpp"
int login2();
int login2(){
	char **logindata2=(char**)malloc(sizeof(char*));
	char *user2=(char*)malloc(sizeof(char));
	char *pass2=(char*)malloc(sizeof(char));
	int bandera=0;

	logindata2=login();
	user2=logindata2[0];
	pass2=logindata2[1];
	
	usuarios **actualPrincipal=(usuarios**)malloc(sizeof(usuarios*));
	usuarios *primeroPrincipal=(usuarios*)malloc(sizeof(usuarios));
 	usuarios *ultimoPrincipal=(usuarios*)malloc(sizeof(usuarios));
 	usuarios *indicePrincipal=(usuarios*)malloc(sizeof(usuarios));
 	
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
	for(int i=1;i<x;i++){
		if(i==1){
			primeroPrincipal=NULL;
			ultimoPrincipal=NULL;
			actualPrincipal=NULL;
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
		
		actualPrincipal=ingresarUsuario(primeroPrincipal,ultimoPrincipal,idBajar,usuarioBajar,contraBajar,puntosBajar,vidasBajar,rectangularBajar,cuadradaBajar,atomicaBajar);
   		primeroPrincipal=actualPrincipal[0];
   		ultimoPrincipal=actualPrincipal[1];
	}
	if(user2!=NULL && pass2!=NULL && strcmp(user2,pass2)!=0){
		indicePrincipal=primeroPrincipal;
		do{
			printf("%s\n",indicePrincipal->siguiente->ingreso->usuario);
			printf("%s %s \n", user2,pass2);
			if(strcmp(user2,indicePrincipal->ingreso->usuario)==0 && strcmp(pass2,indicePrincipal->ingreso->contra)==0){
			bandera=indicePrincipal->ingreso->id;
			printf("User y pass existen son dife");	
			}
			indicePrincipal=indicePrincipal->siguiente;
		}while(indicePrincipal!=primeroPrincipal && bandera==0);
	}
	return bandera;
}

