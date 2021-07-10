#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"GuardarDatos.h"
//Lista doblemente ligada
struct Caracteristicas{//este va a archivos
	char *nombreDelTablero;
	int posicion[5][5];//[x][y]
	int nivel;
};
struct Tableros{
	Caracteristicas *nueva;
	Tableros *siguiente;
 	Tableros *anterior;
}*primero=NULL,*ultimo=NULL;
struct Datos{//este va a archivos
	int id;
	char *usuario;
	char *contra;
	int puntos;
	int vidas;
	int rectagular;
	int cuadrada;
	int atomica;
	Tableros *tablerosDeUsuario;
};
struct Usuarios{
	Datos *ingreso;
	Usuarios *siguiente;
	Usuarios *anterior;
}*inicio=NULL,*fin=NULL;
struct Balas{//este va a archivos
	char *info;
	char *grafico;
	int costo;
	Usuarios *siguiente;
	Usuarios *anterior;
}*uno=NULL,*tres=NULL;
 void ingresarUsuario();//Funciones para usuarios
 void buscarUsuarios();
 void modificarUsuarios();
 void mostrarUsuarios();
 
 void ingresarTablero();//Funciones para el tablero
 void buscarTablero();
 void modificarTablero();
 void eliminarTablero();
 void mostrarTableros();
 
  void ingresarBalas();
  void buscarBalas();
  
 //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
void ingresarUsuario(){
 	int x;
 	nodo *nuevo=(nodo*)malloc(sizeof(nodo));
 	printf("ingresa el dato.\n");
 	scanf("%i",&nuevo->dato);
   if(primero==NULL){
   	primero=nuevo;
   	primero->siguiente=primero;
   	ultimo=primero;
   	primero->anterior=ultimo;
   	
   }
   else{
   	ultimo->siguiente=nuevo;
   	nuevo->siguiente=primero;
   	nuevo->anterior=ultimo;
   	ultimo=nuevo;
   	primero->anterior=ultimo;
   }
   printf("dato ingresado.\n");	
 }
 void buscarNodo(){
 	int nodoBuscado,encontrado;
 	encontrado=0;
 	nodo *actual=(nodo*)malloc(sizeof(nodo));
 	actual=primero;
 	printf("ingresa el dato que quieras buscar.\n");
 	scanf("%i",&nodoBuscado);
 	if(primero!=NULL){
 		do{
 			if(actual->dato=nodoBuscado){
 				printf("tu dato fue encontrado.\n");
 				encontrado=1;
 			}
 			actual=actual->siguiente;
 		}while(actual!=primero && encontrado==0);
 		if(encontrado==0){
 			printf("no se encontro el dato");
 		}
 	}else{
 		printf("la lsita esta vacia.\n");
 	}
 }
void modificarNodo(){
	int nodoBuscado,encontrado;
 	encontrado=0;
 	nodo *actual=(nodo*)malloc(sizeof(nodo));
 	actual=primero;
 	printf("ingresa el dato que quieras buscar.\n");
 	scanf("%i",&nodoBuscado);
 	if(primero!=NULL){
 		do{
 			if(actual->dato==nodoBuscado){
 				printf("tu dato fue encontrado.\n");
 				printf("dame el nuuevo dato.\n");
 				scanf("%i",&actual->dato);
 				
 				encontrado=1;
 			}
 			actual=actual->siguiente;
 		}while(actual!=primero && encontrado==0);
 		if(encontrado==0){
 			printf("no se encontro el dato");
 		}
 	}else{
 		printf("la lsita esta vacia.\n");
 	}
	
}
void eliminarNodo(){
	int nodoBuscado,encontrado;
	
 	encontrado=0;
 	nodo *actual=(nodo*)malloc(sizeof(nodo));
 	actual=primero;
 	nodo *ant=(nodo*)malloc(sizeof(nodo));
 	ant=NULL;
 	
 	printf("ingresa el dato que quieras buscar.\n");
 	scanf("%i",&nodoBuscado);
 	if(primero!=NULL){
 		do{
 			if(actual->dato==nodoBuscado){
 				printf("tu dato fue encontrado.\n");
 				if(actual==primero){
 					primero=primero->siguiente;
 					primero->anterior=ultimo;
 					ultimo->siguiente=primero;
 					
 				}else if(actual==ultimo){
 					ultimo=ant;
 					ultimo->siguiente=primero;
 					primero->anterior=ultimo;
 				
 				}else{
 					ant->siguiente=actual->siguiente;
 					actual->siguiente->anterior=ant;
 				}
 				printf("nodo eliminado.\n");
 				encontrado=1;
 			}
 			ant=actual;
 			actual=actual->siguiente;
 		}while(actual!=primero && encontrado==0);
 		if(encontrado==0){
 			printf("no se encontro el dato");
 		}
 		else{
 			free(ant);
 		}
 	}else{
 		printf("la lista esta vacia.\n");
 	}
}
void mostrarLista(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL){
		do{
			printf("%i\t.\n",actual->dato);
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("la lista esta vacia.\n");
	}
} 
