#ifndef LSO2_H_INCLUDED
#define LSO2_H_INCLUDED
#define MAXIMO 111
#include "vendedores.h"
#include <math.h>
typedef struct{
    int cant;
    vendedor arr[MAXIMO];
}listita;

void inicializarlso(listita *lso){
    (*lso).cant=1;
    (*lso).arr[0].documento=100000000;
}

int localizarLSO(int dni,listita *lso,int *pos){
    int i=0;
    while((*lso).arr[i].documento<dni){
        i++;
    }
    *pos=i;
    if (dni == (*lso).arr[i].documento){
        return 1;
    }else{
        return 0;
    }
}

int altaLSO(listita *lso,vendedor elem){
    int pos,exito,i;
    exito = localizarLSO(elem.documento,lso,&pos);
    if(exito == 0){
            if((*lso).cant<111){
                for(i=(*lso).cant-1;i>=pos;i--){
                    (*lso).arr[i+1]=(*lso).arr[i];
                }
                (*lso).arr[pos] = elem;
                (*lso).cant++;
                return 1;
            }else{
                return 0;
            }
    }else{
        return 0;
    }
}

int bajaLSO(listita *lso,int dni){
    int pos,exito,i=0;
    exito = localizarLSO(dni,lso,&pos);
    if(exito==1){
        for(i=pos;i<(*lso).cant-1;i++){
            (*lso).arr[i]=(*lso).arr[i+1];
        }
        (*lso).cant--;
            return 1;
    }else{
        return 0;
    }
}

vendedor evocacion(listita lso,int dni){
    int pos;
    int exito=localizarLSO(dni,&lso,&pos);
    if (exito==1){
        return lso.arr[pos];
    }
}

#endif // LSO2_H_INCLUDED
