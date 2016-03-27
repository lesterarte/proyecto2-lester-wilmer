#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "tiro.h"
#include "oneofthree.h"
#include "twoofthree.h"
#include "threeofthree.h"
#include <string>
#include <iostream>
using std::cout;

void mapa(); 
void mapapiezas(char**, int,int);
void crearpremios(char**,int, int);
void deletepremios(char**,int, int);
void signedpremios(char**,int,int);
void rules();
bool existencia(char**,char,char);
void clearmap(char**, int,int);

int main(int argc, char*argv[]){
	double apuestaJugador = 100;
	double gananciaJugador ;
	int filas = 3; 
	int columnas= 4; 
	char apuesta = ' '; 
	int cont = 0;
	int contar=0;
	int turnos=0; 
	char pocision[2];
	char** arraypremios = new char*[filas];
	srand(time(NULL));
	crearpremios(arraypremios,filas,columnas);
	signedpremios(arraypremios,filas,columnas);
	initscr();
	refresh();
	echo();
	
	while(apuesta != 51){
		turnos=0;
		clear();
		refresh();
		mvprintw(9,20,"***************************************** BIENVENIDO **************************************");
		mvprintw(10,17,"****************************************** TIRO AL BLANCO ***************************************"); 
		mvprintw(15,20, "1. JUGAR  "); 
		mvprintw(16,20, "2. COMO JUGAR??");
		mvprintw(17,20, "3. SALIR");
		move(18,20);
		noecho();
		apuesta = getch();
		mvprintw(9,20,"                                                                                                 ");
		mvprintw(10,17,"                                                                                                        "); 
		mvprintw(15,20, "                 ");
		mvprintw(16,20, "                    ");
		mvprintw(17,20, "                       ");

		if(apuesta == 49){
			double LePegoAlBlanco = -1;
			signedpremios(arraypremios,filas,columnas);
			clear();
			refresh();
			mapa();
			mapapiezas(arraypremios,filas,columnas);
			refresh();
			move(11,117);
			char apuntar;			 
			while(turnos < 3){
				while( contar  != 2){
					noecho();
					apuntar = getch();
					if(apuntar >= 48 && apuntar <= 57){
						if(contar > 0){
							if(pocision[0] == 48){
								if(apuntar > 48 && apuntar <= 57){
									pocision[1] = apuntar; 
									addch(apuntar);
									echo();

									contar++;
								}
							}else{
								if(apuntar == 48 || apuntar == 49 || apuntar == 50){
									pocision[1] = apuntar; 
									addch(apuntar);
									echo();
									contar++;
								}
							}
						}else{
							if(apuntar == 48 || apuntar == 49 ){
								pocision[0] = apuntar; 
								addch(apuntar);
								echo();

								contar++;
							}
						}
					}
				}//fin de while de ingreso de coordenada	segundo whiler anidado al while turnos
				contar=0;			
				move(11,117);
				
				if(existencia(arraypremios,pocision[0],pocision[1]) == true){
					clearmap(arraypremios,filas,columnas);
					mapapiezas(arraypremios,filas,columnas);
					refresh();
					mvprintw(18,90,"FELICIDADES ACERTASTE ");
						LePegoAlBlanco = LePegoAlBlanco+1;
					if(LePegoAlBlanco==0){

						oneofthree tr (0.10,apuestaJugador);
						gananciaJugador  = tr.DineroGanado();
						
					}	
					if (LePegoAlBlanco==1){
						twoofthree tr (0.35,apuestaJugador);
						gananciaJugador  = tr.DineroGanado();
						
					}	
					if (LePegoAlBlanco==2){
						threeofthree tr (0.50,apuestaJugador);
						gananciaJugador  = tr.DineroGanado();
						
					}	


					printw("[%lf] ",gananciaJugador );

					getch();

				}else{
					clearmap(arraypremios,filas,columnas);
					mapapiezas(arraypremios,filas,columnas);
					refresh();
					mvprintw(18,90,"PERDISTE, NO HAY PREMIO ");
					printw("[%lf] ",gananciaJugador );
					getch();
				}

				mvprintw(11,117,"   ");
				mvprintw(18,90,"                                              ");
				move(11,117);
				apuntar=' ';

				turnos++;
			}// fin del while turnos
		} //fin del if

		if(apuesta == 50){
			clear();
			refresh();
			rules();
			getch();
		}
		gananciaJugador = 0;
	}// fin de apuesta primer while
	
	endwin();
	deletepremios(arraypremios,filas,columnas);
	return 0; 
}//fin  main 

