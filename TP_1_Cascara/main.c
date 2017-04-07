#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int i=1;
    float x;
    float y;
    float suma;
    float resta;
    float divi;
    float multi;
    long fact;
    int flag=0;
    int flag1=0;
    while(seguir=='s')
    {
        if(flag==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%f)\n",x);
        }
         if(flag1==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%f)\n",y);
        }
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("Ingrese el numero de su opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    flag=1;
                    scanf("%f",&x);
                }
                break;
            case 2:
                {
                    flag1=1;
                    scanf("%f",&y);
                }
                break;
            case 3:
                {
                    suma=x+y;
                    printf("la resultado de la suma es de:%f+%f igual a %f\n",x,y,suma);
                }
                break;
            case 4:
                {
                    resta=x-y;
                    printf("la resultado de la resta es de:%f-%f igual a %f\n",x,y,resta);
                }
                break;
            case 5:
                {
                    if(y!=0)
                    {
                        divi=x/y;
                        printf("el resultado de la division es de: %f/%f igual a %f\n",x,y,divi);
                    }
                    else
                    {
                        printf("No se puede realizar la division y es 0");
                    }
                }
                break;
            case 6:
                {
                    multi=x*y;
                    printf("el resultado de la multiplicacion es de: %f*%f igual a %f\n",x,y,multi);
                }
                break;
            case 7:
                {
                    for(i; i<=x; i++)
                    {
                        fact=fact*i;
                    }
                    printf("el factorial es igual a %ld",fact);
                }
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
