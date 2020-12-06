#include "status.h"

status::status(){   
  startx = starty = cursorX = 63;
  cursorY = 64;
  read_map();    
  set_visible();

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


bool status::update(int userinput)
{
  int flag = 0;
  if(userinput == 'w'){
    if(startx - 1 >= 0){
//      if(my_hero->interact(*map[startx-1][starty])){
        --startx;
        flag=1;
       set_visible();
//      }
    }
  }
  if(userinput == 'e'){
    if(startx + 1 <= SIZEX){
  //    if(my_hero->interact(*map[startx+1][starty])){
        ++startx;
        flag=1;
        set_visible();
   //   }
    }
  }
  if(userinput == 'n'){ if(starty - 1 >= 0){
 //     if(my_hero->interact(*map[startx][starty-1])){
        --starty;
        flag=1;
        set_visible();
  //    }
    }
  }
  if(userinput == 's'){
    if(starty + 1 <= SIZEY){
   //   if(my_hero->interact(*map[startx][starty + 1])){
        ++starty;
        flag=1;
        set_visible();
    //  }
    }
  }
  if(flag==1)
    return true;
  return false;
}
bool status::cursor(int userinput)
{
  int flag = 0;
  if(userinput == 'w')
    //if(startx - 1 >= 0){
      --cursorX;
      flag=1;
    //}

  if(userinput == 'e')
    if(startx + 1 <= SIZEX){
      ++cursorX;
      flag=1;
    }

  if(userinput == 'n')
    if(starty - 1 >= 0){
        --cursorY;
        flag=1;
    }
  if(userinput == 's')
    if(starty + 1 <= SIZEY){
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
  ifstream fp("map12.txt"); 
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

  if(starty<128 && startx >0)
    map[starty+1][startx-1] -> toggleSeen();

  if(starty>0)
    map[starty-1][startx] -> toggleSeen();

  if(starty<128)
    map[starty+1][startx] -> toggleSeen();

  if(starty>0 && startx<128)
    map[starty-1][startx+1] -> toggleSeen();

  if(startx<128)
    map[starty][startx+1] -> toggleSeen();

  if(startx<128 && starty<128)
    map[starty+1][startx+1] -> toggleSeen();

  map[starty][startx] -> toggleSeen();

  if(my_hero->check_binoculars()){//if hero has binoculars

    if(starty-2>0 && startx-2>0)
      map[starty-2][startx-2] -> toggleSeen();

    if(startx-2>0)
      map[starty][startx-2] -> toggleSeen();

    if(starty+2<128 && startx-2 >0)
      map[starty+2][startx-2] -> toggleSeen();

    if(starty-2>0)
      map[starty-2][startx] -> toggleSeen();

    if(starty+2<128)
      map[starty+2][startx] -> toggleSeen();

    if(starty-2>0 && startx+2<128)
      map[starty-2][startx+2] -> toggleSeen();

    if(startx+2<128)
      map[starty][startx+2] -> toggleSeen();

    if(starty+2<128 && startx+2<128)
      map[starty+2][startx+2] -> toggleSeen();


    if(starty-2>0 && startx+1<128)
      map[starty-2][startx+1] -> toggleSeen();
    if(starty-2>0 && startx-1>0)
      map[starty-2][startx-1] -> toggleSeen();

    if(starty+2<128 && startx-1>0)
      map[starty+2][startx-1] -> toggleSeen();
    if(starty+2<128 && startx+1<128)
      map[starty+2][startx+1] -> toggleSeen();

    if(starty+1<128 && startx+2<128)
      map[starty+1][startx+2] -> toggleSeen();
    if(starty-1>0 && startx+2<128)
      map[starty-1][startx+2] -> toggleSeen();

    if(starty-1>0 && startx-2>0)
      map[starty-1][startx-2] -> toggleSeen();
    if(starty+1<128 && startx-2>0)
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
