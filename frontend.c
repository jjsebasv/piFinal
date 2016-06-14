#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "frontend.h"





void jugar1v1(char **Tablero, int filas, int columnas){

int turno,hayJugadas = 1;
int aux,aux2,opcion;
int vec[4];
int terminado=0;

turno = randInt(1,2);

printf("Comienza el juego!\n");
printf("Empieza el jugador %d.\n",turno);
while (terminado == 0){

    switch(turno){
        case JUGADOR1:

            if(hayJugadas == 0){ // si el jugador anterior se quedo sin movimientos, rellena los casilleros vacios con fichas del jugador1.
                system("clear");
		            completarRestantes(Tablero,filas,columnas,turno);
                terminado=1;                                           //sale del while
                imprimirTablero(Tablero,filas,columnas);
                break;
            }

            hayJugadas=quedanJugadasA(Tablero,filas,columnas); //checkea si el jugador puede realizar jugadas. 1 si hay jugadas, 0 sino.

            if(hayJugadas == 1){    //si el jugador tiene jugadas disponibles
		            system("clear");
                imprimirTablero(Tablero,filas,columnas);
                printf("Turno jugador 1.\n");
                opcion=menuOpciones();    // 1-Realizar jugada 2-Guardar 3-QUIT

                    switch(opcion){

                            case 1: aux=0;
                                    aux2=0;
                                    do{
                                    printf("Ingrese su jugada en formato [F1,C1][F2,C2]\n");
                                    aux=leerJugada(vec);

                                    if(aux==1){
                                        aux2=jugadaValidaA(Tablero,vec,filas,columnas);

                                            if(aux2==1){
                                                realizarJugadaA(Tablero,vec,turno,filas,columnas); //Se le pasa elturno porque lo usa comerAdyacentes
                                            }
                                            else if(aux2==-1){
                                                printf("No tienes una ficha en esa posicion.\n");
                                                aux2=4;
                                            }
                                            else if(aux2==-2){
                                                printf("Movimiento invalido\n");
                                                aux2=4;
                                            }
                                            else{
                                                printf("Ingreso fuera de rango.\n");
                                                aux2=4;
                                            }
                                    }
                                    else{
                                            printf("Ingreso invalido. \n");
                                            aux2=4;
                                        }
                                    }while( aux2==4 );
                                    break;

                            case 2: terminado=1;
                                    break; //GUARDAR PARTIDA

                            case 3: terminado=1;
                                    break;

                    }
            }
            else{
                printf("El jugador 1 no tiene mas jugadas disponibles,se completará el tablero con fichas del jugador 2.\n");
            }
            turno=JUGADOR2;
            break;


        case JUGADOR2:

            if(hayJugadas == 0){ // si el jugador anterior se quedo sin movimientos, rellena los casilleros vacios con fichas del jugador1.
                system("clear");
                completarRestantes(Tablero,filas,columnas,turno);
                terminado=1;                                           //sale del while
                imprimirTablero(Tablero,filas,columnas);
                break;
            }

            hayJugadas=quedanJugadasB(Tablero,filas,columnas); //checkea si el jugador puede realizar jugadas. 1 si hay jugadas, 0 sino.

            if(hayJugadas == 1){    //si el jugador tiene jugadas disponibles
		          system("clear");
                imprimirTablero(Tablero,filas,columnas);
                printf("Turno jugador 2:\n");
                opcion=menuOpciones();
                    switch(opcion){

                            case 1: aux=0;
                                    aux2=0;
                                    do{
                                    printf("Ingrese su jugada en formato [F1,C1][F2,C2]\n");

                                    aux=leerJugada(vec);

                                    if(aux==1){

                                        aux2=jugadaValidaB(Tablero,vec,filas,columnas);
                                            if(aux2==1){
                                                realizarJugadaB(Tablero,vec,turno,filas,columnas); //Se le pasa elturno porque lo usa comerAdyacentes
                                            }
                                            else if(aux2==-1){
                                                printf("No tienes una ficha en esa posicion.\n");
                                                aux2=4;
                                            }
                                            else if(aux2==-2){
                                                printf("Movimiento invalido.\n");
                                                aux2=4;
                                            }
                                            else{
                                                printf("Ingreso fuera de rango\n");
                                                aux2=4;
                                            }
                                    }
                                    else{
                                            printf("Ingreso invalido. \n");
                                            aux2 = 4;
                                    }

                                    }while( aux2==4 );

                                    break;

                            case 2: break;
                                    terminado=1;  //GUARDAR PARTIDA

                            case 3: terminado=1;
                                    break;
                    }
            }
            else{
                printf("El jugador 2 no tiene mas jugadas disponibles,se completará el tablero con fichas del jugador 1.\n");

            }
            turno = JUGADOR1;
            break;
    }
}//while

printf("FIN DEL JUEGO!\n");

}


