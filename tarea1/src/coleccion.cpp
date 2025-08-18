#include "../include/coleccion.h"
#include <cassert> //es importante para poder usar assert

struct rep_coleccion
{
    TLibro libros[MAX_LIBROS]; //areglo con punteros
    int tope;
};

struct rep_coleccion
{
};

// Función para crear una TColeccion vacía que puede almacenar hasta MAX_LIBROS libros.
TColeccion crearTColeccion()
{
    return NULL;
}

// Función para liberar la memoria asociada a una colección de libros.
// Recibe una referencia a un elemento de tipo TColeccion y libera su memoria
// Debe liberar además la memoria de cada uno de los libros de la colección.
void liberarTColeccion(TColeccion &c)
{
    delete c;
    c = NULL;
}

// Función para agregar un nuevo libro 'l' a la colección 'l'
// Recibe un elemento de tipo TColeccion y un elemento de tipo TLibro y lo agrega a la colección en orden por fecha de edición (de menor a mayor)
// Si dos libros tienen la misma fecha de edición, deben ordenarse por orden de ingreso a la colección,
// quedando antes el último de ellos en ser ingresado (de más reciente a más antiguo).
// Si la cantidad de libros en la colección es igual a MAX_LIBROS, la función no tiene efecto
void agregarEnTColeccion(TColeccion &c, TLibro l)
{
}

// Función para imprimir la información de todos los libros en la colección
// Recibe un elemento de tipo TColeccion e imprime la información de sus libros
// en orden cronológico por fecha de edición (el orden en el que aparecen en la colección).
// El formato en el que se debe imprimir la información de la colección es utilizando de
// forma secuencial la función imprimirTLibro
//
// Colección de libros:
// Libro <isbn 1>
// Título: <título 1>
// Autor: <nombre autor 1> <apellido autor 1>
// Descripción: <descripcion 1>
// Género: <id género 1>
// Fecha de edición: <fecha de edición 1>
// Libro <isbn 2>
// Título: <título 2>
// Autor: <nombre autor 2> <apellido autor 2>
// Descripción: <descripcion 2>
// Género: <id género 2>
// Fecha de edición: <fecha de edición 2>
// ....
// Si la colección está vacía solo imprime el cabezal.
void imprimirTColeccion(TColeccion c)
{
int i;

    if (c == NULL || c->tope == 0){ 
        return; //por si está vacio no devolvemos nada
    }else{

        for (i = 0; i < c->tope; i++){
            imprimirTLibro(c->libros[i]); //impirme libro con su formato
        }

    }

}


// Función para verificar si un libro con isbn 'isbn' existe en la colección 'c'
// Recibe una colección c y un isbn y retorna true si y solo si la colección c contiene
// un libro con isbn 'isbn'
bool estaEnTColeccion(TColeccion c, int isbn){
     for (int i = 0; c->tope > i ; i++){
        if (isbnTLibro(c->libros[i]) == isbn)
        return true;

     }
      return false; //en el caso de que no esté en la coleccion
}

// Función para obtener un libro de una colección
// Recibe una colección y un isbn y regresa el libro con ese isbn
// El libro retornado comparte memoria con el parámetro.
// PRE: El libro debe estar en la colección
TLibro obtenerDeTColeccion(TColeccion c, int isbn){
    assert(estaEnTColeccion(c, isbn)); //uso assert para verificar que la PRE se cumpla, sino usaria un if normal

    for (int i = 0; i < c->tope; i++){
        if (isbnTLibro(c->libros[i]) == isbn)
            return c->libros[i];

    }
    return NULL; //por si no hubiera uno
}


// Función que retorna true si y solo si existe algún libro en la colección editado
// el día de la fecha pasada por parámetro.
// La función debe ejecutar un algoritmo de búsqueda binaria.
bool existenLibrosFechaTColeccion(TColeccion c, TFecha f)
{
    int izq = 0; //para hacer una busqueda binaria 
    int der = c->tope - 1; //porque empieza en 0 y no en 1

    while (izq <= der){
        int med = (izq + der) / 2;
        TFecha fmid = fechaEdicionTLibro(c->libros[med]);
        int cmp = compararTFechas(f, fmid);

        if (cmp == 0){
            return true;   
        }else if (cmp > 0){
            izq = med + 1; // si existe la fecha, va a estar de la mitad hacia la derecha del arreglo
        }else{
            der = med - 1; //buscara a la izquierda del arreglo 
        }
    }
    return false; //si no lo encontró

}

// Función para imprimir todos los libros de una colección con el género pasado por parámetro.
// Recibe una colección y un género e imprime la información de los libros con dicho género,
// ordenados por orden de inserción en la colección (en el orden en que aparecen en la colección)
// Si no hay libros con dicho género, no imprime nada.
void imprimirLibrosGeneroTColeccion(TColeccion c, int idGenero)
{
 int i;
 i = 0;
    if (c == NULL || c->tope == 0){ 
        return;

    }else{

        while (i <= c->tope - 1){
            if (idGenero == idGeneroTLibro(c->libros[i]) ){
                imprimirTLibro(c->libros[i]);
            }

            i++;
    }

    }
}

// Función para remover un libro de una colección
// Recibe una coleccón y el isbn del libro y remueve el libro con ese isbn de la colección.
// PRE: El libro debe pertenecer a la colección
void removerDeTColeccion(TColeccion &c, int isbn)
{
    int i = 0;
    //busco el indice del libro a eliminar
    while (i < c->tope && isbnTLibro(c->libros[i]) != isbn) {
        i++;
    }

    //libero el libro
    liberarTLibro(c ->libros[i]);

    //si el libro existe en la lista
    c->libros[i] = c->libros[c->tope -1]; //muevo el libro que estaba en el final a la posicion del libro a eliminar
    c->tope--; // el -- se usa igual que el ++ en el i, se usa para decrementar el valor de algo
}
