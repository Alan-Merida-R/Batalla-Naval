#include<stdio.h>
#include<string.h>
#include <math.h>
#include<windows.h>
#define verdad 1
#define falso 0
void GuardarNuevoDato(char *archivo,char *dato,char finDatos[3]);
char *LeerArchivo (char *archi,int Id,int datoRequerido);
void HacerArchivo(char *nombreArchivoNuevo);
void CambiarDatos(char *archi,int Id,char *dato,char finDatos[3]);
int ValidarDatosEnMismoRenglon(char *archi,char *Dato,char *Dato2);
int DamePosicionDelDato(char *archi,char *Dato,int rengloOColumna);
int teDaLaContrasena(char *archi,char *nombreDeUsuario,char *contrase);

void GuardarNuevoDato(char *archivo,char *dato,char finDatos[3]){
	FILE *unArchivo;
    unArchivo = fopen(archivo, "a");
    if(unArchivo !=NULL)
    {
    	if(strcmp(finDatos,"FIN")==0){
    		fprintf(unArchivo, "%s:\n", dato);
		}
		else{
			fprintf(unArchivo, "%s:", dato);
		}
        
        if( fclose(unArchivo) != 0 )
        {
           printf("\nNo se guardaron los datos.");
        }
        
    }
    else
    {
        printf("No se pudo abrir el archivo.");
    }
}
char *LeerArchivo (char *archi,int Id,int datoRequerido){
        FILE *archivoLeido;
        int idActual=0, posicion=0,numDato=2;
        char *cadena=" ";
        char *segmentoDeCadena;
        char *regreso;
		char separadorDatos[1]=":";
		char separadorRenglones='\n';
        archivoLeido = fopen(archi,"r");
		rewind(archivoLeido);
        if (archivoLeido != NULL)
        {
            while (feof(archivoLeido) == 0 && idActual<Id)  /* Mientras no se detecte el caracter EOF (End Of File) */
            {
        		numDato=1;
        		strcpy(cadena," ");
                fgets(cadena,1000,archivoLeido);
                idActual=idActual+1;
	            posicion=ftell(archivoLeido);
	            segmentoDeCadena = strtok(cadena,separadorDatos);
	            if(datoRequerido==1){
	            	*regreso=segmentoDeCadena;
				}
				else{
					while(numDato<datoRequerido && (segmentoDeCadena = strtok(NULL,separadorDatos)) != NULL )    // Posteriores llamadas
				   {
	                    numDato=numDato+1;
				   }
				   *regreso=segmentoDeCadena;
				}
			}
            if(fclose(archivoLeido)!=0)
            {
                printf("\n\nHubo un problema al CERRAR el archivo\n\n");
            }

        }
        else
        {
            printf("\nError al ABRIR el archivo. \n\n");
        }
        return *regreso;
}
void HacerArchivo(char *nombreArchivoNuevo){
	FILE *nuevoArchivo;
    nuevoArchivo = fopen(nombreArchivoNuevo, "w");
    if (nuevoArchivo == NULL)
        {
            printf("\nError al ABRIR el archivo. \n\n");
        }
            if(fclose(nuevoArchivo)==0)
            {
                printf("\n\nSe ha CERRADO el archivo \n\n");
            }
            else
            {
                printf("\n\nHubo un problema al CERRAR el archivo\n\n");
            }
        }