void clearmap(char** disparo,int fil,int cols)
{
	for(int i=0; i<fil;i++)
	{
		for(int j=0; j<cols;j++)
		{
			mvprintw((5 + (i*12)),(17 + (j*17)), "    ");
			mvprintw((6 + (i*12)),(17 + (j*17)), "    ");
			mvprintw((7 + (i*12)),(12 + (j*17)), "          ");
			mvprintw((8 + (i*12)),(12 + (j*17)), "          ");
			mvprintw((9 + (i*12)),(17 + (j*17)), "    ");
			mvprintw((10 + (i*12)),(17 + (j*17)), "     ");
			mvprintw((11 + (i*12)),(16 + (j*17)), "       ");
			mvprintw((12 + (i*12)),(15 + (j*17)), "          ");
		}
	}	
}
void rules()
{
	mvprintw(1,35,"******************** INSTRUCCIONES DE JUEGO **********************");
	mvprintw(5,10,"1. APOSTAR: ");
	mvprintw(7,10,"Al comenzar el juego cada jugador invierte una suma de dinero la cual es su capital para jugar.");
	mvprintw(8,10,"El juego termina cuando el jugador termina sus 3 tiros");
	mvprintw(9,10,"cada set de 3 tiros tiene un valor de $ 100");
	mvprintw(11,10,"2. TIROS: ");
	mvprintw(13,10,"El jugador cuenta con 3 tiros los cuales realizara de forma consecutiva y los que se premiaran de la siguiente manera:");
	mvprintw(14,13,"2.1 - si el jugador acierta 1 tiro de 3 su ganancia sera el 0.10 de su apuesta");
	mvprintw(15,13,"2.2 - si el jugador acierta 2 tiros de 3 su ganancia sera el 0.35 de su apuesta");
	mvprintw(16,13,"2.3 - si el jugador acierta 3 tiros de 3 su ganancia sera el 0.50 de su apuesta");
	mvprintw(18,10,"Si el jugador no aciera ningun juego se le preguntara si desea seguir jugando");
	mvprintw(30,10, "Cualquier tecla para continuar ");
}// fin de rules

void crearpremios(char** premios,int fil, int cols){
	for(int i=0;i<fil;i++)
	{
		premios[i] = new char [cols];	
	}
}// fin de crearpremios

void deletepremios(char** premios,int fil, int cols){
	for(int i=0; i<fil; i++)
	{
		delete[] premios[i];		
	}	

	delete[] premios; 
}// liberar memoria

void signedpremios(char** premios, int fil, int cols)
{ 
	for(int i=0; i<fil;i++)
	{
		for(int j=0; j<cols;j++)
		{
			premios[i][j]= '*';
		}
	}

	for(int i=0; i<5; i++)
	{
		premios[rand()%3][rand()%4] = '#';
	}	
}// fin de signedpremios

bool existencia(char** premios,char first, char second)
{

	int xchar= first - '0';
	int ychar= second - '0';
	int x,y; 
	if(xchar == 0)
	{
		if(ychar == 1)
		{
			x=0;
			y=0;
		}

		if(ychar == 2)
		{
			x=0;
			y=1;
		}
		if(ychar == 3)
		{
			x=0;
			y=2;
		}
		if(ychar == 4)
		{
			x=0;
			y=3;
		}
		if(ychar == 5)
		{
			x=1;
			y=0;
		}
		if(ychar == 6)
		{
			x=1;
			y=1;
		}
		if(ychar == 7)
		{
			x=1;
			y=2;
		}
		if(ychar == 8)
		{
			x=1;
			y=3;
		}
		if(ychar == 9)
		{
			x=2;
			y=0;
		}
	}
	else
	{
		if(ychar == 0)
		{
			x=2;
			y=1;
		}

		if(ychar == 1)
		{
			x=2;
			y=2;
		}
		if(ychar == 2)
		{
			x=2;
			y=3;
		}
	}

	if(premios[x][y] == '#')
	{
		premios[x][y] = '-';
		return true; 
	}
	else
	{
		premios[x][y] = '-';
		return false; 
	}
}// fin de existencia

void mapa()
{
	
	mvprintw(1,20,"***************************************** BIENVENIDO **************************************");
	mvprintw(2,17,"****************************************** TIRO AL BLANCO ***************************************");

	
	mvprintw(13,9,"     +---------+      +---------+      +---------+       +--------+   "); 
	mvprintw(14,9,"     |    01   |      |    02   |      |   03    |       |   04   |   ");  
	mvprintw(15,9,"-----+---------+------+---------+------+---------+-------+--------+-----  "); 
	mvprintw(25,9,"     +---------+      +---------+      +---------+       +--------+   "); 
	mvprintw(26,9,"     |    05   |      |    06   |      |    07   |       |   08   |   ");  
	mvprintw(27,9,"-----+---------+------+---------+------+---------+-------+--------+-----  "); 
	mvprintw(37,9,"     +---------+      +---------+      +---------+       +--------+   "); 
	mvprintw(38,9,"     |    09   |      |   10    |      |   11    |       |   12   |   ");  
	mvprintw(39,9,"-----+---------+------+---------+------+---------+-------+--------+-----  "); 
	mvprintw(10,90,"INGRESE LA POCISION DE LA PIEZA");
	mvprintw(11,90,"A LA QUE DESEA DISPARAR:  ");
}// fin de crear el mapa

void mapapiezas(char** disparo,int fil,int cols)
{
	for(int i=0; i<fil;i++)
	{
		for(int j=0; j<cols;j++)
		{
			if(disparo[i][j] != '-')
			{
				mvprintw((5 + (i*12)),(17 + (j*17)), "****");
				mvprintw((6 + (i*12)),(17 + (j*17)), "****");
				mvprintw((7 + (i*12)),(12 + (j*17)), "*********");
				mvprintw((8 + (i*12)),(12 + (j*17)), "*********");
				mvprintw((9 + (i*12)),(17 + (j*17)), "****");
				mvprintw((10 + (i*12)),(17 + (j*17)), "*****");
				mvprintw((11 + (i*12)),(16 + (j*17)), "*** ***");
				mvprintw((12 + (i*12)),(15 + (j*17)), "***   ***");
			}
		}
	}	
}//fin de mapa piezas
