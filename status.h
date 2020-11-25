#include <cstring>
#include <iostream>
using namespace std;

struct list
{
  bool visible;
  color char_color;
  color background_color;
};
//Need to remember if hero has binoculars have to update how many sqaures he can look at.
class status
{
  public:
    status();
    void update_map(/* user input*/);
    void load_map(char **);//loads up the mapp array to update it;
    bool game_progress();//is user did or did they complete the game?
    bool success();
    void cursor(/*dont exactly know what im doing for the cursor yet*/);
    list draw_update();//function to pass the updated index to draw
  protected:
    int startx;//starting coords of hero
    int starty;
    object * items;
    hero * my_hero;
    char ** map_array; // However we are handling the data structure of the map.
};
