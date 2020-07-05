#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"

int menu()
{
    int opcion;

    printf("\n 1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n 2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("\n 3- Alta de empleado.");
    printf("\n 4- Modificar datos de empleado.");
    printf("\n 5- Baja de empleado.");
    printf("\n 6- Listar empleados.");
    printf("\n 7- Ordenar empleados.");
    printf("\n 8- Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n 9- Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    printf("\n 10- Salir.");
    printf("\n Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuMod()
{
    int opcion;

    printf("\n 1- Modificar nombre.");
    printf("\n 2- Modificar sueldo.");
    printf("\n 3- Modificar horas trabajadas.");
    printf("\n 4- Continuar.");
    printf("\n Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuSort()
{
    int opcion;

    printf("\n (1) Ordernar por nombre.");
    printf("\n (2) Ordenar por sueldo.");
    printf("\n (3) Ordenar por horas trabajadas.");
    printf("\n (4) Continuar.");
    printf("\n Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int auxId;
    int auxHoras;
    int auxSueldo;

    auxId= atoi(idStr);
    auxHoras= atoi(horasTrabajadasStr);
    auxSueldo= atoi(sueldoStr);

    if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setNombre(newEmployee, nombreStr);
        employee_setId(newEmployee, auxId);
        employee_setHorasTrabajadas(newEmployee, auxHoras);
        employee_setSueldo(newEmployee, auxSueldo);
    }

    return newEmployee;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}


int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(id > 0)
        {
            this->id = id;
            retorno = 1;
        }
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_compararNombre(void* e1, void* e2)
{
    char nombreUno[100];
    char nombreDos[100];

    int retorno = 0;

    employee_getNombre(e1, nombreUno);
    employee_getNombre(e2, nombreDos);

    if(strcmp(nombreUno, nombreDos) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreUno, nombreDos) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_compararSueldo(void* e1, void* e2)
{
    int sueldoUno;
    int sueldoDos;

    int retorno = 0;

    employee_getSueldo(e1, &sueldoUno);
    employee_getSueldo(e2, &sueldoDos);

    if(sueldoUno > sueldoDos)
    {
        retorno = 1;
    }
    else if(sueldoUno < sueldoDos)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_compararHoras(void* e1, void* e2)
{
    int horasUno;
    int horasDos;

    int retorno = 0;

    employee_getHorasTrabajadas(e1, &horasUno);
    employee_getHorasTrabajadas(e2, &horasDos);

    if(horasUno > horasDos)
    {
        retorno = 1;
    }
    else if(horasUno < horasDos)
    {
        retorno = -1;
    }

    return retorno;
}
