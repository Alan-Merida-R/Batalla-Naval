#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initialize(int *p[10], int *a[10], int *f[10]){
 for(int i=0;i<10;i++){
        p[i]=(int*)malloc(10*sizeof(int));
        a[i]=(int*)malloc(10*sizeof(int));
        f[i]=(int*)malloc(10*sizeof(int));
    }
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        p[i][j]=0;
        a[i][j]=0;
        f[i][j]=0;
    }
}

void grid(int *coords[10]){
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0;i<10;i++){
        printf("%d ", i);
        for(int j=0;j<10;j++)switch(coords[i][j]){
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

void place(int c, int *p[10], int *a[10]){
    int h, v, opc, tf=0, free;

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
                    for(int i=0;i<(c+5-(c*2));i++)if(p[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)p[h][v+i]=c+1;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }   
            break;
            case 2:
                if(h>c+5){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<(c+5-(c*2));i++)if(p[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)p[h+i][v]=c+1;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            default:printf("Opcion no valida\n");system("PAUSE");break;
        }
    }

    tf=0;
    while(tf<1){//ai
        free=1;
        v=rand()%10;
        h=rand()%10;
        opc=1+rand()%2;
        //system("cls");grid(a);printf("v%d h%d opc%d\n", v, h, opc);system("PAUSE");//pa ver que numeros genera
        switch(opc){
            case 1:
                if(v<c+6){
                    for(int i=0;i<(c+5-(c*2));i++)if(a[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)a[h][v+i]=c+1;tf=1;}
                }
            break;
            case 2:
                if(h<c+6){
                    for(int i=0;i<(c+5-(c*2));i++)if(a[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<(c+5-(c*2));i++)a[h+i][v]=c+1;tf=1;}
                }
            break;
        }
    }
}

int pfire(int *p[10], int *a[10], int *f[10]){//hack secreto aqui
    int h, v, tf=0, c=0;

    while(tf<1){
        system("cls");printf("Tu tablero:\n");grid(p);printf("\n");printf("Tablero del oponente:\n");grid(f);
        //printf("\n");printf("Tablero del oponente (real):\n");grid(a);//hack pa ver el tablero oponente
        printf("Coordenada X a lanzar: ");scanf("%d",&v);
        printf("Coordenada Y a lanzar: ");scanf("%d",&h);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else{
            if(a[h][v]==6 || a[h][v]==7){printf("Lugar ya golpeado\n");system("PAUSE");}
            else if(a[h][v]!=0){
                printf("Hit!\n");system("PAUSE");
                a[h][v]=6;f[h][v]=6;c++;
                if(c==15)tf=1;
            }
            else{
                printf("Miss!\n");system("PAUSE");
                a[h][v]=7;f[h][v]=7;tf=1;
            }
        }
    }
    return c;
}

int afire(int *p[10], int *f[10]){
    int h, v, tf=0, c=0;

    while(tf<1){
        system("cls");grid(p);printf("\n");grid(f);
        v=rand()%10;
        h=rand()%10;
        if(p[h][v]!=6 && p[h][v]!=7){
            printf("Cpu X: %d\nCpu Y: %d\n", v, h);
            if(p[h][v]!=0){
                printf("Cpu Hit!\n");system("PAUSE");
                p[h][v]=6;c++;
                if(c==15)tf=1;
            }
            else{
                printf("Cpu Miss!\n");system("PAUSE");
                p[h][v]=7;tf=1;
            }
        }
    }
    return c;
}

int round(int *p[10], int *a[10], int *f[10]){
    int win=0, lose=0, tf=0, wl;
    
    for(int i=0;i<5;i++)place(i, p, a);

    while(tf<1){
        win+=pfire(p, a, f);
        if(win==15){printf("Ganaste!\n");system("PAUSE");tf=1;}
        printf("\n");
        lose+=afire(p, f);
        if(lose==15){printf("Perdiste!\n");system("PAUSE");tf=1;}
    }
    if(win==15)wl=1;
    else if(lose==15)wl=0;
    return wl;
}

int main(){
    int *player[10], *ai[10], *fake[10], win;
    initialize(player, ai, fake);
    round(player, ai, fake);
    system("PAUSE");return 0;
}
