#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED
/** \brief funcion auxiliar que carga la descripcion del tipo ingresado por id en un auxiliar.
 *
 * \param tipos[] eTipo
 * \param tam int
 * \param idTipo int
 * \param descripcion[] char
 * \return int devuelve 0 si ocurrio algun error (tamaño invalido o puntero nulo recibido), -1 si no encontro el tipo ingresado por id o 1 si salio todo bien
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tam,int idTipo, char descripcion[] );
/** \brief muestra todos los tipos del array tipos
 *
 * \param tipos[] eTipo
 * \param tam int
 * \return int devuelve 0 si ocurrio algun error( tamaño invalido o puntero nulo recibido) o 1 si salio todo ok.
 *
 */
int mostrarTipos( eTipo tipos[], int tam );
/** \brief busca en el array de tipos si la id que recibe es valida (se encuentra dentro del array)
 *
 * \param id int
 * \param tipos[] eTipo
 * \param tam int
 * \return int devuelve 1 si la encuentra o 0 si hubo algun error(si el tamaño es invalido, el puntero recibido es nulo o si no encuentra la id del tipo)
 *
 */
int validarIdTipo( int id, eTipo tipos[], int tam );
