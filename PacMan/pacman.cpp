#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "PacMan_Config.h"
#include "LabirinthElem.h"
#include "PacMan_Type.h"
#include "PacMan_Cmd.h"
#include "PacMan_BasicGame.h"
     using namespace std;
 void init_maze(string config_file_name, Labirinth_Elems mm[SIZE][SIZE])
{
	ifstream cfgfile;
	cfgfile.open(config_file_name);
	if (!cfgfile)
		throw "file not found: missing " + config_file_name;
	 for (int y = 0; y < SIZE; ++y) {
		std::string line;
		if (!getline(cfgfile, line))
			line = "";
		std::istringstream line_stream(line);
		for (int x = 0; x < SIZE; ++x) {
			char c;
			if (line_stream >> c)
				mm[x][y] = char2lab_elem(c);
			
			else
				mm[x][y] = Labirinth_Elems::empty;	//missing input is integrated by empty spaces
		}
	}
	cfgfile.close();
}

 int main() 
{
	Labirinth_Elems maze[SIZE][SIZE];
	Fruit f[fruit_number];
	Ghost g1;
	Ghost g2;
	Ghost g3;
	Ghost g4;
	PacMan p;
	int punteggio = 0;
	cout << "PAC MAN BASIC" << endl;
	try {
		init(MAZE_CONFIG_NAME, maze, p, punteggio, f, g1, g2, g3, g4);
	} catch(string & e) {
		cout << e;
		return -1;
	}
	Command cmd = Unknown;
	
	do {
		display(maze, p, punteggio, g1, g2, g3, g4);
		cmd = get_command();
		switch (cmd) {
		case Quit:
			cout << "Grazie di aver giocato con me, alla prossima!"
			    << endl;
			return 0;
		case Unknown:
			throw "unexpected command";
		case Go_E:
		case Go_W:
		case Go_S:
		case Go_N:
			if (!make_move(p, cmd, maze, punteggio, g1, g2, g3, g4))
				cout <<
				    "Mossa impossibile: non puoi passare attraverso i muri!"
				    << endl;
			break;
		default:
			throw "not a command!";
		}
	}
	while (true);
 }


