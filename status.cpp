#include "status.h"
#include "displayClass.h"


status::status()
{
  startx,starty = 0;
}

void status::updatemap(int x,int y)
{
  Display display_map;
  //hero coords
  startx=x;
  starty=y;
  display_map.UpdatePlayerPosition(startx,starty);
  //figure out how interacting is working

}

void status::loadmap(char ** map)
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
list* status::draw_update(int x,int y)
{
  return map_array[x][y].list;
}
