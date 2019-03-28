#include "operaciones.h"
/** \brief SUMAR
 *
 * \param   numero1
 * \param   numero2
 * \return resultado(int)
 *
 */

 /** \brief RESTAR
  *
  * \param  numero1
  * \param  numero2
  * \return resultado(int)
  *
  */

  /** \brief MULTIPLICAR
   *
   * \param numero1
   * \param numero2
   * \return resultado(int)
   *
   */

    /** \brief DIVIDIR
    *
    * \param   numero1
    * \param   numero2
    * \return resultado(float)
    *
    */

    /** \brief FACTORIAL
     *
     * \param  numero
     * \return resultado(int)
     *
     */



int sumar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1+numero2;

    return resultado;
}

int restar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1-numero2;

    return resultado;
}

int multiplicar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1*numero2;

    return resultado;
}

float dividir(int numero1,int numero2)
{
    float resultado;
    resultado=(float)numero1/numero2;

    return resultado;

}

int sacarFactorial(int numero)
{
    int resultado;

        if(numero==0 || numero==1)
        {
        resultado=1;
        }
        else
        {
        resultado = numero * sacarFactorial(numero-1);
        }

    return resultado;
}


