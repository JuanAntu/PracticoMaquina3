#ifndef VENDEDORES_H_INCLUDED
#define VENDEDORES_H_INCLUDED
#include <string.h>
#include <conio.h>
#include <malloc.h>
typedef struct {
    int documento;
    float monto;
    int cantidad;
    char nombreyapellido[50];
    char canal[20];
    char telefono[15];
}vendedor;
//Inicializacion de vendedores
void initVendedores(vendedor *a){
    (*a).documento=0;
    (*a).monto=0.0;
    (*a).cantidad=0;
    strcpy((*a).nombreyapellido,"0");
    strcpy((*a).canal,"0");
    strcpy((*a).telefono,"0");
}

#endif // VENDEDORES_H_INCLUDED
