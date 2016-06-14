#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <stdbool.h>
#include <stddef.h>


#define BOT 2
#define JUGADOR1 1
#define JUGADOR2 2
#define INICIAL 13
#define CORCHETE_ABIERTO 14
#define CORCHETE_CERRADO 15
#define NUMERO 16
#define COMA 17
#define FINAL 18
#define ERROR 19
#define LETRA_Q 2
#define LETRA_U 3
#define LETRA_I 4

typedef struct archivo {
  char * vec; 
  int juego;
  int turno;
  int fichas_1;
  int fichas_2;
  int filas; 
  int columnas; 
}archivo_t;


#endif /* CONSTANTES_H */


