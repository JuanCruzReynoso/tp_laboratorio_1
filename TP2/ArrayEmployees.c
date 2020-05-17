#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "myGets.h"

#define  OCUPADO -1
#define LIBRE 0

#define UP 1
#define DOWN 0

void initEmployees(Employee listado[], int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        listado[i].isEmpty= LIBRE;
    }

}

int buscarLibre(Employee listado[], int len)
{
    int i;
    int indice=-1;
    for(i=0; i<len; i++)
    {
        if(listado[i].isEmpty==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int generarId(Employee paramEmployee[], int len)
{
    int retorno= 99;
    int i;

    for(i=0; i<len; i++)
    {
        if(paramEmployee[i].isEmpty == OCUPADO)
        {
            if(paramEmployee[i].id > retorno)
            {
                retorno = paramEmployee[i].id;
            }
        }
    }

    return retorno+1;

}



void addEmployee(Employee listado[], int len)
{
    Employee myEmployee;
    int i;
    int id;

    i=buscarLibre(listado,len);
    id= generarId(listado, len);
    if (i != -1)
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(myEmployee.name);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(myEmployee.lastName);
        printf("\nIngrese salario: ");
        scanf("%f",&myEmployee.salary);
        printf("\nIngrese sector: ");
        scanf("%d",&myEmployee.sector);

        myEmployee.isEmpty=OCUPADO;
        myEmployee.id=id;
        listado[i]=myEmployee;
    }
    else
    {
        printf("\nNo hay lugar");
    }

}

void printEmployee(Employee pEmployee)
{
    printf("%d \t %8s %4s \t \t%8.2f %10d\n", pEmployee.id, pEmployee.name, pEmployee.lastName, pEmployee.salary, pEmployee.sector);
}

void printEmployees(Employee listado[], int len)
{
    int i;

    printf("ID: \t     Nombre y Apellido: \t Salario: \t Sector: \n");

    for(i=0; i<len; i++)
    {
        if(listado[i].isEmpty == OCUPADO)
        {
            printEmployee(listado[i]);
        }
    }
}

void sortEmployees(Employee listado[], int len)
{
    int i;
    int j;
    Employee aux;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(listado[i].lastName,listado[j].lastName)>0)
            {
                aux = listado[i];
                listado[i] = listado[j];
                listado[j] = aux;
            }
            else
            {
                if(listado[i].lastName == listado[j].lastName)
                {
                    if(listado[i].sector>listado[j].sector)
                    {
                        aux = listado[i];
                        listado[i] = listado[j];
                        listado[j] = aux;
                    }
                }
            }
        }

    }
}

Employee findEmployeeById(Employee listado[], int len,int id)
{
    int i;
    Employee aux= {666,"no existe", "no existe", 6.66, -1};

    for(i=0; i<len; i++)
    {
        if(listado[i].id==id)
        {
            aux=listado[i];
            break;
        }
    }

    return aux;
}

void removeEmployee(Employee listado[], int len)
{
    int i;
    int id;
    int flag = 0;
    Employee aux;
    int respuesta;

    printEmployees(listado,len);
    printf("\nIngrese id de empleado a eliminar: ");
    scanf("%d", &id);
    aux=findEmployeeById(listado,len,id);

    for(i=0; i<len; i++)
    {
        if(aux.id == listado[i].id)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        do
        {
            printf("\nDesea confirmar eliminacion? (1 para confirmar - 2 para cancelar)\n");
            scanf("%d",&respuesta);

            if (respuesta == 1)
            {
                printEmployee(listado[i]);
                listado[i].isEmpty = LIBRE;
                printf("Eliminacion excitosa \n");
            }
            else if(respuesta == 2)
            {
                printf("Eliminacion cancelada \n");
            }
            else
            {
                printf("\n Opcion incorrecta");
            }
        }
        while(respuesta!=1 && respuesta!=2);

    }
    else
    {
        printf("No existe");
    }


}

void modifyEmployee(Employee listado[], int len)
{
    int i;
    int id;
    int flag = 0;
    Employee aux;
    int opcion;
    int respuesta;

    printEmployees(listado,len);
    printf("\n Ingrese id de empleado a modificar: ");
    scanf("%d", &id);
    aux=findEmployeeById(listado,len,id);

    for(i=0; i<len; i++)
    {
        if(aux.id == listado[i].id)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        aux = listado[i];
        printEmployee(aux);
        do
        {
            opcion=menuModify();

            switch(opcion)
            {
            case 1:
                printf("Reingrese nombre : ");
                fflush(stdin);
                gets(aux.name);
                break;
            case 2:
                printf("Reingrese apellido : ");
                fflush(stdin);
                gets(aux.lastName);
                break;
            case 3:
                printf("Reingrese salario : ");
                scanf("%f", &aux.salary);
                break;
            case 4:
                printf("Reingrese sector : ");
                scanf("%d", &aux.sector);
                break;
            case 5:
                break;
            default:
                printf("opcion invalida");
                break;

            }
        }
        while(opcion!=5);
    }
    else
    {
        printf("No existe");
    }

    do
    {
        printf("\nDesea confirmar modificacion? (1 para confirmar - 2 para cancelar)\n");
        scanf("%d", &respuesta);

        if (respuesta == 1)
        {
            listado[i] = aux;
            printf("\n Modificacion excitosa\n");
        }
        else if(respuesta == 2)
        {
            printf("\n Modificacion cancelada\n");
        }
        else
        {
            printf("\n Opcion incorrecta");
        }
    }
    while(respuesta!=1 && respuesta!=2);

}

int menu()
{
    int opcion;
    printf("\n 1- Alta empleado"
           "\n 2- Baja empleado"
           "\n 3- Modificar empleado"
           "\n 4- Mostrar empleados y sueldo total/promedio"
           "\n 5- Salir"
           "\n Ingrese una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}

int menuModify()
{
    int opcion;
    printf("\n 1- Modificar nombre"
           "\n 2- Modificar apellido"
           "\n 3- Modificar salario"
           "\n 4- Modificar sector"
           "\n 5- Continuar"
           "\n Ingrese una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}

int sumarSueldos(Employee listado[], int len)
{
    int i;
    float acumulador = 0;

    for(i=0;i<len;i++)
    {
        if (listado[i].isEmpty==OCUPADO)
        {
        acumulador=acumulador+listado[i].salary;
        }
    }

    return acumulador;
}

int promediarSueldos(Employee listado[], int len,float acumulador)
{
    int i;
    int contador=0;
    float promedio;

        for(i=0;i<len;i++)
    {
        if (listado[i].isEmpty==OCUPADO)
        {
         contador++;
        }
    }
    promedio=acumulador/contador;

    return promedio;
}

void printSalary(Employee listado[], int len)
{
    int sueldoTotal;
    float promedioSueldos;

    sueldoTotal=sumarSueldos(listado,len);
    promedioSueldos=promediarSueldos(listado,len,sueldoTotal);
    printf("\n\tSueldo total: %d \t Promedio de sueldos: %.2f\n",sueldoTotal,promedioSueldos);

}

