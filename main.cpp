#include <fstream>
#include <ncurses.h>
#include <string>
#include <iostream>
#include "displayClass.h"
#include "object.h"

using namespace std;


#if frupalMap
// TODO Map should be loaded in from external file, rather than being hard coded within "main.cpp".
frupalMap Monday_Demo =
{
		DEMO_MAP_NAME,
		DEMO_MAP_HEIGHT,
		DEMO_MAP_WIDTH,
		DEMO_HERO_START_Y,
		DEMO_HERO_START_X,
		{
			{ "tree", 0, 0 },
			{ "food", 10, 0 },
			{ "tool (axe)", 10, 10 }
		}
		// Assume that all Grovnicks are of the "meadow" variety,
		// and that there is no Royal Diamond on this Frupal Island.
};
#endif

#if status
// One game uses a single instance of status class.
status frupalStatus;
#endif

#if displayClass
// One game uses a single instance of draw class.
displayClass frupalDisplay;
#endif


int main( int argc, char ** argv ) {

// TODO Question - Should frupalMap struct be passed to status class, displayClass, or both?

// TODO Question - Should status instance be passed to displayClass instance through a constructor,
//		or by some other public member function of displayClass?

// TODO Keyboard input handled within main function


		return 0;
}


