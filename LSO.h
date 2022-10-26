#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED
#define MAXIMO 111
#include "vendedores.h"
#include <math.h>
typedef struct{
    int cant;
    vendedor arr[MAXIMO];
}listita;

void inicializarlso(lista *lso){
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

int altaLSO(listitita *lso,vendedor elem){
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
    int pos,exito,i=0,confirmar;
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

vendedor evocacion(listita lso,int dni,int *exito){
    int pos;
    *exito=localizarLSO(dni,&lso,&pos);
    if (*exito==1){
        return lso.arr[pos];
    }
}

#endif // LSO_H_INCLUDED
