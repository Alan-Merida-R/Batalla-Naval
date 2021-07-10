//Funcion principal
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "Archivos\ImprecionCompleta.cpp"
int main()
{
	system("dir");
	system("cd Archivos\Graficos");
	system("dir");
	system("more Soldado.txt");
	imprimirArchivoCompleto("Soldado.txt");
	return 0;
}
