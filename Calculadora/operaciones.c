#include "operaciones.h"
/** \brief                              SUMA
 *          esta funcion suma dos operadores enteros y devuelve un resultado
 * \param                            numero1(int)
 * \param                            numero2(int)
 * \return                          resultado(int)
 *
 */

 int sumar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1+numero2;

    return resultado;
}

 /** \brief                             RESTA
 *          esta funcion resta dos operadores enteros y devuelve un resultado
 * \param                            numero1(int)
 * \param                            numero2(int)
 * \return                          resultado(int)
 *
 */

    int restar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1-numero2;

    return resultado;
}

/** \brief                          MULTIPLICACION
 *          esta funcion multiplica dos operadores enteros y devuelve un resultado
 * \param                            numero1(int)
 * \param                            numero2(int)
 * \return                          resultado(int)
 *
 */

    int multiplicar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1*numero2;

    return resultado;
}

/** \brief                              DIVISION
 *          esta funcion divide dos operadores enteros y devuelve un resultado flotante
 * \param                             numero1(int)
 * \param                             numero2(int)
 * \return                          resultado(float)
 *
 */

    float dividir(int numero1,int numero2)
{
    float resultado;
    resultado=(float)numero1/numero2;

    return resultado;

}

/** \brief                            FACTORIAL
 *              esta funcion calcula el factorial de un numero entero
 * \param                            numero1(int)
 * \return                          resultado(int)
 *
 */

int sacarFactorial(int numero)
{
    int resultado=0;

    if(numero>=0)
    {
        if(numero==0 || numero==1)
        {
        resultado=1;
        }
        else
        {
        resultado = numero * sacarFactorial(numero-1);
        }
    }

    return resultado;
}


