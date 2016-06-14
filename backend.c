#include "backend.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>



int quedanJugadasB(char **Matriz, int FIL, int COL){ //PROBADA
int i,j,h,k,huboceros;

huboceros = 0;


    for (i=0 ; i<FIL && huboceros == 0 ; i++){

        for(j=0 ; j<COL && huboceros == 0; j++){

            if(Matriz[i][j] == 'Z'){

                for (h=(i-2) ; h<=(i+2) && huboceros == 0 ; h++) {  //una vez que encontro un 0 ya sabemos que hay jugada, por ende sale del ciclo.
                    for (k=j-2 ; k<=j+2 && huboceros == 0 ; k++){

                        if(esValido(h,k,FIL,COL) ){

                            if( Matriz[h][k] == '0' ){ //encontro un cero dentro del rango de 4x4 de la ficha.
                                huboceros = 1;
                            }
                        }

                    }
                }

            }
        }
    }


if(huboceros==1)
return 1;
else
return 0;
}


int quedanJugadasA(char **Matriz, int FIL, int COL){ //PROBADA

int i,j,h,k,huboceros;

huboceros = 0;

    for (i=0 ; i<FIL && huboceros == 0 ; i++){

        for(j=0 ; j<COL && huboceros == 0; j++){

            if(Matriz[i][j] == 'A'){

                for (h=(i-2) ; h<=(i+2) && huboceros == 0 ; h++) {  //una vez que encontro un 0 ya sabemos que hay jugada, por ende sale del ciclo.
                    for (k=j-2 ; k<=j+2 && huboceros == 0 ; k++){

                        if(esValido(h,k,FIL,COL) ){

                            if( Matriz[h][k] == '0' ){ //encontro un cero dentro del rango de 4x4 de la ficha.
                                huboceros = 1;
                            }
                        }

                    }
                }

            }
        }
    }


if(huboceros==1)
return 1;
else
return 0;
}


int decidirGanador(char **Matriz, int FIL, int COL){ //PROBADA

int fichasJ1, fichasJ2;
int i,j;



fichasJ1=0;
fichasJ2=0;

for (i=0 ; i<FIL ; i++){
    for (j=0 ; j<COL ; j++) {

            if(Matriz[i][j]=='A'){
                fichasJ1++;
            }
            else if (Matriz[i][j]=='Z'){
                fichasJ2++;
            }

    }
}


if(fichasJ1>fichasJ2)
return 1;
else if(fichasJ1==fichasJ2)
return 0;
else
return 2;

}



int esValido(int i,int j, int filas, int columnas){  //PROBADA

if(i>=0 && j>=0 && i<=(filas-1) && j<=(columnas-1) )
    return 1;
else
    return 0;
}

char ** crearMatriz(int fila,int columna){ //AGREGAR TODO LO DE NULL,PROBADA



int i;
char **m2;

m2=malloc(fila*sizeof(char*));

for(i=0 ; i<fila ; i++){

    m2[i] = malloc(columna*sizeof(char));
}

return m2;
}




void asignaCerosyFichas(char** Tablero,int fil,int col){ //PROBADA

int i,j;

    for(i=0 ; i<fil ; i++){
        for(j=0 ; j<col ; j++){
            Tablero[i][j]='0';
        }
    }
Tablero[0][0]='A';
Tablero[fil-1][0]='A';
Tablero[0][col-1]='Z';
Tablero[fil-1][col-1]='Z';

}

void imprimirTablero(char** Tablero, int filas, int columnas){ //PROBADA
int i,j;

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%c ",Tablero[i][j]);

        }
        printf("\n");
    }
}


int jugadaValidaA(char **Matriz,int vec[],int filas,int columnas){ // PROBADA

int i,j,n,m;
int aux,aux2;

i = vec[0];
j = vec[1];
n = vec[2];
m = vec[3];

aux=esValido(i,j,filas,columnas);
aux2=esValido(n,m,filas,columnas);

if(aux==1 && aux2==1){


    if(Matriz[i][j] == 'A'){

        if( ((abs(i-n))<= 2 ) && ((abs(j-m))<=2) && (Matriz[n][m]=='0') )
            return 1;

        else
            return -2; //MOVIMIENTO NO PERMITIDO


    }
    else
        return -1; //NO TIENE UNA FICHA EN ESA POSICION
}
else
return -3; //DATOS INGRESADOS NO TIENE SENTIDO CON LA MATRIZ

}


int randInt(int izq,int derecha){ //PROBADA

return rand()%(derecha-izq+1)+izq;
}


