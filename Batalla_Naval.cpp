//Batalla naval por Equipo 5 : "Los piñeiros"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // Librería para la función system("clear")
#include <unistd.h> // Librería para la función sleep()
#include <windows.h>//Libreria para el color
#include <string.h>
void login(); //Pide datos
void aniLogo(); //Letrotas
void aniBarco(); //Imagen ASCII de un barco (Voy a ver si logro hacer que parpadee
void aniAvion(); // " 				" avion
void barraSup(); //Barra de estado con nombres, vidas, balas y puntajes
void pantCompleta(); //Funcion que logra hacer que el programa se ejecute en pantalla completa (Solo windows)
void menu(); //Animacion del menu ya con animaciones


//SE DEBE USAR PANTALLA COMPLETA ANTES DE ENTRAR A LA PANTALLA DE MENU PARA QUE LAS ANIMACIONES
//SE VEAN COMO SE DEBEN

int main(){ //Main para probar las animaciones BORRAR DESPUES 
pantCompleta();
	aniLogo();
	barraSup();
	menu();
	
}

void login(){
char user[10], pass[10];
	
	system("cls");
	printf("\033[0;31m"); 	//Iniciamos color ROJO
	printf("\t\t\t\t\t%c",201);  for(int p=0; p<24; p++){printf("%c",205);} printf("%c\n",187); printf("\t\t\t\t\t%c \t",186); //Parte de arriba del recuadro
		printf("\033[0m"); //Iniciamos color Blanco
	printf("Bienvenido!      ");
	printf("\033[0;31m"); printf("%c\n",186); 
	printf("\t\t\t\t\t%c",200);  for(int p=0; p<24; p++){printf("%c",205);} printf("%c\n",188);	 //Parte de abajo del recuadro 
	printf("\033[0m");	

	printf("\t\t\t\t\tAntes de empezar crea tu usuario\n\n");
	//metan el gestor de archivos aqui para que cree un archivo de guardado xfas
	//Pongan un IF de que si ya hay un archivo existente obtenga el nombre del usuario con el puntaje maximo guardado
	//y que si no pues que haga un archivo para guardar

    int size;
    printf("\t\t\t\t\tPorfavor ingresa un usario\n\n");
    printf("\t\t\t\t\tUsuario: ");
    gets(user);
    system("CLS");
 
	system("cls");
	printf("\033[0;31m"); 	//Iniciamos color ROJO
	printf("\t\t\t\t\t%c",201);  for(int p=0; p<24; p++){printf("%c",205);} printf("%c\n",187); printf("\t\t\t\t\t%c \t",186); //Parte de arriba del recuadro
		printf("\033[0m"); //Iniciamos color Blanco
	printf("Bienvenido!      ");
	printf("\033[0;31m"); printf("%c\n",186); 
	printf("\t\t\t\t\t%c",200);  for(int p=0; p<24; p++){printf("%c",205);} printf("%c\n",188);	 //Parte de abajo del recuadro 
	printf("\033[0m");	

    printf("\n\t\t\t\t\tPorfavor ingresa tu Password: \n"); 
	printf("\t\t\t\t\tUsuario: "); puts(user); printf("\n");
	printf("\t\t\t\t\tPassword: "); 
	gets(pass);
	system("CLS");
	//Aqui metan que se verifique que pass y user no sea el mismo 
	//y poner una condicion para que se ingresen el valor 
	
	//alerta de datos incorectos
	system("cls");
	printf("\033[0;31m"); 	//Iniciamos color ROJO
	printf("\t\t\t\t\t%c",201);  for(int p=0; p<31; p++){printf("%c",205);} printf("%c\n",187); printf("\t\t\t\t\t%c \t",186); //Parte de arriba del recuadro
	printf(" ERROR ENCONTRADO\t%c\n\t\t\t\t\t%c\tUsuario incorrecto\t%c\n\t\t\t\t\t%c\t\tO\t\t%c\n\t\t\t\t\t%c\tPassword incorrecto\t%c\n",186,186,186,186,186,186,186);
	printf("\t\t\t\t\t%c",200);  for(int p=0; p<31; p++){printf("%c",205);} printf("%c\n",188);	 //Parte de abajo del recuadro 
	printf("\033[0m");

	
	//Si todo es correcto
	printf("\n\t\t\t\t\tPerfecto! Es hora de empezar el juego!!\n");		
	sleep(3);
	system("CLS");
	
}

