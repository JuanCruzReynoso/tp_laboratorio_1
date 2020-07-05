#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    char auxId[100];
    char auxNombre[100];
    char auxHoras[100];
    char auxSueldo[100];

    int retorno = 0;
    int flag = 0;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flag == 0)
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHoras, auxSueldo);
                flag = 1;
            }

            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHoras, auxSueldo);
            printf("%s - %s - %s - %s\n", auxId, auxNombre, auxHoras, auxSueldo);
            pEmployee = employee_newParametros(auxId, auxNombre, auxHoras, auxSueldo);

            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 1;
            }
        }
    }

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int retorno = 0;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmployee = employee_new();
            fread(pEmployee,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,pEmployee);
        }

        retorno = 1;
    }

    return retorno;
}





