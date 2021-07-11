//Funciones de estructura
 #include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"Bibliotecas\GuardarDatos.h"
#include"Bibliotecas\Estructuras.h"
/*
struct datos{
	int id;
	char *usuario;
	char *contra;
	int puntos;
	int vidas;
	int rectagular;
	int cuadrada;
	int atomica;
};

struct usuarios{
	datos *ingreso;
	usuarios *siguiente;
	usuarios *anterior;
};*inicio=NULL, *fin=NULL;
struct balas{//este va a archivos
	char *info;
	char *grafico;
	int costo;
	balas *siguiente;
	balas *anterior;
}*uno=NULL,*tres=NULL;
//tableros
struct caracteristicas{//este va a archivos
	int id;
	char *nombreDelTablero;
	int posicion[5][5];//[x][y]
	int nivel;
};

struct tableros{
	caracteristicas *nueva;
	tableros *siguiente;
 	tableros *anterior;
}*inicial=NULL,*final=NULL;
*/

usuarios **ingresarUsuario(usuarios *primero,struct usuarios *ultimo,int id,char *usuario,char *contra,int puntos,int vidas,int rectagular,int cuadrada,int atomica);
 //usuarios buscarUsuarios();
 //usuarios modificarUsuarios();
 void mostrarUsuarios(usuarios *primero);
 void subirUsuarios(usuarios *primero);
 usuarios **bajarUsuarios();
 
 //void ingresarTablero();//Funciones para el tablero
 //void buscarTablero();
 //void modificarTablero();
 //void eliminarTablero();
 //void mostrarTableros();
 
  //void ingresarBalas();
  //void buscarBalas();

 //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
