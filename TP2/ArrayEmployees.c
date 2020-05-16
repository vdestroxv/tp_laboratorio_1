#include "ArrayEmployees.h"
#define T 1000

void menu(Employee list[],int len,int opcion)
{
    int bandera;
    bandera =0;
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
            loadEmployee(list,len);
            bandera++;
            break;
        case 2://MODIFICAR
            if (bandera>=1)
            {
                menumodificar(list,len,opcion);
            }
            else
            {
                printf("NO HAY EMPLEADOS\n");
            }
            break;

        case 3://BAJA
            if (bandera>=1)
            {

                eliminarEmpoyee(list,len);
                bandera--;
            }
            else
            {
                printf("NO HAY EMPLEADOS\n");
            }
            break;

        case 4://MOSTRAR
            if (bandera>=1)
            {
                ordenarPorApellido_Sector(list,len);
                showAll(list,len);
            }
            else
            {
                printf("NO HAY EMPLEADOS\n");
            }
            break;

        default:
            printf("%d",bandera);
            break;
        }
    }while(opcion!=5);

}
/*************************************************/
/*************************************************/
void menumodificar(Employee list[],int len,int opcion)
{

    do
    {
        printf("1_NOMBRE\n2_APELLIDO\n3_SALARIO\n4_SECTOR\n5_SALIR\n");
        printf("ingrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1://MODIFICAR NOMBRE
            modificarnombre(list,len);
            break;

        case 2://MODIFICAR APELLIDO
            modificarapellido(list,len);
            break;

        case 3://MODIFICAR SALARIO
            modificarsalario(list,len);
            break;

        case 4://MODIFICAR SECTOR
            modificarsector(list,len);
            break;

        default:
            break;
        }


    }while(opcion!=5);
}
/*************************************************/
/*************************************************/
int initEmployees(Employee lista[], int len)
{
  int i;

  for(i=0; i<len; i++)
  {
      lista[i].isEmpty = TRUE;
      lista[i].id = 0;

  }
  return 0;
}
/*************************************************/
/*************************************************/
int serch(Employee lista[], int len)
{
  int i;
  int index = -1;

  for(i=0; i<len; i++)
  {
      if( lista[i].isEmpty == TRUE)
      {
          index =  i;
          break;
      }
  }

  return index;
}
/*************************************************/
/*************************************************/
Employee createEmployee (void)
{
    Employee myEmployee;
    do{
    printf ("Ingrese salario: ");
    scanf ("%f", & myEmployee.salary);
    printf ("Ingrese sector: ");
    scanf ("%d", &myEmployee.sector);
    printf ("Ingrese nombre: ");
    fflush (stdin);
    fgets(myEmployee.name,51,stdin);
    myEmployee.name[strlen(myEmployee.name)-1]='\0';
    printf ("Ingrese apellido: ");
    fflush (stdin);
    fgets(myEmployee.lastName,51,stdin);
    myEmployee.lastName[strlen(myEmployee.lastName)-1]='\0';
    myEmployee.isEmpty = FALSE;
    }while(myEmployee.name==NULL && myEmployee.lastName==NULL);

    return myEmployee;
}
/*************************************************/
/*************************************************/
void loadEmployee(Employee lista[], int len)
{
  int index;
  index = serch(lista, len);

  if(index!=-1)
  {
    lista[index] = createEmployee();
    lista[index].id = index+1;
  }
}
/*************************************************/
/*************************************************/
void showOne (Employee myEmployee)
{
  printf ("%d  %8s     %8s %8.2f %8d\n", myEmployee.id,
                                 myEmployee.name,
                                 myEmployee.lastName,
                                 myEmployee.salary,
                                 myEmployee.sector);
}
/*************************************************/
/*************************************************/
void showAll(Employee list[], int len)
{
    int i;
    float total;
    int contador;
    float promedio;
    total =0;
    contador=0;
    promedio =0;
    printf("id    nombre    apellido    salario    sector\n\n");
    ordenarPorApellido_Sector(list,len);
   for(i=0; i<len; i++)
   {
       if(list[i].isEmpty==FALSE)
       {
           total = total + list[i].salary;
           showOne(list[i]);
           contador++;

       }
   }
    promedio= total / contador;
    printf("\nel total es:%2.2f \n", total);
    printf("el promedio es:%2.2f \n", promedio);
}
/*************************************************/
/*************************************************/
void modificarnombre(Employee listado[], int len)
{
    int legajo;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &legajo);
    for(i=0; i<len;i++)
    {
        if(legajo == listado[i].id)
        {

            printf ("Ingrese el nombre: ");
            fflush (stdin);
            fgets(listado[i].name,51,stdin);
            listado[i].name[strlen(listado[i].name)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarapellido(Employee listado[], int len)
{
    int legajo;
    int i;
    printf("Ingrese el id: ");
    scanf("%d", &legajo);
    for(i=0; i<len;i++)
    {
        if(legajo == listado[i].id)
        {
            printf ("Ingrese el apellido: ");
            fflush (stdin);
            fgets(listado[i].lastName,51,stdin);
            listado[i].lastName[strlen(listado[i].lastName)-1]='\0';

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarsalario(Employee listado[], int len)
{
    int legajo;
    int i;
    int salario;
    printf("Ingrese el id: ");
    scanf("%d", &legajo);
    for(i=0; i<len;i++)
    {
        if(legajo == listado[i].id)
        {

            printf ("Ingrese el salario: ");
            scanf("%d",&salario);
            listado[i].salary=salario;

            break;
        }
    }
}
/*************************************************/
/*************************************************/
void modificarsector(Employee listado[], int len)
{
    int legajo;
    int i;
    int sector;
    printf("Ingrese el id: ");
    scanf("%d", &legajo);
    for(i=0; i<len;i++)
    {
        if(legajo == listado[i].id)
        {
            printf ("Ingrese el sector: ");
            scanf("%d",&sector);
            listado[i].sector=sector;
            break;
        }
    }
}
/*************************************************/
/*************************************************/
void eliminarEmpoyee(Employee listado[], int len)
{
    int legajo;
    int i;
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);
    for(i=0; i<len;i++)
    {
        if(legajo == listado[i].id)
        {
            listado[i].isEmpty=TRUE;
            break;
        }
    }
}
/*************************************************/
/*************************************************/
void ordenarPorApellido_Sector(Employee list[], int len)
{
    int i;
    int j;
    Employee auxemployee;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName)>0)
            {
                auxemployee = list[i];
                list[i] = list[j];
                list[j] = auxemployee;
            }
             else
            {
               if(list[i].lastName==list[j].lastName)
               {
                   if(strcmp(list[i].sector,list[j].sector)>0)
                   {
                        auxemployee = list[i];
                        list[i] = list[j];
                        list[j] = auxemployee;
                   }
               }
            }
        }

    }
}
