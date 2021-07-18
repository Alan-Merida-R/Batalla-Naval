#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct usuario{
    char nombre[25], password[25];
    int score;
}usuario;

void login(){
    usuario u[100];
    int c=0, r=0, d=0;//c=count, r=registered, d=denied
    char n[25], pw[25];//n=nombre, pw=password
    FILE *fp=fopen("batallanaval.txt","a");fclose(fp);

    fp=fopen("batallanaval.txt","r");
    while(feof(fp)==NULL){
        fscanf(fp,"%s",u[c].nombre);
        fscanf(fp,"%s",u[c].password);
        fscanf(fp,"%d",&u[c].score);
        c++;
    }fclose(fp);
    //for(int i=0;i<c;i++)printf("U[%d].nombre: %s\nU[%d].pw: %s\nU[%d].score: %d\n",i, u[i].nombre, i, u[i].password, i, u[i].score);
    printf("Nombre de usuario: ");fflush(stdin);gets(n);
    for(int i=0;i<c;i++)if(strcmp(u[i].nombre, n)==0)r=1;
    if(r==0)printf("Usuario no registrado\n");
    else{
        printf("Password: ");fflush(stdin);gets(pw);
        for(int i=0;i<c;i++)if(strcmp(u[i].nombre, n)==0 && strcmp(u[i].password, pw)==0)d=1;
        if(d==0)printf("Password incorrecto\n");
        else printf("c:\n");
    }
}

void registerin(){
    usuario u[100];
    int c=0, r=0, s=0;//c=count, r=registered, s=score
    char n[25], pw[25];//n=nombre, pw=password
    FILE *fp=fopen("batallanaval.txt","a");fclose(fp);

    fp=fopen("batallanaval.txt","r");
    while(feof(fp)==NULL){
        fscanf(fp,"%s",u[c].nombre);
        fscanf(fp,"%s",u[c].password);
        fscanf(fp,"%d",&u[c].score);
        c++;
    }fclose(fp);
    //for(int i=0;i<c;i++)printf("U[%d].nombre: %s\nU[%d].pw: %s\nU[%d].score: %d\n",i, u[i].nombre, i, u[i].password, i, u[i].score);
    printf("Nombre de usuario: ");fflush(stdin);gets(n);
    for(int i=0;i<c;i++)if(strcmp(u[i].nombre, n)==0)r=1;
    if(r==1)printf("Usuario ya existe\n");
    else{
        printf("Password: ");fflush(stdin);gets(pw);
        fp=fopen("batallanaval.txt","a");
            fprintf(fp,"\n%s",n);
            fprintf(fp,"   %s",pw);
            fprintf(fp,"   %d",s);
        fclose(fp);
    }
}

int main(){
    int opc;
    while(opc!=3){
        printf("1. Registrar\n2. Login\n3. Salir\n");scanf("%d",&opc);
        switch(opc){
            case 1:registerin();break;
            case 2:login();break;
            case 3:break;
            default:break;
        }
    }
    system("PAUSE");return 0;
}
