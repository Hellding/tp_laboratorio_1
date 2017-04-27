#include <stdio.h>
#include <stdlib.h>
#include "F.h"
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define x 20

void grafidedad(int,int,int);
int main()
{
    char seguir='s';
    char name[x][50];
    int i,posicion,banDni;
    int dni[x],edad[x],pes=x;
    int opcion=0,menos18=0,de19a34=0,mas35=0;

    ePersona misPersonas[x];
    for(i=0; i<pes; i++)
    {
        misPersonas[i].dni=0;
        misPersonas[i].edad=0;
        misPersonas[i].estado=0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                posicion=obtenerEspacioLibre(misPersonas);
                banDni=0;
                if(posicion!=-1)
                {
                    printf("Escriba el nombre: \n");
                    fflush(stdin);
                    gets(name[posicion]);
                    printf("Escriba la edad: \n");
                    scanf("%d",&edad[posicion]);
                    while(edad[posicion]<1||edad[posicion]>100)
                    {
                        printf("!!ERROR¡¡ \n Escriba una edad valida: ");
                        scanf("%d",&edad[posicion]);
                    }
                    if(edad[posicion]<19)
                    {
                        menos18++;
                    }
                        else
                        {
                            if(edad[posicion]>18&&edad[posicion]<35)
                            {
                                de19a34++;
                            }
                            else
                            {
                                mas35++;
                            }
                        }
                    printf("Esciba el dni: \n");
                    scanf("%d",&dni[posicion]);
                    for(i=0; i<pes; i++)
                    {
                        if(misPersonas[i].dni==dni[posicion])
                        {
                            printf("!!ADVERTENCIA¡¡\nEl dni ya fue utilizado.");
                            banDni=1;
                            system("pause");
                            system("cls");
                        }
                        if(banDni==0)
                        {
                            misPersonas[posicion]=Cargarpersona(name[posicion],edad[posicion],dni[posicion]);
                        }
                         break;
                        if(posicion==-1)
                        {
                            printf("No hay una posicion disponible.\n");
                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                }
                /*
                CargarPersona(misPersonas);//hardcodea las variantes;

                */
                break;

            case 2:

                borrarPersona(misPersonas,pes);//utiliza la funcion buscarporDni.

                break;
            case 3:

                ClacificarDatos(misPersonas,pes);//utiliza la funcion muestroDatos.

                break;
            case 4:

                grafidedad(menos18,de19a34,mas35);

                break;
            case 5:

                seguir = 'n';

                break;

            default:
                printf("Escriba el numero de la opcion valida.\n");
                system("pause");
                system("cls");
        }
    }

    return 0;
}
