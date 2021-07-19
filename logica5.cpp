#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define pause system("PAUSE");
#define clear system("cls");
#define notvalid default:printf("Opcion no valida\n");break;
#define scanopc scanf("%d",&opc);

typedef struct usuario{
    char nombre[25], password[25];
    int score, prizes;
}usuario;

int registerin();
int login();
void initialize(int ***p, int ***a, int ***f, int **ph, int **pm, int **ah);
void finalize(int ***p, int ***a, int ***f, int **ph, int **pm, int **ah);
void grid(int ***xy);
void place(int c, int ***p, int ***a);
void fire(int ***p, int ***a, int ***f, int **ph, int **pm, int **ah);//hack secreto aqui
int game();
void menu();

int registerin(){
    usuario u[50];
    int c=0, e=0, s=0, p=0, opc, tf=0, success=0;//c=count, e=exists, s=score, p=prizes
    char n[25], pw[25];//n=nombre, pw=password
    FILE *fp=fopen("batallanaval.txt","a");fclose(fp);

    fp=fopen("batallanaval.txt","r");while(feof(fp)==NULL){
        fscanf(fp,"%s",u[c].nombre);
        fscanf(fp,"%s",u[c].password);
        fscanf(fp,"%d",&u[c].score);
        fscanf(fp,"%d",&u[c].prizes);
        c++;
    }fclose(fp);
    //for(int i=0;i<c;i++)printf("U[%d].nombre: %s\nU[%d].pw: %s\nU[%d].score: %d\n",i, u[i].nombre, i, u[i].password, i, u[i].score);
    printf("Nombre de usuario: ");fflush(stdin);gets(n);
    for(int i=0;i<c;i++)if(strcmp(u[i].nombre, n)==0)e=1;
    if(e==1)while(tf<1){
            printf("Usuario ya existe, quieres registrar otro?\n1. Si\n2. No\n");scanopc
            switch(opc){
                case 1:tf=1;break;
                case 2:success=1;tf=1;break;
                notvalid
            }
        }
    else{
        printf("Password: ");fflush(stdin);gets(pw);
        fp=fopen("batallanaval.txt","a");
            fprintf(fp,"\n%s",n);
            fprintf(fp,"   %s",pw);
            fprintf(fp,"   %d",s);
            fprintf(fp,"   %d",p);
        fclose(fp);
        success=1;
    }
    return success;
}

int login(char **n, int **s){
    usuario u[50];
    int c=0, e=0, d=0, opc, tf=0, success=0, registered=0;//c=count, e=exists, d=denied, s=score
    char pw[25];//n=nombre, pw=password
    FILE *fp=fopen("batallanaval.txt","a");fclose(fp);

    fp=fopen("batallanaval.txt","r");while(feof(fp)==NULL){
        fscanf(fp,"%s",u[c].nombre);
        fscanf(fp,"%s",u[c].password);
        fscanf(fp,"%d",&u[c].score);
        fscanf(fp,"%d",&u[c].prizes);
        c++;
    }fclose(fp);
    //for(int i=0;i<c;i++)printf("U[%d].nombre: %s\nU[%d].pw: %s\nU[%d].score: %d\nu[%d].prizes: %d\n",i, u[i].nombre, i, u[i].password, i, u[i].score, i , u[i].prizes);
    printf("Nombre de usuario: ");fflush(stdin);gets(*n);
    for(int i=0;i<c;i++)if(strcmp(u[i].nombre, *n)==0)e=1;
    if(e==0)while(tf<1){
        printf("Usuario no registrado, quieres registrarlo?\n1. Si\n2. No\n");scanf("%d",&opc);
        switch(opc){
            case 1:while(registered<1)registered=registerin();success=1;tf=1;break;
            case 2:success=2;tf=1;break;
            default:printf("Opcion no valida\n");break;
        }
    }
    else while(d<1){
        printf("Password: ");fflush(stdin);gets(pw);
        for(int i=0;i<c;i++)if(strcmp(u[i].nombre, *n)==0 && strcmp(u[i].password, pw)==0){(**s)=u[i].score;d=1;}
        if(d==0)printf("Password incorrecto\n");
        else{printf("Bienvenido %s\n",*n);pause success=1;}
    }
    return success;
}

