#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

EMovie Cargarpelicula( char *nombre,char *tipo,char *link,char *comentario,int *puntos,int *tiempo )
{
    EMovie miPeli;
    strcpy(miPeli.titulo, nombre);
    strcpy(miPeli.genero, tipo);
    strcpy(miPeli.linkImagen, link);
    strcpy(miPeli.descripcion, comentario);
    miPeli.duracion=tiempo;
    miPeli.puntaje=puntos;
    miPeli.estado=1;
    system("pause");
    system("cls");
    return miPeli;
}

int agregarPelicula(EMovie *movie)
{
    FILE *peli;

    char title[20];
    char gender[20];
    char enlazeimage[50];
    char description[50];

    int score;
    int duration;

    int cantmovies=0;

    char *nombre=title;
    char *tipo=gender;
    char *link=enlazeimage;
    char *comentario=description;

    int* puntos;
    int* tiempo;
    puntos=score;
    tiempo=duration;

    printf("Ingrese el Titulo de la Pelicula: \n");
    fflush(stdin);
    gets(title);
    printf("Ingrese el Genero de la Pelicula: \n");
    fflush(stdin);
    gets(gender);
    printf("Ingrese el Duracion de la Pelicula: \n");
    scanf("%d",&duration);
    printf("Ingrese el Descripcion de la Pelicula: \n");
    fflush(stdin);
    gets(description);
    printf("Ingrese el Puntaje de la Pelicula: \n");
    scanf("%d",&score);
    printf("Ingrese el Link de la Imagen de la Pelicula: \n");
    fflush(stdin);
    gets(enlazeimage);
    Cargarpelicula(nombre,tipo,link,comentario,puntos,tiempo );
    cantmovies++;
    return cantmovies;
}

