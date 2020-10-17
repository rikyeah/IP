#ifndef _PACMAN_CONFIG_H_
#define _PACMAN_CONFIG_H_
#include <string>
const int SIZE = 15;		//Dimensione del labirinto (maze); non comprende i muri perimetrali
const std::string MAZE_CONFIG_NAME = "maze.cfg";	//nome del file con i dati iniziali del labirinto
const int dot_points = 10;	//punteggio che da mangiare un puntino
//frutta
const int fruit_points = 300;
const int fruit_time = 7;
const int fruit_number = 5;
const char fruit_char = 'o';
 struct Fruit  {
	int x;
	int y;
	bool visible;
	int turns_left;
};
 struct Ghost  {
	int x;
	int y;
	char prev_move;
};
 
#endif				/*  */
     