void update(char **n, int **s){
    usuario u[50];
    int c=0;//c=count, s=score

    FILE *fp=fopen("batallanaval.txt","r");while(feof(fp)==NULL){
        fscanf(fp,"%s",u[c].nombre);
        fscanf(fp,"%s",u[c].password);
        fscanf(fp,"%d",&u[c].score);
        fscanf(fp,"%d",&u[c].prizes);
        c++;
    }fclose(fp);

    fp=fopen("batallanaval.txt","w");for(int i=0;i<c;i++){
        if(strcmp(u[i].nombre, *n)==0){
            fprintf(fp,"\n%s",u[i].nombre);
            fprintf(fp,"   %s",u[i].password);
            fprintf(fp,"   %d",**s);
            fprintf(fp,"   %d",u[i].prizes);
        }
        else{
            fprintf(fp,"\n%s",u[i].nombre);
            fprintf(fp,"   %s",u[i].password);
            fprintf(fp,"   %d",u[i].score);
            fprintf(fp,"   %d",u[i].prizes);
        }
    }fclose(fp);
}

void initialize(int ***p, int ***a, int ***f, int **ph, int **pm, int **ah){
    *p=(int**)malloc(10*sizeof(int*));
    *a=(int**)malloc(10*sizeof(int*));
    *f=(int**)malloc(10*sizeof(int*));
    for(int i=0;i<10;i++){
        *(*p+i)=(int*)malloc(10*sizeof(int));
        *(*a+i)=(int*)malloc(10*sizeof(int));
        *(*f+i)=(int*)malloc(10*sizeof(int));
    }
    *ph=(int*)malloc(1*sizeof(int));
    *pm=(int*)malloc(1*sizeof(int));
    *ah=(int*)malloc(1*sizeof(int));
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        *(*(*p+i)+j)=0;
        *(*(*a+i)+j)=0;
        *(*(*f+i)+j)=0;
    }
    **ph=0;
    **pm=0;
    **ah=0;
}

void finalize(int ***p, int ***a, int ***f, int **ph, int **pm, int **ah){
    for(int i=0;i<10;i++){
        free(*(*p+i));
        free(*(*a+i));
        free(*(*f+i));
    }
    free(*p);
    free(*a);
    free(*f);
    free(*ph);
    free(*pm);
    free(*ah);
}

void grid(int ***xy){
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0;i<10;i++){
        printf("%d ", i);
        for(int j=0;j<10;j++)
        switch((*xy)[i][j]){
            case 1:printf("P ");break;//portaaviones
            case 2:printf("B ");break;//buque
            case 3:printf("S ");break;//submarino
            case 4:printf("C ");break;//crucero
            case 5:printf("L ");break;//lancha
            case 6:printf("X ");break;//nave golpeada
            case 7:printf("O ");break;//tiro fallido
            default:printf("* ");break;//vacio
        }
        printf("\n");
    }
}