int borrarPelicula(EMovie mimovie[])
{
    char titulo[50];
    char solucion;
    int lugar=0;
    printf("Escriba la pelicula que desea eliminar:\n");
    fflush(stdin);
    gets(titulo);
    lugar = buscarporTitulo(mimovie,titulo);
    if(lugar!=-1)
    {
        printf("Esta seguro de eliminar la pelicula:\n%s",mimovie->titulo);
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
            mimovie->estado=0;
        }
        else
        {
            printf("!!Operacion Cancelada¡¡\n");
        }
    }
    if(lugar==-1)
    {
        printf("La pelicula no existe\n");
    }
    system("pause");
    system("cls");
}
int buscarporTitulo(EMovie lista[], char titulo[50])
{
    int c,lugar,vela=0;
    for(c=0; c<20; c++)
    {
        if(lista[c].titulo==titulo)
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

int modificarPelicula(EMovie movie[],int tam)
{
    char seguir='s';
    char respuesta, auxTitulo[50];
    char auxGenero[50], auxDescripcion[50], auxLink[50];
    char title[50];
    int auxDuracion;
    int auxPuntaje;
    int opcion=0;
    int i;
    int flagEncontro=0;

    printf("Ingrese el Titulo de la pelicula: ");
    fflush(stdin);
    gets(title);
    for(i=0; i<tam; i++)
    {
        if((movie+i)->estado == 1 && title == (movie+i)->titulo)
        {
            printf("\n%s--\n%s--\n%d--\n%s--\n%s", (movie+i)->titulo , (movie+i)->genero, (movie+i)->duracion, (movie+i)->puntaje, (movie+i)->descripcion, (movie+i)->linkImagen);

            while(seguir=='s')
            {
                printf("1- Cambiar Titulo\n");
                printf("2- Cambiar Genero\n");
                printf("3- Cambiar Duracion\n");
                printf("4- Cambiar Puntaje\n");
                printf("5- Cambiar Descripcion\n");
                printf("6- Cambiar Link de la Imagen\n");
                printf("7- Salir\n");

                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                {
                    printf("ingrese el nuevo Titulo: ");
                    fflush(stdin);
                    gets(auxTitulo);
                    printf("Esta seguro que desea modificar? s/n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        strcpy((movie+i)->titulo, auxTitulo);
                    }
                    else
                    {
                        printf("Accion cancelada!!!");
                    }
                }
                break;
                case 2:
                {
                    printf("ingrese el nuevo Genero: ");
                    fflush(stdin);
                    gets(auxGenero);
                    printf("Esta seguro que desea modificar? s/n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        strcpy((movie+i)->genero, auxGenero);
                    }
                    else
                    {
                        printf("Accion cancelada!!!");
                    }
                }
                break;
                case 3:
                {
                    printf("ingrese el nuevo Duracion: ");
                    scanf("%s",&auxDuracion);
                    printf("Esta seguro que desea modificar? s/n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        strcpy((movie+i)->duracion, auxDuracion);
                    }
                    else
                    {
                        printf("Accion cancelada!!!");
                    }
                }
                break;
                case 4:
                {
                    printf("ingrese el nuevo Puntaje: ");
                    scanf("%s",&auxPuntaje);
                    printf("Esta seguro que desea modificar? s/n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        strcpy((movie+i)->puntaje, auxPuntaje);
                    }
                    else
                    {
                        printf("Accion cancelada!!!");
                    }
                }
                break;
                case 5:
                {
                    printf("ingrese la nueva Descripcion: ");
                    fflush(stdin);
                    gets(auxDescripcion);
                    printf("Esta seguro que desea modificar? s/n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        strcpy((movie+i)->descripcion, auxDescripcion);
                    }
                    else
                    {
                        printf("Accion cancelada!!!");
                    }
                }
                break;
                case 6:
                {
                    printf("ingrese el nuevo Link de la Imagen: ");
                    fflush(stdin);
                    gets(auxLink);
                    printf("Esta seguro que desea modificar? s/n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        strcpy((movie+i)->linkImagen, auxLink);
                    }
                    else
                    {
                        printf("Accion cancelada!!!");
                    }
                }
                break;
                case 7:
                {
                    seguir = 'n';
                }
                break;
                }
            }
            flagEncontro = 1;
            break;
        }

    }
    if(!flagEncontro)
    {
        printf("Pelicula Inexistente");
    }
}

void generarPagina(EMovie lista[], char nombre[], int cantmovies)
{
    FILE* moba;
    int i;
    int auxInt;
    int j,q;
    char auxstring[268];
    char auxstring2[268];
    int devolver=0;
    strcat(nombre,".html");
    moba=fopen(nombre,"w");
    if(moba==NULL)
    {
        printf("La pagina no se va a poder generar.");
        devolver=1;
    }
    else
    {
        if(auxInt==-1)
        {
            exit(0);
        }
        fprintf(moba,"<!Doctype html><html> <body>");
        for(i=0;i<cantmovies;i++)
        {
            fprintf(moba,"<img  src=%s alt=%s style=width:200px;hight:200px>",(lista+i)->linkImagen,(lista+i)->titulo);
            fprintf(moba,"<h2><a href=#>%d)%s</a></h2>",i+1,(lista+i)->titulo);
            fprintf(moba,"<h3><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h3>",(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion);
            fprintf(moba,"<pre>");
            strcpy(auxstring,(lista+i)->descripcion);
            q=0;
            for(j=0;j<268;j++)
            {

                auxstring2[j]=auxstring[q];
                q++;
                if(j==60||j==124||j==188)
                {
                    j++;
                    auxstring2[j]='<';
                    j++;
                    auxstring2[j]='b';
                    j++;
                    auxstring2[j]='r';
                    j++;
                    auxstring2[j]='>';
                }
            }
            auxInt=strlen(auxstring2);
            fwrite(&auxstring2,sizeof(char),auxInt,moba);
            fprintf(moba,"</pre>");

        }

        fprintf(moba,"</html> </body>");
    }
    fclose(moba);
    printf("La paguina se genero correctamente.\n");
        printf("Abra el archivo %s que se encuentra en esta misma carpeta.\n",nombre);
    return devolver;
}

int tenercadena(char* input, char mensaje1, char mensaje2, int minimo, int maximo)
{
    int a;
    int caracter;

    a=0;
    caracter=0;
    if(input==NULL)
    {
        printf("error el puntero se encontro vacio");
    }
    else
    {
        a=gets(input);
        caracter=strlen(input);
        fflush(stdin);
        puts(mensaje1);
        if(caracter<minimo||caracter>maximo||a==0)
        {
            puts(mensaje2);
            a=-1;
        }
        else
        {
            a=0;
        }

    }
    return a;
}
