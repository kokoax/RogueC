#include "rogue_header.h"

char mygetch( ) {
	struct termios 	oldt,
			newt;
	int ch;

	tcgetattr( STDIN_FILENO, &oldt );
	
	newt = oldt;
	
	newt.c_lflag &= ~( ICANON | ECHO );
	
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );

	ch = getchar( );
	
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

	return ch;
}


