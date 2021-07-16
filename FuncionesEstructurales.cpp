//Funciones de estructura
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//Bibliotecas
#include"Bibliotecas\GuardarDatos.h"
#include"Bibliotecas\Estructuras.h"
//Archivos
#define ArchivoUsuarios "baseDeDatos.txt"
#define txt ".txt"
#define ArchivoBalas "balas.txt"
//usuario
usuarios **ingresarUsuario(usuarios *primero,struct usuarios *ultimo,int id,char *usuario,char *contra,int puntos,int vidas,int rectagular,int cuadrada,int atomica);//inbresa usiario pero solo a la lista
usuarios *buscarUsuarios(usuarios *primero,int idDeUsuario);
usuarios *modificarUsuarios(usuarios *primero,int id,char *usuario,char *contra,int puntos,int vidas,int rectagular,int cuadrada,int atomica);//modifica pero solo en la lista
void mostrarUsuarios(usuarios *primero);
void subirUsuarios(usuarios *primero);//Sube directamente un usuario nuevo al archivo
void enviarNuevaLista(usuarios *primero);//Borra la lista vieja y pone la nueva
//balas
balas *BajarBalas(balas *primera);
//Tablero
tableros **ingresarTablero(tableros *inicioIngreso, tableros *finIngreso, int idTableroIngreso, char *nombreDelTableroIngreso, int navesDeIngreso[5][2],int nivelIngreso);//Funciones para el tablero
void enviarNuevaListaDeTableros(int idUsuario,tableros *primerTablero);//Subir datos al archivo
tableros **bajarTablero(int idarch);
//tableros *buscarTablero(tableros *inicial,char aliasDelTablero);
//tableros *modificarTablero(tableros *inicio, tableros *fin,int idTableroIngreso, char *nombreDelTableroIngreso, int navesDeIngreso[5][2],int nivelIngreso);
//tableros *eliminarTablero(tableros *inicioDeEliminacion, tableros *finEliminacion,int idAEliminar);

 //void mostrarTableros();

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
 usuarios *buscarUsuarios(usuarios *primero,int idDeUsuario){
 	int usuarioBuscado,encontrado;
 	encontrado=0;
 	usuarios *actual=(usuarios*)malloc(sizeof(usuarios));
 	usuarios *retorno=(usuarios*)malloc(sizeof(usuarios));
 	retorno=NULL;
 	actual=primero;
 	if(primero!=NULL){
 		do{
 			usuarioBuscado=actual->ingreso->id;
 			if(usuarioBuscado==idDeUsuario){
 				actual=actual->anterior;
 				encontrado=1;
 			}
 			actual=actual->siguiente;
 		}while(actual!=primero && encontrado==0);
 		if(encontrado==1){
 			retorno=actual;
 		}

 	}else{
 		printf("la lsita esta vacia.\n");
 	}
	return retorno;
 }

