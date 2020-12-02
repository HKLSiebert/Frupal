#include "status.h"


status::status(frupalMap & startmap)
{
  startx = 0;
  starty = 0;
  map = new object*[SIZEY];
  for(int i=0; i<SIZEY;++i)
    map[i] = new object[SIZEX];
  loadmap(startmap);
}

void status::loadmap(frupalMap & startmap)
{
  //need to load map so i can access and change whatever is necessary 
}

bool status::update(char userinput)
{
  switch(userinput)
  {
    case KEY_LEFT:
      if(my_hero->interact(map[starty][startx-1]))
        --startx;
      break;
    case KEY_RIGHT:
      if(my_hero->interact(map[starty][startx+1]))
        ++startx;
      break;
    case KEY_UP:
      if(my_hero->interact(map[starty+1][startx]))
        ++starty;
      break;
    case KEY_DOWN:
      if(my_hero->interact(map[starty-1][startx]))
        --starty;
      break;
    case 'x':
    case 'X':
      break;
  }
}
void status::updatemap(int x,int y)
{
  //figure out how interacting is working

}

int status::gameprogress()
{
  if(my_hero->energy <= 0)
    return -1 //lost the game
  // if(my_hero->check for game ending jewel)//bool return value
  // return 1 //won the game
  return 0;//game still going
}

//I was thinking maybe draw passes in what index they need then i return the list ptr which has everything that they need
list* status::draw_display(int x,int y)
{
  return map_display[y][x];
}


void status::read_map() {                                                                                                                                                       

  string terrain, content;                                                                                                                                                
  ifstream fp("map.txt");                                                                                                                                                
  if (! fp) {
    printw("Failed to open map");                                                                                                                                   
    return;                                                                                                                                                         
  }                                                                                                                                                                       

  for(int i = 0; i < 128; i++) {  
    for(int j = 0; j < 128; j++){
      getline(fp, map_display[j][i].terrain, ';');                                                                                                            
      getline(fp, map_display[j][i].content, ';');                                                                                                            
      map_display[j][i].visible = false;                                                                                                                                                                                                                                                                    
    }                                                                                                                                                       
  }                                                                                                                                                               
} 

