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

void status::update(char userinput)
{
  if(userinput == 'w'){
    if(startx - 1 >= 0){
      if(my_hero->interact(map[startx-1][starty]))
        --startx;
    }
  }
  if(userinput == 'e'){
    if(startx + 1 <= SIZEX){
      if(my_hero->interact(map[startx+1][starty]))
        ++startx;
    }
  }
  if(userinput == 'n'){
    if(starty - 1 >= 0){
      if(my_hero->interact(map[startx][starty-1]))
        --starty;
    }
  }
  if(userinput == 's'){
    if(starty + 1 <= SIZEY){
      if(my_hero->interact(map[startx][starty + 1]))
        ++starty;
    }
  }
}
void status::cursor(char userinput)
{
  if(userinput == 'w')
    --cursorX;
  else if(userinput == 'e')
    ++cursorX;
  else if(userinput == 'n')
    --cursorY;
  else if(userinput == 's')
    ++cursorY;
}

int status::gameprogress()
{
  if(my_hero->get_energy() <= 0)
    return -1; //lost the game
  //if(my_hero->check_jewel()) //bool return value
  return 1; //won the game
  return 0;//game still going
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
  /*if(my_hero->binoculars()){//if hero has binoculars
    if(startx-1>0 && starty-1>0)
      map[startx-2][starty-2] -> toggleSeen();

    if(starty-1>0)
      map[startx][starty-2] -> toggleSeen();

    if(startx+1<128 && starty-1 >0)
      map[startx+2][starty-2] -> toggleSeen();

    if(startx-1>0)
      map[startx-2][starty] -> toggleSeen();

    if(startx+1<128)
      map[startx+2][starty] -> toggleSeen();

    if(startx-1>0 && starty+1<128)
      map[startx-2][starty+2] -> toggleSeen();

    if(starty+1<128)
      map[startx][starty+2] -> toggleSeen();

    if(startx+1<128 && starty+1<128)
      map[startx+2][starty+2] -> toggleSeen();
  }*/
}

int status::getCursorX(){
  return cursorX;
}
int status::getCursorY(){
  return cursorY;
}