usuarios *modificarUsuarios(usuarios *primero,int id,char *usuario,char *contra,int puntos,int vidas,int rectagular,int cuadrada,int atomica){
	int encontrado;
 	encontrado=0;
 	usuarios *actualModif=(usuarios*)malloc(sizeof(usuarios));
 	actualModif=primero;
 	if(primero!=NULL){
 		do{
 			if(actualModif->ingreso->id==id){
 				actualModif->ingreso->usuario=usuario;
 				actualModif->ingreso->contra=contra;
 				actualModif->ingreso->puntos=puntos;
 				actualModif->ingreso->vidas=vidas;
 				actualModif->ingreso->rectagular=rectagular;
 				actualModif->ingreso->cuadrada=cuadrada;
 				actualModif->ingreso->atomica=atomica;
 				encontrado=1;
 			}
 			actualModif=actualModif->siguiente;
 		}while(actualModif!=primero);
 		if(encontrado==0){
 			actualModif=NULL;
 			printf("no se encontro el dato");
 		}
 	}else{
 		printf("la lsita esta vacia.\n");
 	}
	return actualModif;
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
			GuardarNuevoDato(ArchivoUsuarios,id," ");
			GuardarNuevoDato(ArchivoUsuarios,usuario," ");
			GuardarNuevoDato(ArchivoUsuarios,contra," ");
			GuardarNuevoDato(ArchivoUsuarios,puntos," ");
			GuardarNuevoDato(ArchivoUsuarios,vidas," ");
			GuardarNuevoDato(ArchivoUsuarios,rectangular," ");
			GuardarNuevoDato(ArchivoUsuarios,cuadrada," ");
			GuardarNuevoDato(ArchivoUsuarios,atomica,"FIN");
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("la lista esta vacia.\n");
	}
}
 void enviarNuevaLista(usuarios *primero){

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
		EliminarTodo(ArchivoUsuarios);
		do{
			sprintf(id, "%i", actual->ingreso->id);
			sprintf(puntos, "%i", actual->ingreso->puntos);
			sprintf(vidas, "%i", actual->ingreso->vidas);
			sprintf(rectangular,"%i", actual->ingreso->rectagular);
			sprintf(cuadrada, "%i", actual->ingreso->cuadrada);
			sprintf(atomica, "%i", actual->ingreso->atomica);
			strcpy(usuario,actual->ingreso->usuario);
			strcpy(contra,actual->ingreso->contra);
			GuardarNuevoDato(ArchivoUsuarios,id," ");
			GuardarNuevoDato(ArchivoUsuarios,usuario," ");
			GuardarNuevoDato(ArchivoUsuarios,contra," ");
			GuardarNuevoDato(ArchivoUsuarios,puntos," ");
			GuardarNuevoDato(ArchivoUsuarios,vidas," ");
			GuardarNuevoDato(ArchivoUsuarios,rectangular," ");
			GuardarNuevoDato(ArchivoUsuarios,cuadrada," ");
			GuardarNuevoDato(ArchivoUsuarios,atomica,"FIN");
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("la lista esta vacia.\n");
	}
}
balas *BajarBalas(balas *primera){
	balas *cuarta=NULL;
	char *nombre=(char*)malloc(sizeof(char));
	char *info=(char*)malloc(sizeof(char));
	char *diseno=(char*)malloc(sizeof(char));
	char *signo=(char*)malloc(sizeof(char));
	char *costoLetra=(char*)malloc(sizeof(char));
	
	int costo;
	int x=0;

	x=CantidadDeRenglones(ArchivoBalas);
	printf("[%i]\n",x);
	for(int i=1;i<x;i++){
		if(i==1){
			primera=NULL;
			cuarta=NULL;
		}
		nombre=LeerArchivo(ArchivoBalas,i,1);
		info=LeerArchivo(ArchivoBalas,i,2);
		diseno=LeerArchivo(ArchivoBalas,i,3);
		signo=LeerArchivo(ArchivoBalas,i,4);
		costoLetra=LeerArchivo(ArchivoBalas,i,5);
		costo=atoi(costoLetra);
		
		balas *nuevas=(balas*)malloc(sizeof(balas));
	 	nuevas->Nombre=nombre;
	 	nuevas->info=info;
		nuevas->grafico=diseno;
		nuevas->signo=signo;
		nuevas->costo=costo;
	
	   if(primera==NULL){
	   	primera=nuevas;
	   	primera->siguiente=primera;
	   	cuarta=primera;
	   	primera->anterior=cuarta;
	   }
	   else{
	   	cuarta->siguiente=nuevas;
	   	nuevas->siguiente=primera;
	   	nuevas->anterior=cuarta;
	   	cuarta=nuevas;
	   	primera->anterior=cuarta;
	   }
	}
	return primera;
}
tableros **ingresarTablero(tableros *inicioIngreso, tableros *finIngreso, int idTableroIngreso, char *nombreDelTableroIngreso, int navesDeIngreso[5][2],int nivelIngreso){
	tableros **ambos=(tableros**)malloc(sizeof(tableros*));
 	tableros *nuevoTablero=(tableros*)malloc(sizeof(tableros));

 	caracteristicas *nuevasCaracteristicas=(caracteristicas*)malloc(sizeof(caracteristicas));
 	nuevasCaracteristicas->id=idTableroIngreso;
 	nuevasCaracteristicas->nombreDelTablero=nombreDelTableroIngreso;
 	for(int i=0;i<5;i++){
	 	for(int j=0;j<2;j++){
	 		nuevasCaracteristicas->naves[i][j]=navesDeIngreso[i][j];
	 	}
	}
	nuevasCaracteristicas->nivel=nivelIngreso;
	
	nuevoTablero->nueva=nuevasCaracteristicas;
	
   if(inicioIngreso==NULL){
   	inicioIngreso=nuevoTablero;
   	inicioIngreso->siguiente=inicioIngreso;
   	finIngreso=inicioIngreso;
   	inicioIngreso->anterior=finIngreso;
   }
   else{
   	finIngreso->siguiente=nuevoTablero;
   	nuevoTablero->siguiente=inicioIngreso;
   	nuevoTablero->anterior=finIngreso;
   	finIngreso=nuevoTablero;
   	inicioIngreso->anterior=finIngreso;
   }
   ambos[0]=inicioIngreso;
   ambos[1]=finIngreso;
   return ambos;
}