usuarios **ingresarUsuario(usuarios *primero,struct usuarios *ultimo,int id,char *usuario,char *contra,int puntos,int vidas,int rectagular,int cuadrada,int atomica){
	usuarios **iniYFin=(usuarios**)malloc(sizeof(usuarios*));
 	usuarios *nuevo=(usuarios*)malloc(sizeof(usuarios));
 	
 	datos *nuevosDatos=(datos*)malloc(sizeof(datos));
 	nuevosDatos->id=id;
 	nuevosDatos->usuario=usuario;
 	nuevosDatos->contra=contra;
 	nuevosDatos->puntos=puntos;
 	nuevosDatos->vidas=vidas;
 	nuevosDatos->rectagular=rectagular;
 	nuevosDatos->cuadrada=cuadrada;
 	nuevosDatos->atomica=atomica;
 	nuevo->ingreso=nuevosDatos;
 	
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
   iniYFin[0]=primero;
   iniYFin[1]=ultimo;
   return iniYFin;
 }
 /*
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
 /*
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
/*
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
*/
void mostrarUsuarios(usuarios *primero){
	usuarios *actual=(usuarios*)malloc(sizeof(usuarios));
	actual=primero;
	if(primero!=NULL){
		do{
			printf("%i-",actual->ingreso->id);
			printf("%s-",actual->ingreso->usuario);
			printf("%s-",actual->ingreso->contra);
			printf("%i-",actual->ingreso->vidas);
			printf("%i-",actual->ingreso->rectagular);
			printf("%i-",actual->ingreso->cuadrada);
			printf("%i;",actual->ingreso->atomica);
			printf("\n");
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("la lista esta vacia.\n");
	}
}
void subirUsuario(usuarios *primero){
	
	char *id=(char*)malloc(sizeof(char));
	char *usuario=(char*)malloc(sizeof(char));
	char *contra=(char*)malloc(sizeof(char));
	char *puntos=(char*)malloc(sizeof(char));
	char *vidas=(char*)malloc(sizeof(char));
	char *rectangular=(char*)malloc(sizeof(char));
	char *cuadrada=(char*)malloc(sizeof(char));
	char *atomica=(char*)malloc(sizeof(char));
	
	usuarios *actual=(usuarios*)malloc(sizeof(usuarios));
	actual=primero;
	if(primero!=NULL){
		do{
			
			sprintf(id, "%i", actual->ingreso->id);
			sprintf(puntos, "%i", actual->ingreso->puntos);
			sprintf(vidas, "%i", actual->ingreso->vidas);
			sprintf(rectangular,"%i", actual->ingreso->rectagular);
			sprintf(cuadrada, "%i", actual->ingreso->cuadrada);
			sprintf(atomica, "%i", actual->ingreso->atomica);
			strcpy(usuario,actual->ingreso->usuario);
			strcpy(contra,actual->ingreso->contra);
			GuardarNuevoDato("baseDeDatos.txt",id," ");
			GuardarNuevoDato("baseDeDatos.txt",usuario," ");
			GuardarNuevoDato("baseDeDatos.txt",contra," ");
			GuardarNuevoDato("baseDeDatos.txt",puntos," ");
			GuardarNuevoDato("baseDeDatos.txt",vidas," ");
			GuardarNuevoDato("baseDeDatos.txt",rectangular," ");
			GuardarNuevoDato("baseDeDatos.txt",cuadrada," ");
			GuardarNuevoDato("baseDeDatos.txt",atomica,"FIN");
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("la lista esta vacia.\n");
	}
}
usuarios **bajarDatosAListaCircular(){
	usuarios *prime=(usuarios*)malloc(sizeof(usuarios));
	prime=NULL;
	usuarios *ultim=(usuarios*)malloc(sizeof(usuarios));
	ultim=NULL;
	usuarios **actual=NULL;
	
	char *usuario=(char*)malloc(sizeof(char));
	char *contra=(char*)malloc(sizeof(char));
	char *idn=(char*)malloc(sizeof(char));
	char *puntosn=(char*)malloc(sizeof(char));
	char *vidasn=(char*)malloc(sizeof(char));
	char *rectangularn=(char*)malloc(sizeof(char));
	char *cuadradan=(char*)malloc(sizeof(char));
	char *atomican=(char*)malloc(sizeof(char));
	
	int id,puntos,vidas,rectangular,cuadrada,atomica;
	int x=0;
	
	x=CantidadDeRenglones("baseDeDatos.txt");
	printf("[%i]\n",x);
	for(int i=1;i<x;i++){
		idn=LeerArchivo("baseDeDatos.txt",i,1);
		usuario=LeerArchivo("baseDeDatos.txt",i,2);
		contra=LeerArchivo("baseDeDatos.txt",i,3);
		puntosn=LeerArchivo("baseDeDatos.txt",i,4);
		vidasn=LeerArchivo("baseDeDatos.txt",i,5);
		rectangularn=LeerArchivo("baseDeDatos.txt",i,6);
		cuadradan=LeerArchivo("baseDeDatos.txt",i,7);
		atomican=LeerArchivo("baseDeDatos.txt",i,8);	
		
		printf("letra:  ");
		printf("[%s]-",idn);
		printf("[%s]-",usuario);
		printf("[%s]-",contra);
		printf("[%s]-",puntosn);
		printf("[%s]-",vidasn);
		printf("[%s]-",rectangularn);
		printf("[%s]-",cuadradan);
		printf("[%s]\n",atomican);
		
		id=atoi(idn);
		puntos=atoi(puntosn);
		vidas=atoi(vidasn);
		rectangular=atoi(rectangularn);
		cuadrada=atoi(cuadradan);
		atomica=atoi(atomican);
		
		printf("numero:  ");
		printf("[%d]-",id);
		printf("[%d]-",puntos);
		printf("[%i]-",vidas);
		printf("[%i]-",rectangular);
		printf("[%i]-",cuadrada);
		printf("[%i]\n",atomica);
		
		actual=ingresarUsuario(prime,ultim,id,usuario,contra,puntos,vidas,rectangular,cuadrada,atomica);
		prime=actual[0];
		ultim=actual[1];
	}
	printf("\n\n2.primero:%s|Segundo%s\n\n",actual[0]->ingreso->usuario,actual[1]->ingreso->usuario);
	mostrarUsuarios(actual[0]);

	return actual;
}
