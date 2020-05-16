#include "ArrayEmployees.h"
#define T 3
int main()
{
    int opcion;
    opcion=0;
    Employee lista[T];
    initEmployees(lista,T);
        menu(lista,T,opcion);
    return 0;
}
