#include <ncurses.h>
#include <string>

#include "displayClass.h"
#include "status.h"
#include "object.h"

#define PROGRESS_CHECK_LOST -1
#define PROGRESS_CHECK_CONTINUE 0
#define PROGRESS_CHECK_WON 1

using namespace std;

int main( int argc, char ** argv ) {
        status frupalStatus;
        Display frupalDisplay( frupalStatus );
        bool success = 0;


        bool loop_again = true;
        do {
                switch( getch() )
                {
                        // Arrow keys to move hero on map.
                        case KEY_LEFT:
                                // Move Hero Left
                                success =frupalStatus.update( 'w' );
                                if(success) frupalDisplay.updatePlayerPosition(frupalStatus, 'w');
                                break;
                        case KEY_RIGHT:
                                // Move Hero Right
                                success =frupalStatus.update( 'e' );
                                if(success) frupalDisplay.updatePlayerPosition(frupalStatus, 'e');
                                break;
                        case KEY_UP:
                                // Move Hero Up
                                success =frupalStatus.update( 'n' );
                                if(success) frupalDisplay.updatePlayerPosition(frupalStatus, 'n');
                                break;
                        case KEY_DOWN:
                                // Move Hero Down
                                success =frupalStatus.update( 's' );
                                if(success) frupalDisplay.updatePlayerPosition(frupalStatus, 's');
                                break;

                        // WASD to control cursor movement
                        case 'a':
                        case 'A':

                                // Move Cursor Left
                                success =frupalStatus.cursor( 'w' );
                                if(success) frupalDisplay.updateCursor(frupalStatus, 'w');
                                break;
                        case 'w':
                        case 'W':
                                // Move Cursor Up
                                success =frupalStatus.cursor( 'n' );
                                if(success) frupalDisplay.updateCursor(frupalStatus, 'n');
                                break;

                        case 's':
                        case 'S':
                                // Move Cursor Down
                                success =frupalStatus.cursor( 's' );
                                if(success) frupalDisplay.updateCursor(frupalStatus, 's');
                                break;
                        case 'd':
                        case 'D':
                                // Move Cursor Right
                                success =frupalStatus.cursor( 'e' );
                                if(success) frupalDisplay.updateCursor(frupalStatus, 'e');
                                break;

                        // User can exit game with 'x' key
                        case 'x':
                        case 'X':
                                loop_again = false;     // Exit Frupal
                                break;
                }



		// TODO Determine why:
		// 	- Commenting out this switch statement allows the hero to,
		// 	  walk on water and walk through walls.
		// 	- Including this switch statement triggers in-game segmentation faults,
		// 	  when the hero interacts with water or wall.

		switch( frupalStatus.gameprogress() )
		{
			case PROGRESS_CHECK_LOST:
				// Player has lost the game
				// TODO Notify player of game lost.
				loop_again = false;
                                frupalDisplay.lossMenu();
				break;
			case PROGRESS_CHECK_CONTINUE:
				// Continue
				break;
			case PROGRESS_CHECK_WON:
				// Player has won the game!
				// TODO Notify player of game won.
				loop_again = false;
                                frupalDisplay.winMenu(); 
				break;
		}

 } while( loop_again );

        refresh();
        endwin();
        return 0;

}


