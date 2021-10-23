#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"

int buscarLibreVuelo(eVuelo vuelos[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (vuelos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int altaVuelo(eVuelo vuelos[], int tamv, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[], int tamT , eDestino destinos[], int tamD, int* pIdVuelo)
{
    int todoOk = 0;
    int indice;
    eVuelo auxVuelo;

    if (vuelos != NULL && tamv > 0 && aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && destinos != NULL && tamD > 0 && pIdVuelo != NULL && tipos != NULL && tamT >0 )
    {
        system("cls");
        printf("  ***Alta Vuelo*** \n\n");
        indice = buscarLibreVuelo(vuelos, tamv);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxVuelo.id = *pIdVuelo;
            (*pIdVuelo)++;

            mostrarAviones(aviones, tam, aerolineas, tamA, tipos, tamT);
            printf("Ingrese id de avion: ");
            scanf("%d", &auxVuelo.idAvion);

            while ( !validarIdAvion(auxVuelo.idAvion, aviones, tam) )
            {
                printf("Error, ingrese id de avion  valido: ");
                scanf("%d", &auxVuelo.idAvion);
            }

            mostrarDetinos(destinos, tamD);
            printf("Ingrese id de destino: ");
            scanf("%d", &auxVuelo.idDestino);

            while ( validarIdDestino(auxVuelo.idDestino, destinos, tamD) == -1 )
            {
                printf("Error, ingrese id de destino  valido: ");
                scanf("%d", &auxVuelo.idDestino);
            }

            printf("Ingrese fecha: ");
            scanf("%d/%d/%d", &auxVuelo.fecha.dia, &auxVuelo.fecha.mes, &auxVuelo.fecha.anio);

            auxVuelo.isEmpty = 0;

            vuelos[indice] = auxVuelo;

            todoOk = 1;
        }
    }
    return todoOk;


}
