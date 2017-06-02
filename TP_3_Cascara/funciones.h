#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[300];
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie[]);
int buscarporTitulo(EMovie lista[], char[]);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(EMovie movie[], int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[], int cantmovies);

int tenercadena(char* input, char mensaje1, char mensaje2, int minimo, int maximo);

#endif // FUNCIONES_H_INCLUDED
