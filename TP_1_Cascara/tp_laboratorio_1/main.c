#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "biblioteca de funciones.c"
int main()
{
    char seguir='s';
    int opcion=0;
    float x;
    float y;
    float sumatorai;
    float restal;
    float divik;
    float multi;
    long fact;
    int flagx=0;
    int flagy=0;
    while(seguir=='s')
    {
        printf("         -------------------------\n ");
        printf("@-------|++++++++++++++++++++++++++\n ");
        printf("@-------|++++++++++++++++++++++++++\n");
        printf("         -------------------------\n");
        if(flagx==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");//Se ve al no ingresa ningun valor.
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%f)\n",x);//Se ve al ingresar en case 1 un valor.
        }
         if(flagy==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");//Se ve al no ingresa ningun valor.
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%f)\n",y);//Se ve al ingresar  en case 2 un valor.
        }
        printf("3- Calcular la suma (A+B)\n");//Primera observacion de la operacion suma.
        printf("4- Calcular la resta (A-B)\n");//Primera observacion de la operacion resta.
        printf("5- Calcular la division (A/B)\n");//Primera observacion de la operacion division.
        printf("6- Calcular la multiplicacion (A*B)\n");//Primera observacion de la operacion multiplicacion.
        printf("7- Calcular el factorial (A!)\n");//Primera observacion de la operacion factorial.
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("Ingrese el numero de su opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    flagx=1;//Cancela la primer vision del ingreso del 1º Operando.
                    scanf("%f",&x);
                }
                break;
            case 2:
                {
                    flagy=1;//Cancela la primer vision del ingreso del 2º Operando.
                    scanf("%f",&y);
                }
                break;
            case 3:
                {
                    sumatorai=suma(x,y);
                    printf("El total de la suma es de : %f\n",sumatorai);
                }
                break;
            case 4:
                {
                    restal=resta(x,y);
                    printf("El total de la resta es de : %f\n",restal);
                }
                break;
            case 5:
                {
                    if(y!=0)
                    {
                        divik=division(x,y);
                        printf("El total de la division es igual a %f\n",divik);
                    }
                    else//Si el valor del 2ª operando es 0,se muestra el siguiente printf
                    {
                        printf("No se puede realizar la division y es 0");
                    }
                }
                break;
            case 6:
                {
                    multi=multiplicacion(x,y);
                    printf("El total de la multiplicacion es igual a %f\n",multi);
                }
                break;
            case 7:
                {
                    fact=factorial(x);
                    printf("El factorial es igual a %ld\n",fact);
                }
                break;
            case 8:
                {
                    sumatorai=suma(x,y);
                    printf("El total de la suma es igual a %f\n",sumatorai);
                    restal=resta(x,y);
                    printf("El total de la resta es igual a %f\n",restal);
                    if(y!=0)
                    {
                        divik=division(x,y);
                        printf("El total de la division es igual a %f\n",divik);
                    }
                    else
                    {
                        printf("No se puede realizar la division porque y es 0");
                    }
                    multi=multiplicacion(x,y);
                    printf("El total de la multiplicacion es igual a %f\n",multi);
                    fact=factorial(x);
                    printf("El toal de la factorizacion es igual a %ld\n",fact);
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

