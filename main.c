#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ABB.h"
#include "vendedores.h"
#include "RAC.h"
#include "RS.h"
//GRUPO 5
//MARIANO ARBELOA GUGLIELMINO
//JUAN ANTU ARIAS
void cargaABB(arbol *);

void eliminarABB(arbol *);

void consultarVendABB(arbol);

void memorizacionABB(arbol *);

void cargaRAC(rac *);

void eliminarRAC(rac *);

void consultarVendRAC(rac);

void memorizacionRAC(rac *);

void muestraRAC(rac);

void cargaRS(rs *);

void muestraRS(rs);

void eliminarRS(rs *);

void consultarVendRS(rs);

void memorizacionRS(rs *);

int main(){
    int opcion,opc;
    arbol arbol;
    rac r;
    rs s;
    initABB(&arbol);
    initRAC(&r);
    initRS(&s);
    do{
        system("cls");
        printf("Seleccione la lista que desea utilizar \n");
        printf("<1> Arbol binario de busqueda \n");
        printf("<2> Rebalse abierto cuadratico \n");
        printf("<3> Rebalse separado\n");
        printf("<4> Salir\n");
        printf("Ingrese una opcion \n");
        scanf("%d",&opc);
        if(opc==1 || opc==2 || opc==3){
            do{
                system("cls");
                printf("--Bienvenido al Sistema-- \n");
                printf("--Menu de opciones-- \n");
                printf("---------------------------------------------------------------- \n");
                printf("1. Agregar vendedor \n");
                printf("2. Quitar vendedor \n");
                printf("3. Consultar vendedores \n");
                printf("4. Mostrar estructura \n");
                printf("5. Memorizacion previa \n");
                printf("6. Volver a elegir lista \n");
                printf("---------------------------------------------------------------- \n");
                printf("--Ingrese una opcion-- \n");
                scanf("%d",&opcion);
                switch (opcion) {
                    case 1:
                        system("cls");
                        if (opc==1) {
                            cargaABB(&arbol);
                        }else if (opc==2){
                            cargaRAC(&r);
                        }else{
                            cargaRS(&s);
                        }
                        getch();
                        break;
                    case 2:
                        system("cls");
                        if (opc==1) {
                            eliminarABB(&arbol);
                        }else if(opc==2){
                            eliminarRAC(&r);
                        }else{
                            eliminarRS(&s);
                        }
                        getch();
                        break;
                    case 3:
                        system("cls");
                        if (opc==1) {
                            consultarVendABB(arbol);
                        }else if(opc==2){
                            consultarVendRAC(r);
                        }else{
                            consultarVendRS(s);
                        }
                        getch();
                        break;
                    case 4:
                        system("cls");
                        if (opc==1) {
                            preOrden(arbol.raiz);
                        }else if(opc==2){
                            muestraRAC(r);
                        }else{
                            muestraRS(s);
                        }
                        getch();
                        break;
                    case 5:
                        system("cls");
                        if (opc==1) {
                            memorizacionABB(&arbol);
                        }else if(opc==2){
                            memorizacionRAC(&r);
                        }else{
                            memorizacionRS(&s);
                        }
                        getch();
                        break;
                    case 6:
                        system("cls");
                        opc=5;
                        break;
                    default:
                        system("cls");
                        printf("La opcion no es correcta");
                        getch();
                        break;
                }
            }while(opcion!=6);
        }else if(opc==4){
            system("cls");
            printf("Gracias por utilizar nuestro sistema");
            exit(1);
        }
    }while(opc!=4);
    system("cls");
    return 0;
}

void cargaABB(arbol *arbol){
    vendedor vend;
    int documentoaux;
    float montoaux;
    int cantidadaux;
    int contador=0;
    char nombreyapellidoaux[50], canalaux[20], telefonoaux[15];
    printf("Ingrese el numero de documento\n");
    scanf("%d",&documentoaux);
    while((documentoaux<0)||(documentoaux>99999999)){
        printf("Ingrese un numero de Documento valido:\n ");
        scanf("%d", &documentoaux);
    }
    vend.documento=documentoaux;
    printf("Ingrese el nombre y apellido del vendedor\n");
    fflush(stdin);
    scanf("%[^\n]s",nombreyapellidoaux);
    strcpy(vend.nombreyapellido,nombreyapellidoaux);
    printf("Ingrese el telefono\n");
    fflush(stdin);
    scanf("%[^\n]s", telefonoaux);
    strcpy(vend.telefono,telefonoaux);
    printf("Ingrese el monto vendido\n");
    scanf("%f",&montoaux);
    while((montoaux<0)){
        printf("Ingrese un monto valido:\n ");
        scanf("%f", &montoaux);
    }
    vend.monto = montoaux;
    printf("Ingrese la cantidad vendida\n");
    scanf("%d",&cantidadaux);
    while((cantidadaux<0)){
        printf("Ingrese una cantidad valida:\n ");
        scanf("%d", &cantidadaux);
    }
    vend.cantidad = cantidadaux;
    printf("Ingrese el canal de venta\n");
    fflush(stdin);
    scanf("%[^\n]s", canalaux);
    strcpy(vend.canal,canalaux);
    contador=altaABB(arbol,vend);
    printf("---------------------------------------------------------------- \n");
    if(contador==1){
        printf("Alta exitosa");
    }else if(contador<1){
        printf("El alta no fue exitosa");
    }else{
        printf("Alta no exitosa por estructura llena");
    }
}

