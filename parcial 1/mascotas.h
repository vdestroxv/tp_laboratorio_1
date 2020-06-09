#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0
typedef struct
{
    char nombres[51];
    char tipos[51];
    int edades;
    float pesos;
    char sexos;
    int idmascotas;
    int cliente;
    int estado;

} eMascota;
typedef struct
{
    char razas[51];
    char lugarOrigen[51];
    int idRaza;
    int estadoRaza;

}eRaza;

int iniciarMascotas(eMascota lista[],eRaza listado[],int );

int buscarMascota(eMascota lista[],eRaza listado[],int );

void harcodearMascota(eMascota lista[],int );

void harcodearRaza (eRaza listado[], int );

void mostrarUno (eMascota miMascota, eRaza miRaza);

void mostrarTodos(eMascota lista[],eRaza listado[], int);

eMascota crearMascota (void);

eRaza getRaza (void);

void cargarMascota(eMascota lista[], eRaza listado[], int);

void modificarNombreMascota(eMascota listado[], int);

void modificarTipoMascota(eMascota listado[], int);

void modificarRaza(eRaza listado[], int);

void modificarOrigen(eRaza listado[], int);

void modificarEdadMascota(eMascota listado[], int);

void modificarPeso(eMascota listado[], int);

void modificarSexoMascota(eMascota listado[], int);

void modificarDuenio(eMascota listado[], int);

void eliminarMascota(eMascota lista[], eRaza listado[], int);

void ordenarPorTipo(eMascota lista[], int);

void PromedioEdadMascotaPorTipo(eMascota lista[],int);

void ordenarPorsexo(eMascota lista[], int);
