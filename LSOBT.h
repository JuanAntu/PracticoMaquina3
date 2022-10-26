#ifndef LSOBT_H_INCLUDED
#define LSOBT_H_INCLUDED
#define MAX 110
#include "vendedores.h"
#include <math.h>
typedef struct{
    vendedor arr[MAX];
    int cant;
}listabt;
void init(listabt *a){
    (*a).cant=0;
}
int localizarLSOBT(listabt *a,vendedor b, int *pos){
    float li=-1, ls=(*a).cant-1;
    while(li<ls){
        int medio = ceil((li+ls)/2);
        if(b.documento==(*a).arr[medio].documento){
            (*pos)=medio;
            return 1;
        }
        else if(b.documento<(*a).arr[medio].documento){
            ls=medio-1;
        }
        else{
            li=medio;
        }
    }
    (*pos)= ls + 1;
    return 0;
}
int altaLSOBT(listabt *lsobt,vendedor elem){
    int pos,exito,i;
    exito = localizarLSOBT(lsobt,elem,&pos);
    if(exito == 0){
            if((*lsobt).cant<110){
                for(i=(*lsobt).cant-1;i>=pos;i--){
                    (*lsobt).arr[i+1]=(*lsobt).arr[i];
                }
                (*lsobt).arr[pos] = elem ;
                (*lsobt).cant++;
                return 1;
            }else{
                return 0;
            }
    }else{
        return 0;
    }
}

int bajaLSOBT(listabt *lsobt,vendedor elem){
    int pos,exito,i=0,confirmar;
    exito = localizarLSOBT(lsobt,elem,&pos);
    if(exito==1){
            printf("Vendedor N:%d\n",pos+1);
            printf("%d \n",(*lsobt).arr[pos].documento);
            printf("%s \n",(*lsobt).arr[pos].nombreyapellido);
            printf("%s \n",(*lsobt).arr[pos].telefono);
            printf("%f \n",(*lsobt).arr[pos].monto);
            printf("%d \n",(*lsobt).arr[pos].cantidad);
            printf("%s \n",(*lsobt).arr[pos].canal);
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
                    for(i=pos;i<=(*lsobt).cant-1;i++){
                        (*lsobt).arr[i]=(*lsobt).arr[i+1];
                    }
                    (*lsobt).cant--;
                    return 1;
            }
    }else{
        return 0;
    }

}

vendedor evocacionlsobt(listabt lsobt,vendedor elem,int *exito){
    int pos;
    *exito=localizarLSOBT(&lsobt,elem,&pos);
    if (*exito==1){
        return lsobt.arr[pos];
    }
}
int pertenecelsobt(listabt lsobt,vendedor elem){
    int exito=0,pos;
    exito=localizarLSOBT(&lsobt,elem,&pos);
    if(exito==1){
        return 1;
    }else{
        return 0;
    }
}
#endif // LSOBT_H_INCLUDED
