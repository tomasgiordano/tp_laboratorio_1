#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h";

int main()
{
    int numero1=0;
    int numero2=0;
    int opcion;
    char seguir='s';

    do
    {
        printf("1. Ingresar 1er operando (A=%d).\n",numero1);
        printf("2. Ingresar 2do operando (B=%d).\n",numero2);
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
            break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%d",&numero2);
            break;
            case 3:
                sumar(numero1,numero2);
                restar(numero1,numero2);
                multiplicar(numero1,numero2);
                dividir(numero1,numero2);
                //factorial(numero1,numero2);
            break;
            case 4:


            break;
            case 5:
                seguir='n';
            break;
            default:


            break;
        }

        system("pause");
        system("cls");

    }while(seguir=='s');

    return 0;
}
