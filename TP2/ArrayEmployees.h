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



void initEmployees(Employee listado[], int len);

int buscarLibre(Employee listado[], int len);

void addEmployee(Employee listado[], int len);

int generarId(Employee paramEmployee[], int len);

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
