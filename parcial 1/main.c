#include <stdio.h>
#include <stdlib.h>
#include "dueños-mascotas.h"
#define TMASCOTAS 20
#define TDUENIOS 10
#define TLOCALIDAD 3
int main()

{
    int opcion;
    eRaza listado[TMASCOTAS];
    eMascota lista[TMASCOTAS];
    eDuenios listaDuenios[TDUENIOS];
    eLocalidad listadoLocalidad[TLOCALIDAD];
    iniciarMascotas(lista,listado,TMASCOTAS);
    iniciarClinetes(listaDuenios,TDUENIOS,listadoLocalidad,TLOCALIDAD);
    buscarMascota(lista,listado,TMASCOTAS);
    buscarClientes(listaDuenios,TDUENIOS);
    harcodearMascota(lista,TMASCOTAS);
    harcodearRaza(listado,TMASCOTAS);
    harcodearLocalidad(listadoLocalidad,TLOCALIDAD);
    harcodearClientes(listaDuenios,TDUENIOS);
    menuPrincipal(lista,listado,TMASCOTAS,listaDuenios,TDUENIOS,opcion,listadoLocalidad,TLOCALIDAD);
    return 0;
}
