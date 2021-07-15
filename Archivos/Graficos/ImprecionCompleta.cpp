#include<stdio.h>
#include <stdlib.h>
#include<string.h>
char *imprimirArchivoCompleto(char *archivo);
char *imprimirArchivoCompleto(char *archivo){
		FILE *archivoLeido;
        int idActual=0, posicion=0,numDato=2;
        char cadena[1000]=" ";
        char *segmentoDeCadena;
		char separadorRenglones='\n';
        archivoLeido = fopen(archivo,"r");
		rewind(archivoLeido);
        if (archivoLeido != NULL)
        {
        	while (feof(archivoLeido) == 0){
        		strcpy(cadena," ");
        		fgets(cadena,1000,archivoLeido);
        		
	            printf("%s",cadena);
			}
		}
		else
		 printf("\nError al ABRIR el archivo. \n\n");
}
