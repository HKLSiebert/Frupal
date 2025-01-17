#include "status.h"

status::status(){   
  startx = starty = cursorX = 63;
  cursorY = 64;
  read_map();    
  set_visible();
  my_hero = new hero();

}  

status::~status(){
  for(int i = 0; i < 128; i++) {
    for(int j = 0; j < 128; j++){
      delete map[i][j];
    }
    delete [] map[i];
  }
  delete map;
  delete my_hero;

}


bool status::update(int userinput)
{
  int flag = 0;
  //Left
  if(userinput == 'w'){
    if(startx - 1 >= 0){
      if(my_hero->interact(*map[starty][startx-1])){
        --startx;
        flag=1;
       set_visible();
      }
    }
  }
  //Right
  if(userinput == 'e'){
    if(startx + 1 < SIZEX){
      if(my_hero->interact(*map[starty][startx+1])){
        ++startx;
        flag=1;
        set_visible();
      }
    }
  }
  //Up
  if(userinput == 'n'){ if(starty - 1 >= 0){
      if(my_hero->interact(*map[starty-1][startx])){
        --starty;
        flag=1;
        set_visible();
      }
    }
  }
  //Down
  if(userinput == 's'){
    if(starty + 1 < SIZEY){
      if(my_hero->interact(*map[starty+1][startx])){
        ++starty;
        flag=1;
        set_visible();
      }
    }
  }
  if(flag==1)
    return true;
  return false;
}
bool status::cursor(int userinput)
{
  int flag = 0;
  //Left
  if(userinput == 'w')
    if(cursorX - 1 >= 0){
      --cursorX;
      flag=1;
    }
  //Right
  if(userinput == 'e')
    if(cursorX + 1 < SIZEX){
      ++cursorX;
      flag=1;
    }
  //Up
  if(userinput == 'n')
    if(cursorY - 1 >= 0){
        --cursorY;
        flag=1;
    }
  //Down
  if(userinput == 's')
    if(cursorY + 1 < SIZEY){
        ++cursorY;
        flag=1;
    }
  if(flag==1)
    return true;
  return false;
}

int status::gameprogress()
{
  if(my_hero->get_energy() <= 0)
    return -1; //lost the game
  if(my_hero->check_diamond()) //bool return value
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
    map[starty-1][startx-1] -> toggleSeen();

  if(startx>0)
    map[starty][startx-1] -> toggleSeen();

  if(starty+1<128 && startx >0)
    map[starty+1][startx-1] -> toggleSeen();

  if(starty>0)
    map[starty-1][startx] -> toggleSeen();

  if(starty+1<128)
    map[starty+1][startx] -> toggleSeen();

  if(starty>0 && startx+1<128)
    map[starty-1][startx+1] -> toggleSeen();

  if(startx+1<128)
    map[starty][startx+1] -> toggleSeen();

  if(startx+1<128 && starty+1<128)
    map[starty+1][startx+1] -> toggleSeen();

  map[starty][startx] -> toggleSeen();

  if(my_hero->check_binoculars()){//if hero has binoculars

    if(starty-1>0 && startx-1>0)
      map[starty-2][startx-2] -> toggleSeen();

    if(startx-1>0)
      map[starty][startx-2] -> toggleSeen();

    if(starty+2<128 && startx-1 >0)
      map[starty+2][startx-2] -> toggleSeen();

    if(starty-1>0)
      map[starty-2][startx] -> toggleSeen();

    if(starty+2<128)
      map[starty+2][startx] -> toggleSeen();

    if(starty-1>0 && startx+2<128)
      map[starty-2][startx+2] -> toggleSeen();

    if(startx+2<128)
      map[starty][startx+2] -> toggleSeen();

    if(starty+2<128 && startx+2<128)
      map[starty+2][startx+2] -> toggleSeen();


    if(starty-1>0 && startx+1<128)
      map[starty-2][startx+1] -> toggleSeen();
    if(starty-1>0 && startx>0)
      map[starty-2][startx-1] -> toggleSeen();

    if(starty+2<128 && startx>0)
      map[starty+2][startx-1] -> toggleSeen();
    if(starty+2<128 && startx+1<128)
      map[starty+2][startx+1] -> toggleSeen();

    if(starty+1<128 && startx+2<128)
      map[starty+1][startx+2] -> toggleSeen();
    if(starty>0 && startx+2<128)
      map[starty-1][startx+2] -> toggleSeen();

    if(starty>0 && startx-1>0)
      map[starty-1][startx-2] -> toggleSeen();
    if(starty+1<128 && startx-1>0)
      map[starty+1][startx-2] -> toggleSeen();
  }
}

int status::getCursorX(){
  return cursorX;
}
int status::getCursorY(){
  return cursorY;
}

int status::getHeroX(){
        return startx;
}
int status::getHeroY(){
        return starty;
}
int status::getHeroEnergy(){
        return my_hero->get_energy();
}
int status::getHeroWiffle(){
        return my_hero->get_wiffles();
}

bool status::isCursorVisible(){
        if(map[cursorY][cursorX]->is_Seen()) return true;
        return false;

}

string status::getHeroInv(){
  return my_hero->get_inventory_list();
}
