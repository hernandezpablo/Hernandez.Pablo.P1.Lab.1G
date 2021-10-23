#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
typedef struct{
int id;
char descripcion[20];

}eAerolinea;
#endif // AEROLINEA_H_INCLUDED
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam,int idAerolinea, char descripcion[] );
int mostrarAerolineas( eAerolinea aerolineas[], int tam );
int validarIdAerolinea( int id, eAerolinea aerolineas[], int tam );
