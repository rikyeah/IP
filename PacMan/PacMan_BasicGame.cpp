#include"PacMan_BasicGame.h"
#include"LabirinthElem.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void set_pacman(PacMan & pac_man, int x, int y, PacmanDir d)
{
	pac_man.X = x;
	pac_man.Y = y;
	pac_man.direction = d;
};

void
init(std::string config_file_name, Labirinth_Elems M[SIZE][SIZE],
     PacMan & pac_man, int &punteggio, Fruit f[fruit_number], Ghost & g1,
     Ghost & g2, Ghost & g3, Ghost & g4)
{
	init_maze(config_file_name, M);
	srand(time(0));
	int x = -10;
	int y = -10;
	rand_coord(x, y, M);
	set_pacman(pac_man, x, y, South);
	for (int i = 0; i < fruit_number; ++i) {	//inizializzazione frutta
		x = -10;
		y = -10;
		rand_coord(x, y, M);
		f[i].visible = true;
		f[i].turns_left = 7;
		f[i].x = x;
		f[i].y = y;
		M[x][y] = fruit;
	}
	//inizzializzazione fantasmi
	x = -10;
	y = -10;
	rand_coord(x, y, M);
	g1.x = x;
	g1.y = y;
	g1.prev_move = '6';
	x = -10;
	y = -10;
	rand_coord(x, y, M);
	g2.x = x;
	g2.y = y;
	g2.prev_move = '6';
	x = -10;
	y = -10;
	rand_coord(x, y, M);
	g3.x = x;
	g3.y = y;
	g3.prev_move = '6';
	x = -10;
	y = -10;
	rand_coord(x, y, M);
	g4.x = x;
	g4.y = y;
	g4.prev_move = '6';
	punteggio = 0;
};

void
display(Labirinth_Elems m[SIZE][SIZE], PacMan pac_man, int &punteggio,
	Ghost & g1, Ghost & g2, Ghost & g3, Ghost & g4)
{
	for (int i = 0; i < 17; ++i)
		cout << WALL_C;
	cout << "          " << "PUNTEGGIO: " << punteggio << endl;
	for (int y = 0; y < SIZE; ++y) {
		cout << WALL_C;
		for (int x = 0; x < SIZE; ++x) {
			if ((x == g1.x && y == g1.y) || (x == g2.x && y == g2.y)
			    || (x == g3.x && y == g3.y) || (x == g4.x
							    && y == g4.y))
				cout << "M";
			else if (x == pac_man.X && y == pac_man.Y)
				cout << PacmanDir2char(pac_man.direction);
			else
				cout << lab_elem2char(m[x][y]);
		}
		cout << WALL_C << endl;
	}
	for (int i = 0; i < 17; ++i)
		cout << WALL_C;
	cout << endl << endl;
};

PacmanDir cmd2dir(Command c)
{
	if (c == Go_S)
		return South;
	if (c == Go_N)
		return North;
	if (c == Go_E)
		return East;
	if (c == Go_W)
		return West;
	else {
		string err = "comando non convertibile a direzione";
		throw err;
	}
};

bool
make_move(PacMan & pac_man, Command c, Labirinth_Elems M[SIZE][SIZE],
	  int &punteggio, Ghost & g1, Ghost & g2, Ghost & g3, Ghost & g4)
{
	int x;
	int y;
	x = pac_man.X;
	y = pac_man.Y;
	if (c == Quit || c == Unknown) {
		string err = "errore in make move";
		throw err;
	}
	if (c == Go_S)
		++y;
	if (c == Go_N)
		--y;
	if (c == Go_E)
		++x;
	if (c == Go_W)
		--x;
	if (M[x][y] == dot) {	//se pacman mangia il puntino
		punteggio = punteggio + dot_points;
		M[x][y] = empty;
	}
	//INSERIRE QUI IL MOVIMENTO DEL FANTSMA
	ghost_move(M, g1);
	//ghost_move(M, g2);
	//ghost_move(M, g3);
	//ghost_move(M, g4);
	if (M[x][y] == fruit) {	//se pacman mangia il frutto
		punteggio = punteggio + fruit_points;
		M[x][y] = empty;
	}
	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		return false;
	if (M[x][y] == wall)
		return false;
	set_pacman(pac_man, x, y, cmd2dir(c));
	return true;
};

