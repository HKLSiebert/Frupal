
// Constants, to match "monday_demo_map.png" mockup on group Slack channel.
#define DEMO_MAP_NAME "Monday Demo"

#define DEMO_MAP_HEIGHT 11
#define DEMO_MAP_WIDTH 11

#define DEMO_HERO_START_Y 5
#define DEMO_HERO_START_X 5

#define DEMO_MAX_MAP_ITEMS 3


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

