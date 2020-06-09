#include "dueños.h"
int iniciarClinetes(eDuenios lista[],int tam, eLocalidad listado[], int tamlocalidad)
{
  int i;
  int j;
  for(i=0; i<tam; i++)
  {
      lista[i].estado = LIBRE;
      lista[i].idclientes = 0;
  }
  for(j=0;j<tamlocalidad;j++)
  {
      listado[j].estadoLocalidad=LIBRE;
      listado[j].idLocalidad=0;
  }
  return 0;
}

int buscarClientes(eDuenios lista[],int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if( lista[i].estado == LIBRE)
      {
          index =  i;
          break;
      }
  }

  return index;
}

void mostrarUnCliente(eDuenios miCliente)
{
  printf ("%d %s %s %d %d %c %d\n", miCliente.idclientes,
                                 miCliente.nombre,
                                 miCliente.apellido,
                                 miCliente.telefonos,
                                 miCliente.edad,
                                 miCliente.sexo);
}
void mostrarlocalidad(eLocalidad milocalidad)
{
  printf ("%s %d %s\n",milocalidad.provincia ,milocalidad.codigo_postal, milocalidad.descripcion );
}
void mostrarTodosLosClinetes(eDuenios lista[], int tam, eLocalidad listado[], int tamlocalidad)
{
    int i;
    int j;
    printf("id    nombre    apellido    telefono   edad   sexo\n\n");
   for(i=0; i<tam; i++)
   {
       if(lista[i].estado==OCUPADO)
       {
            mostrarUnCliente(lista[i]);
            for(j=0;j<tamlocalidad;j++)
            {
                if(lista[i].idlocalidad==listado[j].idLocalidad)
                {
                    mostrarlocalidad(listado[j]);
                }
            }
       }
   }
}
void harcodearClientes(eDuenios lista[],int tam)
{
  char nombre[5][51] = {"Juan","Maria","Ana","Pedro","Luisa"};
  char apellido[5][51] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com"};
  int telefono[5] = {12345678,12345678,12345678,12345678,12345678};
  int edad[5] = {1,2,3,4,5};
  char sexo[5] = {'f','f','m','m','m'};
  int ids[5] = {1,2,3,4,5};
  int idlocalidad [5] = {1,2,3,1,2};
  int i;

  for(i=0; i<5; i++)
  {
      strcpy(lista[i].nombre, nombre[i]);
      strcpy(lista[i].apellido, apellido[i]);
      lista[i].telefonos = telefono[i];
      lista[i].edad = edad[i];
      lista[i].sexo = sexo[i];
      lista[i].estado = OCUPADO;
      lista[i].idclientes = ids[i];
      lista[i].idlocalidad = idlocalidad[i];
  }

}
/********************************************************/

/********************************************************/
void harcodearLocalidad(eLocalidad listadoLocalidad[],int tam)
{
    int i;
    char provincia[5][51] = {"Quilmes","Rosario","Santa Rosa"};
    int codigoPostal [5] = {1234,5678,9101};
    char descripcion [5][51] = {"ejemplo","ejemplo2","ejemplo3"};
    int idlocalidad [5] = {1,2,3};

    for (i=0;i<5;i++)
    {
        strcpy(listadoLocalidad[i].provincia,provincia[i]);
        strcpy(listadoLocalidad[i].descripcion,descripcion[i]);
        listadoLocalidad[i].codigo_postal = codigoPostal[i];
        listadoLocalidad[i].idLocalidad = idlocalidad[i];
        listadoLocalidad[i].estadoLocalidad = OCUPADO;

    }
}
/********************************************************/

