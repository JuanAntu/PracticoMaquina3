#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <string.h>
#include <conio.h>
#include "vendedores.h"
#include <malloc.h>
typedef struct Nodo{
    vendedor elem;
    struct Nodo *der;
    struct Nodo *izq;
}nodo;
typedef struct{
    nodo *raiz;
    nodo *pos;
    nodo *padre;
}arbol;
void initABB(arbol *a){
    (*a).pos=NULL;
    (*a).padre=NULL;
    (*a).raiz=NULL;
}
int localizarABB(arbol *a,int dni){
    a->pos = a->raiz;
    a->padre = a->raiz;
    while((*a).pos != NULL && (*a).pos->elem.documento != dni){
        if ((*a).pos->elem.documento > dni){
            (*a).padre = (*a).pos;
            (*a).pos = (*a).pos->izq;
        }else{
            (*a).padre = (*a).pos;
            (*a).pos = (*a).pos->der;
        }
    }
    if ((*a).pos == NULL){
        return 0;
    }else{
        return 1;
    }
}

int altaABB(arbol *a,vendedor dato){
    if (localizarABB(a,dato.documento)==0){
        nodo *nuevo_nodo;
        nuevo_nodo=(nodo*)malloc(sizeof(nodo));
        if(nuevo_nodo==NULL){
            return 2;
        }else{
            nuevo_nodo->elem=dato;
            nuevo_nodo->der=NULL;
            nuevo_nodo->izq=NULL;
            if((*a).padre==NULL){
                (*a).padre=nuevo_nodo;
                (*a).pos=(*a).padre;
                (*a).raiz=(*a).padre;
                return 1;
            }else if ((*a).padre->elem.documento < dato.documento){
                (*a).padre->der=nuevo_nodo;
                return 1;
            }else{
                (*a).padre->izq=nuevo_nodo;
                return 1;
            }
        }
    }else{
        return 0;
    }
}

int bajaABB(arbol *a,int dni){
    if(localizarABB(a,dni) == 0){
        return 2;
    }else{
        int op,c=0;
        nodo *aux,*padre;
        aux = a->pos;
        padre = (*a).pos;
        printf("%d \n",a->pos->elem.documento);
        printf("%s \n",a->pos->elem.nombreyapellido);
        printf("%s \n",a->pos->elem.telefono);
        printf("%f \n",a->pos->elem.monto);
        printf("%d \n",a->pos->elem.cantidad);
        printf("%s \n",a->pos->elem.canal);
        printf("Este es el vendedor que desea eliminar? (1)Si, (2)No.\n");
        scanf("%d",&op);
        while(op > 2 || op < 1){
            printf("Ingrese una respuesta valida.\n");
            scanf("%d",&op);
        }
        if(op == 1){
            if ((*a).pos->izq != NULL){
                if((*a).pos->der != NULL){//caso tiene los dos hijos
                    aux = (*a).pos->izq;
                    while(aux->der != NULL){
                        c++;
                        padre = aux;
                        aux = aux->der;
                    }
                    if(c == 0 )
                        {
                        padre->izq = aux->izq;
                        }
                    else
                        {
                        padre->der = aux->izq;
                        }

                    (*a).pos->elem = aux->elem;
                    free(aux);
                    return 1;
                }
                else{//caso tiene hi
                    aux = (*a).pos->izq;
                    if((*a).padre->izq == (*a).pos)
                        (*a).padre->izq = aux;
                    else if((*a).padre->der == (*a).pos)
                        (*a).padre->der = aux;
                    else
                        (*a).raiz = aux;
                    free(((*a).pos));
                    return 1;
                }
            }
            else if((*a).pos->der != NULL){//caso tiene hd
                    aux = (*a).pos->der;
                    if((*a).padre->izq == (*a).pos)
                        (*a).padre->izq = aux;
                    else if((*a).padre->der == (*a).pos)
                        (*a).padre->der = aux;
                    else
                        (*a).raiz = aux;

                    free(((*a).pos));
                    return 1;
            }
            else if((*a).padre == (*a).pos){
                (*a).raiz = NULL;
                free(aux);
                return 1;
            }
            else if((*a).padre->izq == (*a).pos){//no tiene hijos
                (*a).padre->izq = NULL;
                free(aux);
                return 1;
            }
            else{
                (*a).padre->der = NULL;
                free(aux);
                return 1;
            }
        }else{
            return 0;
        }
    }
}

vendedor evocacionABB(arbol a,int dni,int *exito){
    *exito=localizarABB(&a,dni);
    if(*exito==1){
        return a.pos->elem;
    }
}

void preOrden(nodo *a){
    if( a == NULL){
    }else{
        printf("%d \n", a->elem.documento);
        printf("%s \n",a->elem.nombreyapellido);
        printf("%s \n",a->elem.telefono);
        printf("%.2f \n",a->elem.monto);
        printf("%d \n",a->elem.cantidad);
        printf("%s \n",a->elem.canal);
        if( a->izq != NULL ){
            printf("\nEl Dni de su hijo izquierdo es: %d",a->izq->elem.documento);
        }else{
            printf("\nNo tiene hijo izquierdo.");
        }

        if(a->der != NULL){
            printf("\nEl Dni de su hijo derecho es: %d",a->der->elem.documento);
        }else
            printf("\nNo tiene hijo derecho.");
        printf("\n--------------------------------------------\n");
        getchar();
        preOrden(a->izq);
        preOrden(a->der);
    }
}
#endif // ABB_H_INCLUDED