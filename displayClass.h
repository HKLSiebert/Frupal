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
#define BEGIN_AT 63

class Display{

        public:
                Display(int y, int x, status& object); //hero starting coordinates and status object for loading in map
                ~Display();
                //int updateMenu(/*object Cursor*/);
                //int updateGrovnick(int x, int y);
                //int updateCursor(/*object Cursor*/);
                /*int loadMap();
                int updateFood();
                int updateObstacles();
                int updateTreasure();
                int updateTools();
                int updateClues();*/
                void updatePlayerPosition(int y, int x, status& object, int direction);                                                                                                        
                void updateMap(int startedY, status& object);                                                                                                                        
                void initialMap(status& object);                                                                                                            
                void printGrovnick(string terrain, int y, int x, char toPrint);                                                                             
                char determineContent(string content);    
      
        private:
                int mapY, mapX, mapBeginningY, mapBeginningX, menuSize, posY, posX, mapPosX, mapPosY startedY, startedX;
                WINDOW *map;
                WINDOW *menu;

};

