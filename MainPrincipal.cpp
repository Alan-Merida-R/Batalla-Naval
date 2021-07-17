//main principal que llama a todas las funciones
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define verdad 1
#define falso 0
//Archivos
#define ArchivoUsuarios "baseDeDatos.txt"
#define txt ".txt"
#define ArchivoBalas "balas.txt"

#include"logica.cpp"
//Programas
//#include"FuncionesEstructurales.cpp"//tiene muchas funciones para hacer listas y trae bibleotecas para subir archivos y con las estructuras principales

int main(){
	int confirmador=0;
	do{
	confirmador=login2();
	}while(confirmador==0);
	
	
	//poner un switch y mandar a llamar a todas las funciones
	
	
	//final subir los cambios de la lista
	//enviarNuevaLista(primeroPrincipal);
	return 0;
}
