/*#include <string.h>
#include "dataWarehouse.h"
#include "avion.h"
#include "localidad.h"
char nombres[10][20] =
{
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};




float alturas[10] = {1.65,1.74,1.68,1.80,1.64,1.69,1.75,1.74,1.73,1.82};

int idAerolinea[10] = {1004,1002,003,1004,1003,001,1001,1000,1000,1003};

int hardcodearPersonas(ePersona lista[], int tam, int cant, int* pId)
{
    int contador = -1;
    if (lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo = sexos[i];
            lista[i].edad = edades[i];
            lista[i].altura = alturas[i];
            lista[i].idLocalidad = idLocalidades[i];
            lista[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
*/
