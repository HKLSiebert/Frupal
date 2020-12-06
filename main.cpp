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
Display frupalDisplay( frupalStatus );
#endif


int main( int argc, char ** argv ) {

	bool loop_again = true;
	do {
		switch( getch() )
		{
			/* Arrow keys to move hero on map. */
			case KEY_LEFT:
				/* Move Hero Left */
				if ( frupalStatus.update( 'w' ) )
				{
					frupalDisplay.updatePlayerPosition( frupalStatus, 'w' );
				}
				break;
			case KEY_RIGHT:
				/* Move Hero Right */
				if ( frupalStatus.update( 'e' ) )
				{
					frupalDisplay.updatePlayerPosition( frupalStatus, 'e' );
				}
				break;
			case KEY_UP:
				/* Move Hero Up */
				if ( frupalStatus.update( 'n' ) )
				{
					frupalDisplay.updatePlayerPosition( frupalStatus, 'n' );

				}
				break;
			case KEY_DOWN:
				/* Move Hero Down */
				if ( frupalStatus.update( 's' ) )
				{
					frupalDisplay.updatePlayerPosition( frupalStatus, 's' );
				}
				break;

			/* WASD to control cursor movement */
			case 'w':
			case 'W':
				/* Move Cursor Up */
				if ( frupalStatus.cursor( 'w' ) )
				{	
					frupalDisplay.updateCursor( frupalStatus, 'n' );
				}
				break;
			case 'a':
			case 'A':
				break;
				/* Move Cursor Left */
				if ( frupalStatus.cursor( 'a' ) )
				{
					frupalDisplay.updateCursor( frupalStatus, 'w' );
				}
			case 's':
			case 'S':
				/* Move Cursor Down */
				if ( frupalStatus.cursor( 's' ) )
				{
					frupalDisplay.updateCursor( frupalStatus, 's' );
				}
				break;
			case 'd':
			case 'D':
				/* Move Cursor Right */
				if ( frupalStatus.cursor( 'd' ) )
				{
					frupalDisplay.updateCursor( frupalStatus, 'e' );
				}
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


	return 0;
}


