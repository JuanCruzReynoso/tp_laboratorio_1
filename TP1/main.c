#include <stdio.h>
#include <stdlib.h>
#include "TP1Funciones.h"

int main()
{
    int opcion;
    float numeroUno = 0;
    float numeroDos = 0;
    float suma = 0;
    float resta = 0;
    float division = 0;
    float multiplicacion = 0;
    int factorialUno = 0;
    int factorialDos = 0;

    do
    {
        printf("1. Ingresar primer operando (A = %.2f)\n",numeroUno);
        printf("2. Ingresar segundo operando (B = %.2f)\n",numeroDos);
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");

        opcion = getInt("*.Elija una opcion: \n");

        switch(opcion)
        {
        case 1:
            numeroUno = getFloat("Ingrese el primer numero: \n");
            break;
        case 2:
            numeroDos = getFloat("Ingrese el segundo numero: \n");
            break;
        case 3:
            suma = funcionSuma(numeroUno, numeroDos);
            resta = funcionResta(numeroUno, numeroDos);
            division = funcionDivision(numeroUno, numeroDos);
            multiplicacion = funcionMultiplicacion(numeroUno, numeroDos);
            factorialUno = funcionFactorial(numeroUno);
            factorialDos = funcionFactorial(numeroDos);
            break;
        case 4:
            printf("El resultado de la suma es: %.2f \n", suma);
            printf("El resultado de la resta es: %.2f \n", resta);
            printf("El resultado de la division es: %.2f \n", division);
            printf("El resultado de la multiplicacion es: %.2f \n", multiplicacion);
            printf("El factorial del primer numero es: %d \n", factorialUno);
            printf("El factorial del segundo numero es: %d\n", factorialDos);

            printf("Los numeros han sido reestablecidos a 0\n");
            numeroUno = 0;
            numeroDos = 0;
            suma= 0;
            resta= 0;
            division= 0;
            multiplicacion= 0;
            factorialUno =0;
            factorialDos =0;
            break;
        case 5:
            printf("Cerrando... \n");
            break;
        default:
            printf("Opcion incorrecta, elija una opcion (1,2,3,4,5)\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion!=5);

    return 0;
}
