#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
typedef struct{
int id;
char descripcion[20];

}eAerolinea;
#endif // AEROLINEA_H_INCLUDED
/** \brief carga la descripcion de una aerolinea buscada por id en el array de aerolineas en un auxiliar
 *
 * \param aerolineas[] eAerolinea
 * \param tam int
 * \param idAerolinea int
 * \param descripcion[] char
 * \return int devuelve 0 si hubo un error(tamaño invalido o puntero recibido nulo), -1 si no encontro el id de la aerolinea o 1 si salio todo bien
 *
 */
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam,int idAerolinea, char descripcion[] );
/** \brief muestra todas las aerolineas
 *
 * \param aerolineas[] eAerolinea
 * \param tam int
 * \return int veuelve 0 si hubo un error(tamaño invalido o puntero recibido nulo) o 1 si salio todo bien.
 *
 */
int mostrarAerolineas( eAerolinea aerolineas[], int tam );
/** \brief verifica que el id recibido se encuentre dentro del array de aerolineas
 *
 * \param id int
 * \param aerolineas[] eAerolinea
 * \param tam int
 * \return int int devuelve 1 si sale todo bien o 0 si hubo algun error(tamaño invalido, puntero recibido nulo o no encontreo el id)
 *
 */
int validarIdAerolinea( int id, eAerolinea aerolineas[], int tam );
