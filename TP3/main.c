#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "myGets.h"

int main()
{
    LinkedList* listadoEmpleados = ll_newLinkedList();

    int opcion;

    int flagTexto = 0;
    int flagBinario = 0;

    int retornoController;
    int retornoAdd;
    int retornoEdit;
    int retornoRemove;
    int retornoList;
    int retornoSort;
    int retornoSave;

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            if(flagTexto == 0)
            {
                retornoController = controller_loadFromText("data.csv",listadoEmpleados);

                if(retornoController == 1)
                {
                    printf("\nEl archivo ha sido cargado exitosamente.\n\n");
                }
                else
                {
                    printf("\nError al cargar el archivo.\n\n");
                }

                flagTexto = 1;
            }
            else if(flagTexto == 1)
            {
                printf("\nEl archivo fue cargado anteriormente.\n\n");
            }
            break;

        case 2:
            if(flagBinario == 0)
            {
                retornoController = controller_loadFromBinary("data.bin",listadoEmpleados);

                if(retornoController == 1)
                {
                    printf("\nEl archivo ha sido cargado exitosamente.\n\n");
                }
                else
                {
                    printf("\nError al cargar el archivo.\n\n");
                }
                flagBinario = 1;
            }
            else if(flagBinario == 1)
            {
                printf("\nEl archivo fue cargado anteriormente.\n\n");
            }
            break;

        case 3:
            retornoAdd = controller_addEmployee(listadoEmpleados);
            if(retornoAdd == 1)
            {
                printf("\nEmpleado agregado exitosamente.\n\n");
            }
            else
            {
                printf("\nError al agregar empleado.\n\n");
            }
            break;

        case 4:
            retornoEdit = controller_editEmployee(listadoEmpleados);
            if(retornoEdit == 1)
            {
                printf("\nEmpleado modificado exitosamente.\n\n");
            }
            else
            {
                printf("\nError al modificar empleado.\n\n");
            }
            break;

        case 5:
            retornoRemove = controller_removeEmployee(listadoEmpleados);
            if(retornoRemove == 1)
            {
                printf("\nEmpleado eliminado exitosamente.\n\n");
            }
            else if(retornoRemove == -1)
            {
                printf("\nEliminacion cancelada.\n\n");
            }
            else
            {
                printf("\nNo se ha encontrado el ID.\n\n");
            }
            break;

        case 6:
            retornoList = controller_ListEmployee(listadoEmpleados);
            if(retornoList == 1)
            {
                printf("\nSe ha cargado la lista.\n\n");
            }
            else
            {
                printf("\nError al cargar la lista.\n\n");
            }
            break;

        case 7:
            retornoSort = controller_sortEmployee(listadoEmpleados);
            if(retornoSort == 1)
            {
                printf("\nLista ordenada exitosamente.\n\n");
            }
            else
            {
                printf("\nError al ordenar la lista.\n\n");
            }
            break;

        case 8:
            retornoSave = controller_saveAsText("data.csv",listadoEmpleados);
            if(retornoSave == 1)
            {
                printf("\nArchivo guardado exitosamente.\n\n");
            }
            else
            {
                printf("\nError al guardar archivo.\n\n");
            }
            break;

        case 9:
            retornoSave = controller_saveAsBinary("data.bin",listadoEmpleados);
            if(retornoSave == 1)
            {
                printf("\nArchivo guardado exitosamente.\n\n");
            }
            else
            {
                printf("\nError al guardar archivo.\n\n");
            }
            break;

        case 10:
            printf("\nCerrando...\n");
            break;

        default:
            printf("\nOpcion incorrecta.\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion != 10);

    return 0;
}
