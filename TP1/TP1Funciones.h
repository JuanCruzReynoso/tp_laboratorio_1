#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un numero de tipo entero y devuelve un resultado
 *
 * \param mensaje a mostrar
 * \return numero ingresado
 */
int getInt(char mensaje[]);


/** \brief Pide un numero de tipo flotante y devuelve un resultado
 *
 * \param mensaje a mostrar
 * \return numero ingresado
 */
float getFloat(char mensaje[]);


/** \brief Pide un caracter y devuelve un resultado
 *
 * \param mensaje a mostrar
 * \return caracter ingresado
 */
char getChar(char mensaje[]);


/** \brief Recibe dos numeros, los suma y devuelve el resultado de la suma
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna el resultado de la suma
 *
 */
float funcionSuma(float, float);


/** \brief Recibe dos numeros, los resta y devuelve el resultado de la resta
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna el resultado de la resta
 *
 */
float funcionResta(float, float);


/** \brief Recibe dos numeros, los divide y devuelve el resultado de la division
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna el resultado de la division
 *
 */
float funcionDivision(float, float);


/** \brief Recibe dos numeros, los multiplica y devuelve el resultado de la multiplicacion
 *
 * \param float pide el primer numero
 * \param float pide el segundo numero
 * \return retorna el resultado de la multiplicacion
 *
 */
float funcionMultiplicacion(float, float);


/** \brief Recibe un numero y devuelve su factorial
 *
 * \param float Pide un numero
 * \return retorna el factorial
 *
 */
float funcionFactorial(float);