void place(int c, int ***p, int ***a){
    int h, v, opc, tf=0, free;//h=horizontal, v=vertical, opc=opcion, tf=true/false, c=contador

    while(tf<1){//player
        free=1;
        system("cls");grid(p);
        switch(c){
            case 0:printf("Portaaviones(5):\n");break;
            case 1:printf("Buque(4):\n");break;
            case 2:printf("Crucero(3):\n");break;
            case 3:printf("Submarino(2):\n");break;
            case 4:printf("Lancha(1):\n");break;
        }
        printf("Coordenada X: ");scanf("%d",&v);
        printf("Coordenada Y: ");scanf("%d",&h);
        printf("1. Horizontal\n2. Vertical\n");scanf("%d",&opc);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else switch(opc){
            case 1:
                if(v>c+5){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<(c+5-(c*2));i++)if((*p)[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)(*p)[h][v+i]=c+1;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }   
            break;
            case 2:
                if(h>c+5){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<(c+5-(c*2));i++)if((*p)[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)(*p)[h+i][v]=c+1;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            default:printf("Opcion no valida\n");system("PAUSE");break;
        }
    }

    tf=0;while(tf<1){//ai
        free=1;
        v=rand()%10;
        h=rand()%10;
        opc=1+rand()%2;
        //system("cls");grid(a);printf("v%d h%d opc%d\n", v, h, opc);system("PAUSE");//pa ver que numeros genera
        switch(opc){
            case 1:
                if(v<c+6){
                    for(int i=0;i<(c+5-(c*2));i++)if((*a)[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)(*a)[h][v+i]=c+1;tf=1;}
                }
            break;
            case 2:
                if(h<c+6){
                    for(int i=0;i<(c+5-(c*2));i++)if((*a)[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)(*a)[h+i][v]=c+1;tf=1;}
                }
            break;
        }
    }
}

void fire(int ***p, int ***a, int ***f, int **ph, int **pm, int **ah){
    int h, v, tf=0, win=0;//h=horizontal, v=vertical, tf=true/false

    while(tf<1){//player
        system("cls");printf("Tu tablero:\n");grid(p);printf("\n");printf("Tablero del oponente:\n");grid(f);
        printf("\n");printf("Tablero del oponente (real):\n");grid(a);//hack pa ver el tablero oponente
        printf("Coordenada X a lanzar: ");scanf("%d",&v);
        printf("Coordenada Y a lanzar: ");scanf("%d",&h);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else{
            if((*a)[h][v]==6 || (*a)[h][v]==7){printf("Lugar ya golpeado\n");system("PAUSE");}
            else if((*a)[h][v]!=0){
                printf("Hit!\n");system("PAUSE");
                (*a)[h][v]=6;(*f)[h][v]=6;(**ph)++;
                if((**ph)==15){win=1;tf=1;}
            }
            else{
                printf("Miss!\n");system("PAUSE");
                (*a)[h][v]=7;(*f)[h][v]=7;(**pm)++;tf=1;
            }
        }
    }

    if(win<1){tf=0;while(tf<1){//ai
        system("cls");grid(p);printf("\n");grid(f);
        v=rand()%10;
        h=rand()%10;
        if((*p)[h][v]!=6 && (*p)[h][v]!=7){
            printf("Ai X: %d\nAi Y: %d\n", v, h);
            if((*p)[h][v]!=0){
                printf("Ai Hit!\n");system("PAUSE");
                (*p)[h][v]=6;(**ah)++;
                if((**ah)==15)tf=1;
            }
            else{
                printf("Ai Miss!\n");system("PAUSE");
                (*p)[h][v]=7;tf=1;
            }
        }
    }}
}

int game(){
    int **player, **ai, **fake, *playerhit, *playermiss, *aihit, tf=0, wl, score;//tf=true/false, wl=win/lose
    initialize(&player, &ai, &fake, &playerhit, &playermiss, &aihit);

    for(int i=0;i<5;i++)place(i, &player, &ai);
    while(tf<1){
        fire(&player, &ai, &fake, &playerhit, &playermiss, &aihit);
        if((*playerhit)==15){wl=1;tf=1;}
        if((*aihit)==15){wl=0;tf=1;}
    }
    if(wl==1)score=100-(*playermiss)-(*aihit);
    else score=(*playerhit);

    printf("Ganaste %d puntos\n",score);

    finalize(&player, &ai, &fake, &playerhit, &playermiss, &aihit);
    return score;
}

void menu(){
    int opc1, opc2, success=0;
    char *player=(char*)malloc(25*sizeof(char));
    int *score=(int*)malloc(1*sizeof(int));

    while(opc1!=4){
        printf("1. Register\n2. Login\n3. Ver premios\n4. Salir\n");scanf("%d",&opc1);
        switch(opc1){
            case 1:success=0;
                while(success<1)success=registerin();
            break;
            case 2:success=0;
                while(success==0)success=login(&player, &score);
                if(success==1){
                    while(opc2!=4){
                        printf("1. Jugar\n2. Ver stats\n3. Comprar premios\n4. Salir\n");scanf("%d",&opc2);
                        switch(opc2){
                            case 1:*score+=game();update(&player, &score);break;
                            case 2:break;
                            case 3:break;
                            case 4:break;
                            notvalid
                        }
                    }
                }
            break;
            case 3:break;
            default:break;
        }
    }
    free(player);
    free(score);
}

int main(){
    menu();
    pause return 0;
}
