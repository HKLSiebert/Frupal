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
#define INV_PAIR 7
#define CURSOR_PAIR 8
#define MAP_SIZE 128
#define MENU_SIZE 128
#define BEGIN_AT 63

class Display{

        public:
                Display(int y, int x, status& object); //hero starting coordinates and status object for loading in map
                ~Display();
                void updatePlayerPosition(status& object, int direction); //use if player is updated
                void updateCursor(status& object, int direction); //use is cursor updates
                void updateCursorMenu(status& object);
                void updatePlayerMenu(status& obejct);
                void updateMap(int startedY, status& object);
                void initialMap(status& object);
                void initialMenu();
                void printGrovnick(string terrain, int y, int x, char toPrint);
                char determineContent(string content);
      
        private:
                /*****************************************

                [mapY, mapX] max map x*y
                [mapBeginningX] where the
                [posY posX] previous hero position so we can print the correct grovnick as the hero moves away
                [mapPosX mapPosY] the heroes position in relation to the map window
                [startedY, stoppedY] where the map begins and ends printing on the y-axis
                [cusPosY curPosX curMapY curMapX] previous cursor pos + in relation to map
                [offset] offsets the cursors position relative to the map window if the map "moves" on the y-axis
                [menuY] max menu size on the y-axis

                ******************************************/
                int mapY, mapX, posY, posX, mapPosX, mapPosY, startedY, stoppedY, curPosY, curPosX, curMapY, curMapX, offset, menuY;
                WINDOW *map;
                WINDOW *menu;

};

