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
void barraSup();
void pantCompleta(); //Funcion que logra hacer que el programa se ejecute en pantalla completa (Solo windows)

//SE DEBE USAR PANTALLA COMPLETA ANTES DE ENTRAR A LA PANTALLA DE MENU PARA QUE LAS ANIMACIONES
//SE VEAN COMO SE DEBEN

int main(){ //Main para probar las animaciones BORRAR DESPUES 
	pantCompleta();
	aniLogo();
	barraSup();
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
printf("\033[0;32m");                                                                                                                                                                                                                                                                                                                                                                                                                                                        
printf("\t\t\t\t\t\t\t:::::::::      ::: ::::::::::: :::     :::        :::            :::   					\n");              
printf("\t\t\t\t\t\t\t:+:    :+:   :+: :+:   :+:   :+: :+:   :+:        :+:          :+: :+:               	\n");
printf("\t\t\t\t\t\t\t+:+    +:+  +:+   +:+  +:+  +:+   +:+  +:+        +:+         +:+   +:+              	\n");
printf("\t\t\t\t\t\t\t+#++:++#+  +#++:++#++: +#+ +#++:++#++: +#+        +#+        +#++:++#++:             	\n");
printf("\t\t\t\t\t\t\t+#+    +#+ +#+     +#+ +#+ +#+     +#+ +#+        +#+        +#+     +#+             	\n");
printf("\t\t\t\t\t\t\t#+#    #+# #+#     #+# #+# #+#     #+# #+#        #+#        #+#     #+#             	\n");
printf("\t\t\t\t\t\t\t#########  ###     ### ### ###     ### ########## ########## ###     ###             	\n");
printf("\t\t\t\t\t\t\t                          ::::    :::     :::     :::     :::     :::     :::        	\n");
printf("\t\t\t\t\t\t\t                          :+:+:   :+:   :+: :+:   :+:     :+:   :+: :+:   :+:        	\n");
printf("\t\t\t\t\t\t\t                          :+:+:+  +:+  +:+   +:+  +:+     +:+  +:+   +:+  +:+        	\n");
printf("\t\t\t\t\t\t\t                          +#+ +:+ +#+ +#++:++#++: +#+     +:+ +#++:++#++: +#+        	\n");
printf("\t\t\t\t\t\t\t                          +#+  +#+#+# +#+     +#+  +#+   +#+  +#+     +#+ +#+        	\n");
printf("\t\t\t\t\t\t\t                          #+#   #+#+# #+#     #+#   #+#+#+#   #+#     #+# #+#        	\n");
printf("\t\t\t\t\t\t\t                          ###    #### ###     ###     ###     ###     ### ########## 	\n");

                                                                                        
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
	
printf("    	   __					\n");
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
	
	char fuser[]={"Diego"}; int vidas=3;
	int BalaC=3; 
	int BalaM=1; 
	int BalaG=0;
	int puntos=100;
	printf("%c",201);  for(int p=0; p<209; p++){printf("%c",205);} printf("%c\n",187); printf("%c \t",186); //Parte de arriba del recuadro
		
	printf("Nombre: %s ", fuser); printf("\t\tVidas:");	for(int i=0; i<vidas; i++){printf("%c",3);}
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Balas: %i CH %c%c, %i M %c%c, %i G %c%c",BalaC,176,176,BalaM,177,177, BalaG,178,178);
	printf("\t\t     Puntos: %c%i\t  %c",36, puntos,186);
	printf("\n%c",200);  for(int p=0; p<209; p++){printf("%c",205);} printf("%c\n",188);	 //Parte de abajo del recuadro 
}


