#ifndef RAL_H_INCLUDED
#define RAL_H_INCLUDED
#include "vendedores.h"
#define MAXI 149
//float ralcostA= 0.0,ralcontA = 0.0,maxralA = 0.0;
//float ralcostB= 0.0,ralcontB = 0.0,maxralB = 0.0;
float ralcostEvoc = 0.0,ralcontEvoc = 0.0,ralmaxEvoc=0.0;
typedef struct Ral{
    vendedor arr[MAXI];
    int cant;
}ral;

int hashing(int);

void initRAL(ral *r){
    int i;
    (*r).cant=0;
    for(i=0;i<MAXI;i++){
        (*r).arr[i].documento=0;
    }
}
int localizarRAL(ral *r,int dni,int *pos){
    int h=hashing(dni);
    int n=0;
    int contador=0;
    float tempp=0.0;
    ralcostEvoc++;
    tempp++;
    while(n<MAXI && (*r).arr[(h+n) % MAXI].documento!=0 && (*r).arr[(h+n) % MAXI].documento!=dni){
        if(contador==0 && (*r).arr[(h+n) % MAXI].documento==1){
            contador+=1;
            (*pos)=(h+n) % MAXI;
        }
        n++;
        ralcostEvoc++;
        tempp++;
    }
    ralcontEvoc++;
    if(ralmaxEvoc<tempp){
        ralmaxEvoc = tempp;
    }
    if(n==MAXI && contador==0){
        return 2;
    }else if(n==MAXI && contador==1){
        return 0;
    }
    if((*r).arr[(h+n) % MAXI].documento==0){
        if (contador==0){
            (*pos)=(h+n) % MAXI;
            return 0;
        }else{
            return 0;
        }
    }else if((*r).arr[(h+n) % MAXI].documento==dni){
        (*pos)=(h+n) % MAXI;
        return 1;
    }
}

int altaRAL(ral *r,vendedor dato){
    int pos,exito;
    if((*r).cant<MAXI){
        exito = localizarRAL(r, dato.documento, &pos);
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

int bajaRAL(ral *r,int dni){
    int pos,exito;
    exito=localizarRAL(r,dni,&pos);
    if(exito==1){
        (*r).arr[pos].documento=1;
        (*r).cant--;
        return 1;
    }else{
        return 0;
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

vendedor evocacionRAL(ral r,int dni){
    int pos;
    int exito=localizarRAL(&r,dni,&pos);
    if (exito==1){
        return r.arr[pos];
    }
}

#endif // RAL_H_INCLUDED
