#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "myGets.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = 0;

    if(pArchivo!=NULL)
    {
        pArchivo=fopen(path,"r");
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = 0;

    if(pArchivo != NULL)
    {
        pArchivo = fopen(path, "rb");
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}

int controller_newId(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int len;
    int i;
    int auxId;
    int id= 0;
    int idAnterior;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            for(i=0; i<len; i++)
            {
                pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(pEmployee,&auxId);
                if(auxId > id)
                {
                    idAnterior = id;
                    id = auxId;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int id;
    char nombre[100];
    int horas;
    int sueldo;

    char auxSueldo[100];
    char auxHoras[100];

    int retorno= 0;

    pEmpleado = employee_new();

    if(pArrayListEmployee != NULL)
    {
        id = controller_newId(pArrayListEmployee);

        do
        {
            getString("\nIngrese nombre: ",nombre);
        }
        while(isOnlyLetters(nombre)==0);

        stringToUpper(nombre);

        do
        {
            getString("\nIngrese sueldo: ",auxSueldo);
        }
        while(isOnlyNumbers(auxSueldo)==0);

        sueldo = atoi(auxSueldo);

        do
        {
            getString("\nIngrese horas trabajadas: ",auxHoras);
        }
        while(isOnlyNumbers(auxHoras)==0);

        horas= atoi(auxHoras);

        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, id);
            employee_setNombre(pEmpleado, nombre);
            employee_setHorasTrabajadas(pEmpleado, horas);
            employee_setSueldo(pEmpleado, sueldo);

            ll_add(pArrayListEmployee, pEmpleado);

            retorno = 1;
        }
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int i;

    char auxId[100];
    int id;
    int idObtenido;

    char nombreMod[100];
    int sueldoMod;
    int horasMod;

    char auxSueldo[100];
    char auxHoras[100];

    int opcion;
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {

        do
        {
            getString("\nIngrese ID de empleado a modificar: ",auxId);
        }
        while(isOnlyNumbers(auxId)==0);

        id=atoi(auxId);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,&idObtenido);

            if(idObtenido == id)
            {
                do
                {
                    opcion = menuMod();

                    switch(opcion)
                    {
                    case 1:

                        do
                        {
                            getString("\nIngrese nombre nuevo: ",nombreMod);
                        }
                        while(isOnlyLetters(nombreMod)==0);

                        stringToUpper(nombreMod);
                        employee_setNombre(pEmployee, nombreMod);
                        retorno = 1;
                        break;

                    case 2:
                        do
                        {
                            getString("\nIngrese sueldo nuevo: ",auxSueldo);
                        }
                        while(isOnlyNumbers(auxSueldo)==0);

                        sueldoMod= atoi(auxSueldo);

                        employee_setSueldo(pEmployee, sueldoMod);

                        retorno = 1;
                        break;

                    case 3:
                        do
                        {
                            getString("\nIngrese horas trabajadas nuevas: ",auxHoras);
                        }
                        while(isOnlyNumbers(auxHoras)==0);

                        horasMod= atoi(auxHoras);

                        employee_setHorasTrabajadas(pEmployee, horasMod);

                        retorno = 1;
                        break;

                    case 4:
                        printf("\nCerrando menuMod...\n");
                        break;

                    default:
                        printf("\nOpcion incorrecta.\n");
                    }
                }
                while(opcion != 4);
            }
        }
    }

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int i;

    char auxId[100];
    int id;
    int idObtenido;

    int opcion;
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            getString("\nIngrese ID de empleado a eliminar: ",auxId);
        }
        while(isOnlyNumbers(auxId)==0);

        id=atoi(auxId);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee, &idObtenido);

            if(idObtenido == id)
            {
                printf("\nDesea confirmar eliminacion? (1 para confirmar - 2 para cancelar)\n");
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    employee_delete(pEmployee);
                    ll_remove(pArrayListEmployee,i);
                    retorno = 1;
                    break;

                case 2:
                    retorno = -1;
                    break;

                default:
                    printf("\nOpcion incorrecta.\n");
                    break;
                }
            }
        }
    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int i;

    int id;
    char nombre[128];
    int sueldo;
    int horasTrabajadas;

    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n  Id: \t\t   Nombre: \t\t Horas:\t      Sueldo: \n\n");

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);

            employee_getId(pEmpleado,&id);
            employee_getNombre(pEmpleado, nombre);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
            employee_getSueldo(pEmpleado,&sueldo);


            printf("%4d  %20s %20d %20d \n\n", id, nombre, horasTrabajadas, sueldo);
        }
        retorno = 1;
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            opcion = menuSort();

            switch(opcion)
            {
            case 1:
                printf("\nOrdenando lista por nombre...\n\n");
                ll_sort(pArrayListEmployee, employee_compararNombre, 1);
                retorno = 1;
                break;

            case 2:
                printf("\nOrdenando lista por sueldo...\n\n");
                ll_sort(pArrayListEmployee, employee_compararSueldo, 1);
                retorno = 1;
                break;

            case 3:
                printf("\nOrdenando lista por horas trabajadas...\n\n");
                ll_sort(pArrayListEmployee, employee_compararHoras, 1);
                retorno = 1;
                break;

            case 4:
                printf("\nCerrando menuSort...\n");
                break;

            default:
                printf("Opcion incorrecta.\n");
            }
        }
        while(opcion != 4);

    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmployee;

    int i;

    int* auxId;
    char* auxNombre;
    int* auxSueldo;
    int* auxHoras;

    int retorno = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        auxId = malloc(sizeof(int));
        auxNombre = malloc(sizeof(char)*100);
        auxSueldo = malloc(sizeof(int));
        auxHoras = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,auxId);
            employee_getNombre(pEmployee, auxNombre);
            employee_getHorasTrabajadas(pEmployee,auxHoras);
            employee_getSueldo(pEmployee,auxSueldo);
            fprintf(pArchivo,"%d,%s,%d,%d\n",*auxId,auxNombre,*auxHoras,*auxSueldo);
        }

        free(auxId);
        free(auxNombre);
        free(auxHoras);
        free(auxSueldo);

        fclose(pArchivo);

        retorno = 1;
    }

    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* pEmployee;

    int i;
    int retorno = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo = fopen(path,"wb");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmployee, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);

        retorno = 1;
    }

    return retorno;
}

