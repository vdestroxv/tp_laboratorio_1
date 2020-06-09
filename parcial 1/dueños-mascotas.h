#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include "mascotas.h"
#include "dueños.h"
#define LIBRE 0
#define OCUPADO 1

void mostrarClientesConSusMascotas(eMascota listaDeMascotas[],eRaza listado[], int, eDuenios listaDeClientes[], int, eLocalidad listadoLocalidad[], int);

void menuPrincipal(eMascota listaDeMascotas[],eRaza listado[], int, eDuenios listaDeClientes[], int, int, eLocalidad listadoLocalidad[], int );

void menuCargar(eMascota listaDeMascotas[],eRaza listado[], int, eDuenios listaDeClientes[], int, int, int, int);

void menuModificar(eMascota listaDeMascotas[], int, eDuenios listaDeClientes[], int  , int);

void menuModificarCliente(eDuenios listaDeClientes[], int , int);

void menuModificarMascota(eMascota listaDeMascotas[], int , int);

void menuEliminar(eMascota listaDeMascotas[],eRaza listado[], int , eDuenios listaDeClientes[], int , int, int, int);

void menuMostrar(eMascota listaDeMascotas[],eRaza listado[], int, eDuenios listaDeClientes[], int, int,eLocalidad listadoLocalidad[], int );

void eliminarEnCascada(eMascota listaDeMascotas[], int, eDuenios listaDeClientes[], int);

void mostrarPorTipo(eMascota listaDeMascotas[],eRaza listado[], int, eDuenios listaDeClientes[], int);

void mostrarClientesCatidadMascotas(eMascota listaDeMascotas[], int, eDuenios listaDeClientes[], int);

void mostrarMascotasMayorDeEdad(eMascota listaDeMascotas[],eRaza listado[], int, eDuenios listaDeClientes[], int);

void ClientesConMayorCantidadMascotas(eDuenios lista[], int,eMascota listaDeMascota[],int);

void ordenarPorCantidadMascota(eDuenios lista[], int);

void ordenarPorCantidadMascota_Nombre(eDuenios lista[], int);

void PromedioEdadMascota(eMascota lista[],int);

void ClientesConMAscotasDelMismoSexo(eDuenios lista[], int, eMascota listaMascotas[], int);
