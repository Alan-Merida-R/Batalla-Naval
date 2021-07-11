#include<stdio.h>
#include<stdlib.h>

void grid(int);
int place(int);

void grid(int coords[10][10]){
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0;i<10;i++){
        printf("%d ",i);
        for(int j=0;j<10;j++){
            if(coords[i][j]==6)printf("X ");//nave golpeada
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

int place(int coords[10][10]){
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
        free=1;
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
    return coords[10][10];
}

int main(){
    int coords[10][10];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)coords[i][j]=0;
    coords[10][10]=place(coords);
    system("cls");grid(coords);
    system("PAUSE");return 0;
}

/*
portaaviones5 buque4 submarino3 crucero2 lancha1
*/