void eliminarABB(arbol *a){
    int dni;
    int exito;
    printf("Ingrese el dni del vendedor que desea eliminar:\n");
    scanf("%d",&dni);
    exito=bajaABB(a,dni);
    if (exito==1){
        printf("Baja exitosa");
    }else if(exito==0){
        printf("Se cancelo la baja");
    }else{
        printf("No se encontro el vendedor");
    }
}

void consultarVendABB(arbol a){
    int exito,documento;
    vendedor vend;
    printf("Ingrese el documento del vendedor a consultar\n");
    scanf("%d",&documento);
    vend = evocacionABB(a,documento,&exito);
    if(exito==1){
        printf("%d \n",vend.documento);
        printf("%s \n",vend.nombreyapellido);
        printf("%s \n",vend.telefono);
        printf("%f \n",vend.monto);
        printf("%d \n",vend.cantidad);
        printf("%s \n",vend.canal);
    }else{
        printf("El vendedor no se encuentra en el registro\n");
    }
}

void memorizacionABB(arbol *arbol){
    FILE *archivo;
    int cont;
    vendedor vend;
    int documentoaux;
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
            cont=altaABB(arbol,vend);
            if(cont==2){
                printf("La estructura se lleno");
                break;
            }
        }
        printf("La operacion se ha realizado exitosamente.");
        fclose(archivo);
    }
}

void cargaRAC(rac *r){
    vendedor vend;
    int documentoaux;
    float montoaux;
    int cantidadaux;
    int contador=0;
    char nombreyapellidoaux[50], canalaux[20], telefonoaux[15];
    if((*r).cant==MAXI){
        printf("La estructura esta llena");
    }else{
        printf("Ingrese el numero de documento\n");
        scanf("%d",&documentoaux);
        while((documentoaux<1)||(documentoaux>99999999)){
            printf("Ingrese un numero de Documento valido:\n ");
            scanf("%d", &documentoaux);
        }
        vend.documento=documentoaux;
        printf("Ingrese el nombre y apellido del vendedor\n");
        fflush(stdin);
        scanf("%[^\n]s",nombreyapellidoaux);
        strcpy(vend.nombreyapellido,nombreyapellidoaux);
        printf("Ingrese el telefono\n");
        fflush(stdin);
        scanf("%[^\n]s", telefonoaux);
        strcpy(vend.telefono,telefonoaux);
        printf("Ingrese el monto vendido\n");
        scanf("%f",&montoaux);
        while((montoaux<0)){
            printf("Ingrese un monto valido:\n ");
            scanf("%f", &montoaux);
        }
        vend.monto = montoaux;
        printf("Ingrese la cantidad vendida\n");
        scanf("%d",&cantidadaux);
        while((cantidadaux<0)){
            printf("Ingrese una cantidad valida:\n ");
            scanf("%d", &cantidadaux);
        }
        vend.cantidad = cantidadaux;
        printf("Ingrese el canal de venta\n");
        fflush(stdin);
        scanf("%[^\n]s", canalaux);
        strcpy(vend.canal,canalaux);
        contador=altaRAC(r,vend);
        printf("---------------------------------------------------------------- \n");
        if(contador==1){
            printf("Alta exitosa\n");
        }else if(contador>1){
            printf("El alta no fue exitosa para ese vendedor\n");
        }else{
            printf("El alta no fue exitosa");
        }
    }
}

void eliminarRAC(rac *r){
    vendedor vend;
    int documento;
    int exito;
    if ((*r).cant==0){
        printf("No hay vendedores");
    }else{
        printf("Ingrese el DNI del vendedor que desea eliminar\n");
        scanf("%d",&documento);
        vend.documento = documento;
        system("cls");
        exito=bajaRAC(r,vend.documento);
        if(exito==1){
            printf("------------------------------------------\n");
            printf("Baja exitosa\n");
        }else if(exito==2){
            printf("------------------------------------------\n");
            printf("No se encuentra el vendedor\n");
        }else{
            printf("------------------------------------------\n");
            printf("Usted cancelo la baja del vendedor\n");
        }
    }
}

