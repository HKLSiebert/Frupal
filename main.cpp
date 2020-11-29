// CS300 Fall 2020 -- Frupal -- Group 11 -- Monday 11.29.2020 Demo


#include <fstream>
#include <ncurses.h>
#include <string>


using namespace std;


// TODO constant values and struct definitions need to be moved out of "main.cpp".

// Constants, to match "monday_demo_map.png" mockup on group Slack channel.
const string DEMO_MAP_NAME = "Monday Demo";

const int DEMO_MAP_HEIGHT = 11;
const int DEMO_MAP_WIDTH = 11;

const int DEMO_HERO_START_Y = 5;
const int DEMO_HERO_START_X = 5;

const int DEMO_MAX_MAP_ITEMS = 3;


// Example items can include tool (axe), food, tree, obstacle, binoculars, etc.
struct mapItem {
		string itemName;
		int yCoord;
		int xCoord;
};


// TODO frupalMap struct should accomadate for dynamic memory allocation,
//		as each map will contain different numbers of Items, and different types of Grovnick layouts.
//		Could use <vector>?
struct frupalMap {
		string mapName;
		int mapHeight;
		int mapWidth;
		int heroStartY;
		int heroStartX;
		mapItem items[ DEMO_MAX_MAP_ITEMS ];
		// TODO This struct needs to take into account the different types of
		// Grovnick/terrain. Such as meadow, river, lake, swamp, wall, etc.
		// TODO This struct needs to give a location for the Royal Diamond.
};


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

		return 0;
}


// CS300 Fall 2020 -- Frupal -- Group 11 -- Monday 11.29.2020 Demo
