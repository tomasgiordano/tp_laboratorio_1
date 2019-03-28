#include "operaciones.h"

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

int factorial(int numero)
{
    int resultado;

        if(numero==0 || numero==1)
        {
        resultado=1;
        }
        else
        {
        resultado = numero * factorial(numero-1);
        }

    return resultado;
}
