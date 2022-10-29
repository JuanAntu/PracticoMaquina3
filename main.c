#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ABB.h"
#include "vendedores.h"
#include "RAL.h"
#include "RS.h"
#include "LSO2.h"
#include "LSOBB2.h"
//GRUPO 5
//MARIANO ARBELOA GUGLIELMINO
//JUAN ANTU ARIAS
int main(){

    int opcion,opc;
    arbol arbol;
    ral r;
    rs s;
    listita lso;
    listabb lsobb;
    initABB(&arbol);
    initRAL(&r);
    initRS(&s);
    inicializarlso(&lso);
    init(&lsobb);
    memorizacionABB(&arbol,&s,&lso,&lsobb,&r);
    do{
        system("cls");
        printf("--Bienvenido al Sistema-- \n");
        printf("--Menu de opciones-- \n");
        printf("---------------------------------------------------------------- \n");
        printf("1. Comparar estructuras \n");
        printf("2. Mostrar RAL \n");
        printf("3. Mostrar RS \n");
        printf("4. Mostrar ABB \n");
        printf("5. Mostrar LSOBB \n");
        printf("6. Mostrar LSO \n");
        printf("7. Salir \n");
        printf("---------------------------------------------------------------- \n");
        printf("--Ingrese una opcion-- \n");
        scanf("%d",&opcion);
            switch (opcion){
                case 1:
                    system("cls");
                    printf(" ------------------------------------------------------------------------------------------------------------------ \n");
                    printf("        | Esf. Max. Alta | Esf. Med. Alta | Esf. Max. Baja | Esf. Med. Baja | Esf. Max. Evocar | Esf. Med. Evocar |\n");
                    printf(" ------------------------------------------------------------------------------------------------------------------ \n");
                    printf("  LSO   |     %.2f     |     %.2f      |     %.2f      |     %.2f      |      %.2f      |      %.2f       |\n",maxlsoA,(lsocostA/lsocontA),maxlsoB,(lscostB/lscontB),lsomaxEvoc,(lsocosEvoc/lsocontEvoc));
                    printf(" ------------------------------------------------------------------------------------------------------------------ \n");
                    printf(" LSOBB  |     %.2f     |     %.2f      |     %.2f     |     %.2f      |      %.2f        |      %.2f        |\n",maxlsbA,(lsbcostA/lsbcontA),maxlsbB,(lsbcostB/lsbcontB),lsbmaxEvoc,(lsbcosEvoc/lsbcontEvoc));
                    printf(" ------------------------------------------------------------------------------------------------------------------ \n");
                    printf("  ABB   |     1.00       |     %.2f       |     2.50       |     %.2f       |      %.2f       |      %.2f       |\n",(costAlta/contAlta),(costBaja/contBaja),maxEvoc,(costEvoc/contEvoc));
                    printf(" ------------------------------------------------------------------------------------------------------------------ \n");
                    printf("  RAL   |     1.50       |     1.50       |     1.50       |     1.50       |      %.2f       |      %.2f        |\n",ralmaxEvoc,(ralcostEvoc/ralcontEvoc));
                    printf(" ------------------------------------------------------------------------------------------------------------------ \n");

                    getchar();
                    getchar();
                    break;
                case 2:
                    system("cls");
                    muestraRAL(r);
                    break;
                case 3:
                    system("cls");
                    muestraRS(s);
                    break;
                case 4:
                    system("cls");
                    borrar(arbol.raiz);
                    preOrden(arbol.raiz);

                    break;
                case 5:
                    system("cls");
                        muestraLSOBB(lsobb);
                    break;
                case 6:
                    system("cls");
                        muestraLSO(lso);
                    break;
                case 7:
                    system("cls");
                    printf("Gracias por utilizar nuestro sistema");
                    exit(1);
                default:
                    system("cls");
                    printf("La opcion no es correcta");
                    getch();
                    break;
            }
    }while(opcion!=7);
    system("cls");
    return 0;
}
//ELIMINE CARGAS, ELIMINACION, MEMORIZAR Y DEMAS FUNCIONES QUE NO NOS SIRVEN
//ARBOL Y REBALSE SEPARADO Y LSO MUESTRAN 81 VENDEDORES
//RAL MUESTRA 91 Y LSOBB MUESTRA 110
//LA MEMORIZACION POR LO QUE SE VE FUNCIONA PERFECTAMENTE
void memorizacionABB(arbol *arbol, rs *s, listita *l, listabb *lbb, ral *r){
    FILE *archivo;
    int cont;
    vendedor vend;
    int documentoaux, aux;
    float montoaux;
    int cantidadaux;
    char auxc;
    char nombreyapellidoaux[50], canalaux[20], telefonoaux[15];
    char aux1[50],aux2[20],aux3[15];
    if((archivo=fopen("vendedores.txt","r"))==NULL){
        printf("No se puede ingresar al archivo\n");
    }else{
        rewind(archivo);
        while((feof(archivo))==0){
            fscanf(archivo,"%d",&aux);
            if(aux==1){
                fscanf(archivo,"%d",&documentoaux);
                vend.documento = documentoaux;
                fscanf(archivo,"%c",&auxc);
                fflush(stdin);
                fgets(nombreyapellidoaux,50,archivo);
                nombreyapellidoaux[strlen(nombreyapellidoaux)-1]='\0';
                strcpy(aux1,nombreyapellidoaux);
                strcpy(vend.nombreyapellido,aux1);
                fflush(stdin);
                fgets(telefonoaux,15,archivo);
                telefonoaux[strlen(telefonoaux)-1]='\0';
                strcpy(aux3,telefonoaux);
                strcpy(vend.telefono,aux3);
                fscanf(archivo,"%f",&montoaux);
                vend.monto = montoaux;
                fscanf(archivo,"%d",&cantidadaux);
                vend.cantidad = cantidadaux;
                fscanf(archivo,"%c",&auxc);
                fflush(stdin);
                fgets(canalaux,20,archivo);
                canalaux[strlen(canalaux)-1]='\0';
                strcpy(aux2,canalaux);
                strcpy(vend.canal,aux2);

                altaABB(arbol,vend);
                altaRS(s,vend);
                altaLSO(l,vend);
                altaLSOBB(lbb,vend);
                altaRAL(r,vend);

            }else if(aux==2){
                fscanf(archivo,"%d",&documentoaux);
                vend.documento = documentoaux;
                fscanf(archivo,"%c",&auxc);
                fflush(stdin);
                fgets(nombreyapellidoaux,50,archivo);
                nombreyapellidoaux[strlen(nombreyapellidoaux)-1]='\0';
                strcpy(aux1,nombreyapellidoaux);
                strcpy(vend.nombreyapellido,aux1);
                fflush(stdin);
                fgets(telefonoaux,15,archivo);
                telefonoaux[strlen(telefonoaux)-1]='\0';
                strcpy(aux3,telefonoaux);
                strcpy(vend.telefono,aux3);
                fscanf(archivo,"%f",&montoaux);
                vend.monto = montoaux;
                fscanf(archivo,"%d",&cantidadaux);
                vend.cantidad = cantidadaux;
                fscanf(archivo,"%c",&auxc);
                fflush(stdin);
                fgets(canalaux,20,archivo);
                canalaux[strlen(canalaux)-1]='\0';
                strcpy(aux2,canalaux);
                strcpy(vend.canal,aux2);

                bajaABB(arbol,vend.documento);
                bajaRS(s,vend.documento);
                bajaLSO(l,vend.documento);
                bajaLSOBB(lbb,vend.documento);
                bajaRAL(r,vend.documento);

            }else{
                fscanf(archivo,"%d",&documentoaux);
                vend.documento = documentoaux;

                evocacionABB(*arbol,vend.documento);
                evocacionRS(*s,vend.documento);
                evocacion(*l,vend.documento);
                evocacionlsobb(*lbb,vend.documento);
                evocacionRAL(*r,vend.documento);

            }
        }
        fclose(archivo);
    }
}

