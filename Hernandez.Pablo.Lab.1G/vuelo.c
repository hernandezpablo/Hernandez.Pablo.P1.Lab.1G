#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"

int inicializarVuelos(eVuelo vuelos[], int tam)
{
    int todoOk = 0;
    if (vuelos != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            vuelos[i].isEmpty = 1;
        }
    }
    return todoOk;
}

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
            while((auxVuelo.fecha.dia <1 || auxVuelo.fecha.dia > 31) || (auxVuelo.fecha.mes < 1 || auxVuelo.fecha.mes >12) || (auxVuelo.fecha.anio <2000 || auxVuelo.fecha.anio >3000))
            {
            printf(" Fecha invalida, por favor ingrese una fecha valida: (xx/xx/xxxx) ");
            scanf("%d/%d/%d", &auxVuelo.fecha.dia, &auxVuelo.fecha.mes, &auxVuelo.fecha.anio);
            }

            auxVuelo.isEmpty = 0;

            vuelos[indice] = auxVuelo;

            todoOk = 1;
        }
    }
    return todoOk;
}



void mostrarVueloCompleto(eVuelo vuelos,int idAvion,eAvion aviones[],int tam ,eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, eDestino destinos[],int tamD)
{
    char descAerolinea[20];
    char descTipo[20];
    char descDestino[20];
    int precio;
    int auxIdTipo;
    int auxIdAerolinea;

      if (buscarAvion(idAvion, aviones, tam, &auxIdAerolinea, &auxIdTipo) == 0){
        printf("No pudo encontrar avion");
      }


    if ( cargarDescripcionAerolinea( aerolineas, tamA, auxIdAerolinea, descAerolinea) == 1
        && (cargarDescripcionTipo(tipos, tamT, auxIdTipo, descTipo)) ==1 &&
        (cargarDescripcionDestino( destinos, tamD, vuelos.idDestino , descDestino, &precio) == 1) )

    {
        printf(" %d     %-10s       %-10s       %-10s       $%d              %2d/%2d/%4d\n",
               vuelos.id,
               descAerolinea,
               descTipo,
               descDestino,
               precio,
               vuelos.fecha.dia,
               vuelos.fecha.mes,
               vuelos.fecha.anio
               );
    }
    else{
            printf("Error al cargar el vuelo");

    }

}
int mostrarVuelosCompletos(eVuelo vuelos[], int tamV ,eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT, eDestino destinos[], int tamD)
{
    int todoOk = 0;
    int flag = 1;
    if ( vuelos != NULL && tamV > 0 && aviones != NULL && tam > 0 && destinos != NULL && tamD > 0 && aerolineas != NULL && tamA>0)
    {
        system("cls");
        printf("                     ***Lista de Vuelos  ***\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf(" ID         Aerolinea           TipoAvion           Destino         Precio         Fecha\n");
        printf("--------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < tamV; i++)
        {
            if (!vuelos[i].isEmpty)
            {
               mostrarVueloCompleto(vuelos[i],vuelos[i].idAvion,aviones, tam, aerolineas, tamA, tipos, tamT,destinos, tamD);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay Vuelos para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
