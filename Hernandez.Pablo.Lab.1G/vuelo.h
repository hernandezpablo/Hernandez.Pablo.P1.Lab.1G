#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include "fecha.h"
#include "avion.h"
#include "destino.h"
#include "piloto.h"

typedef struct{

    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;
}eVuelo;


#endif // VUELO_H_INCLUDED
/** \brief  indica que todas las posiciones del array estan vacias, esta funcion pone la variable flag (isEmpty) en 1 en todas las posiciones del array.
 *
 * \param vuelos[] eVuelo
 * \param tam int
 * \return int retorna int 0 si hubo un error(tamaño invalido o puntero recibido nulo) - 0 si se pudo hacer todo bien.
 *
 */
int inicializarVuelos(eVuelo vuelos[], int tam);
/** \brief busca el primer espacio libre del array
 *
 * \param vuelos[] eVuelo
 * \param tam int
 * \return int int -1 si no hay ningun espacio libre, sino la posicion del array que se encuentra la primer posicion libre.
 *
 */
int buscarLibreVuelo(eVuelo vuelos[], int tam);
/** \brief agrega en una existente lista de vuelos, los valores recibidos como parametros en la primera posicion libre disponible
 *
 * \param vuelos[] eVuelo
 * \param tamv int
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \param destinos[] eDestino
 * \param tamD int
 * \param pIdVuelo int*
 * \return int retorna 0 si error(tamaño invalido de arrays o puntero Nulo o sin espacio libre) 1 si todo salio bien.
 *
 */
int altaVuelo(eVuelo vuelos[], int tamv, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[], int tamT , eDestino destinos[], int tamD, int* pIdVuelo, ePiloto pilotos[], int tamP);
/** \brief Funcion auxiliar de mostrarVuelosCompletos que muestra un solo vuelo
 *
 * \param vuelos eVuelo
 * \param idAvion int
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \param destinos[] eDestino
 * \param tamD int
 * \return void
 *
 */
void mostrarVueloCompleto(eVuelo vuelos,int idAvion,eAvion aviones[],int tam ,eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, eDestino destinos[],int tamD, ePiloto pilotos[],int tamP);
/** \brief muestra todo el contenido del array vuelos
 *
 * \param vuelos[] eVuelo
 * \param tamV int
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \param destinos[] eDestino
 * \param tamD int
 * \return int int 0 si hubo un error(tamaño invalido de alguno de los arrays, o si algun array es nulo) 1 si todo salio bien.
 *
 */
int mostrarVuelosCompletos(eVuelo vuelos[], int tamV ,eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP);
int informarVuelosAvion( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, eVuelo vuelos[], int tamV, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP );
int informarVueloAuto( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, eVuelo vuelos[], int tamV, eDestino destinos[], int tamD, ePiloto pilotos[], int tamP ,int idAvion );

