#ifndef LSO2_H_INCLUDED
#define LSO2_H_INCLUDED
#define MAXIMO 111
#include "vendedores.h"
#include <math.h>
float lsocostA= 0.0,lsocontA = 0.0,maxlsoA = 0.0;
float lscostB= 0.0,lscontB = 0.0,maxlsoB = 0.0;
float lsocosEvoc = 0.0,lsocontEvoc = 0.0,lsomaxEvoc=0.0;
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
    float tempp =0.0;
    while((*lso).arr[i].documento<dni){
        lsocosEvoc++;
        tempp++;
        i++;
    }
    if(lsomaxEvoc<tempp){
        lsomaxEvoc = tempp;
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
    float tempp = 0.0;
    exito = localizarLSO(elem.documento,lso,&pos);
    if(exito == 0){
            if((*lso).cant<111){

                for(i=(*lso).cant-1;i>=pos;i--){
                    (*lso).arr[i+1]=(*lso).arr[i];
                    lsocostA +=1.5;
                    tempp+=1.5;
                }
                if(maxlsoA<tempp){
                    maxlsoA = tempp;
                }
                lsocontA++;
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
        float tempp = 0.0;
        for(i=pos;i<(*lso).cant-1;i++){
            (*lso).arr[i]=(*lso).arr[i+1];
            lscostB +=1.5;
            tempp +=1.5;
        }
        if(maxlsoB<temp){
            maxlsoB = tempp;
        }
        lscontB++;
        (*lso).cant--;
            return 1;
    }else{
        return 0;
    }
}

vendedor evocacion(listita lso,int dni){
    int pos;
    int exito=localizarLSO(dni,&lso,&pos);
    lsocontEvoc++;
    if (exito==1){
        return lso.arr[pos];
    }
}

#endif // LSO2_H_INCLUDED
