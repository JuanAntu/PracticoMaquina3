#ifndef COSTOS_H_INCLUDED
#define COSTOS_H_INCLUDED
typedef struct Costo{
    float costAlta,contAlta,maxAlta;
    float costBaja,contBaja,maxBaja;
    float costEvoc,contEvoc,maxEvoc;
}costo;


void initcostos(costo c){
    c.contAlta=c.contBaja=c.contEvoc=0.0;
    c.costAlta=c.costBaja=c.costEvoc=0.0;
    c.maxAlta=c.maxBaja=c.maxEvoc=0.0;
}
#endif // COSTOS_H_INCLUDED
