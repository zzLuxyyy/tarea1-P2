#include "../include/libro.h"

struct rep_libro {
    /**** Parte 4.1 ****/
    int isbn;
    char titulo [MAX_TITULO];
    char nombreAutor [MAX_NOMBRE_AUTOR];
    char apellidoAutor [MAX_APELLIDO_AUTOR];
    char descripcion [MAX_DESCRIPCION];
    int idGeneroLibro;
    TFecha fechaEdicion;
    /** Fin de parte Parte 4.1 ***/
};

// Crea y retorna un elemento de tipo TLibro con los valores dados
TLibro crearTLibro(int isbn, const char titulo[MAX_TITULO], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], const char descripcion[MAX_DESCRIPCION], int idGeneroLibro, TFecha fechaEdicion){
    /**** Parte 4.2 ****/
    TLibro nuevoLibro = new rep_libro;
    nuevoLibro->isbn = isbn;
    strcpy(nuevoLibro->titulo, titulo);
    strcpy(nuevoLibro->nombreAutor, nombreAutor);
    strcpy(nuevoLibro->apellidoAutor, apellidoAutor);
    strcpy(nuevoLibro->descripcion, descripcion);
    nuevoLibro->idGeneroLibro = idGeneroLibro;
    nuevoLibro->fechaEdicion = fechaEdicion;
    return nuevoLibro;
    /** Fin de parte Parte 4.2 ***/
}

// Libera la memoria asignada para el libro 'l'
// Debe liberar también la memoria de la fecha asociada
void liberarTLibro(TLibro &l){
    /**** Parte 4.4 ****/
    liberarTFecha(l->fechaEdicion);
    delete l;
    l = NULL;
    /** Fin de parte Parte 4.4 ***/
}

// Retorna el isbn del libro 'l'
int isbnTLibro(TLibro l){
    return l->isbn;
}

// Retorna el titulo del libro 'l'
// El titulo retornado comparte memoria con el parámetro. 
char* tituloTLibro(TLibro l){
    return l->titulo;
}

// Retorna la descripción del libro 'l'
// La descripción retornada comparte memoria con el parámetro. 
char* descripcionTLibro(TLibro l){
    return l->descripcion; 
}

// Retorna el nombre del autor del libro 'l'
// El nombre retornado comparte memoria con el parámetro. 
char* nombreAutorTLibro(TLibro l){
    return l->nombreAutor;
}

// Retorna el apellido del autor del libro 'l'
// El apellido retornado comparte memoria con el parámetro. 
char* apellidoAutorTLibro(TLibro l){
    return l->apellidoAutor;
}

// Retorna el id del género del libro 'l'
int idGeneroTLibro(TLibro l){
    return l->idGeneroLibro;
}

// Retorna la fecha de edición del libro 'l'.
// La fecha retornada comparte memoria con el parámetro. 
TFecha fechaEdicionTLibro(TLibro l){
    return l->fechaEdicion;
}

void imprimirTLibro(TLibro l){
    printf("Libro %d\n", l->isbn);
    printf("Título: %s\n", l->titulo);
    printf("Autor: %s %s\n", l->nombreAutor, l->apellidoAutor);
    printf("Descripción: %s\n", l->descripcion);
    printf("Género: %d\n", l->idGeneroLibro);
    printf("Fecha de edición: ");
    imprimirTFecha(l->fechaEdicion);
}

// Retorna una copia del libro 'l' que no comparte memoria con el parámetro.
TLibro copiarTLibro(TLibro l){
    TLibro copia = new rep_libro;
    copia->isbn = l->isbn;
    strcpy(copia->titulo, l->titulo);
    strcpy(copia->nombreAutor, l->nombreAutor);
    strcpy(copia->apellidoAutor, l->apellidoAutor);
    strcpy(copia->descripcion, l->descripcion);
    copia->idGeneroLibro = l->idGeneroLibro;
    copia->fechaEdicion = copiarTFecha(l->fechaEdicion);
    return copia;
}
