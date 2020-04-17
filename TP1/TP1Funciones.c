#include <stdio.h>
#include <stdlib.h>
#include "TP1Funciones.h"

/// Ingresos
int getInt(char mensaje[])
{
    int fInt;

    printf("%s", mensaje);
    scanf("%d", &fInt);

    return fInt;
}

float getFloat(char mensaje[])
{
    float fFloat;

    printf("%s", mensaje);
    scanf("%f", &fFloat);

    return fFloat;
}

char getChar(char mensaje[])
{
    char fChar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &fChar);

    return fChar;
}

/// Operaciones
float funcionSuma(float numeroUno, float numeroDos)
{
    float suma;

    suma = numeroUno + numeroDos;

    return suma;
}

float funcionResta(float numeroUno, float numeroDos)
{
    float resta;

    resta = numeroUno - numeroDos;

    return resta;
}

float funcionDivision(float numeroUno, float numeroDos)
{
    float div;

    if(numeroDos == 0)
    {
        printf("Advertencia: No se puede dividir por 0 \n");
    }
    else
    {
        div = numeroUno / numeroDos;
    }

    return div;
}

float funcionMultiplicacion(float numeroUno, float numeroDos)
{
    float multi;

    multi = numeroUno * numeroDos;

    return multi;
}


float funcionFactorial(float numero)
{
    int factorial;

    if (numero == 0)
    {
        factorial = 1;
    }
    else if(numero>0)
    {
        factorial = numero * funcionFactorial(numero - 1);
    }
    else
    {
        printf("Advertencia: No se puede calcular el factorial de un numero negativo ni de un numero con decimal\n");
        factorial = 0;
    }

    return factorial;
}
