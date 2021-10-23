#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aerolinea.h"


int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam,int idAerolinea, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (aerolineas != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (aerolineas[i].id == idAerolinea)
            {
                strcpy(descripcion, aerolineas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}
int mostrarAerolineas( eAerolinea aerolineas[], int tam )
{
    int todoOk = 0;
    if (aerolineas != NULL && tam > 0 )
    {
        printf("      *** Aerolineas *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", aerolineas[i].id, aerolineas[i].descripcion);
        }
        //printf("\n");
        todoOk = 1;
    }

    return todoOk;
}
int validarIdAerolinea( int id, eAerolinea aerolineas[], int tam )
{
    int esValido = 0;
    if (aerolineas != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == aerolineas[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
