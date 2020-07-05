#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include <stdio.h>

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

/** \brief Esta funcion pone la bandera isEmpty en LIBRE(-1) en todas las posiciones del array recibido
 *
 * \param Listado[] Employee: Array de empleados que se desea inicializar
 * \param Len int: Largo del array
 *
 */
void initEmployees(Employee listado[], int len);

/** \brief Recorre el array hasta encontrar el primer isEmpty en LIBRE(-1).
 *
 * \param Listado[] Employee: Array de
 * \param
 * \return
 *
 */
int buscarLibre(Employee listado[], int len);

void addEmployee(Employee listado[], int len);

int generarId(Employee pEmployee[], int len);

void printEmployee(Employee pEmployee);

void printEmployees(Employee listado[], int len);

void sortEmployees(Employee listado[], int len);

Employee findEmployeeById(Employee listado[], int len,int id);

void modifyEmployee(Employee listado[], int len);

void removeEmployee(Employee listado[], int len);

int menu();

int menuModify();

int sumarSueldos(Employee listado[], int len);

int promediarSueldos(Employee listado[], int len,float acumulador);

void printSalary(Employee listado[], int len);






#endif // ARRAYEMPLOYEES_H_INCLUDED
