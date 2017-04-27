
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;
}ePersona;


/** \brief recibe los datos ingresados y los codifica en los vectores, y cambia el valor del estado a 1.
 *
 *  \param char: la variable que se guardara en el vector nombre.
 *  \param int: la variable que se guardara en el vector edad.
 *  \param int: la variable que se guardara en el vector dni.
 *
 *  \return devuelve un ePersona cargado.
 */
ePersona Cargarpersona(char[],int,int);

void grafidedad(int,int,int);
void borrarPersona(ePersona[],int);
void ClacificarDatos(ePersona[],int);

/** \brief consigue los valores de cada variante de la estructura y los muestra.
*
*   \param array de estructura ePersona.
*   \param int de la altura del array.
*
*   \return
*/
void muestroDatos(ePersona[],int);
/**
 *Obtiene el primer indice del array.
 *@param lista del array se pasa como paramero.
 *@return el primer indice disponible.
 */
int obtenerEspacioLibre (ePersona lista[]);
 /**
  *Obtiene el que coinside con el dni pasado por parametro.
  *@param lista el arrays se pasa como parametro.
  *@param dni el dni a ser buscado en el array.
  *@return el indice en donde se encuentra en elemento que coincide con el paramatro dni.
  */
int buscarpordni(ePersona lista[],int dni);
