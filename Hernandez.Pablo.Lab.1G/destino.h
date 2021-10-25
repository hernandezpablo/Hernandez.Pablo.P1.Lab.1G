#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
typedef struct{
    int id;
    char descripcion[25];
    int precio;

}eDestino;


#endif // DESTINO_H_INCLUDED
int mostrarDetinos( eDestino destinos[], int tam );
int validarIdDestino( int id, eDestino destinos[], int tam );
int cargarDescripcionDestino( eDestino destinos[], int tamD, int idDestino, char descripcion[], int* precio);
