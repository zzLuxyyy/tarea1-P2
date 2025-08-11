#include "../include/libro.h"
#include <string.h> //lo necesitamos si o si para usar strcpy

struct rep_libro { //la estructura del libro es la que dice en la tarea 
int isbn;
char titulo[MAX_TITULO];
char nombreAutor[MAX_NOMBRE_AUTOR];
char apellidoAutor[MAX_APELLIDO_AUTOR];
char descripcion[MAX_DESCRIPCION];
int idGeneroLibro;
TFecha fechaEdicion; //esto es un putero del tipo fecha 

};

// Crea y retorna un elemento de tipo TLibro con los valores dados
TLibro crearTLibro(int isbn, const char titulo[MAX_TITULO], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], const char descripcion[MAX_DESCRIPCION], int idGeneroLibro, TFecha fechaEdicion){
    TLibro nuevoLibro = new rep_libro;

    nuevo->isb = isbn;
    strcpy(nuevoLibro->titulo, titulo);
    strcpy(nuevoLibro->nombreAutor, nombreAutor);
    strcpy(nuevoLibro->apellidoAutor, apellidoAutor);
    strcpy(nuevoLibro->descripcion, descripcion);
    nuevoLibro->idGeneroLibro = idGeneroLibro;
    nuevo->fechaEdicion = copiarTFecha(fechaEdicion); //es un puntero, entonces al asigno directamente          

    return nuevoLibro;
}

// Libera la memoria asignada para el libro 'l'
// Debe liberar también la memoria de la fecha asociada
void liberarTLibro(TLibro &l)
{
    delete l;
    l = NULL;
}

// Retorna el isbn del libro 'l'
int isbnTLibro(TLibro l)
{
    return 0;
}

// Retorna el titulo del libro 'l'
// El titulo retornado comparte memoria con el parámetro.
char *tituloTLibro(TLibro l)
{
    return NULL;
}

// Retorna la descripción del libro 'l'
// La descripción retornada comparte memoria con el parámetro.
char *descripcionTLibro(TLibro l)
{
    return NULL;
}

// Retorna el nombre del autor del libro 'l'
// El nombre retornado comparte memoria con el parámetro.
char *nombreAutorTLibro(TLibro l)
{
    return NULL;
}

// Retorna el apellido del autor del libro 'l'
// El apellido retornado comparte memoria con el parámetro.
char *apellidoAutorTLibro(TLibro l)
{
    return NULL;
}

// Retorna el id del género del libro 'l'
int idGeneroTLibro(TLibro l)
{
    return 0;
}

// Retorna la fecha de edición del libro 'l'.
// La fecha retornada comparte memoria con el parámetro.
TFecha fechaEdicionTLibro(TLibro l)
{
    return NULL;
}

// Imprime la información del libro 'l' en el siguiente formato:
// Libro <isbn>
// Título: <título>
// Autor: <nombre autor> <apellido autor>
// Descripción: <descripcion>
// Género: <id género>
// Fecha de edición: <fecha de edición>
void imprimirTLibro(TLibro l)
{
}

// Retorna una copia del libro 'l' que no comparte memoria con el parámetro.
TLibro copiarTLibro(TLibro l)
{
    return NULL;
}
