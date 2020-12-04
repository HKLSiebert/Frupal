#include "status.h"

status::status(){   
        startx = starty = cursorX = 63;
        cursorY = 64;
        read_map();    
}  


status::~status(){
        for(int i = 0; i < 128; i++) {
                for(int j = 0; j < 128; j++){
                        delete [] map[i][j];
                }
                delete [] map[i];
        }
        delete map;

}

=======
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

grovnic* status::get_grovnic(int x, int y){
  return map[x][y];
}

void status::read_map() {                                                                                                                                                       
        
        string terrain, content, desc;                                               
        ifstream fp("map.txt"); 
        if (! fp) {
                printw("Failed to open map");                                        
                return;
        }       
        map = new grovnic**[128];                                                    
        for(int i = 0; i < 128; i++) {                                               
                map[i] = new grovnic*[128];                                          
                for(int j = 0; j < 128; j++){                                        
                        getline(fp, terrain, ';');                                   
                        getline(fp, content, ';');
                        getline(fp, desc, ';');
                        map[i][j] = new grovnic(terrain, content, desc);                                                                                                                                                                                                                                                                                                                                                                                                                                
                }                                                                                                                                                       
        }                                                                                                                                                               

} 

void status::set_visible(){
        if(startx>0 && starty>0)
                map[startx-1][starty-1] -> toggleSeen();

        if(starty>0)
                map[startx][starty-1] -> toggleSeen();

        if(startx<128 && starty >0)
                map[startx+1][starty-1] -> toggleSeen();

        if(startx>0)
                map[startx-1][starty] -> toggleSeen();

        if(startx<128)
                map[startx+1][starty] -> toggleSeen();

        if(startx>0 && starty<128)
                map[startx-1][starty+1] -> toggleSeen();

        if(starty<128)
                map[startx][starty+1] -> toggleSeen();

        if(startx<128 && starty<128)
                map[startx+1][starty+1] -> toggleSeen();

        map[startx][starty] -> toggleSeen();
}

int status::getCursorX(){
        return cursorX;
}
int status::getCursorY(){
        return cursorY;
}

