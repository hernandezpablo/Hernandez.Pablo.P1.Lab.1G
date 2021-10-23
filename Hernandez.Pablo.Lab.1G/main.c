#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vuelo.h"
#include "avion.h"
#include "tipo.h"
#include "aerolinea.h"
#include "dataWarehouse.h"
#include "destino.h"
#define TAM 10
#define TAM_A 5
#define TAM_T 4
#define TAM_D 4
#define TAM_V 10

int main()
{
    char seguir = 's';
    char salir;
    int nextId = 10000;
    eAvion aviones[TAM];
    int IdVuelo = 8000;


    eAerolinea aerolineas[TAM_A] =
    {
        { 1000, "Lan" },
        { 1001, "Iberia" },
        { 1002, "Norwegian" },
        { 1003, "American" },
        { 1004, "Austral" }
    };

    eTipo tipos[TAM_T] =
    {
        { 20000, "Jet" },
        { 20001, "Helice" },
        { 20002, "Planeador" },
        { 20003, "Carga" }
    };
    eDestino destinos[TAM_D] =
    {
        { 5000, "Calafate", 22250 },
        { 5001, "Miami", 103000 },
        { 5002, "Madrid", 84400 },
        { 5003, "Amsterdam", 95600 }
    };

    if ( !inicializarAviones(aviones, TAM) )
    {
        printf("Error al iniciar personas\n");
    }



   do
    {
        switch (menu())
        {
        case 1:
            if(!altaAvion(aviones, TAM, aerolineas, TAM_A,tipos, TAM_T , &nextId))
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }
            break;
        case 2:
            if(!bajaAvion(aviones, TAM, aerolineas, TAM_A, tipos, TAM_T))
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;
        case 3:
            if(!modificarAvion(aviones, TAM, aerolineas, TAM_A, tipos, TAM_T))
            {
                printf("No se pudo modificar\n");
            }
            else
            {
                printf("Cambios realizados con exito\n");
            }
            break;

        case 4:
            ordenarAviones(aviones, TAM);
            system("cls");
            if ( !mostrarAviones(aviones, TAM, aerolineas, TAM_A, tipos, TAM_T) )
            {
                printf("No se pudieron mostrar los aviones\n");
            }
            break;
        case 5:
                 system("cls");
            if ( !mostrarAerolineas(aerolineas, TAM_A) )
            {
                printf("No se pudieron mostrar las aerolineas\n");
            }
            break;
        case 6:
               system("cls");
            if ( !mostrarTipos(tipos, TAM_T) )
            {
                printf("No se pudieron mostrar los tipos\n");
            }
            break;
        case 7:
               system("cls");
            if ( !mostrarDetinos(destinos, TAM_D) )
            {
                printf("No se pudieron mostrar los destinos\n");
            }
            break;
            /*case 8:

            if(!altaVuelo(vuelos, TAM_V,aviones, TAM ,aerolineas, TAM_A, tipos, TAM_T , &IdVuelo)
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }
            break;*/
        case 20:
            printf("Esta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");

    }
    while(seguir == 's');

    return 0;
}
