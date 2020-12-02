#include "displayClass.h"                                                           
                                                                           

Display::Display(int y, int x, status& object) {                                                                                                                     
  initscr();
        refresh();
        if(has_colors() == FALSE){
                endwin();
                printf("This terminal does not support color. Exiting...\n");
                exit(1);
        }
        start_color();
        init_pair(PLAYER_PAIR, COLOR_YELLOW, COLOR_RED);
        init_pair(GRASS_PAIR, COLOR_BLACK, COLOR_GREEN);
        init_pair(BLANK_PAIR, COLOR_GREEN, COLOR_GREEN);
        init_pair(SWAMP_PAIR, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(WATER_PAIR, COLOR_BLACK, COLOR_BLUE);
        init_pair(WALL_PAIR, COLOR_BLACK, COLOR_WHITE);
        noecho();

        posY = posX = BEGIN_AT;
        int maxY, maxX;
        getmaxyx(stdscr, maxY, maxX);
        menuSize = 30;
        map = newwin(maxY, maxX-menuSize, 0, 0);
        menu = newwin(maxY, menuSize, 0, maxX - menuSize);
        keypad( stdscr, TRUE );
        keypad( map, TRUE );
        getmaxyx(map, mapY, mapX);
        mapPosY = (mapY-1)/2;

        if(mapX % 2 == 0)
                mapPosX = (mapX-1)/2;
        else mapPosX = mapX/2-1;

        mapBeginningY = mapY/2;
        mapBeginningX = (mapX-MAP_SIZE)/2;
        box(map, 0, 0);
        box(menu, 0, 0);
        wprintw(menu, "Menu");
        wprintw(map, "Map");
        wrefresh(menu);
        wrefresh(map);

        initialMap(object);
        updatePlayerPosition(y, x, object, 0);                                                                                           
}                                                                                 
                                                                                    
Display::~Display() {                                                               
        delwin(menu);                                                               
        delwin(map);                                                                
        endwin();                                                        
}                                                                                   
                                                                                                                                  
                                                          
void Display::updatePlayerPosition(int y, int x, status& object, int direction) {
        if( y < 0 || y > 127 || x < 0 || x > 127) return;



        if(y < startedY){
                startedY = y;
                updateMap(startedY, object);
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wrefresh(map);
                return;
        }
        if(y > stoppedY){
                ++startedY;
                updateMap(startedY, object);
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wrefresh(map);
                return;
        }

        list grovnick = object.draw_display(posY,posX);
        char toPrint = determineContent(grovnick.content);
        printGrovnick(grovnick.terrain, mapPosY, mapPosX, toPrint);

        wattron(map, COLOR_PAIR(PLAYER_PAIR));
        if(direction == KEY_LEFT) --mapPosX;
        else if(direction == KEY_RIGHT) ++mapPosX;
        else if(direction == KEY_UP) --mapPosY;
        else if(direction == KEY_DOWN) ++mapPosY;
        mvwaddch(map, mapPosY, mapPosX, PLAYER);
        wattroff(map, COLOR_PAIR(PLAYER_PAIR));
        wrefresh(map);

        posY = y;
        posX = x;

}  


void Display::updateMap(int startedY, status& object) {
        list grovnick;
        char toPrint = ' ';
        for(int i = 0; i < 128; ++i) {
                for(int j = 0; j < mapY; ++j) {
                        grovnick = object.draw_display(j+startedY, i);
                        toPrint = ' ';
                        toPrint = determineContent(grovnick.content);
                        printGrovnick(grovnick.terrain, j, i+mapBeginningX, toPrint);
                        stoppedY = j+startedY;
                }
        }
        wrefresh(map);

}


void Display::initialMap(status& object) {
         startedY = (MAP_SIZE - mapY)/2;
        list grovnick;
        char toPrint = ' ';
        for(int i = 0; i < 128; ++i) {
                for(int j = 0; j < mapY; ++j) {
                        grovnick = object.draw_display(j+startedY, i);
                        toPrint = ' ';
                        toPrint = determineContent(grovnick.content);
                        printGrovnick(grovnick.terrain, j, i+mapBeginningX, toPrint);
                        if(j+startedY > stoppedY) stoppedY = j+startedY;
                }
        }
        wrefresh(map);
}


void Display::printGrovnick(string terrain, int y, int x, char toPrint) {
        if(terrain == "meadow") {
                wattron(map, COLOR_PAIR(GRASS_PAIR));
                mvwaddch(map, y, x, toPrint);
                wattroff(map, COLOR_PAIR(GRASS_PAIR));
        }
        else if(terrain == "swamp") {
                wattron(map, COLOR_PAIR(SWAMP_PAIR));
                mvwaddch(map, y, x, toPrint);
                wattroff(map, COLOR_PAIR(SWAMP_PAIR));
        }
        else if(terrain == "water") {
                wattron(map, COLOR_PAIR(WATER_PAIR));
                mvwaddch(map, y, x, toPrint);
                wattroff(map, COLOR_PAIR(WATER_PAIR));
        }
        else if(terrain == "wall") {
                wattron(map, COLOR_PAIR(WALL_PAIR));
                mvwaddch(map, y, x, toPrint);
                wattroff(map, COLOR_PAIR(WALL_PAIR));
        }

}

char Display::determineContent(string content) {
        if(content == "axe" || content == "hatchet" || content == "hammer")
                return TOOL;
        if(content == "food")
                return FOOD;
        if(content == "ship")
                return SHIP;
        if(content == "tree" || content == "boulder")
                return OBSTACLE;
        if(content == "treasure")
                return TREASURE;
        return ' ';

}