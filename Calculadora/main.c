#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int opcion;
    char seguir='s';

    do
    {
        printf("1. Ingresar 1er operando (A=x).\n");
        printf("2. Ingresar 2do operando (B=y).\n");
        printf("3. Calcular todas las operaciones.\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n");
        printf("Ingrese una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:


            break;
            case 2:


            break;
            case 3:


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
