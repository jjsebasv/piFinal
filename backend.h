#ifndef BACKEND_H
#define BACKEND_H


#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "constantes.h"
#include "getnum.h"


int quedanJugadasB(char **Matriz, int FIL, int COL);
int quedanJugadasA(char **Matriz, int FIL, int COL);
int decidirGanador(char **Matriz, int FIL, int COL);
int esValido(int i,int j, int filas, int columnas);
char ** crearMatriz(int fila,int columna);
void completarRestantes(char **Tablero, int FIL, int COL,int turno);
int leerJugada(int vec[]);
int maxComeBot(char **Matriz,int filas,int columnas,int vecBot[]);
int cuantosCome(char **Matriz,int h,int m,int fil,int col);
void jugadaBotB(char **Tablero,int vecBot[],int filas,int columnas);
struct archivo* nueva_estructura(char * vec, int turno, int juego,int fichas_1,int fichas_2 ,int filas, int cols);
void abrir_escribir_archivo(struct archivo *file, char * nombre);
void leer_archivo(char *nombre, struct archivo *file);
char * pedir_nombre_archivo(void);
void jugarVsBot(char **Tablero,int filas,int columnas);
void imprimirTablero(char **Tablero, int filas, int columnas);
int menuOpciones();
int randInt(int izq,int derecha);
void ingresarDim(int *fila, int *columna);
void asignaCerosyFichas(char** Tablero,int fil,int col);
int jugadaValidaA(char **Matriz,int vec[],int filas,int columnas);
int jugadaValidaB(char **Matriz,int vec[],int filas,int columnas);
void realizarJugadaB(char **Matriz, int vec[],int turno, int filas, int columnas);
void realizarJugadaA(char **Matriz, int vec[],int turno, int filas, int columnas);
void comerAdyacentes(char **Tablero,int n,int m,int turno, int filas, int columnas);
void completarRestantes(char **Tablero, int FIL, int COL,int turno);
int leerJugada(int vec[]);
int validar_quit() ;
int menu(); 






#endif /* BACKEND_H*/