void muestraLSOBB(listabb lsobb){
    int j;
    if((lsobb).cant==0){
        printf("No hay vendedores en la lista");
    }else{
        getchar();
        for(j=0;j<(lsobb).cant;j++){
            printf("Vendedor N:%d\n",j+1);
            printf("%d \n",lsobb.arr[j].documento); //ROMPEMOS ENCAPSULAMIENTO POR PROBLEMAS DEL CODEBLOCKS
            printf("%s \n",lsobb.arr[j].nombreyapellido);
            printf("%s \n",lsobb.arr[j].telefono);
            printf("%f \n",lsobb.arr[j].monto);
            printf("%d \n",lsobb.arr[j].cantidad);
            printf("%s \n",lsobb.arr[j].canal);
            printf("---------------------------------------------------------------- \n");
            getchar();
        }
    }
}

void muestraLSO(listita lso){
    int j;
    if((lso).cant==1){
        printf("No hay vendedores ingresados");
    }else{
            getchar();
            for(j=0;j<(lso).cant-1;j++){
                printf("Vendedor N:%d\n",j+1);
                printf("%d \n",lso.arr[j].documento); //ROMPEMOS ENCAPSULAMIENTO POR PROBLEMAS DEL CODEBLOCKS
                printf("%s \n",lso.arr[j].nombreyapellido);
                printf("%s \n",lso.arr[j].telefono);
                printf("%f \n",lso.arr[j].monto);
                printf("%d \n",lso.arr[j].cantidad);
                printf("%s \n",lso.arr[j].canal);
                printf("---------------------------------------------------------------- \n");
                getchar();
        }
    }
}

