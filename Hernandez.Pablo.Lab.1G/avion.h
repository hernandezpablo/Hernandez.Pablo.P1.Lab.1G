#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
typedef struct{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;

}eAvion;
#endif // AVION_H_INCLUDED
int menu();
int inicializarAviones(eAvion aviones[], int tam);
void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT);
int altaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[],int tamT ,int* pId);
int buscarAvionId(eAvion aviones[], int tam, int Id);
int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int menuModificarAvion(eAvion aviones[], int tam, int indice, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int ordenarAviones(eAvion aviones[], int tam);
int validarIdAvion( int id, eAvion aviones[], int tam);
int buscarAvion(int idAvion, eAvion aviones[], int tam, int* idAerolinea, int* idTipo);

