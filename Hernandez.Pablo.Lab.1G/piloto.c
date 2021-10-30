#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piloto.h"


int cargarNombrePiloto(ePiloto pilotos[], int tam,int idPiloto, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if (pilotos != NULL && tam > 0 && nombre != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (pilotos[i].id == idPiloto)
            {
                strcpy(nombre, pilotos[i].nombre);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
int mostrarPilotos( ePiloto pilotos[], int tam )
{
    int todoOk = 0;
    if (pilotos != NULL && tam > 0 )
    {
        printf("      *** pilotos *** \n\n");
        printf("  Id         Nombre         Sexo\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s        %c\n", pilotos[i].id, pilotos[i].nombre, pilotos[i].sexo);
        }
        //printf("\n");
        todoOk = 1;
    }

    return todoOk;
}
int validarIdPiloto( int id, ePiloto pilotos[], int tam )
{
    int esValido = 0;
    if (pilotos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == pilotos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