bool acceptable(int x, int y, Labirinth_Elems M[SIZE][SIZE])
{
	if (M[x][y] == wall)
		return false;
	if (x >= 0 && M[x - 1][y] != wall)
		return true;
	if (y >= 0 && M[x][y - 1] != wall)
		return true;
	if (x <= SIZE - 1 && M[x + 1][y] != wall)
		return true;
	if (y <= SIZE - 1 && M[x][y + 1] != wall)
		return true;
	return false;
};

void rand_coord(int &x, int &y, Labirinth_Elems M[SIZE][SIZE])
{
	while (!acceptable(x, y, M)) {
		x = rand() % SIZE;
		y = rand() % SIZE;
	}
};

void ghost_move(Labirinth_Elems M[SIZE][SIZE], Ghost & g)
{
	int random = rand() % 5;
	cout << "il numero random è " << random << endl;
	if (random == 0) {	//ripeto la mossa 1 caso su 4
		if ((g.prev_move == 'w' || g.prev_move == '6')
		    && acceptable(g.x, g.y + 1, M)) {
			cout << "ripeto la mossa verso nord" << endl;
			g.y = g.y + 1;
			g.prev_move = 'w';
			return;
		}
		if ((g.prev_move == 's' || g.prev_move == '6')
		    && acceptable(g.x, g.y - 1, M)) {
			cout << "ripeto la mossa verso sud" << endl;
			g.y = g.y - 1;
			return;
		}
		if ((g.prev_move == 'a' || g.prev_move == '6')
		    && acceptable(g.x - 1, g.y, M)) {
			cout << "ripeto la mossa verso sinistra" << endl;
			g.x = g.x - 1;
			return;
		}
		if ((g.prev_move == 'd' || g.prev_move == '6')
		    && acceptable(g.x, g.y + 1, M)) {
			cout << "ripeto la mossa verso destra" << endl;
			g.y = g.y + 1;
			return;
		}
	}
	random = rand() % 4 + 1;
	if (random == 1) {	// mossa a nord
		cout << "provo a nord ";
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'w';
			cout << " e invece nord" << endl;
			return;
		}
		if (acceptable(g.x, g.y - 1, M)) {
			g.y = g.y - 1;
			g.prev_move = 's';
			cout << " e invece sud" << endl;
			return;
		}
		if (acceptable(g.x - 1, g.y, M)) {
			g.x = g.x - 1;
			g.prev_move = 'a';
			cout << " e invece sinistra" << endl;
			return;
		}
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'd';
			cout << " e invece destra" << endl;
			return;
		}
	}
	if (random == 2) {
		cout << "provo a sud" << endl;
		if (acceptable(g.x, g.y - 1, M)) {
			g.y = g.y - 1;
			g.prev_move = 's';
			cout << " e invece sud" << endl;
			return;
		}
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'w';
			cout << " e invece nord" << endl;
			return;
		}
		if (acceptable(g.x - 1, g.y, M)) {
			g.x = g.x - 1;
			g.prev_move = 'a';
			cout << " e invece sinistra" << endl;
			return;
		}
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'd';
			cout << " e invece destra" << endl;
			return;
		}
	}
	if (random == 3) {
		cout << "provo ad destra" << endl;
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'd';
			cout << " e invece destra" << endl;
			return;
		}
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'w';
			cout << " e invece nord" << endl;
			return;
		}
		if (acceptable(g.x, g.y - 1, M)) {
			g.y = g.y - 1;
			g.prev_move = 's';
			cout << " e invece sud" << endl;
			return;
		}
		if (acceptable(g.x - 1, g.y, M)) {
			g.x = g.x - 1;
			g.prev_move = 'a';
			cout << " e invece sinistra" << endl;
			return;
		}
	}
	if (random == 4) {
		cout << "provo ad sinistra" << endl;
		if (acceptable(g.x - 1, g.y, M)) {
			g.x = g.x - 1;
			g.prev_move = 'a';
			cout << " e invece sinistra" << endl;
			return;
		}
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'w';
			cout << " e invece nord" << endl;
			return;
		}
		if (acceptable(g.x, g.y - 1, M)) {
			g.y = g.y - 1;
			g.prev_move = 's';
			cout << " e invece sud" << endl;
			return;
		}
		if (acceptable(g.x, g.y + 1, M)) {
			g.y = g.y + 1;
			g.prev_move = 'd';
			cout << " e invece destra" << endl;
			return;
		}
	}
};
