#include <fstream>
#include <ncurses.h>
#include <string>

#include "displayClass.h"
#include "status.h"
#include "object.h"

using namespace std;



#if status
// One game uses a single instance of status class.
status frupalStatus;
#endif

#if Display
// One game uses a single instance of draw class.
Display frupalDisplay( 0, 0, frupalStatus );
#endif


int main( int argc, char ** argv ) {

	initscr();
	clear();
	noecho();
	keypad( stdscr, true );


	bool loop_again = true;
	do {
		switch( getch() )
		{
			/* Arrow keys to move hero on map. */
			case KEY_LEFT:
				/* Move Hero Left */
				frupalStatus.update( 'w' );
				break;
			case KEY_RIGHT:
				/* Move Hero Right */
				frupalStatus.update( 'e' );
				break;
			case KEY_UP:
				/* Move Hero Up */
				frupalStatus.update( 'n' );
				break;
			case KEY_DOWN:
				/* Move Hero Down */
				frupalStatus.update( 's' );
				break;

			/* WASD to control cursor movement */
			case 'w':
			case 'W':
				/* Move Cursor Up */
				frupalStatus.cursor( 'w' );
				break;
			case 'a':
			case 'A':
				break;
				/* Move Cursor Left */
				frupalStatus.cursor( 'a' );
			case 's':
			case 'S':
				/* Move Cursor Down */
				frupalStatus.cursor( 's' );
				break;
			case 'd':
			case 'D':
				/* Move Cursor Right */
				frupalStatus.cursor( 'd' );
				break;

			/* User can exit game with 'x' key */
			case 'x':
			case 'X':
				loop_again = false;	// Exit Frupal
				break;
		}

		/* Check for Win or Lose Game */
		switch( frupalStatus.gameprogress() )
		{
			case 0:
				/* Continue Game */
				break;
			case 1:
				/* Game has been won! */
				// TODO notify the player of success	
				loop_again = false;
				break;
			case 2:
				/* Game has been lost */
				// TODO notify the player of lost game
				loop_again = false;
				break;
		}	
	} while( loop_again );

	refresh();
	endwin();


	return 0;
}