void ingresarDim(int *fila, int *columna){ //PROBADA

int a,b;

do{
printf("Ingrese el numero de filas entre 5 y 30:\n");
scanf("%d",&a);
if(a<5 || a>30)
printf("Ingreso Incorrecto.\n");
}while( a<5 || a>30);

do{
printf("Ingrese el numero de columnas entre 5 y 30:\n");
scanf("%d",&b);
if(b<5 || b>30)
printf("Ingreso Incorrecto.\n");
}while( b<5 || b>30);

*fila = a;
*columna = b;

}


int menu(){ //PROBADA

int opcion;

do{
printf("Elige una opcion para continuar:\n");
printf("1-Partida de dos jugadores.\n");
printf("2-Partida contra la maquina.\n");
printf("3-Cargar una partida guardada.\n");
printf("4-Salir.\n");

opcion=getint("");
}while( opcion<1 || opcion>4);
return opcion;

}


void realizarJugadaB(char **Matriz, int vec[],int turno, int filas, int columnas){ //PROBADA
int distFila;
int distCol;
int i, j, n, m;


i = vec[0];
j = vec[1];
n = vec[2];
m = vec[3];

distFila = abs(i-n);
distCol = abs(j-m);

if( distFila==2 || distCol==2 ){
    Matriz[n][m] = 'Z';
    Matriz[i][j] = '0';
    comerAdyacentes(Matriz,n,m,turno,filas,columnas);

}
else{
    Matriz[n][m] = 'Z';
    comerAdyacentes(Matriz,n,m,turno,filas,columnas);

}

}

void realizarJugadaA(char **Matriz, int vec[],int turno, int filas, int columnas){ //PROBADA

int distFila;
int distCol;
int i, j, n, m;


i = vec[0];
j = vec[1];
n = vec[2];
m = vec[3];

distFila = abs(i-n);
distCol = abs(j-m);

if( distFila==2 || distCol==2 ){
    Matriz[n][m] = 'A';
    Matriz[i][j] = '0';
    comerAdyacentes(Matriz,n,m,turno,filas,columnas);
}
else{
    Matriz[n][m] = 'A';
    comerAdyacentes(Matriz,n,m,turno,filas,columnas);
}
}



void comerAdyacentes(char **Tablero,int n,int m,int turno, int filas, int columnas){

int i,j;

if(turno==1){
    for(i=n-1 ;i<=n+1 ; i++){
        for(j=m-1 ; j<=m+1 ;j++){
            if(esValido(i,j,filas,columnas)){
                if(Tablero[i][j]=='Z'){
                    Tablero[i][j] = 'A';
                }
            }
        }

    }
  }
else {

    for(i=n-1 ;i<=n+1 ; i++){
        for(j=m-1 ; j<=m+1 ;j++){
            if(esValido(i,j,filas,columnas)){
                if(Tablero[i][j]=='A'){
                    Tablero[i][j] = 'Z';
                }

            }
        }

    }

}
}


int jugadaValidaB(char **Matriz,int vec[],int filas,int columnas){ //PROBADA
int i,j,n,m;
int aux,aux2;

i = vec[0];
j = vec[1];
n = vec[2];
m = vec[3];

aux=esValido(i,j,filas,columnas);
aux2=esValido(n,m,filas,columnas);

if(aux==1 && aux2){


    if(Matriz[i][j] == 'Z'){

        if( ((abs(i-n))<= 2 ) && ((abs(j-m))<=2) && (Matriz[n][m]=='0') )
            return 1;

        else
            return -2; //MOVIMIENTO NO PERMITIDO


    }
    else
        return -1; //NO TIENE UNA FICHA EN ESA POSICION
}
else
return -3; //DATOS INGRESADOS NO TIENE SENTIDO CON LA MATRIZ

}


void completarRestantes(char **Tablero, int FIL, int COL,int turno){ //PROBADA
int i,j;

if(turno==1){
    for(i=0 ;i<FIL ; i++){
        for(j=0 ; j<COL ; j++){
            if(Tablero[i][j] == '0'){
                Tablero[i][j] = 'A';
            }
        }
    }
}
else{
    for(i=0 ;i<FIL ; i++){
        for(j=0 ; j<COL ; j++){
            if(Tablero[i][j] == '0'){
                Tablero[i][j] = 'Z';
            }
        }
    }

}

}

