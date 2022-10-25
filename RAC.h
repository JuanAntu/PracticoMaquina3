#ifndef RAC_H_INCLUDED
#define RAC_H_INCLUDED
#include "vendedores.h"
#define MAXI 110
typedef struct Rac{
    vendedor arr[MAXI];
    int cant;
}rac;

int hashing(int);

void initRAC(rac *r){
    int i;
    (*r).cant=0;
    for(i=0;i<MAXI;i++){
        (*r).arr[i].documento=0;
    }
}
int localizarRAC(rac *r,int dni,int *pos){
    int h=hashing(dni);
    int n=0;
    int i=0;
    int contador=0;
    while(n<MAXI && (*r).arr[(h+i) % MAXI].documento!=0 && (*r).arr[(h+i) % MAXI].documento!=dni){
        if(contador==0 && (*r).arr[(h+i) % MAXI].documento==1){
            contador+=1;
            (*pos)=(h+i) % MAXI;
        }
        n++;
        i+=n;
    }
    if(n==MAXI && contador==0){
        return 2;
    }else if(n==MAXI && contador==1){
        return 0;
    }
    if((*r).arr[(h+i) % MAXI].documento==0){
        if (contador==0){
            (*pos)=(h+i) % MAXI;
            return 0;
        }else{
            return 0;
        }
    }else if((*r).arr[(h+i) % MAXI].documento==dni){
        (*pos)=(h+i) % MAXI;
        return 1;
    }
}

int altaRAC(rac *r,vendedor dato){
    int pos,exito;
    if((*r).cant<MAXI){
        exito = localizarRAC(r, dato.documento, &pos);
        if (exito == 0) {
            (*r).arr[pos] = dato;
            (*r).cant++;
            return 1;
        } else if(exito == 2){
            return 2;
        }else {
            return 0;
        }
    }else{
        return 0;
    }
}

int bajaRAC(rac *r,int dni){
    int pos,exito,confirmar;
    exito=localizarRAC(r,dni,&pos);
    if(exito==1){
        printf("Vendedor N:%d\n",pos+1);
        printf("%d \n",(*r).arr[pos].documento);
        printf("%s \n",(*r).arr[pos].nombreyapellido);
        printf("%s \n",(*r).arr[pos].telefono);
        printf("%f \n",(*r).arr[pos].monto);
        printf("%d \n",(*r).arr[pos].cantidad);
        printf("%s \n\n",(*r).arr[pos].canal);
        printf("Es el elemento que desea dar de baja?\n");
        printf("<1>SI\n");
        printf("<2>NO\n");
        scanf("%d",&confirmar);
        while(confirmar<1||confirmar>2){
            printf("Ingrese correctamente");
            printf("<1>SI\n");
            printf("<2>NO\n");
            scanf("%d",&confirmar);
        }
        if(confirmar==1){
            (*r).arr[pos].documento=1;
            (*r).cant--;
            return 1;
        }else{
            return 0;
        }
    }else{
        return 2;
    }
}

int hashing (int dni) {
    char x[8];
    int longitud,i;
    int contador = 0;
    sprintf (x,"%d",dni) ;
    longitud = strlen(x) ;
    for (i = 0; i < longitud; i++)
        contador +=((int)x[i]) * (i + 1);
    return (contador % MAXI);
}

vendedor evocacionRAC(rac r,int dni,int *exito){
    int pos;
    *exito=localizarRAC(&r,dni,&pos);
    if (*exito==1){
        return r.arr[pos];
    }
}
#endif // RAC_H_INCLUDED
