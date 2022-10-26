#ifndef LSOBB_H_INCLUDED
#define LSOBB_H_INCLUDED
#define MAXIM 110
#include "vendedores.h"
#include <math.h>
typedef struct{
    vendedor arr[MAXIM];
    int cant;
}listabb;

void init(listabbt *a){
    (*a).cant=0;
}

int localizarLSOBB(listabb *a,int dni, int *pos){
    float li=0, ls=(*a).cant-1;
    while(li<ls){
        int testigo = floor((li+ls)/2);
        if(b.documento<(*a).arr[testigo].documento){
            ls=testigo-1;
        }
        else{
            li=testigo+1;
        }
    }
    (*pos)=li;
    if(dni==(*a).arr[li].documento){
        return 1;
    }else{
        return 0;
    }
}

int altaLSOBT(listabb *lsobb,vendedor elem){
    int pos,exito,i;
    exito = localizarLSOBB(elem.documento,elem,&pos);
    if(exito == 0){
            if((*lsobt).cant<110){
                for(i=(*lsobb).cant-1;i>=pos;i--){
                    (*lsobb).arr[i+1]=(*lsobb).arr[i];
                }
                (*lsobb).arr[pos] = elem ;
                (*lsobb).cant++;
                return 1;
            }else{
                return 0;
            }
    }else{
        return 0;
    }
}

int bajaLSOBT(listabt *lsobb,int dni){
    int pos,exito,i=0,confirmar;
    exito = localizarLSOBB(lsobb,dni,&pos);
    if(exito==1){
        for(i=pos;i<(*lsobt).cant-1;i++){
            (*lsobt).arr[i]=(*lsobt).arr[i+1];
        }
        (*lsobt).cant--;
        return 1;
    }else{
        return 0;
    }

}

vendedor evocacionlsobb(listabb lsobb,int dni,int *exito){
    int pos;
    *exito=localizarLSOBT(&lsobt,dni,&pos);
    if (*exito==1){
        return lsobt.arr[pos];
    }
}

#endif // LSOBB_H_INCLUDED