void aniLogo(){
	system("cls");
	const char *const azul = "\033[1;34m";
	const char *const gris = "\033[1;30m";
    const char *const verde = "\033[0;40;32m";
	const char *const rojo = "\033[31m";     
	                                                                                                                                                                                                                                                                                                                                                                                                                                                  
printf("%s\t\t\t\t\t\t\t:::::::::      ::: ::::::::::: :::     :::        :::            :::   					\n",azul);              
printf("\t\t\t\t\t\t\t:+:    :+:   :+: :+:   :+:   :+: :+:   :+:        :+:          :+: :+:               	\n");
printf("\t\t\t\t\t\t\t+:+    +:+  +:+   +:+  +:+  +:+   +:+  +:+        +:+         +:+   +:+              	\n");
printf("\t\t\t\t\t\t\t+#++:++#+  +#++:++#++: +#+ +#++:++#++: +#+        +#+        +#++:++#++:             	\n");
printf("\t\t\t\t\t\t\t+#+    +#+ +#+     +#+ +#+ +#+     +#+ +#+        +#+        +#+     +#+             	\n");
printf("\t\t\t\t\t\t\t#+#    #+# #+#     #+# #+# #+#     #+# #+#        #+#        #+#     #+#             	\n");
printf("\t\t\t\t\t\t\t#########  ###     ### ### ###     ### ########## ########## ###     ###             	\n");
printf("%s\t\t\t\t\t\t\t                          ::::    :::     :::     :::     :::     :::     :::        	\n",rojo);
printf("\t\t\t\t\t\t\t                          :+:+:   :+:   :+: :+:   :+:     :+:   :+: :+:   :+:        	\n");
printf("\t\t\t\t\t\t\t                          :+:+:+  +:+  +:+   +:+  +:+     +:+  +:+   +:+  +:+        	\n");
printf("\t\t\t\t\t\t\t                          +#+ +:+ +#+ +#++:++#++: +#+     +:+ +#++:++#++: +#+        	\n");
printf("\t\t\t\t\t\t\t                          +#+  +#+#+# +#+     +#+  +#+   +#+  +#+     +#+ +#+        	\n");
printf("\t\t\t\t\t\t\t                          #+#   #+#+# #+#     #+#   #+#+#+#   #+#     #+# #+#        	\n");
printf("\t\t\t\t\t\t\t                          ###    #### ###     ###     ###     ###     ### ########## 	\n%s",verde);

                                                                                        
}                                                                       

void aniBarco(){
	
	
	
printf("                                   )___(						\n");
printf("                           _______/__/_							\n");
printf("                  ___     /===========|   ___					\n");
printf(" ____       __   [\\\\\\]___/____________|__[///]   __			\n");	
printf(" \\   \\_____[\\\\]__/___________________________\\__[//]___	\n");
printf("  \\40A                                                 |		\n");
printf("   \\                                                  /		\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	\n");
	
}

void aniAvion(){
	

printf("           \\  \\     _ _		\n");
printf("            \\**\\ ___\\/ \\	\n");
printf("          X*#####*+^^\\_\\		\n");
printf("            o/\\  \\			\n");
printf("               \\__\\			\n");

}

void pantCompleta(){
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
} 

void barraSup(){
	
	
    const char *const rosa = "\033[0;1;31m"; //Dar color rosa
    const char *const verde = "\033[0;40;32m"; //Dar color verde
    const char *const normal = "\033[0m"; //Volver al color normal
	char fuser[]={"Diego"}; int vidas=3;
	int BalaC=3; 
	int BalaM=1; 
	int BalaG=0;
	int puntos=100;
	printf("%c",201);  for(int p=0; p<209; p++){printf("%c",205);} printf("%c\n",187); printf("%c \t",186); //Parte de arriba del recuadro
		
	printf("Nombre: %s%s%s ",normal,fuser,verde); printf("\t\tVidas:");	for(int i=0; i<vidas; i++){printf("%s%c%s",rosa,3,verde);}
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Balas: %s%i%s CH %s%c%c %s%i%s M %s%c%c %s%i%s G %s%c%c%s",normal,BalaC,verde,rosa,176,176,normal,BalaM,verde,rosa,177,177,normal,BalaG,verde,rosa,178,178,verde);
	printf("\t\t     Puntos: %s$%s%i%s\t  %c",rosa,normal,puntos,verde,186);
	printf("\n%c",200);  for(int p=0; p<209; p++){printf("%c",205);} printf("%c\n",188);	 //Parte de abajo del recuadro 
}

