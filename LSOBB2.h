#ifndef LSOBB2_H_INCLUDED
#define LSOBB2_H_INCLUDED
#define MAXIM 110
#include "vendedores.h"
#include <math.h>

float lsbcostA= 0.0,lsbcontA = 0.0,maxlsbA = 0.0;
float lsbcostB= 0.0,lsbcontB = 0.0,maxlsbB = 0.0;
float lsbcosEvoc = 0.0,lsbcontEvoc = 0.0,lsbmaxEvoc=0.0;

typedef struct{
    vendedor arr[MAXIM];
    int cant;
}listabb;

void init(listabb *a){
    (*a).cant=0;
}

int localizarLSOBB(listabb *a,int dni, int *pos){
    float li=0, ls=(*a).cant-1,tempp = 0.0;
    lsbcosEvoc++;
        tempp++;
    while(li<ls){
        lsbcosEvoc++;
        tempp++;
        int testigo = floor((li+ls)/2);
        if(dni<(*a).arr[testigo].documento){
            ls=testigo-1;
        }
        else{
            li=testigo+1;
        }
    }
    if(lsbmaxEvoc < tempp){
        lsbmaxEvoc = tempp;
    }
    lsbcontEvoc++;
    (*pos)=li;
    if(dni==(*a).arr[(int)li].documento){
        return 1;
    }else{
        return 0;
    }
}

int altaLSOBB(listabb *lsobb,vendedor elem){
    int pos,exito,i;
    float tempp = 0.0;
    exito = localizarLSOBB(lsobb,elem.documento,&pos);
    if(exito == 0){
            lsbcontA++;
            if((*lsobb).cant<110){
                for(i=(*lsobb).cant-1;i>=pos;i--){
                    (*lsobb).arr[i+1]=(*lsobb).arr[i];
                    lsbcostA+=1.5;
                    tempp+=1.5;
                }
                if(maxlsbA < tempp){
                    maxlsbA = tempp;
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

int bajaLSOBB(listabb *lsobb,int dni){
    int pos,exito,i=0;
    float tempp = 0.0;
    exito = localizarLSOBB(lsobb,dni,&pos);
    if(exito==1){
        lsbcontB++;
        for(i=pos;i<(*lsobb).cant-1;i++){
            (*lsobb).arr[i]=(*lsobb).arr[i+1];
            tempp+=1.5;
            lsbcostB+=1.5;
        }
        if(maxlsbB < tempp){
                    maxlsbB = tempp;
                }
        (*lsobb).cant--;
        return 1;
    }else{
        return 0;
    }

}

vendedor evocacionlsobb(listabb lsobb,int dni){
    int pos;
    int exito=localizarLSOBB(&lsobb,dni,&pos);

    if (exito==1){
        return lsobb.arr[pos];
    }
}

#endif // LSOBB2_H_INCLUDED
