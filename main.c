#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "frontend.h"



int main(void){

int filas,columnas,opcion,ganador,quit;
char **Tablero;
srand(time(NULL));

opcion = menu();

switch (opcion){

        case 1: ingresarDim(&filas,&columnas);
                Tablero=crearMatriz(filas,columnas);
                asignaCerosyFichas(Tablero,filas,columnas);
                jugar1v1(Tablero,filas,columnas);

                ganador=decidirGanador(Tablero,filas,columnas);
                if(ganador == 0)
                printf("¡¡Ha sido un empate!!\n");
                else
                printf("El ganador es el jugador %d. Felicitaciones!\n",ganador);
                break;

        case 2: ingresarDim(&filas,&columnas);
                Tablero=crearMatriz(filas,columnas);
                asignaCerosyFichas(Tablero,filas,columnas);
                jugarVsBot(Tablero,filas,columnas);

                ganador=decidirGanador(Tablero,filas,columnas);
                if(ganador==0){
                printf("Ha sido un empate!\n");
                }
                else if(ganador == 1)
                    printf("Has Ganado!\n");
                else
                    printf("Game Over\n");
                break;

        case 3: //MARU ACA PONE LO DE GUARDAR

        case 4: printf("¿Seguro que desea cerrar?\n");
                //printf("En ese caso, escriba la palabra 'quit'\n");
                //quit=validar_quit();
                //if (quit == 1)
                //{
                    printf("El juego se cerrara...\n");
                    break;
                //}
                //else
                //{
                  //  opcion= menu();
                    //break;
                //}
}

printf("Gracias por jugar BlobWars!\n");
return 0;
}


