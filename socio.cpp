#include "../include/socio.h"
#include <string.h> // para usar correctamente strcpy, ya que no usamos string, sino cadenas de caracteres

typedef struct arre_gen *TArrGen;

struct rep_socio {
    int ci;
    char nombre[MAX_NOMBRE_SOCIO];
    char apellido[MAX_APELLIDO_SOCIO];
    nat diaAlta, mesAlta, anioAlta;
    TFecha fechaAlta;
    TArrGen generos;
};

struct arre_gen {
    int g[MAX_GENEROS_FAVORITOS];
    int cantidad;
};

TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO],
                   nat diaAlta, nat mesAlta, nat anioAlta) {
    TSocio nuevoSocio = new rep_socio;

    nuevoSocio->ci = ci;
    strcpy(nuevoSocio->nombre, nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);

    TArrGen generos = new arre_gen;
    nuevoSocio->generos = generos;
    nuevoSocio->generos->cantidad = 0;
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio) {
    printf("Socio %d: %s %s\n", socio->ci, socio->nombre, socio->apellido);

    printf("Fecha de alta: ");
    imprimirTFecha(socio->fechaAlta);

    printf("Géneros favoritos: ");
    for (int i = 0; i < socio->generos->cantidad; i++) {
        printf("%d ", socio->generos->g[i]);
        if (i < socio->generos->cantidad - 1);
    }
    printf("\n");
}

void liberarTSocio(TSocio &socio) {
    if (socio != NULL) {
        // Primero libero la fecha que cree al crear al Socio
        liberarTFecha(socio->fechaAlta);
        delete socio->generos;
        delete socio;
        socio = NULL;
    }
}

int ciTSocio(TSocio socio) {
    return socio->ci;
}

char* nombreTSocio(TSocio socio) {
    return socio->nombre;
}

char* apellidoTSocio(TSocio socio) {
    return socio->apellido;
}

TFecha fechaAltaTSocio(TSocio socio) {
    return socio->fechaAlta;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero) {
    int* cantidad = &socio->generos->cantidad;
    if ((*cantidad) < MAX_GENEROS_FAVORITOS) {
        socio->generos->g[*cantidad] = idGenero;
        (*cantidad)++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero) {
    int aux = 0;
    while (aux < socio->generos->cantidad && idGenero != socio->generos->g[aux]) {
        aux++;
    }
    return aux < socio->generos->cantidad;
}

int cantidadGenerosFavoritosTSocio(TSocio socio) {
    return socio->generos->cantidad;
}

TSocio copiarTSocio(TSocio socio) {
    if (socio == NULL) return NULL; // primero evaluo si no hay socio

    TSocio copia = new rep_socio;

    copia->ci = socio->ci;
    strcpy(copia->nombre, socio->nombre);
    strcpy(copia->apellido, socio->apellido);

    copia->fechaAlta = copiarTFecha(socio->fechaAlta); // con copiarTFecha, la fecha tampoco comparte memoria
    TArrGen generos = new arre_gen;
    copia->generos = generos;
    copia->generos->cantidad = socio->generos->cantidad;

    for (int i = 0; i < socio->generos->cantidad; i++) {
        copia->generos->g[i] = socio->generos->g[i];
    }

    return copia;
}
