#include<stdio.h>
#include<string.h>
//Usuario
//este va a archivos
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
}*inicio=NULL, *fin=NULL;
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

