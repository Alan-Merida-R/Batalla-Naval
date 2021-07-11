//Biblioteca para el manejo de archivos
#include<stdio.h>
#include<string.h>
#include <math.h>
#include<windows.h>
#define verdad 1
#define falso 0
void GuardarNuevoDato(char *archivo,char *dato,char finDatos[3]);
void GuardarTodo(char *archivo,char *dato,char finDatos[3]);
char *LeerArchivo (char *archi,int Id,int datoRequerido);
void HacerArchivo(char *nombreArchivoNuevo);
void CambiarDatos(char *archi,int Id,char *dato,char finDatos[3]);
int ValidarDatosEnMismoRenglon(char *archi,char *Dato,char *Dato2);
int DamePosicionDelDato(char *archi,char *Dato,int rengloOColumna);
int teDaLaContrasena(char *archi,char *nombreDeUsuario,char *contrase);
int CantidadDeRenglones (char *archi);

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
void GuardarTodo(char *archivo,char *dato,char finDatos[3]){
	FILE *unArchivo;
    unArchivo = fopen(archivo, "w");
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
    char *cadena=(char*)malloc(sizeof(char)*1000000);;
    char *segmentoDeCadena=(char*)malloc(sizeof(char));;
    char *regreso=(char*)malloc(sizeof(char));;
	char separadorDatos[]=":";
	char separadorRenglones='\n';
    archivoLeido = fopen(archi,"r");
	rewind(archivoLeido);
    if (archivoLeido != NULL)
    {
        while (feof(archivoLeido) == 0 && idActual<Id)  /* Mientras no se detecte el caracter EOF (End Of File) */
        {
    		numDato=1;
    		strcpy(cadena," ");
    		//fscanf(archivoLeido,"%s",cadena);
    		fgets(cadena,99999999999,archivoLeido);
            idActual=idActual+1;
            posicion=ftell(archivoLeido);
            segmentoDeCadena = strtok(cadena,separadorDatos);
            if(datoRequerido==1){
            	regreso=segmentoDeCadena;
			}
			else{
				while(numDato<datoRequerido && (segmentoDeCadena = strtok(NULL,separadorDatos)) != NULL )    // Posteriores llamadas
			   {
                    numDato=numDato+1;
			   }
			   regreso=segmentoDeCadena;
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
    return regreso;
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

void CambiarDatos(char *archi,int Id,char *dato,char finDatos[3]){
        FILE *CambioArchivo;
        int idActual=0, posicion=0,numDato=2;
        char *cadena;
        char *nuevosDatos;
        CambioArchivo = fopen(archi,"r+");
		rewind(CambioArchivo);
        if (CambioArchivo != NULL)
        {
            while (feof(CambioArchivo) == 0 && idActual<Id)  /* Mientras no se detecte el caracter EOF (End Of File) */
            {
            		strcpy(cadena," ");
                    fgets(cadena,1000,CambioArchivo);
                    idActual=idActual+1;
                    
            }
            posicion=ftell(CambioArchivo);
            if(strcmp(finDatos,"FIN")==0){
    		fprintf(CambioArchivo, "%s:\n", dato);
    		printf("si entra");
			}
			else{
				fprintf(CambioArchivo, "%s:", dato);
			}
            if(fclose(CambioArchivo)==0)
            {
            	printf("%i",posicion);
                printf("\n\nSe ha CERRADO el archivo \n\n");
            }
            else
            {
                printf("\n\nHubo un problema al CERRAR el archivo\n\n");
            }

        }
        else
        {
            printf("\nError al ABRIR el archivo. \n\n");
        }
        }
int ValidarDatosEnMismoRenglon(char *archi,char *Dato,char *Dato2){
        FILE *archivo;
        int validacion=falso,idActual=0, bandera=0, bandera2=0,idDato=1;
        char *cadena;
        char *segmentoDeCadena;
        char *regreso;
		char separadorDatos[]=":";
		char separadorRenglones='\n';
        archivo = fopen(archi,"r");
		rewind(archivo);
        if (archivo != NULL)
        {
        	while (feof(archivo) == 0 && validacion==falso)  /* Mientras no se detecte el caracter EOF (End Of File) */
            {
            		bandera=0;
            		bandera2=0;
            		idDato=1;
            		strcpy(cadena," ");
                    fgets(cadena,500,archivo);
                    idActual=idActual+1;
            segmentoDeCadena = strtok(cadena,separadorDatos);
            if(strcmp(segmentoDeCadena,Dato)==0){
            	bandera=1;
			}
			if(strcmp(segmentoDeCadena,Dato2)==0){
            	bandera2=1;
			}
			while((segmentoDeCadena=strtok(NULL,separadorDatos)) != NULL && validacion==falso)    // Posteriores llamadas
			   {
			   		idDato=idDato+1;
                    if(strcmp(segmentoDeCadena,Dato)==0){
                    	bandera=1;
						if(bandera==1&&bandera2==1){
                    		validacion=idActual;
						}
						}
					if(strcmp(segmentoDeCadena,Dato2)==0){
                    	bandera2=1;
						if(bandera==1&&bandera2==1){
                    		validacion=idActual;
						}		
			   		}
			}
		}
            if(fclose(archivo)==0)
            {
                printf("\n\nSe ha CERRADO el archivo \n\n");
            }
            else
            {
                printf("\n\nHubo un problema al CERRAR el archivo\n\n");
            }
    	}
        else
        {
            printf("\nError al ABRIR el archivo. \n\n");
        }
	return validacion;
}

int DamePosicionDelDato(char archi[50],char Dato[50],int rengloOColumna){
        FILE *archivo;
        int *val;
        int validacion[2]={falso,falso},idActual=0, bandera=0, bandera2=0,idDato=1;
        char cadena[500]=" ";
        char *segmentoDeCadena;
        char*regreso[50];
		char separadorDatos[]=":";
		char separadorRenglones='\n';
        archivo = fopen(archi,"r");
		rewind(archivo);
        if (archivo != NULL){
        	while (feof(archivo) == 0 && validacion[0]==falso&&validacion[1]==falso)  /* Mientras no se detecte el caracter EOF (End Of File) */
            {
	            		idDato=1;
	            		strcpy(cadena," ");
	                    fgets(cadena,500,archivo);
	                    idActual=idActual+1;
	            segmentoDeCadena = strtok(cadena,separadorDatos);
	            if(strcmp(segmentoDeCadena,Dato)==0){
	            	validacion[0]=idActual;
	            	validacion[1]=idDato;
				}
				while((segmentoDeCadena=strtok(NULL,separadorDatos)) != NULL && validacion[0]==falso&&validacion[1]==falso){
				   		idDato=idDato+1;
	                    if(strcmp(segmentoDeCadena,Dato)==0){
	                    		validacion[0]=idActual;
	            				validacion[1]=idDato;
							}
				}
			}
            if(fclose(archivo)!=0){
                printf("\n\nHubo un problema al CERRAR el archivo\n\n");
            }
    	}else{
    		if (archivo == NULL){
            	printf("\nError al ABRIR el archivo. \n\n");
			}
        }
	return validacion[rengloOColumna];	
}
int teDaLaContrasena(char *archi,char *nombreDeUsuario,char *contrase){
	int renglon=0,columna=0,contra=0;
	char *cadin,*cadin2;
	char *guardarEnEstaVariable;
	renglon=DamePosicionDelDato(archi,nombreDeUsuario,0);
	if(renglon==0){
		renglon=1;
	}
	columna=DamePosicionDelDato(archi,nombreDeUsuario,1);
	contra=columna+1;
	guardarEnEstaVariable=LeerArchivo(archi,renglon,contra);
	if(strcmp(guardarEnEstaVariable,contrase)!=0){
		renglon=falso;
	}
	return renglon;
}
int CantidadDeRenglones (char *archi){
        FILE *archivoLeido;
        int idActual=0,posicion=0;
        char *cadena;
        char *segmentoDeCadena=NULL;
        int regreso=0;
		char separadorRenglones='\n';
        archivoLeido = fopen(archi,"r");
		rewind(archivoLeido);
        if (archivoLeido != NULL)
        {
            while (feof(archivoLeido) == 0)  /* Mientras no se detecte el caracter EOF (End Of File) */
            {
        		strcpy(cadena," ");
                fgets(cadena,99999999999/*10000000000000*/,archivoLeido);
                
	            posicion=ftell(archivoLeido);
	            segmentoDeCadena = strtok(cadena,":\n");
	            idActual++;
			}
			regreso=idActual;
            if(fclose(archivoLeido)!=0)
            {
                printf("\n\nHubo un problema al CERRAR el archivo\n\n");
            }

        }
        else
        {
            printf("\nError al ABRIR el archivo. \n\n");
        }
        return regreso;
}

