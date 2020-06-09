#include "dueños-mascotas.h"

void mostrarClientesConSusMascotas(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes,eLocalidad listadoLocalidad[],int tam)
{
    int i;
    int j;
    int o;
    for(i=0; i<sizeClientes; i++)
    {
        if(listaDeClientes[i].estado!=LIBRE)
        {
            for(o=0;o<tam;o++)
            {
                if(listadoLocalidad[o].idLocalidad==listaDeClientes[i].idlocalidad)
                {
                    printf("\nlocalidad:");
                    mostrarlocalidad(listadoLocalidad[o]);
                }
            }

            printf("CLIENTE:%s\n", listaDeClientes[i].nombre);
            for(j=0; j<sizeMascotas; j++)
            {
                if(listaDeClientes[i].idclientes == listaDeMascotas[j].cliente && listaDeMascotas[j].estado!=LIBRE)
                {
                    mostrarUno(listaDeMascotas[j],listado[j]);
                }

            }
        }

    }


}
/*************************************************/
/*************************************************/
void menuPrincipal(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes, int opcion, eLocalidad listadoLocalidad[], int tamlocalidad)
{
    int bandera;
    int banderaMascota;
    bandera =5;
    banderaMascota =11;
    fflush(stdin);
        do
    {
        printf("1_ALTAS\n2_MODIFICAR\n3_BAJAS\n4_MOSTRAR\n5_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", & opcion);
        fflush(stdin);
         switch(opcion)
        {
        case 1://ALTA
            menuCargar(listaDeMascotas,listado,sizeMascotas,listaDeClientes,sizeClientes,opcion,bandera,banderaMascota);
            break;
        case 2://MODIFICAR
            if (bandera>0)
            {
                menuModificar(listaDeMascotas,sizeMascotas,listaDeClientes,sizeClientes,opcion);
            }
            else
            {
                printf("NO HAY EMPLEADOS\n");
            }
            break;

        case 3://BAJA
            if (bandera>0)
            {

                menuEliminar(listaDeMascotas,listado,sizeMascotas,listaDeClientes,sizeClientes,opcion,bandera,banderaMascota);
                bandera--;
            }
            else
            {
                printf("NO HAY EMPLEADOS\n");
            }
            break;

        case 4://MOSTRAR
            if (bandera>0)
            {
                menuMostrar(listaDeMascotas,listado,sizeMascotas,listaDeClientes,sizeClientes,opcion,listadoLocalidad,tamlocalidad);
            }
            else
            {
                printf("NO HAY EMPLEADOS\n");
            }
            break;

        default:
            break;
        }
    }while(opcion!=5);

}
/*************************************************/
/*************************************************/
void menuCargar(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes, int opcion,int bandera,int banderaMascota)
{

    fflush(stdin);
    do
    {
        printf("1_CARGAR CLIENTE\n2_CARGAR MASCOTA\n3_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1://ALTA CLIENTE
            cargarCliente(listaDeClientes,sizeClientes);
            bandera++;
            break;

        case 2://ALTA MASCOTA
            if (bandera>0)
            {
                cargarMascota(listaDeMascotas,listado,sizeMascotas);
                banderaMascota++;
            }
            else
            {
                printf("NO HAY CLIENTE\n");
            }
        default:

            break;
        }


    }while(opcion!=3);
}
/*************************************************/
/*************************************************/
void menuModificar(eMascota listaDeMascotas[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes, int opcion)
{
    fflush(stdin);
    do
    {
        printf("1_MODIFICAR CLIENTE\n2_MODIFICAR MASCOTA\n3_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1://MODIFICAR NOMBRE
            menuModificarCliente(listaDeClientes,sizeClientes,opcion);
            break;

        case 2://MODIFICAR APELLIDO
            menuModificarMascota(listaDeMascotas,sizeMascotas,opcion);
            break;
        default:
            break;
        }


    }while(opcion!=3);
}
/*************************************************/
/*************************************************/
void menuModificarCliente(eDuenios listaDeClientes[], int sizeClientes, int opcion)
{
    fflush(stdin);
    do
    {
        printf("1_NOMBRE\n2_APELLIDO\n3_LOCALIDAD\n4_TELEFONO\n5_EDAD\n6_SEXO\n7_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1://MODIFICAR NOMBRE
            modificarNombre(listaDeClientes,sizeClientes);
            break;

        case 2://MODIFICAR APELLIDO
            modificarApellido(listaDeClientes,sizeClientes);
            break;

        case 3://MODIFICAR LOCALIDAD
            //modificarLocalidad(listaDeClientes,sizeClientes);
            break;

        case 4://MODIFICAR TELEFONO
            modificarTelefono(listaDeClientes,sizeClientes);
            break;

        case 5://MODIFICAR EDAD
            modificarEdad(listaDeClientes,sizeClientes);
            break;

        case 6://MODIFICAR SEXO
            modificarSexo(listaDeClientes,sizeClientes);
            break;

        default:
            printf("\nNO VALIDO\n");
            break;
        }


    }while(opcion!=7);
}

/*************************************************/
/*************************************************/
void menuModificarMascota(eMascota listaDeMascotas[], int sizeMascotas,int opcion)
{
    fflush(stdin);
    do
    {
        printf("1_NOMBRE\n2_TIPO\n3_RAZA\n4_EDAD\n5_PESO\n6_SEXO\n7_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1://MODIFICAR NOMBRE
            modificarNombreMascota(listaDeMascotas,sizeMascotas);

            break;

        case 2://MODIFICAR TIPO
            modificarTipoMascota(listaDeMascotas,sizeMascotas);

            break;

        case 3://MODIFICAR RAZA
            modificarRaza(listaDeMascotas,sizeMascotas);

            break;

        case 4://MODIFICAR EDAD
            modificarEdadMascota(listaDeMascotas,sizeMascotas);

            break;

        case 5://MODIFICAR PESO
            modificarPeso(listaDeMascotas,sizeMascotas);

            break;

        case 6://MODIFICAR SEXO
            modificarSexoMascota(listaDeMascotas,sizeMascotas);

            break;
        case 7:
            modificarDuenio(listaDeMascotas,sizeMascotas);

        default:
            break;
        }


    }while(opcion!=8);
}
/*************************************************/
/*************************************************/
void menuEliminar(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes, int opcion,int bandera,int banderaMascota)
{
    fflush(stdin);
    do
    {
        printf("1_ELIMINAR MASCOTA\n2_ELIMINAR CLIENTE CON LAS MASCOTAS\n3_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1://ELIMINAR MASCOTA
            eliminarMascota(listaDeMascotas,listado,sizeMascotas);
            banderaMascota--;

            break;

        case 2://ELIMINAR CLIENTE Y MASCOTAS
            eliminarEnCascada(listaDeMascotas,sizeMascotas,listaDeClientes,sizeClientes);

            break;
        default:
            break;
        }


    }while(opcion!=3);
}
/*************************************************/
/*************************************************/
void menuMostrar(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes, int opcion, eLocalidad listadoLocalidad[],int tamlocalidad)
{
    fflush(stdin);
    do
    {
        printf("1_MOSTRAR LISTA DE CLIENTES\n2_MOSTRAR LISTA DE MASCOTAS\n3_MOSTRAR LISTA DE CLIENTES CON MASCOTAS\n4_SECTOR\n13_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            mostrarTodosLosClinetes(listaDeClientes,sizeClientes,listadoLocalidad,tamlocalidad);
            break;

        case 2:
             mostrarTodos(listaDeMascotas,listado,sizeMascotas);
            break;

        case 3:

            mostrarClientesConSusMascotas(listaDeMascotas,listado,sizeMascotas,listaDeClientes,sizeClientes,listadoLocalidad,tamlocalidad);
            break;

        case 4:
            ordenarPorTipo(listaDeMascotas,sizeMascotas);
            mostrarPorTipo(listaDeMascotas,listado,sizeMascotas,listaDeClientes,sizeClientes);
            break;

        case 5:
            mostrarMascotasMayorDeEdad(listaDeMascotas,listado,sizeMascotas,listaDeClientes,sizeClientes);
            break;

        case 6:
            ClientesConMayorCantidadMascotas(listaDeClientes,sizeClientes,listaDeMascotas,sizeMascotas);
            break;

        case 7:
            mostrarClientesCatidadMascotas(listaDeMascotas,sizeMascotas,listaDeClientes,sizeClientes);
            break;

        case 8:
            ordenarPorCantidadMascota(listaDeClientes,sizeClientes);
            break;

        case 9:
            ordenarPorCantidadMascota_Nombre(listaDeClientes,sizeClientes);
            break;

        case 10:
            PromedioEdadMascota(listaDeMascotas,sizeMascotas);
            break;

        case 11:
            PromedioEdadMascotaPorTipo(listaDeMascotas,sizeMascotas);
            break;

        case 12:
            ordenarPorsexo(listaDeMascotas,sizeMascotas);
            ClientesConMAscotasDelMismoSexo(listaDeClientes,sizeClientes,listaDeMascotas,sizeMascotas);
            break;

        default:
            break;
        }


    }while(opcion!=13);
}
/*********************************************************************/

/*********************************************************************/
void eliminarEnCascada(eMascota listaDeMascotas[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes)
{
    int idcascada;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idcascada);
    for(i=0; i<sizeClientes;i++)
    {
        if(idcascada == listaDeClientes[i].idclientes)
        {
            listaDeClientes[i].estado = LIBRE;
            break;
        }
        for(i=0; i<sizeMascotas;i++)
        {
            if(idcascada == listaDeMascotas[i].cliente)
            {
                listaDeMascotas[i].estado=LIBRE;
            }
        }
    }
}
/*********************************************************************/

/*********************************************************************/
void mostrarPorTipo(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClintes)
{
    int i;//alumnos
    int j;//cursos

    for(i=0; i<sizeMascotas; i++)
    {
        if(listaDeMascotas[i].estado==OCUPADO)
        {
            for(j=0; j<sizeClintes; j++)
            {
                if(listaDeMascotas[i].cliente /*FK*/ == listaDeClientes[j].idclientes /*PK*/ )
                {
                    switch(listaDeMascotas[i].tipos[0])
                    {
                    case'g':
                        printf("\nGATO: %s %s  ", listaDeClientes[j].nombre,listaDeClientes[j].apellido);
                        mostrarUno(listaDeMascotas[i],listado[i]);

                        break;

                    case 'p':
                        printf("\nPERRO: %s %s  ", listaDeClientes[j].nombre,listaDeClientes[j].apellido);
                        mostrarUno(listaDeMascotas[i],listado[i]);
                        break;

                    default:
                        printf("\nOTRO: %s %s  ", listaDeClientes[j].nombre,listaDeClientes[j].apellido);
                        mostrarUno(listaDeMascotas[i],listado[i]);
                        break;
                    }

                }

            }
        }

    }


}
/*********************************************************************/

/*********************************************************************/
void mostrarClientesCatidadMascotas(eMascota listaDeMascotas[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClientes)
{
    int i;
    int j;
    for(i=0; i<sizeClientes; i++)
    {
        if(listaDeClientes[i].estado==OCUPADO)
        {
            listaDeClientes[i].cantidaddemascotas=0;
            for(j=0; j<sizeMascotas; j++)
            {
                if(listaDeMascotas[j].cliente== listaDeClientes[i].idclientes && listaDeMascotas[j].estado==OCUPADO)
                {
                    listaDeClientes[i].cantidaddemascotas++;
                }
            }
            if(listaDeClientes[i].cantidaddemascotas>0)
            {
                printf("%s %s %d\n", listaDeClientes[i].nombre, listaDeClientes[i].apellido, listaDeClientes[i].cantidaddemascotas);
            }
        }
    }


}
/*********************************************************************/

/*********************************************************************/
void mostrarMascotasMayorDeEdad(eMascota listaDeMascotas[],eRaza listado[], int sizeMascotas, eDuenios listaDeClientes[], int sizeClintes)
{
    int i;//alumnos
    int j;//cursos

    for(i=0; i<sizeMascotas; i++)
    {
        if(listaDeMascotas[i].estado==OCUPADO && listaDeMascotas[i].edades>3)
        {
            for(j=0; j<sizeClintes; j++)
            {
                if(listaDeMascotas[i].cliente == listaDeClientes[j].idclientes )
                {
                    printf("\n%s",listaDeClientes[j].nombre);
                    mostrarUno(listaDeMascotas[i],listado[i]);
                }
            }
        }
    }


}
/*********************************************************************/

/*********************************************************************/
void ClientesConMayorCantidadMascotas(eDuenios lista[], int sizeClientes,eMascota listaDeMascota[],int sizeMascotas)
{
    int i;
    for(i=0;i<sizeClientes;i++)
    {
        if(lista[i].cantidaddemascotas>1 && lista[i].estado==OCUPADO)
        {
            printf("%s %s \n",lista[i].nombre,lista[i].apellido);
        }
    }

}
/*********************************************************************/

/*********************************************************************/
void ordenarPorCantidadMascota(eDuenios lista[], int sizeClientes)
{
    int i;
    int j;
    eDuenios auxClinetes;
    for(i=0;i<sizeClientes-1;i++)
    {
        for(j=i+1;j<sizeClientes;j++)
        {
            if(lista[i].cantidaddemascotas>lista[j].cantidaddemascotas)
            {
                auxClinetes = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxClinetes;
            }
        }
    }
}
/*********************************************************************/

/*********************************************************************/
void ordenarPorCantidadMascota_Nombre(eDuenios lista[], int sizeClientes)
{
    int i;
    int j;
    eDuenios auxClinetes;
    for(i=0;i<sizeClientes-1;i++)
    {
        for(j=i+1;j<sizeClientes;j++)
        {
            if(lista[i].cantidaddemascotas>lista[j].cantidaddemascotas)
            {
                auxClinetes = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxClinetes;
            }
            else
            {
                if(lista[i].cantidaddemascotas==lista[j].cantidaddemascotas)
                {
                    if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                    {
                        auxClinetes = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxClinetes;
                    }
                }
            }
        }
    }
}
/*********************************************************************/

/*********************************************************************/
void PromedioEdadMascota(eMascota lista[],int sizeMascotas)
{
    int i;
    int totalEdad;
    int contadorEdad;
    float promedioEdad;
    totalEdad=0;
    contadorEdad=0;
    promedioEdad=0;
    for(i=0;i<sizeMascotas;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            totalEdad=totalEdad+lista[i].edades;
            contadorEdad++;
        }
    }
    promedioEdad=(float)totalEdad/(float)contadorEdad;
    printf("el total de las edades es: %d\n", totalEdad);
    printf("el promedio de edad de las mascotas es : %f",promedioEdad);
}
/*********************************************************************/

/*********************************************************************/
void ClientesConMAscotasDelMismoSexo(eDuenios lista[], int sizeClientes, eMascota listaMascotas[], int sizeMascotas)
{
    int i;//alumnos
    int j;//cursos

    for(i=0; i<sizeMascotas; i++)
    {
        if(listaMascotas[i].estado==OCUPADO)
        {
            for(j=0; j<sizeClientes; j++)
            {
                if(listaMascotas[i].cliente /*FK*/ == lista[j].idclientes /*PK*/ )
                {
                    switch(listaMascotas[i].sexos)
                    {
                    case'f':
                        printf("\nM: %s %s  ", lista[j].nombre,lista[j].apellido);

                        break;

                    case 'm':
                        printf("\nF: %s %s  ", lista[j].nombre,lista[j].apellido);
                        break;

                    default:

                        break;
                    }

                }

            }
        }

    }
}
