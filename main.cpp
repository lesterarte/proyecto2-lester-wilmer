#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 

void mapa(); 
void crearpremios(char**,int, int);
void deletepremios(char**,int, int);
void signedpremios(char**,int,int);
int main(int argc, char*argv[])
{
	int filas = 3; 
	int columnas= 4; 
	char apuesta = ' '; 
	int cont = 1; 
	char** arraypremios = new char*[filas];
	srand(time(NULL));
	initscr();
	refresh();
	echo();
	mvprintw(9,20,"***************************************** BIENVENIDO **************************************");
	mvprintw(10,17,"****************************************** TIRO AL BLANCO ***************************************"); 
	mvprintw(15,20, "INGRESE LA CANTIDAD DE DINERO QUE DESEA APOSTAR: "); 

	while( apuesta != '\n')
	{
		noecho();
		apuesta = getch();
		if( cont > 1 && apuesta >= 48  && apuesta <58)
		{
			addch(apuesta);
			echo();
		}
		else if(apuesta >= 49  && apuesta <58)
		{
			addch(apuesta);
			echo();
			cont++; 
		}
		
	}

	mvprintw(9,20,"                                                                                                 ");
	mvprintw(10,17,"                                                                                                        "); 
	mvprintw(15,20, "                                                                "); 
	mapa();
	getch();
	endwin();
	return 0; 
}

void crearpremios(char** premios,int fil, int cols)
{
	for(int i=0;i<fil;i++)
	{
		premios[i] = new char [cols];	
	}
}

void deletepremios(char** premios,int fil, int cols)
{
	for(int i=0; i<fil; i++)
	{
		delete[] premios[i];		
	}	

	delete[] premios; 
}

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
}

void mapa()
{
	
	mvprintw(1,20,"***************************************** BIENVENIDO **************************************");
	mvprintw(2,17,"****************************************** TIRO AL BLANCO ***************************************");

	mvprintw(5,8,"         ****             ****             ****             ****   ");
	mvprintw(6,8,"         ****             ****             ****             ****   ");
	mvprintw(7,8,"    *********        *********        *********        *********  ");
	mvprintw(8,8,"    *********        *********        *********        *********   ");
	mvprintw(9,8,"         ****             ****             ****             ****   ");
	mvprintw(10,8,"        *****            *****            *****            *****   ");
	mvprintw(11,8,"       *** ***          *** ***          *** ***          *** ***   ");
	mvprintw(12,8,"      ***   ***	      ***    ***        ***   ***        ***   ***   ");
	mvprintw(13,8,"     +---------+      +---------+      +---------+      +--------+   "); 
	mvprintw(14,8,"     |    1    |      |     2   |      |    3    |      |   4    |   ");  
	mvprintw(15,8,"-----+---------+------+---------+------+---------+------+--------+-----  "); 
	mvprintw(17,8,"         ****             ****             ****             ****   ");
	mvprintw(18,8,"         ****             ****             ****             ****   ");
	mvprintw(19,8,"    *********        *********        *********        *********  ");
	mvprintw(20,8,"    *********        *********        *********        *********   ");
	mvprintw(21,8,"         ****             ****             ****             ****   ");
	mvprintw(22,8,"        *****            *****            *****            *****   ");
	mvprintw(23,8,"       *** ***          *** ***          *** ***          *** ***   ");
	mvprintw(24,8,"      ***   ***	      ***    ***        ***   ***        ***   ***   ");
	mvprintw(25,8,"     +---------+      +---------+      +---------+      +--------+   "); 
	mvprintw(26,8,"     |    5    |      |     6   |      |    7    |      |   8    |   ");  
	mvprintw(27,8,"-----+---------+------+---------+------+---------+------+--------+-----  "); 
	mvprintw(28,8,"         ****             ****             ****             ****   ");
	mvprintw(29,8,"         ****             ****             ****             ****   ");
	mvprintw(30,8,"    *********        *********        *********        *********  ");
	mvprintw(31,8,"    *********        *********        *********        *********   ");
	mvprintw(32,8,"         ****             ****             ****             ****   ");
	mvprintw(33,8,"        *****            *****            *****            *****   ");
	mvprintw(34,8,"       *** ***          *** ***          *** ***          *** ***   ");
	mvprintw(35,8,"      ***   ***	      ***    ***        ***   ***        ***   ***   ");
	mvprintw(36,8,"     +---------+      +---------+      +---------+      +--------+   "); 
	mvprintw(37,8,"     |    9    |      |    10   |      |    11   |      |   12   |   ");  
	mvprintw(38,8,"-----+---------+------+---------+------+---------+------+--------+-----  "); 

	mvprintw(19,90,"INGRESE LA POCISION DE LA PIEZA");
	mvprintw(20,90,"A LA QUE DESEA DISPARAR:  ");
 
}

