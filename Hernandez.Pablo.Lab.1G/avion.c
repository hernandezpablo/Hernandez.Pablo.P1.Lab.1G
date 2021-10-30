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
    printf("  9- Listar Vuelos \n");
    printf("  10- Informes \n");
    printf("  11- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}

int menuInformes()
{
    int opcion = 0;
    system("cls");
    printf("     *** Informes Avion ***\n");
    printf("  1- Listar aviones por aerolinea\n");
    printf("  2- Listar aviones por tipo\n");
    printf("  3- Mostrar porcentaje de Aviones con tipo Jet\n");
    printf("  4- Listar aviones separados por Aerolinea\n");
    printf("  5- Listar Aerolineas con mayor capacidad\n");
    printf("  7- Mostrar vuelos avion\n");
    printf("  10- Salir\n");
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

void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    char descAerolinea[20];
    char descTipo[20];
    char nombrePiloto[20];

    if ( cargarDescripcionAerolinea( aerolineas, tamA, aviones.idAerolinea, descAerolinea) == 1
        && (cargarDescripcionTipo(tipos, tamT, aviones.idTipo, descTipo)) ==1 &&
        (cargarNombrePiloto(pilotos, tamP, aviones.idPiloto, nombrePiloto) == 1))

    {
        printf(" %d     %-10s       %-10s        %d             %-10s \n",
               aviones.id,
               descAerolinea,
               descTipo,
               aviones.capacidad,
               nombrePiloto
               );
    }

}
int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int flag = 1;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA>0 && tipos != NULL && tamT >0 && pilotos != NULL && tamP>0)
    {
        system("cls");
        printf("                     ***Lista de Aviones  ***\n");
        printf("------------------------------------------------------------\n");
        printf(" ID         Aerolinea           Tipo         Capacidad         Piloto\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!aviones[i].isEmpty)
            {
                mostrarAvion(aviones[i], aerolineas, tamA, tipos, tamT, pilotos,tamP);
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
int altaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[],int tamT ,int* pId, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int indice;
    eAvion auxAvion;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA>0 && tipos != NULL && tamT>0 && pilotos != NULL && tamP>0)
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
            fflush(stdin);
            scanf("%d", &auxAvion.idAerolinea);

            while ( !validarIdAerolinea(auxAvion.idAerolinea, aerolineas, tamA) )
            {
                printf("Error, ingrese id de aerolinea valido: ");
                fflush(stdin);
                scanf("%d", &auxAvion.idAerolinea);
            }
            mostrarTipos(tipos, tamT);
            printf("Ingrese id del Tipo: ");
            fflush(stdin);
            scanf("%d", &auxAvion.idTipo);

            while ( !validarIdTipo(auxAvion.idTipo, tipos, tamT) )
            {
                printf("Error, ingrese id de tipo valido: ");
                fflush(stdin);
                scanf("%d", &auxAvion.idTipo);
            }

            printf("Ingrese capacidad: ");
            fflush(stdin);
            scanf("%d", &auxAvion.capacidad);
            while (auxAvion.capacidad < 10 || auxAvion.capacidad > 300){
                printf("Por favor ingrese una cantidad de pasajeros valido: (Entre 10 y 300)\n");
                fflush(stdin);
                scanf("%d", &auxAvion.capacidad);
            }

            mostrarPilotos(pilotos, tamP);
            printf("Ingrese id del Piloto: ");
            fflush(stdin);
            scanf("%d", &auxAvion.idPiloto);

            while ( !validarIdPiloto(auxAvion.idPiloto, pilotos, tamP) )
            {
                printf("Error, ingrese id de tipo valido: ");
                fflush(stdin);
                scanf("%d", &auxAvion.idPiloto);
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
int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA >0 && tipos != NULL && tamT >0 && pilotos && tamP)
    {
        system("cls");
        printf("   *** Baja Avion *** \n\n");
        mostrarAviones(aviones, tam, aerolineas, tamA, tipos,tamT, pilotos, tamP) ;
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
            mostrarAvion(aviones[indice], aerolineas, tamA, tipos, tamT, pilotos, tamP);
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
int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eAvion auxAvion;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA>0 && tipos != NULL && tamT > 0 && pilotos != NULL && tamP>0)
    {
        system("cls");
        printf("   *** Modificar Avion *** \n\n");
        mostrarAviones(aviones, tam, aerolineas, tamA, tipos, tamT, pilotos, tamP) ;
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
                switch (menuModificarAvion(aviones, tam, indice, aerolineas, tamA, tipos, tamT, pilotos, tamP) )
                {
                case 1:
                   mostrarTipos(tipos, tamT);
                    printf("Modificar tipo: ");
                    fflush(stdin);
                    scanf("%d", &auxAvion.idTipo);
                        while ( !validarIdTipo(auxAvion.idTipo, tipos, tamT) )
                        {
                            printf("Error, ingrese id de tipo valido: ");
                            fflush(stdin);
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
                    fflush(stdin);
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
                    mostrarPilotos(pilotos, tamP);
                    printf("Modificar Piloto: ");
                    fflush(stdin);
                    scanf("%d", &auxAvion.idPiloto);
                        while ( !validarIdPiloto(auxAvion.idPiloto, pilotos, tamP) )
                        {
                            printf("Error, ingrese id de Piloto valido: ");
                            fflush(stdin);
                            scanf("%d", &auxAvion.idPiloto);
                        }
                    printf("Confirma cambio de piloto? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        aviones[indice].idPiloto = auxAvion.idPiloto;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;

                case 4:
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

int menuModificarAvion(eAvion aviones[], int tam, int indice, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int opcion = 0;
    system("cls");
    printf("------------------------------------------------------------\n");
    mostrarAvion(aviones[indice], aerolineas, tamA, tipos, tamT, pilotos, tamP);
    printf("------------------------------------------------------------\n");

    printf("1- Editar id del Tipo\n");
    printf("2- Editar capacidad\n");
    printf("3- Editar Piloto\n");
    printf("4- Salir\n");
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
int buscarAvion(int idAvion, eAvion aviones[], int tam, int* idAerolinea, int* idTipo, int* idPiloto){
    int todoOk =0;
    if(aviones != NULL && tam>0){
    for (int i =0; i <  tam; i++){
        if (aviones[i].id == idAvion){
            *idAerolinea = aviones[i].idAerolinea;
            *idTipo = aviones[i].idTipo;
            *idPiloto = aviones[i].idPiloto;
            todoOk = 1;
        }
    }
    todoOk =-1;
    }

return todoOk;
}



int informarAvionAerolinea( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[],int tamP )
{
    int todoOk = 0;
    int auxIdAero;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 && pilotos != NULL && tamP>0)
    {

        printf("            ***   Aviones por aerolineas  ***\n");
        printf("------------------------------------------------------------\n");

        mostrarAerolineas(aerolineas, tamA);


            printf("Ingrese id de Aerolinea: ");
            fflush(stdin);
            scanf("%d", &auxIdAero);
            while (validarIdAerolinea(auxIdAero, aerolineas, tamA) == 0 )
            {
                printf("Error, ingrese id de aerolinea valido: ");
                fflush(stdin);
                scanf("%d", &auxIdAero);

            }

        informarAvionIdAerolinea(auxIdAero, aviones, tam, aerolineas, tamA, tipos, tamT, pilotos, tamP);

        todoOk = 1;
    }
    return todoOk;
}
int informarAvionIdAerolinea( int IdAerolinea, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int flag = 1;
    char descAerolinea[20];
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 && pilotos != NULL && tamP>0)
    {
        //printf("------------------------------------------------------------\n");
        printf(" ID    Aerolinea                Tipo           Capacidad        Piloto \n");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if ( !aviones[i].isEmpty && aviones[i].idAerolinea == IdAerolinea)
            {
                mostrarAvion(aviones[i], aerolineas, tamA, tipos, tamT, pilotos, tamP);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionAerolinea(aerolineas, tamA, IdAerolinea, descAerolinea);
            printf("   No hay aviones de la aerolinea %s.\n", descAerolinea);
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarAvionTipo( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[],int tamP )
{
    int todoOk = 0;
    int auxIdTipo;
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 && pilotos != NULL && tamP>0)
    {

        printf("            ***   Aviones por aerolineas  ***\n");
        printf("------------------------------------------------------------\n");

        mostrarTipos(tipos, tamT);


            printf("Ingrese id de Tipo: ");
            fflush(stdin);
            scanf("%d", &auxIdTipo);
            while (validarIdTipo(auxIdTipo, tipos, tamT) == 0 )
            {
                printf("Error, ingrese id de tipo valido: ");
                fflush(stdin);
                scanf("%d", &auxIdTipo);

            }

        informarAvionIdTipo(auxIdTipo, aviones, tam, aerolineas, tamA, tipos, tamT, pilotos, tamP);

        todoOk = 1;
    }
    return todoOk;
}
int informarAvionIdTipo( int IdTipo, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;
    int flag = 1;
    char descTipo[20];
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 && pilotos != NULL && tamP>0)
    {
        //printf("------------------------------------------------------------\n");
        printf(" ID    Aerolinea                Tipo           Capacidad        Piloto \n");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if ( !aviones[i].isEmpty && aviones[i].idTipo== IdTipo)
            {
                mostrarAvion(aviones[i], aerolineas, tamA, tipos, tamT, pilotos, tamP);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionTipo(tipos, tamT, IdTipo, descTipo);
            printf("   No hay aviones del tipo %s.\n", descTipo);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarPorcentajeAvionesJet( eAvion aviones[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    int contTotal = 0;
    int contJet = 0;
    float porcJet = 0;

    if (aviones != NULL && tam > 0 )
    {
        system("cls");
        printf("            ***   Porcentaje de aviones tipo Jet  ***\n");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if (!aviones[i].isEmpty )
            {
                contTotal++;
                if (aviones[i].idTipo == 20000)
                {
                    contJet++;
                }
                flag = 0;
            }
        }
        if (!flag)
        {
            printf("En total hay %d aviones.\n", contTotal);
            porcJet = (float) contJet * 100 / contTotal;
            printf("Con tipo jet %.2f%%\n", porcJet);
        }
        else
        {
            printf("No hay autos con ese tipo de caja.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAvionesIdAerolinea( int idAerolinea, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP )
{
    int todoOk = 0;
    int flag = 1;
    char descAerolinea[20];
    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT>0 && pilotos != NULL && tamP > 0)
    {
        //printf("------------------------------------------------------------\n");
        printf(" ID         Aerolinea           Tipo         Capacidad         Piloto\n");
        printf("------------------------------------------------------------\n");

        for (int i =0; i < tam; i++)
        {
            if ( !aviones[i].isEmpty && aviones[i].idAerolinea == idAerolinea )
            {
                mostrarAvion(aviones[i], aerolineas, tamA, tipos, tamT, pilotos, tamP);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionAerolinea(aerolineas, tamA, idAerolinea, descAerolinea);
            printf("   No hay aviones con esta aerolinea: %s.\n", descAerolinea);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}

int mostrarAvionesAllAerolineas( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;

    if (aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos !=NULL && tamT>0 && pilotos != NULL && tamP >0)
    {
        system("cls");
        printf("               ***Aviones de cada aerolinea ***\n");
        for (int i =0; i < tamA; i++)
        {
            printf("\n");
            printf("Aerolineas: %s\n", aerolineas[i].descripcion);
            fflush(stdin);

            mostrarAvionesIdAerolinea(aerolineas[i].id, aviones, tam, aerolineas, tamA, tipos, tamT, pilotos, tamP);
            printf("\n------------------------------------------------------------\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarAerolineaMayorCapacidad( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP)
{
    int todoOk = 0;

    int contadores[tamA] ;
    for (int i = 0; i < tamA; i++)
    {
        contadores[i] = 0;
    }

    int empresaMayorCantidad = 0;
    int flag = 1;

    if (  aviones != NULL && tam > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 && pilotos != NULL && tamP >0)
    {
        system("cls");
        printf("            *** Aerolineas con mayor capacidad   ***\n\n");

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tamA; j++)
            {
                if ( !aviones[i].isEmpty && aviones[i].idAerolinea == aerolineas[j].id)
                {
                    contadores[j]++;
                }
            }
        }
        //ya sabemos la cantidad de pasajeros de cada aerolinea
        for (int i = 0; i < tamA; i++)
        {
            if (flag || contadores[i] > empresaMayorCantidad )
            {
                empresaMayorCantidad = contadores[i];
                flag = 0;
            }
        }
        //ya sabemos la mayor capacidad de todas las aerolineas
        for (int i = 0; i < tamA; i++)
        {
            if (contadores[i] == empresaMayorCantidad)
            {

                printf("La Aerolinea con mayor capacidad es %s\n", aerolineas[i].descripcion);
            }
        }
        printf("Con %d pasajeros.\n", empresaMayorCantidad);
        printf("\n");
        todoOk = 1;
    }
    return todoOk;

}

