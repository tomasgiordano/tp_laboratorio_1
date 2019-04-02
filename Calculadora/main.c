#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
    int numero1;
    int numero2;
    int flagA=0;
    int flagB=0;
    int flagCalcular=0;
    int opcion;
    char seguir='s';
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorial1;
    int resultadoFactorial2;

    do
    {
        if(flagA==0)
        {
            printf("1. Ingresar 1er operando (A=x).\n");
        }
        else
        {
            printf("1. Ingresar 1er operando (A=%d).\n",numero1);
        }
        if(flagB==0)
        {
            printf("2. Ingresar 2do operando (B=y).\n");
        }
        else
        {
            printf("2. Ingresar 2do operando (B=%d).\n",numero2);
        }
        printf("3. Calcular todas las operaciones.\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n");
        printf("Ingrese una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%d",&numero1);
                flagA=1;
                flagCalcular=0;
            break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%d",&numero2);
                flagB=1;
                flagCalcular=0;
            break;
            case 3:
                if(flagA==0||flagB==0)
                {
                    printf("No es posible hacer los calculos ya que falta ingresar uno o ambos operadores.\n");
                }
                else
                {
                    resultadoSuma=sumar(numero1,numero2);
                    resultadoResta=restar(numero1,numero2);
                    resultadoMultiplicacion=multiplicar(numero1,numero2);
                    resultadoDivision=dividir(numero1,numero2);
                    resultadoFactorial1=sacarFactorial(numero1);
                    resultadoFactorial2=sacarFactorial(numero2);
                    flagCalcular=1;
                    printf("\nCalculadas todas las operaciones.\n\n");
                }
                system("pause");
            break;
            case 4:
                if(flagCalcular==0)
                {
                    printf("No ha calculado las operaciones, por lo tanto no podemos mostrar el resultado.\n");
                }
                else
                {
                    //SUMA RESTA MULTIPLICACION
                    printf("a) El resultado de %d+%d es: %d\n",numero1,numero2,resultadoSuma);
                    printf("b) El resultado de %d-%d es: %d\n",numero1,numero2,resultadoResta);
                    printf("c) El resultado de %d*%d es: %d\n",numero1,numero2,resultadoMultiplicacion);

                    //DIVISION
                    if(numero2==0)
                    {
                        printf("d) No es posible dividir por 0.\n");
                    }
                    else
                    {
                        printf("d) El resultado de %d/%d es: %.2f\n",numero1,numero2,resultadoDivision);
                    }

                    //FACTORIAL
                    if(numero1<0 && numero2<0)
                    {
                        printf("e) No se pueden calcular los factoriales de estos valores.\n");
                    }
                    else if(numero1<0)
                    {
                        printf("e) El factorial de %d NO se puede calcular y el factorial de %d es: %d\n",numero1,numero2,resultadoFactorial2);
                    }
                    else if(numero2<0)
                    {
                        printf("e) El factorial de %d es: %d y el factorial de %d NO se puede calcular\n",numero1,resultadoFactorial1,numero2);
                    }
                    else
                    {
                        printf("e) El factorial de %d es: %d y el factorial de %d es: %d\n",numero1,resultadoFactorial1,numero2,resultadoFactorial2);
                    }
                }
                system("pause");
            break;
            case 5:
                seguir='n';
            break;
            default:
                printf("ERROR. Ingrese una opcion valida.\n");
                system("pause");
            break;
        }

        system("cls");

    }while(seguir=='s');

    return 0;
}
