#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//Lista doblemente ligada
struct Caracteristicas{
	char *nombreDelTablero;
	int posicion[5][5];//[x][y]
	int nivel;
};
struct Tableros{
	Caracteristicas *nueva;
	Tableros *siguiente;
 	Tableros *anterior;
}*primero=NULL,*ultimo=NULL;
struct Datos{
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
 void ingresarUsuario();//Funciones para usuarios
 void buscarUsuarios();
 void modificarUsuarios();
 void mostrarUsuarios();
 
 void ingresarTablero();//Funciones para el tablero
 void buscarTablero();
 void modificarTablero();
 void eliminarTablero();
 void mostrarTableros();
 
