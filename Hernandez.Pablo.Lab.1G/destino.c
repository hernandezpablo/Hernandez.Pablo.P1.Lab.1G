#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int mostrarDetinos( eDestino destinos[], int tam )
{
    int todoOk = 0;
    if (destinos != NULL && tam > 0 )
    {
        printf("      *** Destinos *** \n\n");
        printf("  Id         Descripcion       Precio\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s        %d\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        //printf("\n");
        todoOk = 1;
    }
}
int validarIdDestino( int id, eDestino destinos[], int tam )
{
    int esValido = 0;
    if (destinos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == destinos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

