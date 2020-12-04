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
        init_pair(INV_PAIR, COLOR_BLACK, COLOR_BLACK);
        init_pair(CURSOR_PAIR, COLOR_BLACK, COLOR_YELLOW);

        noecho();

        posY = posX =curPosX = BEGIN_AT;
        curPosY = BEGIN_AT+1;
        int maxY, maxX;
        getmaxyx(stdscr, maxY, maxX);
        menuSize = 30;
        map = newwin(maxY, maxX-menuSize, 0, 0);
        menu = newwin(maxY, menuSize, 0, maxX - menuSize);
        keypad( stdscr, TRUE );
        keypad( map, TRUE );
        getmaxyx(map, mapY, mapX);
        mapPosY  = (mapY-1)/2;
        curMapY = mapPosY+1;

        if(mapX % 2 == 0)
                mapPosX = (mapX-1)/2;
        else mapPosX = mapX/2-1;

        curMapX = mapPosX;

        mapBeginningY = mapY/2;
        mapBeginningX = (mapX-MAP_SIZE)/2;
        box(map, 0, 0);
        box(menu, 0, 0);
        wprintw(menu, "Menu");
        wprintw(map, "Map");


        initialMap(object);

        updatePlayerPosition(y, x, object, 0);
        updateCursor(object,0);
        wrefresh(menu);
        wrefresh(map);                                                                                        
}                                                                                 
                                                                                    
Display::~Display() {                                                               
        delwin(menu);                                                               
        delwin(map);                                                                
        endwin();                                                        
}                                                                                   
                                                                                                                                  
                                                          
void Display::updatePlayerPosition(int y, int x, status& object, int direction) {
        if( y < 0 || y > 127 || x < 0 || x > 127) return;
        grovnic* location = object.get_grovnic(posY, posX);

        if(y < startedY){            
                startedY = y;   
                updateMap(startedY, object);    
                wattron(map, COLOR_PAIR(PLAYER_PAIR));
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wattroff(map, COLOR_PAIR(PLAYER_PAIR));
                wrefresh(map);
                printY();
                return; 
        }       
        if(y > stoppedY){
                ++startedY;
                updateMap(startedY, object);
                wattron(map, COLOR_PAIR(PLAYER_PAIR));
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wattroff(map, COLOR_PAIR(PLAYER_PAIR)); 
                wrefresh(map); 
                printY();
                return; 
        }       

        char toPrint = determineContent(location->get_item_info());
        printGrovnick(location->get_name(), mapPosY, mapPosX, toPrint);


        if(direction == KEY_LEFT) --mapPosX;
        else if(direction == KEY_RIGHT) ++mapPosX;
        else if(direction == KEY_UP) --mapPosY;
        else if(direction == KEY_DOWN) ++mapPosY;
        wattron(map, COLOR_PAIR(PLAYER_PAIR));
        mvwaddch(map, mapPosY, mapPosX, PLAYER);
        wattroff(map, COLOR_PAIR(PLAYER_PAIR));
        wrefresh(map); 
 
        posY = y;
        posX = x;

}  




void Display::updateCursor(status& object, int direction){
        int y = object.getCursorY();
        int x = object.getCursorX();
        if(y == startedY || y == stoppedY) return;
        grovnic* location = object.get_grovnic(curPosY, curPosX);
        //if(!location -> is_Seen()) return;
        char toPrint = determineContent(location->get_item_info());
        printGrovnick(location->get_name(), curMapY, curMapX, toPrint);



        if(direction == 'a') --curMapX;
        else if(direction == 'd') ++curMapX;
        else if(direction == 'w') --curMapY;
        else if(direction == 's') ++curMapY;

        curPosX = x;
        curPosY = y;
        location = object.get_grovnic(curPosY, curPosX);
        toPrint = determineContent(location->get_item_info());
        wattron(map, COLOR_PAIR(CURSOR_PAIR));
        mvwaddch(map, curMapY, curMapX, toPrint);
        wattroff(map, COLOR_PAIR(CURSOR_PAIR));
        wrefresh(map);
}


void Display::updateMap(int startedY, status& object) {
        char toPrint = ' ';
        for(int i = 0; i < 128; ++i) {
                for(int j = 0; j < mapY; ++j) {

                        grovnic *location = object.get_grovnic(j+startedY,i);
                        toPrint = ' ';
                        toPrint = determineContent(location->get_item_info());
                        printGrovnick(location->get_name(), j, i+mapBeginningX, toPrint);
                        stoppedY = j+startedY;
                }
        }
        wrefresh(map);

}


void Display::initialMap(status& object) {
        startedY = (MAP_SIZE - mapY)/2;
        char toPrint = ' ';
        for(int i = 0; i < 128; ++i) {
                for(int j = 0; j < mapY; ++j) {
                        grovnic* location = object.get_grovnic(j+startedY,i);
                        toPrint = ' ';
                        toPrint = determineContent(location->get_item_info());
                        printGrovnick(location->get_name(), j, i+mapBeginningX, toPrint);
                        stoppedY = j+startedY;
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