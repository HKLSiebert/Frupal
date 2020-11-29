#include <ncurses>
#include <string>


#define PLAYER "@"                                                           
#define FOOD "F"        
#define TOOL "T"
#define OBSTACLE "!"  
#define TREASURE "$"                                    
#define CLUE "?"                                    
#define SHIP "S" 
#define BINOCULARS "B"               
#define PLAYER_PAIR 1 
#define GRASS_PAIR 2                            
#define MAP_SIZE 11                      


class Display{
	public:
		Display();
		~Display();
		void updateMap(/*grovnick array*/);
		void updateMenu();
		void getInput(); 
		void updateGrovnick(int x, int y);
		void updateFood();
		void updateObstacles();
		void updateTreasure();
		void updateTools();
		void updateClues();
		void updatePlayerPosition(/*pass hero object or coordinates*/);	
	private:
		void maxY, maxX, mapY, mapX, mapBeginningY, mapBeginningX menuSize;
		WINDOW *map;
		WINDOW *menu;

}
