/*
 * informes.c
 *
 *  Created on: May 20, 2021
 *      Author: andre
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contribuyente.h"
#include "recaudacion.h"
#include "utn.h"
#include "informes.h"
/*

	a) Contribuyentes con más recaudaciones en estado “refinanciar”.
	b) Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimirá
	la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.
	c) Informar todos los datos de los contribuyentes de un tipo de recaudación
	ingresada por el usuario (ARBA, IIBB, GANANCIAS)
	d)Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de
	FEBRERO.

*/

/*
void contribuyentesConMasRecaudaciones(estructuraContribuyente arrayContribuyente[], int tamanoContribuyente, estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion){
	int contadorRecaudaciones  = 0;
	//int mayorRecaudaciones;
	if((arrayContribuyente != NULL) && (tamanoContribuyente > 0 ) && (arrayRecaudacion != NULL) && (tamanoRecaudacion > 0)){
				for(int i = 0; i < tamanoRecaudacion ; i++){

					if(arrayRecaudacion[i].isEmpty == 0 && arrayRecaudacion[i].estado == 0){
						contadorRecaudaciones++;

						printf(" \n         ****************  DATOS PERSONALES  ***************** ");
						printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE    NOMBRE");

						for(int j= 0; j < tamanoRecaudacion; j++){
										if ((arrayRecaudacion[j].idContribuyente == arrayContribuyente[i].idContribuyente) &&
												(arrayRecaudacion[j].isEmpty == 0)){

													mostrarUnaRecaudacion(arrayRecaudacion[j]);
													printf("      %s", arrayContribuyente[i].nombre);

										}else{
											printf("No hay recaudaciones saldadas");
											break;
										}
									};

					}
				}
		}
};*/

void mostrarCantidadRSaldadas(estructuraRecaudacion arrayRecaudacion[], int tamanoRecaudacion){
int contadorRSaldadas = 0;
	if((arrayRecaudacion != NULL) && (tamanoRecaudacion > 0))	{
			for(int i = 0; i < tamanoRecaudacion  ; i++){

				if((arrayRecaudacion[i].isEmpty == 0) && (arrayRecaudacion[i].estado == 2) ){

					if(arrayRecaudacion[i].importe  >= 1000){
						contadorRSaldadas++;
					if(contadorRSaldadas > 0){

							printf("\n Cantidad de recaudaciones saldadas de importe mayor a 1000: %d", contadorRSaldadas);
							printf(" \n         **************** RECAUDACIONES CON IMPORTE MAYOR A 1000  ***************** ");
							printf("\n   ID.RECAUDACION      MES       TIPO          ESTADO      IMPORTE      ID.CONTRIBUYENTE ");
							mostrarUnaRecaudacion(arrayRecaudacion[i]);

						}else{
							printf("No hay recaudaciones saldadas con importe mayor a 1000");
							break;
						}

					}
				}
			};

	};


};
int mostrarMenuInformes(int *respuesta) {

	int auxRespuesta;
	printf(" \n _____________MENÚ INFORMES_______________");
	printf( "\n |      "
			"\n |  1. Contribuyentes con más recaudaciones en estado “refinanciar”."
			"\n |  2. Cantidad de recaudaciones saldadas de importe mayor a 1000  "
			"\n |  3. Informar todos los datos de los contribuyentes de un tipo de recaudación      "
			"\n |  4. Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de FEBRERO.                 "
			"\n |  "


			);

	utn_getNumero(&auxRespuesta, "\n  Ingrese una opcion    ","\nError, ingrese una opcion del 1 al 9 \n\n", 1,4,3);
	*respuesta = auxRespuesta;

	return 0;

};

