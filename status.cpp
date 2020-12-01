#include "status.h"


status::status(frupalMap & startmap)
{
  //startx,starty = 0;
  map=new object*[/*size of map*/];
  map = new object*[/* size of map*/];
  loadmap(startmap);
}
bool status::update(char userinput)
{
  switch(getch())
  {
    case KEY_LEFT:
      if(my_hero.interact(map[x-1][y]))
        --x;
      break;
    case KEY_RIGHT:
      my_hero.interact(map[x+1][y]);
      break;
    case KEY_UP:
      my_hero.interact(map[x][y+1]);
      break;
    case KEY_DOWN:
      my_hero.interact(map[x][y-1]);
      break;
    case 'x':
    case 'X':
      loop_again = false; // Exit Frupal
      break;
  }
  void status::updatemap(int x,int y)
  {
    //hero coords
    startx=x;
    starty=y;
    //display_map.UpdatePlayerPosition(startx,starty);
    //figure out how interacting is working

  }

  void status::loadmap(frupalMap & startmap)
  {
    //need to load map so i can access and change whatever is necessary 
  }


  int status::gameprogress()
  {
    //if(my_hero->hero_health() < 0)
    //return -1 //lost the game
    // if(my_hero->check for game ending jewel)//bool return value
    // return 1 //won the game
    return 0;//game still going
  }

  //I was thinking maybe draw passes in what index they need then i return the list ptr which has everything that they need
  list* status::draw_display(int x,int y)
  {
    //map[x][y]->getdisplaychar(); 
    //return map_array[x][y].list;
  }




