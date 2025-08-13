#include "../include/fecha.h"

struct rep_fecha
{
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;
    /****** Fin de parte Parte 2.1 *****/
};

//Funciones auxiliares que voy a crear para aumentar Tfecha
//verifica si el año es bisiesto
bool esBisiesto(nat anio){
    if ((anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0)) return true; //si es multiplo de 4 y no de 100, o de 400 es bisiesto
    
    return false;

}
//verifica los dias de un mes dado
static nat diasMes(nat mes, nat anio){ 
    switch (mes) {
    case 4 : case 6 : case 9 : case 11 : return 30;
    case 2 : return esBisiesto(anio) ? 29 : 28;
       
    default: return 31;
    }
}

static int comparador(TFecha fecha1, TFecha fecha2){
    if (fecha1->anio != fecha2->anio) //varios if comparando gerarquicamente el año, despues el mes y por ultimo el dia
    return (fecha1->anio > fecha2->anio) ? 1 : -1; //el ? funciona eligiendo 1 o -1 depende de el valor booleano que da lo de dentro del () 

    if (fecha1->mes != fecha2->mes) 
    return (fecha1->mes > fecha2->mes) ? 1 : -1;

    if (fecha1->dia != fecha2->dia)
    return (fecha1->dia > fecha2->dia) ? 1 : -1;

    return 0; //si las fechas son iguales 
}


TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    return nuevaFecha;
    
}

void liberarTFecha(TFecha &fecha)
{
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    delete fecha;
    fecha = NULL;
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha)
{
    printf("%u/%u/%u\n", fecha->dia, fecha->mes, fecha->anio);
}

TFecha copiarTFecha(TFecha fecha) //copia la fecha usando la funcion crear fecha
{                          
    if (fecha == NULL ) return NULL; //por si no me llegan a pasar ninguna fecha
    else 
    return crearTFecha(fecha->dia, fecha->mes, fecha->anio);

}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/

void aumentarTFecha(TFecha &fecha, nat dias) {

fecha->dia += dias;
while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
fecha->dia -= diasMes(fecha->mes, fecha->anio);
fecha->mes++;
if (fecha->mes > 12) {
fecha->mes = 1;
fecha->anio++;
}
}
}


/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    //imagino que las fechas no son nulas, si no aqui deberia ir el if de comprobacion de fechas nulas
    return comparador(fecha1, fecha2);
}
