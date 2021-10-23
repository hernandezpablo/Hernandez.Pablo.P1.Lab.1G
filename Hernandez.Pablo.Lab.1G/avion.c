#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "avion.h"


int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** ABM Personas ***\n");
    printf("  1- Alta Avion\n");
    printf("  2- Baja Avion\n");
    printf("  3- Modificar Avion\n");
    printf("  4- Listar Aviones\n");
    printf("  5- Listar Aerolineas\n");
    printf("  6- Listar Tipos\n");
    printf("  7- Listar Destinos\n");
    printf("  8- Alta Vuelos\n");
    printf("  9- Mostrar personas por localidad\n");
    printf("  20- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}


int inicializarAviones(eAvion aviones[], int tam)
{
    int todoOk = 0;
    if (aviones != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            aviones[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibre(eAvion aviones[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (aviones[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    char descAerolinea[20];
    char descTipo[20];

    if ( cargarDescripcionAerolinea( aerolineas, tamA, aviones.idAerolinea, descAerolinea) == 1
        && (cargarDescripcionTipo(tipos, tamT, aviones.idTipo, descTipo)) ==1)
        //&&(cargarDescripcionTipo(tipos, tamT,aviones.idTipo, descTipo) ==1))
    {
        printf(" %d     %-10s       %-10s        %d\n",
               aviones.id,
               descAerolinea,
               descTipo,
               aviones.capacidad
               );
    }

}
int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA>0 && tipos != NULL && tamT >0)
    {
        system("cls");
        printf("                     ***Lista de Aviones  ***\n");
        printf("------------------------------------------------------------\n");
        printf(" ID         Aerolinea           Tipo         Capacidad\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!aviones[i].isEmpty)
            {
                mostrarAvion(aviones[i], aerolineas, tamA, tipos, tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay Aviones para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
int altaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[],int tamT ,int* pId)
{
    int todoOk = 0;
    int indice;
    eAvion auxAvion;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA>0 && tipos != NULL && tamT>0)
    {
        system("cls");
        printf("  ***Alta Avion*** \n\n");
        indice = buscarLibre(aviones, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxAvion.id = *pId;
            (*pId)++;

            mostrarAerolineas(aerolineas, tamA);
            printf("Ingrese id de Aerolinea: ");
            scanf("%d", &auxAvion.idAerolinea);

            while ( !validarIdAerolinea(auxAvion.idAerolinea, aerolineas, tamA) )
            {
                printf("Error, ingrese id de aerolinea valido: ");
                scanf("%d", &auxAvion.idAerolinea);
            }
            mostrarTipos(tipos, tamT);
            printf("Ingrese id del Tipo: ");
            scanf("%d", &auxAvion.idTipo);

            while ( !validarIdTipo(auxAvion.idTipo, tipos, tamT) )
            {
                printf("Error, ingrese id de tipo valido: ");
                scanf("%d", &auxAvion.idTipo);
            }

            printf("Ingrese capacidad: ");
            scanf("%d", &auxAvion.capacidad);
            while (auxAvion.capacidad < 10 || auxAvion.capacidad > 300){
                printf("Por favor ingrese una cantidad de pasajeros valido: (Entre 10 y 300)\n");
                scanf("%d", &auxAvion.capacidad);
            }

            auxAvion.isEmpty = 0;

            aviones[indice] = auxAvion;

            todoOk = 1;
        }
    }
    return todoOk;
}
int buscarAvionId(eAvion aviones[], int tam, int Id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (aviones[i].id == Id && aviones[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA >0 && tipos != NULL && tamT >0)
    {
        system("cls");
        printf("   *** Baja Avion *** \n\n");
        mostrarAviones(aviones, tam, aerolineas, tamA, tipos,tamT) ;
        printf("------------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarAvionId(aviones, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarAvion(aviones[indice], aerolineas, tamA, tipos, tamT);
            printf("Confirma baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                aviones[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}
int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eAvion auxAvion;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA>0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Modificar Avion *** \n\n");
        mostrarAviones(aviones, tam, aerolineas, tamA, tipos, tamT) ;
        printf("------------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarAvionId(aviones, tam, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch (menuModificarAvion(aviones, tam, indice, aerolineas, tamA, tipos, tamT) )
                {
                case 1:
                   mostrarTipos(tipos, tamT);
                    printf("Modificar tipo: ");
                    scanf("%d", &auxAvion.idTipo);
                        while ( !validarIdTipo(auxAvion.idTipo, tipos, tamT) )
                        {
                            printf("Error, ingrese id de tipo valido: ");
                            scanf("%d", &auxAvion.idTipo);
                        }
                    printf("Confirma cambio de tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        aviones[indice].idTipo = auxAvion.idTipo;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    printf("Modificar capacidad: ");
                    fflush(stdin);
                    scanf("%d", &auxAvion.capacidad);
                    while (auxAvion.capacidad < 10 || auxAvion.capacidad > 300){
                    printf("Por favor ingrese una cantidad de pasajeros valido: (Entre 10 y 300)\n");
                    scanf("%d", &auxAvion.capacidad);
                }
                    printf("Confirma cambio de capacidad? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        aviones[indice].capacidad = auxAvion.capacidad;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;

                case 3:
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
                //system("pause");
            }
            while(seguir == 's');

            todoOk = 1;

        }
    }
    return todoOk;
}

int menuModificarAvion(eAvion aviones[], int tam, int indice, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    int opcion = 0;
    system("cls");
    printf("------------------------------------------------------------\n");
    mostrarAvion(aviones[indice], aerolineas, tamA, tipos, tamT);
    printf("------------------------------------------------------------\n");

    printf("1- Editar id del Tipo\n");
    printf("2- Editar capacidad\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
   ;
    return opcion;
}
int ordenarAviones(eAvion aviones[], int tam)
{
    int todoOk = 0;
    eAvion auxAvion;
    int orden;
    if (aviones != NULL && tam > 0)
    {

        todoOk = 1;

            for (int i = 0; i < tam -1; i++)
            {
                for (int j = i+1; j < tam; j++)
                {
                    if ( (aviones[i].idAerolinea > aviones[j].idAerolinea)  ||
                            (aviones[i].idAerolinea == aviones[j].idAerolinea && aviones[i].capacidad > aviones[j].capacidad))
                    {
                        auxAvion = aviones[i];
                        aviones[i] = aviones[j];
                        aviones[j] = auxAvion;
                    }
                }
            }


    }
    return todoOk;
}
int validarIdAvion( int id, eAvion aviones[], int tam )
{
    int esValido = 0;
    if (aviones != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == aviones[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
