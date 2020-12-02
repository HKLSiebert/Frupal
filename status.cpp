#include "status.h"


status::status()
{
  startx = 0;
  starty = 0;

  map = new object*[SIZEY];
  for(int i=0; i<SIZEY;++i)
    map[i] = new object[SIZEX];

  map_display = new list*[SIZEY];
  for(int i=0; i<SIZEY;++i)
    map_display[i] = new list[SIZEX];

  //loadmap(startmap);
}

/*void status::loadmap(frupalMap & startmap)
{
  //need to load map so i can access and change whatever is necessary 
}*/

bool status::update(char userinput)
{
  int flag=1;
  switch(userinput)
  {
    case KEY_LEFT:
      if(startx - 1 >= 0){
        if(my_hero->interact(map[starty][startx-1]))
          --startx;
        else
          flag=0;
      }
      else
        flag=0;
      break;
    case KEY_RIGHT:
      if(startx + 1 <= SIZEX){
        if(my_hero->interact(map[starty][startx+1]))
          ++startx;
        else
          flag=0;
      }
      else
        flag=0;
      break;
    case KEY_UP:
      if(starty - 1 >= 0){
        if(my_hero->interact(map[starty-1][startx]))
          --starty;
        else
          flag=0;
      }
      else
        flag=0;
      break;
    case KEY_DOWN:
      if(starty + 1 <= SIZEY){
        if(my_hero->interact(map[starty + 1][startx]))
          ++starty;
        else
          flag=0;
      }
      else
        flag=0;
      break;
    case 'x':
    case 'X':
      break;
  }
  if(flag == 0)
    return false;
  return true;
}
void status::updatemap(int x,int y)
{
  //figure out how interacting is working

}

int status::gameprogress()
{
  if(my_hero->energy <= 0)
    return -1; //lost the game
  // if(my_hero->check for game ending jewel)//bool return value
  // return 1 //won the game
  return 0;//game still going
}

//I was thinking maybe draw passes in what index they need then i return the list ptr which has everything that they need
list status::draw_display(int x,int y)
{
  return map_display[y][x];
}


void status::read_map() {                                                                                                                                                       

  string terrain, content;                                                                                                                                                
  ifstream fp("map.txt");                                                                                                                                                
  if (! fp) {
    printf("Failed to open map");                                                                                                                                   
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

