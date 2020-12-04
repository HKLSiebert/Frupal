#include "status.h"

status::status(){   
        x = y = cursorX = 63;
        cursorY = 64;
        read_map();    
}  

status::status(frupalMap & startmap)
{
  //startx,starty = 0;
  map=new object*[/*size of map*/];
  map = new object*[/* size of map*/];
  loadmap(startmap);
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
    return map_display[y][x];
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

void status::set_visible(){
        if(x>0 && y>0)
                map[x-1][y-1] -> toggleSeen();

        if(y>0)
                map[x][y-1] -> toggleSeen();

        if(x<128 && y >0)
                map[x+1][y-1] -> toggleSeen();

        if(x>0)
                map[x-1][y] -> toggleSeen();

        if(x<128)
                map[x+1][y] -> toggleSeen();

        if(x>0 && y<128)
                map[x-1][y+1] -> toggleSeen();

        if(y<128)
                map[x][y+1] -> toggleSeen();

        if(x<128 && y<128)
                map[x+1][y+1] -> toggleSeen();

        map[x][y] -> toggleSeen();
}

int status::getCursorX(){
        return cursorX;
}
int status::getCursorY(){
        return cursorY;
}

