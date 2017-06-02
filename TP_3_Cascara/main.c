#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    EMovie *movie;
    EMovie *mimovie;
    movie=(EMovie*)malloc(sizeof(EMovie));

    char seguir='s';
    char cuerdaux[26];
    int opcion=0;
    int cantmovies=0;
    int auxin;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");


        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    agregarPelicula(movie);
                }
                break;
            case 2:
                {
                    borrarPelicula(mimovie);
                }
                break;
            case 3:
                {
                    modificarPelicula(movie,cantmovies);
                }
               break;
            case 4:
                {
                    auxin=tenercadena(cuerdaux,"Escriba el nombre para el archivo .HTML a crear: \n","Hubo un error durante la sleecion del nombre, reingreselo:",1,25);

                }
               break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