int leerJugada(int vec[])  //-1 si el ususario ingreso mal la jugada [F1,C1][F2,C2] y 1 si es correcto *PROBADA*
{
  int cantnum=1; //simplemente para diferenciar los casos que haya uno o dos numeros
  int aux,i=0;
  int estado=INICIAL;
  int c,contCorcheteCerrado=0; //simplemente para diferenciar del primer corchete que lo deberia seguir un [, del final de la jugada
  int resp;
  while ((c=getchar()) != '\n')
  {
   switch(estado)
    {
      case INICIAL:

                  if (c == '[')
                    {
                      estado=CORCHETE_ABIERTO;
                      break;
                    }
                  else
                    {
                      estado=ERROR;
                      break;
                    }

      case CORCHETE_ABIERTO:

                              if(isdigit(c))
                              {
                                cantnum=1;
                                aux=(c-'0'); //c-'0' pasa mi parametro char a numero de valor int, sino devolveria basura
                                estado=NUMERO;
                                break;
                              }
                              else
                              {
                                estado=ERROR;
                                break;
                              }

      case NUMERO:

                              if(isdigit(c)) //segundo numero, guardado en aux por 10 mas c me da nro de dos digitos
                              {
                                cantnum++;
                                vec[i]=((aux*10)+(c-'0'));
                                i++;
                                estado=NUMERO;
                                  if (cantnum>2) //en caso de que ingerse mas de dos digitos sale error
                                  {
                                    estado=ERROR;
                                    break;
                                  }
                                break;
                              }
                              else if (cantnum == 2 && c == ',') //es distinto el caso de si hay 2 digitos y despues una coma
                              {
                                cantnum=1;
                                estado=COMA;
                                break;
                              }
                              else if(c == ',')
                              {
                                vec[i]=aux;
                                i++;
                                estado=COMA;
                                break;
                              }
                              else if(cantnum == 2 && contCorcheteCerrado == 1 && c == ']')
                              {
                                estado=FINAL;
                                break;
                              }
                              else if(cantnum == 1 && contCorcheteCerrado == 1 && c == ']')
                              {
                                vec[i]=aux;
                                estado=FINAL;
                                break;
                              }
                              else if(cantnum == 1 && contCorcheteCerrado == 0 && c == ']')
                              {
                                vec[i]=aux;
                                i++;
                                contCorcheteCerrado=1;
                                estado=CORCHETE_CERRADO;
                                break;
                              }
                              else if(cantnum == 2 && contCorcheteCerrado == 0 && c == ']')
                              {
                                cantnum=1;
                                estado=CORCHETE_CERRADO;
                                contCorcheteCerrado=1;
                                break;
                              }
                              else
                              {
                                estado=ERROR;
                                break;
                              }

      case COMA:

                              if(isdigit(c))
                              {
                                cantnum=1;
                                aux=(c-'0');
                                estado=NUMERO;
                                break;
                              }
                              else
                              {
                                estado=ERROR;
                                break;
                              }

      case CORCHETE_CERRADO:

                          if(c == '[')
                          {
                            estado=CORCHETE_ABIERTO;
                            break;
                          }
                          else
                          {
                            estado=ERROR;
                            break;
                          }

      case ERROR:
                  break;
      case FINAL:
                if ( c != '\n')
                {
                  estado=ERROR;
                  break;
                }
                else
                  break;

    }
  }

  if (estado != FINAL)
    resp=-1;
  else
    resp=1;
  return resp;





}


int menuOpciones(){ //PROBADA
int option;
do{

printf("Ingrese la opcion deseada:\n");
printf("1-Realizar jugada.\n");
printf("2-Guardar mi partida.\n");
printf("3-EXIT.\n");
option=getint("");
if(option != 1 && option != 2 && option != 3){
printf("Opcion inválida.\n");
}

}while(option != 1 && option != 2 && option != 3);

return option;
}

void matrizAVec(char **Tablero, int filas, int columnas) //probada
{
  int k=0, i, j;
  char *vec=malloc(sizeof(char)*columnas*filas);
  for (i = 0 ; i < filas ; i++)
  {
    for (j = 0 ; j < columnas ; j++)
    {
      vec[k++]=Tablero[i][j];
    }
  }
}




void vecAmatriz(char **Matriz,char vec[],int filas,int columnas){

int i,j,k;
k=0;

for(i=0 ;i<filas ;i++){
    for(j=0 ;j<columnas ;j++){
        Matriz[i][j]=vec[k++];
    }
}

}

