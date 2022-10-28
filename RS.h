#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#define MAX 60
#include "Vendedores.h"
#include "lista.h"
float rscostA= 0.0,rscontA = 0.0,maxrsA = 0.0;
float rscostB= 0.0,ralcontB = 0.0,maxrsB = 0.0;
float rscostEvoc = 0.0,rscontEvoc = 0.0,rsmaxEvoc=0.0;
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
    while((*s).cur!=NULL && (*s).cur->vipd.documento!=dni){
        (*s).curaux=(*s).cur;
        (*s).cur=(*s).cur->ps;
    }
    if((*s).cur==NULL){
        return 0;
    }else{
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
            (*p).ps=NULL;
            (*p).vipd=dato;
            if((*s).arr[h].acc==(*s).cur){
                (*s).arr[h].acc=p;
            }else{
                (*s).curaux->ps=p;
            }
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
        if ((*s).arr[h].acc == (*s).cur) {
            (*s).arr[h].acc = (*s).cur->ps;
            free((void *) (*s).cur);
            (*s).cur = (*s).arr[h].acc;
            (*s).curaux = (*s).arr[h].acc;
        } else {
            (*s).curaux->ps = (*s).cur->ps;
            free((void *) (*s).cur);
            (*s).cur = (*s).cur->ps;
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
