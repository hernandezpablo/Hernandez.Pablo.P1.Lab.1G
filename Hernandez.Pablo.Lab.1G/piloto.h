#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED
typedef struct{
int id;
char nombre[20];
char sexo;

}ePiloto;


#endif // PILOTO_H_INCLUDED
int cargarNombrePiloto(ePiloto pilotos[], int tam,int idPiloto, char nombre[]);
int mostrarPilotos( ePiloto pilotos[], int tam );
int validarIdPiloto( int id, ePiloto pilotos[], int tam );
