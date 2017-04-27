#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "F.h"

ePersona Cargarpersona(char name[], int edad, int dni)
{
    ePersona misPersonas;
    strcpy(misPersonas.nombre, name);
    misPersonas.dni=dni;
    misPersonas.edad=edad;
    misPersonas.estado=1;
    system("pause");
    system("cls");
    return misPersonas;
}
void grafidedad(int menos18, int de19a34, int mas35)
{
    int a,b;
    int value[]={menos18, de19a34, mas35};
    int sup=0;
    for(a=0; a<3; a++)
    {
        if(value[a]>sup)
        {
            sup=value[a];
        }
        printf("\n");
        for(a=sup; a>0; a--)
        {
            printf("%d\n",a);
            for(b=0; b<3; b++)
            {
                if(value[b]>=a)
                {
                    printf("\t  *");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\t>19\t19a34\t<35\n");
        system("pause");
        system("cls");
        break;
    }
}
void borrarPersona(ePersona misPersonas[], int pes)
{
    int dni,lugar;
    char solucion;
    printf("Digite el dni que desea eliminar:\n");
    scanf("%d",&dni);
    lugar=buscarpordni(misPersonas,dni);
    if(lugar!=-1)
    {
        printf("Esta seguro de eliminar al usuario:\n%s|||%d|||%d",misPersonas[lugar].nombre,misPersonas[lugar].edad,misPersonas[lugar].dni);
        printf("\nIngrese s/n");
        fflush(stdin);
        solucion=tolower(getche());
        while(solucion!='s'&&solucion!='n')
        {
            printf("\nIngrese s/n");
            fflush(stdin);
            solucion=getche();
        }
        if(solucion=='s')
        {
            printf("!!Operacion Completada¡¡\n");
            misPersonas[lugar].estado=0;
        }
        else
        {
            printf("!!Operacion Cancelada¡¡\n");
        }
    }
    if(lugar==-1)
    {
        printf("El dni no existe\n");
    }
    system("pause");
    system("cls");
}
int buscarpordni(ePersona lista[], int dni)
{
    int c,lugar,vela=0;
    for(c=0; c<20; c++)
    {
        if(lista[c].dni==dni)
        {
            vela=1;
            lugar=c;
        }
    }
        if(vela==0)
        {
            lugar=-1;
        }
        return lugar;
}
void ClacificarDatos(ePersona misPersonas[], int pes)
{
    system("cls");
    int d,e,posicion;
    ePersona Aux;
    printf("1/ Desde A-Z\n");
    printf("2/ Desde Z-A\n");
    scanf("%d",&posicion);

    while(posicion!=1&&posicion!=2)
    {
        system("cls");
        printf("1/ Desde A-Z\n");
        printf("2/ Desde Z-A\n");
        scanf("%d",&posicion);
    }
    system("cls");
    if(posicion==1)
    {
        for(d=0; d<pes-1;d++)
        {
            for(e=d+1; e<pes; e++)
            {
                if(strcmp(misPersonas[d].nombre, misPersonas[e].nombre)==1)
                {
                    Aux=misPersonas[d];
                    misPersonas[d]=misPersonas[e];
                    misPersonas[e]=Aux;
                }
            }
        }
    }
    if(posicion==2)
    {
        for(d=0; d<pes-1;d++)
        {
            for(e=d+1; e<pes; e++)
            {
                if(strcmp(misPersonas[d].nombre, misPersonas[e].nombre)==-1)
                {
                    Aux=misPersonas[d];
                    misPersonas[d]=misPersonas[e];
                    misPersonas[e]=Aux;
                }
            }
        }
    }
    muestroDatos(misPersonas,pes);
    system("pause");
    system("cls");
}
void muestroDatos(ePersona misPersonas[], int pes)//se utiliza en la funcion ordenar.
{
    int f;
    for(f=0; f<pes; f++)
    {
        if(misPersonas[f].estado==1)
        {
            printf("%s|||%d|||%d\n",misPersonas[f].nombre, misPersonas[f].edad, misPersonas[f].dni);
        }
    }
}
int obtenerEspacioLibre(ePersona lista[])
{
    int g,posicion,vela=0;
    for(g=0; g<20;g++)
    {
        if(lista[g].estado==0)
        {
            vela=1;
            posicion=g;
            break;
        }
    }
    if(vela==0)
    {
        posicion=-1;
    }
    return posicion;
}
