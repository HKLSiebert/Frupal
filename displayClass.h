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
#define BLANK ' '
#define BINOCULARS 'B'
#define PLAYER_PAIR 1
#define GRASS_PAIR 2
#define BLANK_PAIR 3
#define SWAMP_PAIR 4                                                                                                                                    
#define WATER_PAIR 5                                                                                                                                    
#define WALL_PAIR 6 
#define MAP_SIZE 128
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
                Display(int y, int x, status& object); //hero starting coordinates and status object for loading in map
                ~Display();
                void getInput();
                //int updateMenu(/*object Cursor*/);
                //int updateGrovnick(int x, int y);
                //int updateCursor(/*object Cursor*/);
                /*int loadMap();
                int updateFood();
                int updateObstacles();
                int updateTreasure();
                int updateTools();
                int updateClues();*/
                void updatePlayerPosition(int y, int x, status& object);                                                                                                        
                void updateMap(status& object);                                                                                                                        
                void initialMap(status& object);                                                                                                            
                void printGrovnick(string terrain, int y, int x, char toPrint);                                                                             
                char determineContent(string content);    
      
        private:
                int maxY, maxX, mapY, mapX,  mapBeginningY, mapBeginningX, menuSize, posY, posX, startedY, startedX;
                WINDOW *map;
                WINDOW *menu;

};
~     