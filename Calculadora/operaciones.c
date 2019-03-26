#include "operaciones.h"

int sumar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1+numero2;
    printf("a) El resultado de %d+%d es: %d\n",numero1,numero2,resultado);

    return resultado;
}

int restar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1-numero2;
    printf("b) El resultado de %d-%d es: %d\n",numero1,numero2,resultado);

    return resultado;
}

int multiplicar(int numero1,int numero2)
{
    int resultado;
    resultado=numero1*numero2;
    printf("c) El resultado de %d*%d es: %d\n",numero1,numero2,resultado);

    return resultado;
}

float dividir(int numero1,int numero2)
{
    int resultado;

    if(numero2==0)
    {
        printf("No es posible dividir por 0\n");

    }
    else
    {
        resultado=(float)numero1/numero2;
        printf("d) El resultado de %d/%d es: %d\n",numero1,numero2,resultado);

        return resultado;
    }
}

/*int factorial(int numero1, int numero2)
{
    int resultado2;
    int resultado1;
    int basura=123456789;

    if(numero1!=basura)
    {
        if(numero1==0 || numero1==1)
        {
        resultado1=1;
        }
        else
        {
        resultado1 = numero1 * factorial(numero1-1,basura);
        }
    }

    if(numero2!=basura)
    {
        if(numero2==0 || numero2==1)
        {
        resultado2=1;
        }
        else
        {
        resultado2 = numero2 * factorial(basura,numero2-1);
        }
    }

    printf("e) El factorial de %d es: %d y El factorial de %d es: %d",numero1,resultado1,numero2,resultado2);

    return 0;

}
*/
