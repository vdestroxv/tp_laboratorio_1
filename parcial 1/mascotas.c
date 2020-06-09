#include "mascotas.h"
int iniciarMascotas(eMascota lista[],eRaza listado[], int tam)
{
  int i;

  for(i=0; i<tam; i++)
  {
      listado[i].estadoRaza = LIBRE;
      lista[i].estado = LIBRE;//inicia todas las mascotas en 0
      lista[i].idmascotas = 0;//incia todos los id en 0
      listado[i].idRaza = 0;

  }
  return 0;
}
/********************************************************/

/********************************************************/
int buscarMascota(eMascota lista[],eRaza listado[],int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if( lista[i].estado == LIBRE && listado[i].estadoRaza == LIBRE)
      {
          index =  i;
          break;
      }
  }

  return index;
}
/********************************************************/

/********************************************************/
void harcodearMascota(eMascota lista[],int tam)
{
  char nombre[20][51] = {"gata","gata","perro","perro","gato","pitbull","iguana","labrador","gato","gato","Bulldog"};
  char tipo[20][51] = {"gato","gato","perro","perro","gato","perro","iguana","perro","gato","gato","perro"};
  int edad[20] = {1,2,3,4,5,6,7,8,9,10,11};
  float peso[20] = {1,2,3,4,5,6,7,8,9,10,11};
  char sexo[20] = {'f','f','m','m','m','f','f','m','f','m'};
  int idcliente[20] = {1,1,2,2,2,3,3,4,5,5,5};
  int id [20] = {1,2,3,4,5,6,7,8,9,10,11};
  int i;

  for(i=0; i<11; i++)
  {
      strcpy(lista[i].nombres, nombre[i]);
      strcpy(lista[i].tipos, tipo[i]);
      lista[i].edades = edad[i];
      lista[i].pesos = peso[i];
      lista[i].sexos = sexo[i];
      lista[i].cliente = idcliente[i];
      lista[i].idmascotas = id[i];
      lista[i].estado = OCUPADO;
  }

}
/********************************************************/

/********************************************************/
void harcodearRaza (eRaza listado[], int tam)
{

    char razas[20][51] = {"gato", "gato", "perro", "perro", "gato", "pitbull", "lagarto hovero", "labrador", "gato", "gato", "gato", "bulldog"};
    char nacion [20][51] = {"persa","persa","calle","calle","persa","estados unidos","argentina","canda","persa","persa","reino unido"};
    int id [20] = {1,2,3,4,5,6,7,8,9,10,11};
    int i;

    for(i=0;i<11;i++)
    {
        strcpy(listado[i].razas,razas[i]);
        strcpy(listado[i].lugarOrigen,nacion[i]);
        listado[i].idRaza = id[i];
        listado[i].estadoRaza = OCUPADO;
    }

}
/********************************************************/

/********************************************************/
void mostrarUno (eMascota miMascota,eRaza miRaza)
{
  printf ("%d %2s %2c %2s %2d %2.2f %2s %2s %2d\n", miMascota.idmascotas,
                              miMascota.nombres,
                              miMascota.sexos,
                              miMascota.tipos,
                              miMascota.edades,
                              miMascota.pesos,
                              miRaza.razas,
                              miRaza.lugarOrigen,
                              miMascota.cliente);
}

/********************************************************/

/********************************************************/
void mostrarTodos(eMascota lista[],eRaza listado[], int tam)
{
    int i;
   for(i=0; i<tam; i++)
   {
       if(lista[i].estado!=LIBRE)
       {
           mostrarUno(lista[i],listado[i]);

       }
   }
}

/********************************************************/