void muestraRAL(ral r){
    int j;
    getchar();
    if(r.cant==0){
           printf("El rebalse esta vacio");
    }else{
        for(j=0;j<MAXI;j++){
            if(r.arr[j].documento==0){
                printf("Celda: %d\n",j);
                printf("Celda virgen\n");
                printf("---------------------------------------------------------------- \n");
                getchar();
            }else if(r.arr[j].documento==1){
                printf("Celda: %d\n",j);
                printf("Celda libre\n");
                printf("---------------------------------------------------------------- \n");
                getchar();
            }else{
                printf("Celda: %d\n",j);
                printf("%d \n",r.arr[j].documento);
                printf("%s \n",r.arr[j].nombreyapellido);
                printf("%s \n",r.arr[j].telefono);
                printf("%f \n",r.arr[j].monto);
                printf("%d \n",r.arr[j].cantidad);
                printf("%s \n",r.arr[j].canal);
                printf("---------------------------------------------------------------- \n");
                getchar();
            }
        }
    }
}

void muestraRS(rs s){
    int j;
    int contador=0;
    int cont=0;
    for(j=0;j<MAX;j++){
        if(s.arr[j].acc==NULL){
            contador++;
        }
    }
    if(contador==MAX){
            printf("La estructura esta vacia");
    }else{
        for(j=0;j<MAX;j++){
            s.cur=s.arr[j].acc;
            s.curaux=s.arr[j].acc;
            while(s.cur!=NULL) {
                printf("Lista N:%d\n",j);
                printf("%d \n", s.cur->vipd.documento);
                printf("%s \n", s.cur->vipd.nombreyapellido);
                printf("%s \n", s.cur->vipd.telefono);
                printf("%f \n", s.cur->vipd.monto);
                printf("%d \n", s.cur->vipd.cantidad);
                printf("%s \n", s.cur->vipd.canal);
                printf("---------------------------------------------------------------- \n");
                s.curaux=s.cur;
                s.cur=s.cur->ps;
                getchar();
            }
        }
    }
}
