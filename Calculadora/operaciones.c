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
    int resultado;

    if(numero2==0)
    {
        printf("ERROR. Ingrese un dividendo valido.");
    }
    else
    {
        resultado=(float)numero1/numero2;

        return resultado;
    }

    return 0;
}
