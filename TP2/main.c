#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"

#define T 5

int main()
{
    Employee empleados[T];
    int opcion;

  initEmployees(empleados,T);

    do
    {
        opcion=menu();
        switch(opcion)
        {
        case 1:
            addEmployee(empleados,T);
            break;
        case 2:
            removeEmployee(empleados,T);
            break;
        case 3:
            modifyEmployee(empleados,T);
            break;
        case 4:
            sortEmployees(empleados,T);
            printEmployees(empleados,T);
            printSalary(empleados,T);
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta");
            break;


        }
    }
    while(opcion!=5);

    return 0;
}