void cuentaFichas(char **Matriz,int filas,int columnas){

int i,j;
int cantidadA,cantidadZ;
cantidadA=0;
cantidadZ=0;

for(i=0 ;i<filas ;i++){
    for(j=0 ;j<columnas ;j++){

        if(Matriz[i][j]=='A'){
        cantidadA++;
        }
        else if(Matriz[i][j]=='Z'){
        cantidadZ++;
        }


    }
}
printf("El jugador 1 tiene %d ficha%s.\n",cantidadA,((cantidadA>1)||(cantidadA==0))?"s":"");
printf("El jugador 2 tiene %d ficha%s.\n",cantidadZ,((cantidadZ>1)||(cantidadZ==0))?"s":"");


}

int validar_quit()  //validar_quit retorna 0 si es falso, 1 si es verdadero
{
	int c;
	int estado=INICIAL;
	while((c=getchar()) != '\n')
	{
		switch(estado)
		{
				case INICIAL:
						if (c == 'q')
						{
							estado=LETRA_Q;
							break;
						}
						else
						{
							estado=ERROR;
							break;
						}
				
				case LETRA_Q:
						if (c == 'u')
						{
							estado=LETRA_U;
							break;
						}
						else
						{
							estado=ERROR;
							break;
						}
				
				case LETRA_U:
						if (c == 'i')
						{
							estado=LETRA_I;
							break;
						}
						else
						{
							estado=ERROR;
							break;
						}
				case LETRA_I:
						if(c == 't')
						{
							estado=FINAL;
							break;
						}
						else
						{
							estado=ERROR;
							break;
						}
				case ERROR:
					break;
		}
	}
	if (estado != FINAL)
		return 0;
	else
		return 1;
}


struct archivo* nueva_estructura(char * vecMat, int turno, int juego,int fichas_1,int fichas_2, int filas, int columnas) {
  
    struct archivo * file = (struct archivo*)malloc(sizeof(struct archivo));
    file->vec = malloc(sizeof(char)*filas*columnas);
    memcpy(file->vec,vecMat,(filas*columnas));
    file->turno=turno;
    file->juego=juego;
    file->fichas_1=fichas_1;
    file->fichas_2=fichas_2;
    file->filas=filas;
    file->columnas=columnas;
    return file;
    
}
void abrir_escribir_archivo(struct archivo *file, char* nombre){
	
	FILE *fp;
	if((fp=fopen(nombre, "wb"))==NULL) {
    	printf("No se puede abrir el archivo.\n");
	}
	fwrite(file, sizeof(struct archivo),1,fp);
	fclose(fp);

}

void leer_archivo(char *nombre, struct archivo *file){
	FILE *fp;
	if((fp=fopen(nombre, "rb"))==NULL) {
    	printf("No se puede abrir el archivo.\n");
	}
	fread(file,sizeof(struct archivo),1,fp);
	fclose(fp);

}

char * pedir_nombre_archivo(void){
  
  char c;
  int i=0;
  char *nombre=malloc(sizeof(char)*80);
  printf("Por favor a continuacion ingrese nombre del archivo seguido de un Enter \n");
  while((c=getchar()) != '\n' ){
    nombre[i]=c;
    i++;
  }
  nombre[i]='\0';
  return nombre;
}



int maxComeBot(char **Matriz,int filas,int columnas,int vecBot[]){
  int i, j, h, m;
  int maxCome=0, maxTotal=0;
  int aux;

    for (i=0 ; i<filas ; i++){
        for (j=0 ; j<columnas ; j++){
            if (Matriz[i][j] == 'Z'){
                for(h=(i-2) ; h<=(i+2) ; h++){
                    for (m=(j-2) ; m<=(j+2) ; m++){
                        if(esValido(h,m,filas,columnas)){
                            if (Matriz[h][m] == '0'){
                                    maxCome = cuantosCome(Matriz,h,m,filas,columnas);

                                    if (maxCome > maxTotal){

                                        maxTotal=maxCome;
                                        vecBot[0]=i;
                                        vecBot[1]=j;
                                        vecBot[2]=h;
                                        vecBot[3]=m;

                                    }
                                    else if (maxCome == maxTotal && maxTotal != 0){
                                        aux=randInt(1,2);
                                        switch (aux){

                                            case 1:break;

                                            case 2: vecBot[0]=i;
                                                    vecBot[1]=j;
                                                    vecBot[2]=h;
                                                    vecBot[3]=m;
                                                    break;
                                        }

                                    }
                            }

                        }
                    }
                }
            }
        }
    }

return maxTotal;

}

int cuantosCome(char **Matriz,int h,int m,int fil,int col){
int p,n;
int contador=0;


                for (p=(h-1) ; p<=(h+1) ; p++){
                    for (n=(m-1) ; n<=(m+1) ; n++){
                        if(esValido(p,n,fil,col)){
                            if (Matriz[p][n] == 'A'){
                                contador++;

                            }
                        }
                    }
                }

return contador;

}