/********************************************************/
eDuenios crearCliente (void)
{
    eDuenios miCliente;

    printf ("Ingrese nombre: ");
    fflush (stdin);
    fgets(miCliente.nombre,51,stdin);
    miCliente.nombre[strlen(miCliente.nombre)-1]='\0';

    printf ("Ingrese apellido: ");
    fflush (stdin);
    fgets(miCliente.apellido,51,stdin);
    miCliente.apellido[strlen(miCliente.apellido)-1]='\0';

    printf ("Ingrese telefono: ");
    scanf ("%d", & miCliente.telefonos);

    printf ("Ingrese edad: ");
    scanf ("%d", &miCliente.edad);
    fflush(stdin);//limpia lo anterior para evitar una carga automatica en "sexo"

    printf ("Ingrese sexo: ");
    scanf ("%c", &miCliente.sexo);
    fflush(stdin);

    printf("ingrese la localidad: 1= Quilmes, 2= Rosario, 3= Santa Rosa");
    scanf("%d", &miCliente.idlocalidad);

    miCliente.estado = OCUPADO;

    return miCliente;
}
/*************************************************/
/*************************************************/
void cargarCliente(eDuenios lista[], int len)
{
  int index;
  index = buscarClientes(lista, len);

  if(index!=-1)
  {
    lista[index] = crearCliente();
    lista[index].idclientes = index+1;
  }
}
/*************************************************/
/*************************************************/
void modificarNombre(eDuenios listado[], int len)
{
    int idclinete;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idclinete);
    for(i=0; i<len;i++)
    {
        if(idclinete == listado[i].idclientes)
        {

            printf ("Ingrese el nombre: ");
            fflush (stdin);
            fgets(listado[i].nombre,51,stdin);
            listado[i].nombre[strlen(listado[i].nombre)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarApellido(eDuenios listado[], int len)
{
    int idcliente;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idcliente);
    for(i=0; i<len;i++)
    {
        if(idcliente == listado[i].idclientes)
        {
            printf ("Ingrese el apellido: ");
            fflush (stdin);
            fgets(listado[i].apellido,51,stdin);
            listado[i].apellido[strlen(listado[i].apellido)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
/*void modificarLocalidad(eDuenios listado[], int len)
{
    int idcliente;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idcliente);
    for(i=0; i<len;i++)
    {
        if(idcliente == listado[i].idclientes)
        {

            printf ("Ingrese la localidad: ");
            fflush (stdin);
            fgets(listado[i].localidad,51,stdin);
            listado[i].localidad[strlen(listado[i].localidad)-1]='\0';


            break;
        }
    }
}*/
/*************************************************/
/*************************************************/
void modificarTelefono(eDuenios listado[], int len)
{
    int idcliente;
    int i;
    int telefono;
    printf("Ingrese el id: ");
    scanf("%d", &idcliente);
    for(i=0; i<len;i++)
    {
        if(idcliente == listado[i].idclientes)
        {
            printf ("Ingrese el telefono: ");
            scanf("%d",&telefono);
            listado[i].telefonos=telefono;
            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarEdad(eDuenios listado[], int len)
{
    int idcliente;
    int i;
    int edad;
    printf("Ingrese el id: ");
    scanf("%d", &idcliente);
    for(i=0; i<len;i++)
    {
        if(idcliente == listado[i].idclientes)
        {

            printf ("Ingrese la edad: ");
            scanf("%d",&edad);
            listado[i].edad=edad;

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarSexo(eDuenios listado[], int len)
{
    int idcliente;
    int i;
    int sexo;
    printf("Ingrese el id: ");
    scanf("%d", &idcliente);
    for(i=0; i<len;i++)
    {
        if(idcliente == listado[i].idclientes)
        {

            printf ("Ingrese la edad: ");
            scanf("%d",&sexo);
            listado[i].sexo=sexo;

            break;
        }
    }
}

/*************************************************/
/*************************************************/
void promedioClientesVarones_mujeres(eDuenios lista[], int sizeClientes)
{
    int i;
    int contadorMasculino;
    int contadorFemenino;
    int totalMasculino;
    int totalFemenino;
    float promedioMasculino;
    float promedioFemenino;
    contadorFemenino=0;
    contadorMasculino=0;
    totalFemenino=0;
    totalMasculino=0;
    promedioFemenino=0;
    promedioMasculino=0;
    for(i=0;i<sizeClientes;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            switch(lista[i].sexo)
            {
            case'm':
                totalMasculino=totalMasculino+lista[i].sexo;
                contadorMasculino++;
                break;

            case 'f':
                totalFemenino=totalFemenino+lista[i].sexo;
                contadorFemenino++;
                break;

            default:
                break;
            }
        }
    }
    promedioFemenino=(float)totalFemenino/(float)contadorFemenino;
    promedioMasculino=(float)totalMasculino/(float)contadorMasculino;
    printf("el promedio de mujeres es: %f\n",promedioFemenino);
    printf("el promedio de hombres es: %f\n",promedioMasculino);
}
/*************************************************/
/*************************************************/
void porcentajeMujeres(eDuenios lista[],int sizeClientes)
{
    int i;
    int contador;
    int contadorMujeres;
    int porcentaje;
    contador=0;
    contadorMujeres=0;
    porcentaje=0;
    for (i=0; i<sizeClientes ;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            contador++;
            if(lista[i].sexo=='f')
            {
                contadorMujeres++;
            }
        }
    }
    porcentaje = (contadorMujeres*100)/contador;
}
