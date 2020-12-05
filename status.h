#pragma once
#include <string>
#include <iostream>
#include "frupalMap.h"
#include <ncurses.h>
#include <fstream>
#include "object.h"
using namespace std;
const int SIZEX=128;
const int SIZEY=128;

//Need to remember if hero has binoculars have to update how many sqaures he can look at.
class status
{
  public:
    status();
    status(frupalMap & startmap);
    ~status();

    void read_map(); //reads map from external file into list **map_display
    int gameprogress();//is user did or did they complete the game?
    int success();
    void cursor(char);

    void update(char userinput);
    grovnic* get_grovnic(int x, int y);//returns grovnic ptr according to coords
    int getCursorX();
    int getCursorY();
    void set_visible();
  protected:
    int startx;//coords of hero
    int starty;

    int cursorX; //coords of cursor
    int cursorY;

    hero * my_hero;
    grovnic ***map; //map of grovnicks, dynamically allocated, 128x128
};