/********************************************************/
eMascota crearMascota (void)
{
    eMascota miMascota;

    printf ("Ingrese nombre: ");
    fflush (stdin);
    fgets(miMascota.nombres,51,stdin);
    miMascota.nombres[strlen(miMascota.nombres)-1]='\0';

    printf ("Ingrese tipo: ");
    fflush (stdin);
    fgets(miMascota.tipos,51,stdin);
    miMascota.tipos[strlen(miMascota.tipos)-1]='\0';

    printf ("Ingrese edad: ");
    scanf ("%d", &miMascota.edades);

    printf ("Ingrese peso: ");
    scanf ("%f", &miMascota.pesos);

    printf ("Ingrese sexo: ");
    scanf ("%c", &miMascota.sexos);
    fflush(stdin);//limpia lo anterior para evitar una carga automatica en "cliente"

    printf ("Ingrese el id del cliente al que pertenece la mascota: ");
    scanf ("%d", &miMascota.cliente);
    fflush(stdin);

    miMascota.estado = OCUPADO;

    return miMascota;
}
/*************************************************/
/*************************************************/
eRaza getRaza (void)
{
    eRaza RazaMascota;
    printf ("Ingrese la raza: ");
    fflush (stdin);
    fgets(RazaMascota.razas,51,stdin);
    RazaMascota.razas[strlen(RazaMascota.razas)-1]='\0';

    printf ("Ingrese e lugar de origen: ");
    fflush (stdin);
    fgets(RazaMascota.lugarOrigen,51,stdin);
    RazaMascota.lugarOrigen[strlen(RazaMascota.lugarOrigen)-1]='\0';

    RazaMascota.estadoRaza = OCUPADO;
    return RazaMascota;
}
/*************************************************/
/*************************************************/
void cargarMascota(eMascota lista[],eRaza listado[], int len)
{
  int index;
  index = buscarMascota(lista,listado, len);

  if(index!=-1)
  {
    lista[index] = crearMascota();
    lista[index].idmascotas = index+1;
    listado[index]= getRaza();
    listado[index].idRaza = index+1;
  }
}
/*************************************************/
/*************************************************/
void modificarNombreMascota(eMascota listado[], int len)
{
    int idmascota;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idmascotas)
        {

            printf ("Ingrese el nombre: ");
            fflush (stdin);
            fgets(listado[i].nombres,51,stdin);
            listado[i].nombres[strlen(listado[i].nombres)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarTipoMascota(eMascota listado[], int len)
{
    int idmascota;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idmascotas)
        {
            printf ("Ingrese el tipo de mascota: ");
            fflush (stdin);
            fgets(listado[i].tipos,51,stdin);
            listado[i].tipos[strlen(listado[i].tipos)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarRaza(eRaza listado[], int len)
{
    int idmascota;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idRaza)
        {
            printf ("Ingrese la raza: ");
            fflush (stdin);
            fgets(listado[i].razas,51,stdin);
            listado[i].razas[strlen(listado[i].razas)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarOrigen(eRaza listado[], int len)
{
    int idmascota;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idRaza)
        {
            printf ("Ingrese la raza: ");
            fflush (stdin);
            fgets(listado[i].lugarOrigen,51,stdin);
            listado[i].lugarOrigen[strlen(listado[i].lugarOrigen)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarEdadMascota(eMascota listado[], int len)
{
    int idmascota;
    int i;
    int edad;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idmascotas)
        {
            printf ("Ingrese la edad: ");
            scanf("%d",&edad);
            listado[i].edades=edad;
            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarPeso(eMascota listado[], int len)
{
    int idmascota;
    int i;
    int peso;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idmascotas)
        {

            printf ("Ingrese el peso: ");
            scanf("%d",&peso);
            listado[i].pesos=peso;

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarSexoMascota(eMascota listado[], int len)
{
    int idmascota;
    int i;
    int sexo;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idmascotas)
        {

            printf ("Ingrese la edad: ");
            scanf("%d",&sexo);
            listado[i].sexos=sexo;

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarDuenio(eMascota listado[], int len)
{
    int idmascota;
    int i;
    int duenio;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == listado[i].idmascotas)
        {

            printf ("Ingrese el id del cliente al que pertenece la mascota: ");
            scanf("%d",&duenio);
            listado[i].cliente=duenio;

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void eliminarMascota(eMascota lista[],eRaza listado[], int len)
{
    int idmascota;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &idmascota);
    for(i=0; i<len;i++)
    {
        if(idmascota == lista[i].idmascotas )
        {
            lista[i].estado = LIBRE;
            listado[i].estadoRaza = LIBRE;
            break;
        }
    }
}
/*************************************************/
/*************************************************/
void ordenarPorTipo(eMascota lista[], int len)
{
    int i;
    int j;
    eMascota auxmascotas;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(lista[i].tipos,lista[j].tipos)>0)
            {
                auxmascotas = lista[i];
                lista[i] = lista[j];
                lista[j] = auxmascotas;
            }
        }

    }
}
/*************************************************/
/*************************************************/
void PromedioEdadMascotaPorTipo(eMascota lista[],int sizeMascotas)
{
    int i;
    int totalEdadGato;
    int contadorEdadGato;
    float promedioEdadGato;

    int totalEdadPerro;
    int contadorEdadPerro;
    float promedioEdadPerro;

    int totalEdadOtro;
    int contadorEdadOtro;
    float promedioEdadOtro;

    totalEdadGato=0;
    contadorEdadGato=0;
    promedioEdadGato=0;

    totalEdadPerro=0;
    contadorEdadPerro=0;
    promedioEdadPerro=0;

    totalEdadOtro=0;
    contadorEdadOtro=0;
    promedioEdadOtro=0;
    for(i=0;i<sizeMascotas;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            switch(lista[i].tipos[0])
            {
            case 'g':
                totalEdadGato=totalEdadGato+lista[i].edades;
                contadorEdadGato++;
                break;

            case 'p':
                totalEdadPerro=totalEdadPerro+lista[i].edades;
                contadorEdadPerro++;
                break;

            default:
                totalEdadOtro=totalEdadOtro+lista[i].edades;
                contadorEdadOtro++;
                break;
            }
        }
    }
    promedioEdadGato=(float)totalEdadGato/(float)contadorEdadGato;
    promedioEdadPerro=(float)totalEdadPerro/(float)contadorEdadPerro;
    promedioEdadOtro=(float)totalEdadOtro/(float)contadorEdadOtro;
    printf("el total de las edades de los gatos es: %d\n", totalEdadGato);
    printf("el promedio de edad de las mascotas es : %f\n",promedioEdadGato);

    printf("el total de las edades de los perros es: %d\n", totalEdadPerro);
    printf("el promedio de edad de las mascotas es : %f\n",promedioEdadPerro);

    printf("el total de las edades de otros es: %d\n", totalEdadOtro);
    printf("el promedio de edad de las mascotas es : %f\n",promedioEdadOtro);
}
/*************************************************/
/*************************************************/
void ordenarPorsexo(eMascota lista[], int len)
{
    int i;
    int j;
    eMascota auxmascotas;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(lista[i].tipos,lista[j].tipos)>0)
            {
                auxmascotas = lista[i];
                lista[i] = lista[j];
                lista[j] = auxmascotas;
            }
        }

    }
}
/*************************************************/
/*************************************************/
