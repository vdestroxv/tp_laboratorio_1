#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    char nombre[51];
    char apellido[51];
    int telefonos;
    int edad;
    char sexo;
    int idclientes;
    int cantidaddemascotas;
    int estado;
    int idlocalidad;

} eDuenios;

typedef struct
{
    char provincia[51];
    int codigo_postal;
    char descripcion[51];
    int idLocalidad;
    int estadoLocalidad;
}eLocalidad;

int iniciarClinetes(eDuenios lista[],int, eLocalidad listado[], int);
int buscarClientes(eDuenios lista[],int);
void mostrarUnCliente(eDuenios miCliente);
void mostrarlocalidad(eLocalidad milocalidad);
void mostrarTodosLosClinetes(eDuenios lista[], int, eLocalidad listado[], int);
void harcodearClientes(eDuenios lista[],int);
void harcodearLocalidad(eLocalidad listadoLocalidad[],int tam);
eDuenios crearCliente (void);
void cargarCliente(eDuenios lista[], int );
void modificarNombre(eDuenios listado[], int);
void modificarApellido(eDuenios listado[], int);
void modificarLocalidad(eDuenios listado[], int);
void modificarTelefono(eDuenios listado[], int);
void modificarEdad(eDuenios listado[], int);
void modificarSexo(eDuenios listado[], int);
void promedioClientesVarones_mujeres(eDuenios lista[], int);
void porcentajeMujeres(eDuenios lista[],int);
