#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 0
#define FALSE 1
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

void menu(Employee list[],int,int);
void menumodificar(Employee list[],int,int);
int initEmployees(Employee lista[], int);
int buscarLibre(Employee lista[], int);
Employee createEmployee (void);
void loadEmployee(Employee lista[], int);
void showOne (Employee myEmployee);
void showAll(Employee list[], int);
void modificarnombre(Employee listado[], int);
void modificarapellido(Employee listado[], int);
void modificarsalario(Employee listado[], int);
void modificarsector(Employee listado[], int);
void eliminarEmpoyee(Employee listado[], int);
void ordenarPorApellido_Sector(Employee listado[], int);



