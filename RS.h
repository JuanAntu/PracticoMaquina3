#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#define MAX 60
#include "Vendedores.h"
#include "lista.h"
//float rscostA= 0.0,rscontA = 0.0,maxrsA = 0.0; siempre va a ser 2 ya que nuestra funcion de costo es cantidad de cambio de punteros.
float rscostB= 0.0,rscontB = 0.0;//no necesita calcularse el max ya q se va a dar cuando debamos realizar dos modificaciones de punteros.
float rscostEvoc = 0.0,rscontEvoc = 0.0,rsmaxEvoc=0.0;
float rscostEvocf = 0.0,rscontEvocf = 0.0,rsmaxEvocf=0.0;
typedef struct RS{
    lista arr[MAX];
    Nodo *cur;
    Nodo *curaux;
}rs;

int hashingRS(int);

void initRS(rs *s){
    int i;
    for(i=0;i<MAX;i++){
        (*s).arr[i].acc=NULL;
    }
    (*s).cur=(*s).arr[0].acc;
    (*s).curaux=(*s).arr[0].acc;
}

int localizarRS(rs *s,int dni,int *h){
    (*h)= hashingRS(dni);
    (*s).cur=(*s).arr[(*h)].acc;
    float tempp = 0.0;
    tempp++;
    while((*s).cur!=NULL && (*s).cur->vipd.documento!=dni){
        (*s).curaux=(*s).cur;
        (*s).cur=(*s).cur->ps;
        tempp++;

    }

    if((*s).cur==NULL){

        if(rsmaxEvocf<tempp)
            rsmaxEvocf = tempp;
        rscostEvocf+=tempp;
        rscontEvocf++;

        return 0;
    }else{
        if(rsmaxEvoc<tempp)
            rsmaxEvoc = tempp;
        rscostEvoc+=tempp;
        rscontEvoc++;

        return 1;
    }
}

int altaRS(rs *s,vendedor dato){
    int h;
    int exito = localizarRS(s,dato.documento,&h);
    if(exito==0){
        Nodo *p=(Nodo*)malloc(sizeof(Nodo));
        if(p==NULL){
            return 2;
        }else{
            (*p).ps=(*s).arr[h].acc;
            (*p).vipd=dato;
            (*s).arr[h].acc=p;
            return 1;
            }
    }else{
        return 0;
    }
}

int bajaRS(rs *s, int dni) {
    int pos,exito;
    int h;
    exito = localizarRS(s, dni,&h);
    if (exito == 1) {

        rscontB++;
        if ((*s).arr[h].acc == (*s).cur) {
            (*s).arr[h].acc = (*s).cur->ps;
            free((void *) (*s).cur);
            (*s).cur = (*s).arr[h].acc;
            (*s).curaux = (*s).arr[h].acc;
            rscostB++;
        } else {
            (*s).curaux->ps = (*s).cur->ps;
            free((void *) (*s).cur);
            (*s).cur = (*s).cur->ps;
            rscostB++;
        }
        return 1;
    }else{
        return 0;
    }
}


vendedor evocacionRS(rs s,int dni){
    int h;
    int exito=localizarRS(&s,dni,&h);
    if (exito==1){
        return s.cur->vipd;
    }
}
void borrarRS(rs *s){
    int j;
    for(j=0;j<MAX;j++){
            (*s).cur=(*s).arr[j].acc;
            (*s).curaux=(*s).arr[j].acc;
            while((*s).cur!=NULL){
                (*s).curaux=(*s).cur;
                (*s).cur=(*s).cur->ps;
                free((*s).curaux);
            }
    }
}


int hashingRS (int dni) {
    char x[8];
    int longitud,i;
    int contador = 0;
    sprintf (x,"%d",dni) ;
    longitud = strlen(x) ;
    for (i = 0; i < longitud; i++)
        contador +=((int)x[i]) * (i + 1);
    return (contador%MAX);
}
#endif // RS_H_INCLUDED
