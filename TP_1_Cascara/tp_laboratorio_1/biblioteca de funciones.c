#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
float suma(float x,float y)
{
    float suma=x+y;
    return suma;
}
float resta(float x,float y)
{
    float resta=x-y;
    return resta;
}
float division(float x,float y)
{
    float division=x/y;
    return division;
}
float multiplicacion(float x,float y)
{
    float multiplicacion=x*y;
    return multiplicacion;
}
long factorial(float x)
{
    long factor;
    if(x==0)
    {
        return 1;
    }
    else
    {
        factor=x*factorial(x-1);
    }
    return factor;
}
