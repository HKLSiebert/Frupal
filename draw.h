#include <string>
#include <sstream>
#include <fstream>

class draw{
	public:
		int updateMap(); 
		int updateGrovnick(int x, int y);
		int loadMap(stringstream &file);
		int saveMap(ofstream &file);
		int setVisible(bool binoculars);
		int updateFood();
		int updateObstacles();
		int updateTreasure();
		int updateTools();
		int updateClues();
		void heroPosition();	
	private:
		int x;
		int y;

}