void enviarNuevaListaDeTableros(int idUsuario,tableros *primerTablero){
	char *idArchivo=(char*)malloc(sizeof(char));
	char *idTable=(char*)malloc(sizeof(char));
	char *nombreTable=(char*)malloc(sizeof(char));
	char *nivelTable=(char*)malloc(sizeof(char));
	char *Dato1=(char*)malloc(sizeof(char));
	char *Dato2=(char*)malloc(sizeof(char));
	char *Dato3=(char*)malloc(sizeof(char));
	char *Dato4=(char*)malloc(sizeof(char));
	char *Dato5=(char*)malloc(sizeof(char));
	char *Dato6=(char*)malloc(sizeof(char));
	char *Dato7=(char*)malloc(sizeof(char));
	char *Dato8=(char*)malloc(sizeof(char));
	char *Dato9=(char*)malloc(sizeof(char));
	char *Dato10=(char*)malloc(sizeof(char));
	
	tableros *indiceDeTableroRecorrido=(tableros*)malloc(sizeof(tableros));
	indiceDeTableroRecorrido=primerTablero;
	
	sprintf(idArchivo, "%i", idUsuario);
	strcat(idArchivo,txt);
	if(primerTablero!=NULL){
		HacerArchivo(idArchivo);
		do{
			sprintf(idTable, "%i", indiceDeTableroRecorrido->nueva->id);
			nombreTable=indiceDeTableroRecorrido->nueva->nombreDelTablero;
			sprintf(nivelTable, "%i", indiceDeTableroRecorrido->nueva->nivel);
			sprintf(Dato1, "%i", indiceDeTableroRecorrido->nueva->naves[0][0]);
			sprintf(Dato2, "%i", indiceDeTableroRecorrido->nueva->naves[0][1]);
			sprintf(Dato3, "%i", indiceDeTableroRecorrido->nueva->naves[1][0]);
			sprintf(Dato4, "%i", indiceDeTableroRecorrido->nueva->naves[1][1]);
			sprintf(Dato5, "%i", indiceDeTableroRecorrido->nueva->naves[2][0]);
			sprintf(Dato6, "%i", indiceDeTableroRecorrido->nueva->naves[2][1]);
			sprintf(Dato7, "%i", indiceDeTableroRecorrido->nueva->naves[3][0]);
			sprintf(Dato8, "%i", indiceDeTableroRecorrido->nueva->naves[3][1]);
			sprintf(Dato9, "%i", indiceDeTableroRecorrido->nueva->naves[4][0]);
			sprintf(Dato10, "%i", indiceDeTableroRecorrido->nueva->naves[4][1]);
			
			GuardarNuevoDato(idArchivo,idTable,"");
			GuardarNuevoDato(idArchivo,nombreTable,"");
			GuardarNuevoDato(idArchivo,Dato1,"");
			GuardarNuevoDato(idArchivo,Dato2,"");
			GuardarNuevoDato(idArchivo,Dato3,"");
			GuardarNuevoDato(idArchivo,Dato4,"");
			GuardarNuevoDato(idArchivo,Dato5,"");
			GuardarNuevoDato(idArchivo,Dato6,"");
			GuardarNuevoDato(idArchivo,Dato7,"");
			GuardarNuevoDato(idArchivo,Dato8,"");
			GuardarNuevoDato(idArchivo,Dato9,"");
			GuardarNuevoDato(idArchivo,Dato10,"");
			GuardarNuevoDato(idArchivo,nivelTable,"FIN");
			indiceDeTableroRecorrido=indiceDeTableroRecorrido->siguiente;
		}while(indiceDeTableroRecorrido!=primerTablero);
	}else{
		printf("la lista esta vacia.\n");
	}
	}
tableros **bajarTablero(int idarch){
	tableros **actualTableroRecorrido=(tableros**)malloc(sizeof(tableros*));
	actualTableroRecorrido=NULL;
	tableros *inicioBajarTablero=(tableros*)malloc(sizeof(tableros));
	inicioBajarTablero=NULL;
	tableros *finBajarTablero=(tableros*)malloc(sizeof(tableros));
	finBajarTablero=NULL;
	
	char *nombreLet=(char*)malloc(sizeof(char));
	int id;
	int datos[5][2];
	int nivel;
	
	char *idEnLetraBajar;
	sprintf(idEnLetraBajar, "%i", idarch);
	int cantidadDeTableros;
	
	strcat(idEnLetraBajar,txt);
	cantidadDeTableros=CantidadDeRenglones(idEnLetraBajar);
	for(int i=1;i<=cantidadDeTableros;i++){
		id=atoi(LeerArchivo(idEnLetraBajar,i,1));
		nombreLet=LeerArchivo(idEnLetraBajar,i,2);
		int l=3;
		for(int j=0;j<5;j++){
			datos[j][0]=atoi(LeerArchivo(idEnLetraBajar,i,l));
			l++;
			datos[j][1]=atoi(LeerArchivo(idEnLetraBajar,i,l));
			l++;
		}
		nivel=atoi(LeerArchivo(idEnLetraBajar,i,13));
		actualTableroRecorrido=ingresarTablero(inicioBajarTablero,finBajarTablero,id,nombreLet,datos,nivel);
		inicioBajarTablero=actualTableroRecorrido[0];
		finBajarTablero=actualTableroRecorrido[1];
	}
	actualTableroRecorrido[0]=inicioBajarTablero;
	actualTableroRecorrido[1]=finBajarTablero;
	printf("en bajar\n");
	return actualTableroRecorrido;
}

/*tableros *buscarTablero(tableros *inicial,char aliasDelTablero){
	
}

/*
/*tableros *eliminarTablero(tableros *inicioDeEliminacion, tableros *finEliminacion,int idAEliminar){
	
}*/

