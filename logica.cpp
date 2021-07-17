#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void grid(int *coords[10]){
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0;i<10;i++){
        printf("%d ", i);
        for(int j=0;j<10;j++){
            if(coords[i][j]==6)printf("X ");//nave golpeada
            else if(coords[i][j]==7)printf("O ");//tiro fallido
            else if(coords[i][j]==1)printf("P ");//portaaviones
            else if(coords[i][j]==2)printf("B ");//buque
            else if(coords[i][j]==3)printf("S ");//submarino
            else if(coords[i][j]==4)printf("C ");//crucero
            else if(coords[i][j]==5)printf("L ");//lancha
            else printf("* ");//vacio
        }
        printf("\n");
    }
}

void place(int *coords[10]){
    int h, v, opc, tf=0, free=1;

    while(tf<1){//portaaviones
        system("cls");grid(coords);
        printf("Portaaviones(5):\n");
        printf("Coordenada X: ");scanf("%d",&v);
        printf("Coordenada Y: ");scanf("%d",&h);
        printf("1. Horizontal\n2. Vertical\n");scanf("%d",&opc);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else switch(opc){
            case 1:
                if(v>5){printf("Lugar no valido\n");system("PAUSE");}
                else{for(int i=0;i<5;i++)coords[h][v+i]=1;tf=1;}
            break;
            case 2:
                if(h>5){printf("Lugar no valido\n");system("PAUSE");}
                else{for(int i=0;i<5;i++)coords[h+i][v]=1;tf=1;}
            break;
            default:printf("Opcion no valida\n");system("PAUSE");break;
        }
    }

    tf=0;
    while(tf<1){//buque
        free=1;
        system("cls");grid(coords);
        printf("Buque(4):\n");
        printf("Coordenada X: ");scanf("%d",&v);
        printf("Coordenada Y: ");scanf("%d",&h);
        printf("1. Horizontal\n2. Vertical\n");scanf("%d",&opc);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else switch(opc){
            case 1:
                if(v>6){printf("Lugar no valido\n");system("PAUSE");}//si excede el numero de casillas que hay no se pone
                else{
                    for(int i=0;i<4;i++)if(coords[h][v+i]!=0)free=0;//checa si el lugar esta vacio o no
                    if(free==1){for(int i=0;i<4;i++)coords[h][v+i]=2;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }   
            break;
            case 2:
                if(h>6){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<4;i++)if(coords[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<4;i++)coords[h+i][v]=2;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            default:printf("Opcion no valida\n");system("PAUSE");break;
        }
    }

    tf=0;
    while(tf<1){//submarino
        free=1;
        system("cls");grid(coords);
        printf("Submarino(3):\n");
        printf("Coordenada X: ");scanf("%d",&v);
        printf("Coordenada Y: ");scanf("%d",&h);
        printf("1. Horizontal\n2. Vertical\n");scanf("%d",&opc);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else switch(opc){
            case 1:
                if(v>7){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<3;i++)if(coords[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<3;i++)coords[h][v+i]=3;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            case 2:
                if(h>7){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<3;i++)if(coords[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<3;i++)coords[h+i][v]=3;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            default:printf("Opcion no valida\n");system("PAUSE");break;
        }
    }

    tf=0;
    while(tf<1){//crucero
        free=1;
        system("cls");grid(coords);
        printf("Crucero(2):\n");
        printf("Coordenada X: ");scanf("%d",&v);
        printf("Coordenada Y: ");scanf("%d",&h);
        printf("1. Horizontal\n2. Vertical\n");scanf("%d",&opc);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else switch(opc){
            case 1:
                if(v>8){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<3;i++)if(coords[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<2;i++)coords[h][v+i]=4;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            case 2:
                if(h>8){printf("Lugar no valido\n");system("PAUSE");}
                else{
                    for(int i=0;i<2;i++)if(coords[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<2;i++)coords[h+i][v]=4;tf=1;}
                    else{printf("Lugar ocupado\n");system("PAUSE");}
                }
            break;
            default:printf("Opcion no valida\n");system("PAUSE");break;
        }
    }

    tf=0;
    while(tf<1){//lancha
        system("cls");grid(coords);
        printf("Lancha(1):\n");
        printf("Coordenada X: ");scanf("%d",&v);
        printf("Coordenada Y: ");scanf("%d",&h);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else{
            if(coords[h][v]!=0){printf("Lugar no valido\n");system("PAUSE");}
            else{coords[h][v]=5;tf=1;}
        }
    }
}

void autoplace(int *coords[10]){
    int h, v, opc, tf=0, free=1;

    while(tf<1){//portaaviones
        opc=1+rand()%2;
        v=rand()%10;
        h=rand()%10;
        //system("cls");grid(coords);printf("v%d h%d opc%d\n", v, h, opc);system("PAUSE");//pa ver que numeros genera
        switch(opc){
            case 1:
                if(v<5){for(int i=0;i<5;i++)coords[h][v+i]=1;tf=1;}
            break;
            case 2:
                if(h<5){for(int i=0;i<5;i++)coords[h+i][v]=1;tf=1;}
            break;
        }
    }

    tf=0;
    while(tf<1){//buque
        free=1;
        opc=1+rand()%2;
        v=rand()%10;
        h=rand()%10;
        //system("cls");grid(coords);printf("v%d h%d opc%d\n", v, h, opc);system("PAUSE");
        switch(opc){
            case 1:
                if(v<7){
                    for(int i=0;i<4;i++)if(coords[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<4;i++)coords[h][v+i]=2;tf=1;}
                }   
            break;
            case 2:
                if(h<7){
                    for(int i=0;i<4;i++)if(coords[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<4;i++)coords[h+i][v]=2;tf=1;}
                }
            break;
        }
    }

    tf=0;
    while(tf<1){//submarino
        free=1;
        opc=1+rand()%2;
        v=rand()%10;
        h=rand()%10;
        //system("cls");grid(coords);printf("v%d h%d opc%d\n", v, h, opc);system("PAUSE");
        switch(opc){
            case 1:
                if(v<8){
                    for(int i=0;i<3;i++)if(coords[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<3;i++)coords[h][v+i]=3;tf=1;}
                }   
            break;
            case 2:
                if(h<8){
                    for(int i=0;i<3;i++)if(coords[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<3;i++)coords[h+i][v]=3;tf=1;}
                }
            break;
        }
    }

    tf=0;
    while(tf<1){//crucero
        free=1;
        opc=1+rand()%2;
        v=rand()%10;
        h=rand()%10;
        //system("cls");grid(coords);printf("v%d h%d opc%d\n", v, h, opc);system("PAUSE");
        switch(opc){
            case 1:
                if(v<9){
                    for(int i=0;i<2;i++)if(coords[h][v+i]!=0)free=0;
                    if(free==1){for(int i=0;i<2;i++)coords[h][v+i]=4;tf=1;}
                }   
            break;
            case 2:
                if(h<9){
                    for(int i=0;i<2;i++)if(coords[h+i][v]!=0)free=0;
                    if(free==1){for(int i=0;i<2;i++)coords[h+i][v]=4;tf=1;}
                }
            break;
        }
    }

    tf=0;
    while(tf<1){//lancha
        v=rand()%10;
        h=rand()%10;
        //system("cls");grid(coords);printf("v%d h%d\n", v, h);system("PAUSE");
        if(coords[h][v]==0){coords[h][v]=5;tf=1;}
    }
}

int fire(int *player[10], int *ai[10], int *fake[10]){
    int h, v, tf=0, count=0;

    while(tf<1){
        system("cls");grid(player);printf("\n");grid(fake);
        //printf("\n");grid(ai);//hack pa ver el tablero oponente
        printf("Coordenada X a lanzar: ");scanf("%d",&v);
        printf("Coordenada Y a lanzar: ");scanf("%d",&h);
        if(v<0 || v>9 || h<0 || h>9){printf("Coordenadas invalidas\n");system("PAUSE");}
        else{
            if(ai[h][v]==6 || ai[h][v]==7){printf("Lugar ya golpeado\n");system("PAUSE");}
            else if(ai[h][v]!=0){
                printf("Hit!\n");system("PAUSE");
                ai[h][v]=6;fake[h][v]=6;count++;
                if(count==15)tf=1;
            }
            else{
                printf("Miss!\n");system("PAUSE");
                ai[h][v]=7;fake[h][v]=7;tf=1;
            }
        }
    }
    return count;
}

int autofire(int *player[10], int *fake[10]){
    int h, v, tf=0, count=0;

    while(tf<1){
        system("cls");grid(player);printf("\n");grid(fake);
        v=rand()%10;
        h=rand()%10;
        if(player[h][v]!=6 && player[h][v]!=7){
            printf("Cpu X: %d\nCpu Y: %d\n", v, h);
            if(player[h][v]!=0){
                printf("Cpu Hit!\n");system("PAUSE");
                player[h][v]=6;count++;
                if(count==15)tf=1;
            }
            else{
                printf("Cpu Miss!\n");system("PAUSE");
                player[h][v]=7;tf=1;
            }
        }
    }
    return count;
}

int round(int *player[10], int *ai[10], int *fake[10]){
    int win=0, lose=0, tf=0, wl;
    
    autoplace(ai);
    place(player);system("PAUSE");

    while(tf<1){
        win+=fire(player, ai, fake);
        if(win==15){printf("Ganaste!\n");system("PAUSE");tf=1;}
        printf("\n");
        lose+=autofire(player, fake);
        if(lose==15){printf("Perdiste!\n");system("PAUSE");tf=1;}
    }
    if(win==15)wl=1;
    else if(lose==15)wl=0;
    return wl;
}

int main(){
    srand(time(NULL));
    int *player[10], *ai[10], *fake[10], win;
    for(int i=0;i<10;i++){
        player[i]=(int*)malloc(10*sizeof(int));
        ai[i]=(int*)malloc(10*sizeof(int));
        fake[i]=(int*)malloc(10*sizeof(int));
    }
    for(int i=0;i<10;i++)for(int j=0;j<10;j++){
        player[i][j]=0;
        ai[i][j]=0;
        fake[i][j]=0;
    }

    win=round(player, ai, fake);
    if(win==1)printf("Ganaste 100 puntos\n");
    if(win==0)printf("no ganaste nada\n");

    system("PAUSE");return 0;
}
