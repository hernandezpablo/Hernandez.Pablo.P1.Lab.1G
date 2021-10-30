#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
typedef struct{
    int id;
    char descripcion[25];
    int precio;

}eDestino;


#endif // DESTINO_H_INCLUDED
/** \brief muestra todos los destinos del array destinos
 *
 * \param destinos[] eDestino
 * \param tam int
 * \return int devuelve 0 si hubo algun error (tamaño invalido o puntero recibido invalido) o 1 si salio todo bien
 *
 */
int mostrarDestinos( eDestino destinos[], int tam );
/** \brief verifica que el id recibido se encuentre dentro del array de destinos
 *
 * \param id int
 * \param destinos[] eDestino
 * \param tam int
 * \return int devuelve 1 si sale todo bien o 0 si hubo algun error(tamaño invalido, puntero recibido nulo o no encontreo el id)
 *
 */
int validarIdDestino(int id, eDestino destinos[], int tam);
/** \brief carga la descripcion de un destino y su precio dependiendo de la id de un destino en dos auxiliares
 *
 * \param destinos[] eDestino
 * \param tamD int
 * \param idDestino int
 * \param descripcion[] char
 * \param precio int*
 * \return int devuelve 0 si tuvo un error(tamaño invalido o puntero recibido nulo), -1 si no encontro esa id de destino o 1 si todo salio bien.
 *
 */
int cargarDescripcionDestinoPrecio( eDestino destinos[], int tamD, int idDestino, char descripcion[], int* precio);