void menu(){

    const char *const rosa = "\033[0;1;31m"; //Dar color rosa
    const char *const verde = "\033[0;40;32m"; //Dar color verde
    const char *const normal = "\033[0m"; //Volver al color normal osea blanco
	const char *const azul = "\033[1;34m";
	const char *const gris = "\033[1;30m";
	const char *const rojo = "\033[31m";
	const char *const morado = "\033[35m";
printf("\n\n\n");	
printf("                                   %s)___(%s						",azul,verde); 									printf("%c",201);  for(int p=0; p<40; p++){printf("%c",205);} printf("%c",187);			printf("%s                  (\\__.-. |%s\n",gris,verde);
printf("                                  %s)___(%s					    	",azul,verde);									printf("\t%c\t\t\t\t\t %c",186,186);													printf("%s                  == ===_]%s+%s\n",gris,rojo,verde);
printf("                           %s_______/__/_%s							",gris,verde);									printf("%c \t\t%s 1. Jugar%s\t\t %c",186,normal,verde,186);								printf("%s                          |%s\n",gris,verde);
printf("                  %s___     /%s===========%s|   ___%s					",gris,rojo,gris,verde);					printf("\t%c\t\t\t\t\t %c",186,186);													printf("%s 			` - .		   			%s\n",gris,verde);
printf(" %s____       __   [%s\\\\\\%s]___/____________|__[%s///%s]   __%s			",gris,rojo,gris,rojo,gris,verde);		printf("\t\t%c\t\t%s2. Tienda%s\t\t %c",186,normal,verde,186);							printf("%s            	  	    ` - %s>%s-%s>%s		\n",gris,azul,verde,rojo,verde);
printf(" %s\\   \\_____[%s\\\\%s]__/___________________________\\__[%s//%s]___%s	",gris,rojo,gris,rojo,gris,verde);		printf("\t\t\t\t%c\t\t\t\t\t %c\n",186,186);												
printf("  %s\\%s40A%s                                                 |%s		",gris,morado,gris,verde);					printf("\t\t%c    %s\t   3. Salir del juego%s\t\t %c\n",186,normal,verde,186);			
printf("   %s\\                                                  /%s		",gris,verde);									printf("\t\t\t%c\t\t\t\t\t %c\n",186,186);											
printf("%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%s	",azul,verde);									printf("\t\t\t%c",200);  for(int p=0; p<40; p++){printf("%c",205);} printf("%c\n",188);	

printf("\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s          _ ._  _ , _ ._\n",gris);
printf("\t\t\t\t\t\t\t\t\t\t\t                        %s /\\				\t\t\t        (_ ' ( `  )_  .__)\n",gris);
printf("\t\t\t\t\t\t\t\t\t\t\t                        /  \\				\t\t\t      ( (  (    )   `)  ) _)\n");
printf("\t\t\t\t\t\t\t\t\t\t\t                        \\   \\__			\t\t\t\t     (__ (_   (_ . _) _) ,__)\n");
printf("\t\t\t\t\t\t\t\t\t\t\t                         %s\\   \\%so%s\\			\t\t\t%s         `~~`\\ ' . /`~~`\n%s",gris,azul,gris,rojo,gris);
printf("\t\t\t\t\t\t\t\t\t\t\t                          %s\\   \\%so%s\\=		        \t\t\t%s              ;   ;%s\n"		,gris,azul,gris,rojo,gris);
printf("\t\t\t\t\t\t\t\t\t\t%s~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \t\t\t\t%s              /   \\	%s\n",azul,rojo,azul);
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~/~ ~~ \\~~~~~~~~~~~~~");
	//aqui pongan el switch pa elegir 










	
}


