#include "PacMan_Cmd.h"
#include <iostream>
using namespace std;
Command char2command(const char c)
{
	switch (c) {
	case 'w':
	case 'W':
		return Go_N;
		break;
	case 'a':
	case 'A':
		return Go_W;
	case 'd':
	case 'D':
		return Go_E;
	case 's':
	case 'S':
		return Go_S;
	case 'q':
	case 'Q':
		return Quit;
	default:
		return Unknown;
	}
};

 Command get_command()
{
	char my_char;
	Command my_cmd;
	
	do {
		cout << " Inserisci un comando (W/w  S/s  A/a  D/d  Q/q): ";
		cin >> my_char;
		my_cmd = char2command(my_char);
	}
	while (my_cmd == Unknown);
	 return my_cmd;
};