void jugadaBotB(char **Tablero,int vecBot[],int filas,int columnas){



int i,j,h,k,aux;
int huboPrimera=0;

for(i=0 ; i<filas; i++){   //Recorre el tablero hasta encontrar una pieza.
    for(j=0; j<columnas ;j++){

        if(Tablero[i][j]=='Z'){ //Si encontro una pieza recorre los casilleros adyacentes para ver si se puede mover (encontrar un 0)

            for(h=i-1; h<=i+1; h++){
                    for(k=j-1 ; k<=j+1 ; k++){
                        if(esValido(h,k,filas,columnas)){
                            if(Tablero[h][k]=='0'){ //Si encontro un 0 en los casilleros adyacentes de la ficha entra al if

                                if(huboPrimera==0){ //La primera vez no se puede hacer un rand de la jugada ya que es la primera encontrada.
                                vecBot[0]=i;
                                vecBot[1]=j;
                                vecBot[2]=h;
                                vecBot[3]=k;
                                huboPrimera=1;
                                }
                                else {      //Ya se encontro otra jugada de duplicado para alguna ficha, elige al azar cual toma.
                                aux=randInt(1,2);
                                    switch(aux){

                                        case 1: break;
                                        case 2: vecBot[0]=i;
                                                vecBot[1]=j;
                                                vecBot[2]=h;
                                                vecBot[3]=k;
                                                break;
                                    }
                                }
                            }
                        }
                    }

            }


        }
    }
}//primer for
}




void jugarVsBot(char **Tablero,int filas,int columnas){


int turno,aux,aux2,auxBot,opcion;
int hayJugadas=1;
int vec[4],vecBot[4];
int terminado=0;


turno=randInt(1,2);
printf("Comienza el juego!\n");

while(terminado==0){

    switch(turno){

        case JUGADOR1:

            if(hayJugadas == 0){ // si el jugador anterior se quedo sin movimientos, rellena los casilleros vacios con fichas del jugador1.
                completarRestantes(Tablero,filas,columnas,turno);
                terminado=1;                                           //sale del while
                imprimirTablero(Tablero,filas,columnas);
                break;
            }

            hayJugadas=quedanJugadasA(Tablero,filas,columnas); //checkea si el jugador puede realizar jugadas. 1 si hay jugadas, 0 sino.

            if(hayJugadas == 1){    //si el jugador tiene jugadas disponibles
                system("sleep 1");
                system("clear");
                imprimirTablero(Tablero,filas,columnas);
                printf("Turno jugador 1.\n");
                opcion=menuOpciones();    // 1-Realizar jugada 2-Guardar 3-QUIT

                    switch(opcion){

                            case 1:
                                    do{
                                    printf("Ingrese su jugada en formato [F1,C1][F2,C2]\n");

                                    aux=leerJugada(vec);


                                    if(aux==1){
                                        aux2=jugadaValidaA(Tablero,vec,filas,columnas);

                                            if(aux2==1){
                                                system("clear");
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
                system("clear");
                printf("No tienes mas jugadas disponibles,se completara el tablero con fichas del ordenador.\n");
            }
            turno=BOT;
            break;

        case BOT:

            if(hayJugadas == 0){
                system("sleep 1");
                completarRestantes(Tablero,filas,columnas,turno); //completa casilleros vacios con fichas del BOT.
                terminado = 1;
                imprimirTablero(Tablero,filas,columnas); //imprime el Tablero
                break;
            }
            hayJugadas=quedanJugadasB(Tablero,filas,columnas); //0 si NO hay jugadas 1 si hay.
            if(hayJugadas==1){
                imprimirTablero(Tablero,filas,columnas);
                printf("Turno BOT.\n");
                system("sleep 2");
                auxBot=maxComeBot(Tablero,filas,columnas,vecBot);
                if(auxBot>0){   //Si se encontro una jugada que come fichas del otro jugador, realiza dicha jugada.
                    realizarJugadaB(Tablero,vecBot,turno,filas,columnas);   //
                }
                else{ //No hay jugadas que comen fichas
                    jugadaBotB(Tablero,vecBot,filas,columnas); //Guarda en vecBot una jugada de duplicado disponible para el Bot.
                    realizarJugadaB(Tablero,vecBot,turno,filas,columnas);   //Realiza dicha jugada
                }
            }
            else{
            printf("El ordenador se ha quedado sin jugadas,se rellenara el tablero con fichas del jugador 1.\n");
            }
            turno=JUGADOR1;
            break;
    }//switch
}//while

}
