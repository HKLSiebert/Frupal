#include <string>
#include <iostream>
#include "frupalMap.h"
//#include "displayClass.h"
#include "object.h"
using namespace std;

struct list
{
  string name;
  string description;
  char display_char;
  color char_color;
  color background_color;
  bool visible;
};

//Need to remember if hero has binoculars have to update how many sqaures he can look at.
class status
{
  public:
    status(frupalMap & startmap);
    void update_map(int x, int y/* user input*/);
    void load_map(frupalMap & startmap);//loads up the mapp array to update it;
    bool game_progress();//is user did or did they complete the game?
    int success();
    void cursor(/*dont exactly know what im doing for the cursor yet*/);
    list* draw_display(int x,int y);//function to pass the updated index to draw
    bool update(char userinput);
  protected:
    int startx;//starting coords of hero
    int starty;
    int mapx;
    int mapy;
    object ** map;
    hero * my_hero;
    list ** map_display; // However we are handling the data structure of the map.
};
