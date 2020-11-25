#include <ncurses>
#include <string>

class Display{
	public:
		Display();
		~Display();
		void updateMap();
		void updateMenu();
		void getInput(); 
		void updateGrovnick(int x, int y);
		void updateFood();
		void updateObstacles();
		void updateTreasure();
		void updateTools();
		void updateClues();
		void heroPosition();	
	private:
		void maxY, maxX, menuSize;
		WINDOW *map;
		WINDOW *menu;

}
