#pragma once
#include <ncurses.h>
#include <string>
#include <iostream>
#include "status.h"

#define PLAYER '@'
#define FOOD 'F'
#define TOOL 'T'
#define OBSTACLE '!'
#define TREASURE '$'
#define CLUE '?'
#define SHIP 'S'
#define BLANK 0
#define BINOCULARS 'B'
#define PLAYER_PAIR 1
#define GRASS_PAIR 2
#define BLANK_PAIR 3
#define MAP_SIZE 11
/*
BLACK   0
RED     1
GREEN   2
YELLOW  3
BLUE    4
MAGENTA 5
CYAN    6
WHITE   7
*/

class Display{
        public:
                Display();
                Display(int y, int x); //hero starting coordinates
                ~Display();
                void getInput();
                void initialMap(status& object);
                void updateMap();
                //int updateMenu(/*object Cursor*/);
                //int updateGrovnick(int x, int y);
                //int updateCursor(/*object Cursor*/);
                /*int loadMap();
                int updateFood();
                int updateObstacles();
                int updateTreasure();
                int updateTools();
                int updateClues();*/
                void updatePlayerPosition(int y, int x);
      
        private:
                int maxY, maxX, mapY, mapX,  mapBeginningY, mapBeginningX, menuSize, posY, posX;
                WINDOW *map;
                WINDOW *menu;

};
~     