//Batalla naval por Equipo 5 : "Los piñeiros"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // Librería para la función system("clear")
#include <unistd.h> // Librería para la función sleep()

void login();
void aniInicial();
void aniAhorcado();
void AltEnter();


main(){

	login();
	aniInicial();
}


void login(){
char user[10], pass[10];
	system("COLOR C");
	printf("\t\t\t\t\t_________________________\n");
	printf("\t\t\t\t\t|\tBienvenido!      |\n");
	printf("\t\t\t\t\t-------------------------\n\n");	
	printf("\t\t\t\t\tAntes de empezar crea tu usuario\n\n");
	//metan el gestor de archivos aqui para que cree un archivo de guardado xfas
	//Pongan un IF de que si ya hay un archivo existente obtenga el nombre del usuario con el puntaje maximo guardado
	//y que si no pues que haga un archivo para guardar

    int size;
    printf("\t\t\t\t\tPorfavor ingresa un usario\n\n");
    printf("\t\t\t\t\tUsuario: ");
    gets(user);
    system("CLS");
 
 	printf("\t\t\t\t\t_________________________\n");
	printf("\t\t\t\t\t|\tBienvenido!      |\n");
	printf("\t\t\t\t\t-------------------------\n");  
    printf("\n\t\t\t\t\tPorfavor ingresa tu Password: \n"); 
	printf("\t\t\t\t\tUsuario: "); puts(user); printf("\n");
	printf("\t\t\t\t\tPassword: "); 
	gets(pass);
	system("CLS");
	//Aqui metan que se verifique que pass y user no sea el mismo 
	//y poner una condicion para que se ingresen el valor 
	
	//alerta de datos incorectos
	printf("\t\t\t\t\t__________________________________\n");
	printf("\t\t\t\t\t|\tUn error ah ocurrido      |\n");
	printf("\t\t\t\t\t----------------------------------\n\n");	
	printf("\t\t\t\t\tLos datos introducidos no son validos\n\n");
	
	
	printf("\n\t\t\t\t\tPerfecto! Es hora de empezar el juego!!\n");		
	sleep(3);
	system("CLS");
}