void consultarVendRAC(rac r){
    int exito,documento;
    vendedor vend;
    printf("Ingrese el documento del vendedor a consultar\n");
    scanf("%d",&documento);
    vend = evocacionRAC(r,documento,&exito);
    if(exito==1){
        printf("%d \n",vend.documento);
        printf("%s \n",vend.nombreyapellido);
        printf("%s \n",vend.telefono);
        printf("%f \n",vend.monto);
        printf("%d \n",vend.cantidad);
        printf("%s \n",vend.canal);
    }else{
        printf("El vendedor no se encuentra en el registro\n");
    }
}

void muestraRAC(rac r){
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

void memorizacionRAC(rac *r){
    FILE *archivo;
    vendedor vend;
    int documentoaux;
    float montoaux;
    int cantidadaux;
    char auxc;
    char nombreyapellidoaux[50], canalaux[20], telefonoaux[15];
    char aux1[50],aux2[20],aux3[15];
    if((*r).cant==MAXI){
        printf("La estructura esta llena");
    }else{
        if((archivo=fopen("vendedores.txt","r"))==NULL){
            printf("No se puede ingresar al archivo\n");
        }else{
            rewind(archivo);
            while((feof(archivo))==0){
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
                altaRAC(r,vend);
                if((*r).cant==MAXI){
                    printf("La estructura se lleno\n");
                    break;
                }
            }
            printf("La operacion se ha realizado exitosamente.");
            fclose(archivo);
        }
    }
}

void cargaRS(rs *s){
    vendedor vend;
    int documentoaux;
    float montoaux;
    int cantidadaux;
    int contador=0;
    char nombreyapellidoaux[50], canalaux[20], telefonoaux[15];
    printf("Ingrese el numero de documento\n");
    scanf("%d",&documentoaux);
    while((documentoaux<1)||(documentoaux>99999999)){
        printf("Ingrese un numero de Documento valido:\n ");
        scanf("%d", &documentoaux);
    }
    vend.documento=documentoaux;
    printf("Ingrese el nombre y apellido del vendedor\n");
    fflush(stdin);
    scanf("%[^\n]s",nombreyapellidoaux);
    strcpy(vend.nombreyapellido,nombreyapellidoaux);
    printf("Ingrese el telefono\n");
    fflush(stdin);
    scanf("%[^\n]s", telefonoaux);
    strcpy(vend.telefono,telefonoaux);
    printf("Ingrese el monto vendido\n");
    scanf("%f",&montoaux);
    while((montoaux<0)){
        printf("Ingrese un monto valido:\n ");
        scanf("%f", &montoaux);
    }
    vend.monto = montoaux;
    printf("Ingrese la cantidad vendida\n");
    scanf("%d",&cantidadaux);
    while((cantidadaux<0)){
        printf("Ingrese una cantidad valida:\n ");
        scanf("%d", &cantidadaux);
    }
    vend.cantidad = cantidadaux;
    printf("Ingrese el canal de venta\n");
    fflush(stdin);
    scanf("%[^\n]s", canalaux);
    strcpy(vend.canal,canalaux);
    contador=altaRS(s,vend);
    printf("---------------------------------------------------------------- \n");
    if(contador==1){
        printf("Alta exitosa");
    }else if(contador<1){
        printf("Alta no exitosa");
    }else{
        printf("Alta no exitosa por estructura llena");
    }
}

void eliminarRS(rs *s){
    int documento;
    int opc=1;
    int exito;
    int contador=0,j;
    for(j=0;j<MAX;j++){
        if((*s).arr[j].acc==NULL){
            contador++;
        }
    }
    if(contador==MAX){
            printf("La estructura esta vacia");
    }else{
            printf("Ingrese el DNI del vendedor que desea eliminar\n");
            scanf("%d",&documento);
            system("cls");
            exito=bajaRS(s,documento);
            if(exito==1){
                printf("------------------------------------------\n");
                printf("Baja exitosa\n");
            }else if(exito==2){
                printf("------------------------------------------\n");
                printf("No se encuentra el vendedor\n");
            }else{
                printf("------------------------------------------\n");
                printf("Usted cancelo la baja del vendedor\n");
        }
    }
}


void consultarVendRS(rs s){
    int exito,documento;
    vendedor vend;
    printf("Ingrese el documento del vendedor a consultar\n");
    scanf("%d",&documento);
    vend = evocacionRS(s,documento,&exito);
    if(exito==1){
        printf("%d \n",vend.documento);
        printf("%s \n",vend.nombreyapellido);
        printf("%s \n",vend.telefono);
        printf("%f \n",vend.monto);
        printf("%d \n",vend.cantidad);
        printf("%s \n",vend.canal);
    }else{
        printf("El vendedor no se encuentra en el registro\n");
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

void memorizacionRS(rs *s){
    FILE *archivo;
    vendedor vend;
    int cont=0;
    int documentoaux;
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
            cont=altaRS(s,vend);
            if(cont==2){
                printf("La estructura se lleno\n");
                break;
            }
        }
        printf("La operacion se ha realizado exitosamente.");
        fclose(archivo);
    }
}

