#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include "fecha.h"
#include "avion.h"
#include "destino.h"

typedef struct{

    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;
}eVuelo;


#endif // VUELO_H_INCLUDED
int inicializarVuelos(eVuelo vuelos[], int tam);
int buscarLibreVuelo(eVuelo vuelos[], int tam);
int altaVuelo(eVuelo vuelos[], int tamv, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[], int tamT , eDestino destinos[], int tamD, int* pIdVuelo);
void mostrarVueloCompleto(eVuelo vuelos,int idAvion,eAvion aviones[],int tam ,eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, eDestino destinos[],int tamD);
int mostrarVuelosCompletos(eVuelo vuelos[], int tamV ,eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT, eDestino destinos[], int tamD);
