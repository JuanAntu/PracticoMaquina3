#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
typedef struct nodo{
    vendedor vipd;
    struct nodo *ps;
}Nodo;

typedef struct{
    Nodo *acc;
}lista;
#endif // LISTA_H_INCLUDED