void aniInicial(){
	
	system("CLS"); // Para limpiar la pantalla despues de cada interacción con el juego
    printf("\033[5;3;1;35m"); // Códigos para darle formato, colores y animaciones a lo mostrado en pantalla
    // Pantalla de inicio
    printf("\n\n\n\n\n\t\t\t     A BADILLO'S PRODUCTION\n\n\n\n\t\t\t       POWERED BY ALAN\n\n\n\n\t\t\t\t ©2020 ENRIQUE-PINEIRO");
    
	printf("\n\n\n\n\t\t\t  PRESIONA ENTER PARA CONTINUAR...");
    printf("\033[0m"); // Códigos para restablecer el formato inicial, sino el resto del programa adopta el mismo formato declarado arriba
    getchar(); // Función para darle una pausa al programa hasta que el usuario presione Enter
	system("CLS");
	printf("BIENVENIDO A \n");


                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                 
printf("BBBBBBBBBBBBBBBBB                             tttt                            lllllll lllllll                      \n"); 
printf("B::::::::::::::::B                         ttt:::t                            l:::::l l:::::l                      \n");
printf("B::::::BBBBBB:::::B                        t:::::t                            l:::::l l:::::l                      \n");
printf("BB:::::B     B:::::B                       t:::::t                            l:::::l l:::::l                      \n");
printf("  B::::B     B:::::B  aaaaaaaaaaaaa  ttttttt:::::ttttttt      aaaaaaaaaaaaa    l::::l  l::::l   aaaaaaaaaaaaa      \n");
printf("  B::::B     B:::::B  a::::::::::::a t:::::::::::::::::t      a::::::::::::a   l::::l  l::::l   a::::::::::::a     \n");
printf("  B::::BBBBBB:::::B   aaaaaaaaa:::::at:::::::::::::::::t      aaaaaaaaa:::::a  l::::l  l::::l   aaaaaaaaa:::::a    \n");
printf("  B:::::::::::::BB             a::::atttttt:::::::tttttt               a::::a  l::::l  l::::l            a::::a    \n");
printf("  B::::BBBBBB:::::B     aaaaaaa:::::a      t:::::t              aaaaaaa:::::a  l::::l  l::::l     aaaaaaa:::::a    \n");
printf("  B::::B     B:::::B  aa::::::::::::a      t:::::t            aa::::::::::::a  l::::l  l::::l   aa::::::::::::a    \n");
printf("  B::::B     B:::::B a::::aaaa::::::a      t:::::t           a::::aaaa::::::a  l::::l  l::::l  a::::aaaa::::::a    \n");
printf("  B::::B     B:::::Ba::::a    a:::::a      t:::::t    tttttta::::a    a:::::a  l::::l  l::::l a::::a    a:::::a    \n");
printf("BB:::::BBBBBB::::::Ba::::a    a:::::a      t::::::tttt:::::ta::::a    a:::::a l::::::ll::::::la::::a    a:::::a    \n");
printf("B:::::::::::::::::B a:::::aaaa::::::a      tt::::::::::::::ta:::::aaaa::::::a l::::::ll::::::la:::::aaaa::::::a    \n");
printf("B::::::::::::::::B   a::::::::::aa:::a       tt:::::::::::tt a::::::::::aa:::al::::::ll::::::l a::::::::::aa:::a   \n");
printf("BBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaa         ttttttttttt    aaaaaaaaaa  aaaallllllllllllllll  aaaaaaaaaa  aaaa   \n");
                                                                                                                                                                                                                                 
printf("\n \n");                                                                                        
                                                                                        
printf("NNNNNNNN        NNNNNNNN                                                        lllllll  \n");
printf("N:::::::N       N::::::N                                                        l:::::l  \n");
printf("N::::::::N      N::::::N                                                        l:::::l  \n");
printf("N:::::::::N     N::::::N                                                        l:::::l  \n");
printf("N::::::::::N    N::::::N  aaaaaaaaaaaaavvvvvvv           vvvvvvvaaaaaaaaaaaaa    l::::l  \n");
printf("N:::::::::::N   N::::::N  a::::::::::::av:::::v         v:::::v a::::::::::::a   l::::l  \n");
printf("N:::::::N::::N  N::::::N  aaaaaaaaa:::::av:::::v       v:::::v  aaaaaaaaa:::::a  l::::l  \n");
printf("N::::::N N::::N N::::::N           a::::a v:::::v     v:::::v            a::::a  l::::l  \n");
printf("N::::::N  N::::N:::::::N    aaaaaaa:::::a  v:::::v   v:::::v      aaaaaaa:::::a  l::::l  \n");
printf("N::::::N   N:::::::::::N  aa::::::::::::a   v:::::v v:::::v     aa::::::::::::a  l::::l  \n");
printf("N::::::N    N::::::::::N a::::aaaa::::::a    v:::::v:::::v     a::::aaaa::::::a  l::::l  \n");
printf("N::::::N     N:::::::::Na::::a    a:::::a     v:::::::::v     a::::a    a:::::a  l::::l  \n");
printf("N::::::N      N::::::::Na::::a    a:::::a      v:::::::v      a::::a    a:::::a l::::::l \n");
printf("N::::::N       N:::::::Na:::::aaaa::::::a       v:::::v       a:::::aaaa::::::a l::::::l \n");
printf("N::::::N        N::::::N a::::::::::aa:::a       v:::v         a::::::::::aa:::al::::::l \n");
printf("NNNNNNNN         NNNNNNN  aaaaaaaaaa  aaaa        vvv           aaaaaaaaaa  aaaallllllll \n");
                                                                                        
                                                                                        
                                                                                        
                                                                                        
                                                                                        
                                                                                        
                                                                                        
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                 



}

 

