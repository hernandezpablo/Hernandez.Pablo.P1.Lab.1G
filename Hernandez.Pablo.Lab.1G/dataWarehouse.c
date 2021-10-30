#include <string.h>
#include "dataWarehouse.h"


int idTipos [10] = {20000,20001,20000,20001,20001,20000,20002,20001,20002,20003};

int idAerolineas [10] = {1004,1002,1002,1004,1001,1003,1001,1000,1000,1003};

int capacidades [10] = {100,15,88,150,145,180,90,132,176,65};

int idPiloto [10] = {7004,7002,7002,7004,7001,7003,7001,7000,7000,7003};

int hardcodearAviones(eAvion aviones[], int tam, int cant, int* pId)
{
    int contador = -1;
    if (aviones != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            aviones[i].id = *pId;
            (*pId)++;
            aviones[i].idAerolinea = idAerolineas[i];
            aviones[i].idTipo = idTipos[i];
            aviones[i].capacidad = capacidades[i];
            aviones[i].idPiloto = idPiloto[i];
            aviones[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}

