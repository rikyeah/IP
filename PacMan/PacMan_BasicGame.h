#ifndef _PACMAN_BASIC_H_
#define _PACMAN_BASIC_H_
#include "PacMan_Type.h"
#include "PacMan_Config.h"
#include"LabirinthElem.h"
#include"PacMan_Cmd.h"
 void init_maze(std::string config_file_name, Labirinth_Elems mm[SIZE][SIZE]);
 void set_pacman(PacMan & pac_man, int x, int y, PacmanDir d);
 void init(std::string config_file_name, Labirinth_Elems M[SIZE][SIZE],
	     PacMan & pac_man, int &punteggio, Fruit f[fruit_number],
	     Ghost & g1, Ghost & g2, Ghost & g3, Ghost & g4);
 void display(Labirinth_Elems m[SIZE][SIZE], PacMan pac_man, int &punteggio,
		Ghost & g1, Ghost & g2, Ghost & g3, Ghost & g4);
 PacmanDir cmd2dir(Command c);
 bool make_move(PacMan & pac_man, Command c, Labirinth_Elems M[SIZE][SIZE],
		  int &punteggio, Ghost & g1, Ghost & g2, Ghost & g3,
		  Ghost & g4);
 bool acceptable(int, int, Labirinth_Elems M[SIZE][SIZE]);
 void rand_coord(int &, int &, Labirinth_Elems M[SIZE][SIZE]);
 void ghost_move(Labirinth_Elems m[SIZE][SIZE], Ghost &);
 
#endif				/*  */
