#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "piloto.h"
#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
typedef struct{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int idPiloto;
    int isEmpty;

}eAvion;
#endif // AVION_H_INCLUDED
/** \brief funcion menu principal
 *
 * \return int
 *
 */
int menu();
/** \brief indica que todas las posiciones del array estan vacias
    esta funcion pone la variable flag (isEmpty) en 1 en todas las posiciones del array.
 *
 * \param aviones[] eAvion
 * \param tam int
 * \return retorna int 0 si hubo un error(tamaño invalido o avion NULL) - 0 si se pudo hacer todo bien.
 *
 */
 int menuInformes();
int inicializarAviones(eAvion aviones[], int tam);
/** \brief busca el primer espacio libre de un array
 *
 * \param aviones[] eAvion
 * \param tam int
 * \return int -1 si no hay ningun espacio libre, sino la posicion del array que se encuentra la primer posicion libre.
 *
 */
int buscarLibre(eAvion aviones[], int tam);
/** \brief Funcion auxiliar de mostrarAviones que muestra un solo avion
 *
 * \param aviones eAvion
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void mostrarAvion(eAvion aviones, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
/** \brief muestra todo el contenido del array aviones
 *
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int 0 si hubo un error(tamaño invalido de alguno de los arrays, o si algun array es nulo) 1 si todo salio bien.
 *
 */
int mostrarAviones(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[],int tamT, ePiloto pilotos[], int tamP);
/** \brief agrega en una existente lista de aviones, los valores recibidos como parametros en la primera posicion libre disponible
 *
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \param pId int*
 * \return int retorna 0 si error(tamaño invalido de arrays o puntero Nulo o sin espacio libre) 1 si todo salio bien.
 *
 */
int altaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA,eTipo tipos[],int tamT ,int* pId, ePiloto pilotos[], int tamP);
/** \brief busca un avion por su Id y devuelve su posicion en el array
 *
 * \param aviones[] eAvion
 * \param tam int
 * \param Id int
 * \return int devuelve la posicion index del avion o -1 si hubo un error( tamaño invalido o array Nula)
 *
 */
int buscarAvionId(eAvion aviones[], int tam, int Id);
/** \brief remueve un avion por su id (pone el isEmpty flag en 1)
 *
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve 1 si salio bien o 0 si hubo un error(tamaño invalido de array o puntero nulo o no existe dicho empleado)
 *
 */
int bajaAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
/** \brief menu de opciones auxiliar a la funcion modificarAvion que muestra el avion ingresado previamente
y te da las opciones de modificar dicho avion.
 *
 * \param aviones[] eAvion
 * \param tam int
 * \param indice int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve un valor ingresado como opcion del usuario
 *
 */
int menuModificarAvion(eAvion aviones[], int tam, int indice, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
/** \brief modifica un avion ingresado por id cualquiera de sus parametros menos el id.
 *
 * \param aviones[] eAvion
 * \param tam int
 * \param aerolineas[] eAerolinea
 * \param tamA int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int devuelve 1 si salio todo bien o 0 si hubo error(tamaño invalido de arrays, puntero nulo recibido o avion no encontrado)
 *
 */
int modificarAvion(eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
/** \brief Ordena los elementos del array de aviones por aerolinea y si son iguales por capacidad
 *
 * \param aviones[] eAvion
 * \param tam int
 * \return int retorna 1 si salio todo bien o 0 si hubo un error(tamaño invalido de array o puntero nulo recibido)
 *
 */
int ordenarAviones(eAvion aviones[], int tam);
/** \brief compara la id recibida con una id existente en el array de aviones
y la valida.
 *
 * \param id int
 * \param aviones[] eAvion
 * \param tam int
 * \return int devuelve 1 si salio todo bien , 0 si hubo un error(tamaño invalido, puntero nulo recibido)
 *
 */
int validarIdAvion( int id, eAvion aviones[], int tam);
/** \brief busca en el array de aviones el avion ingresado por id y si lo encuentra
remplaza los valores de los auxiliares con el valor de dicho avion existente.
 *
 * \param idAvion int
 * \param aviones[] eAvion
 * \param tam int
 * \param idAerolinea int*
 * \param idTipo int*
 * \return int devuelve 0 si hubo un error(tamaño invalido o puntero nulo recibido), -1 si no se pudo encontrar la id del avion ingresado en el array de aviones o 1 si salio todo bien.
 *
 */
int buscarAvion(int idAvion, eAvion aviones[], int tam, int* idAerolinea, int* idTipo, int* idPiloto);
int informarAvionAerolinea( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP );
int informarAvionIdAerolinea( int IdAerolinea, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int informarAvionTipo( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[],int tamP );
int informarAvionIdTipo( int IdTipo, eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int informarPorcentajeAvionesJet( eAvion aviones[], int tam);
int mostrarAvionesAllAerolineas( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int informarAerolineaMayorCapacidad( eAvion aviones[], int tam, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
