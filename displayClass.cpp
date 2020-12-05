#include "displayClass.h"                                                           
                                                                           

Display::Display(int y, int x, status& object) {          
        int x, maxX, maxY;

        initscr();
        noecho();
        refresh();

        offset = 0;
        curs_set(0);
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


        posY = posX =curPosX = BEGIN_AT;
        curPosY = BEGIN_AT+1;
        getmaxyx(stdscr, maxY, maxX);
        map = newwin(maxY, maxX-MENU_SIZE, 0, 0);
        menu = newwin(maxY, MENU_SIZE, 0, maxX - MENU_SIZE);
        keypad( stdscr, TRUE );
        keypad( map, TRUE );
        getmaxyx(map, mapY, mapX);
        getmaxyx(menu, menuY, x);
        mapPosY  = (mapY-1)/2;
        curMapY = mapPosY+1;
        if(mapX % 2 == 0)
                mapPosX = (mapX-1)/2;
        else mapPosX = mapX/2-1;
        curMapX = mapPosX;
        box(map, 0, 0);
        wprintw(menu, "Menu");
        wprintw(map, "Map");
        initialMap(object);
        updatePlayerPosition(object, 0);
        updateCursor(object,0);
        updatePlayerMenu(object);
        initialMenu();
        wrefresh(menu);
        wrefresh(map);                                                                                      
}                                                                                 
                                                                                    
Display::~Display() {                                                               
        delwin(menu);                                                               
        delwin(map);                                                                
        endwin();                                                        
}                                                                                   
                                                                                                                                  
                                                          
void Display::updatePlayerPosition(int y, int x, status& object, int direction) {
        int y = object.getHeroY();
        int x = object.getHeroX();
        char toPrint = ' ';
        if( y < 0 || y > 127 || x < 0 || x > 127) return;
        grovnic* location = object.get_grovnic(posY, posX);

        if(y < startedY){
                offset = 1;
                startedY = y;
                updateMap(startedY, object);
                wattron(map, COLOR_PAIR(PLAYER_PAIR));
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wattroff(map, COLOR_PAIR(PLAYER_PAIR));
                updateCursor(object, 0);
                offset = 0;
                wrefresh(map);
                return;
        }
        if(y > stoppedY){
                offset = -1;
                ++startedY;
                updateMap(startedY, object);
                wattron(map, COLOR_PAIR(PLAYER_PAIR));
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wattroff(map, COLOR_PAIR(PLAYER_PAIR));
                updateCursor(object, 0);
                offset = 0;
                wrefresh(map);
                return;
        }
        updateMap(startedY, object);
        updateCursor(object, 0);
        if(posY == object.getCursorY() && posX == object.getCursorX()){

                wattron(map, COLOR_PAIR(CURSOR_PAIR));
                mvwaddch(map, mapPosY, mapPosX, ' ');
                wattroff(map, COLOR_PAIR(CURSOR_PAIR));
        }
        else{
                item * content = location->get_item();
                if(content)
                        toPrint = determineContent(content->get_name());
                printGrovnick(location->get_name(), mapPosY, mapPosX, toPrint);
        }


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
        char toPrint = ' ';

        if(y == startedY || y == stoppedY) return;
        grovnic* location = object.get_grovnic(curPosY, curPosX);
        item* content = location->get_item();
        if(content)
                toPrint = determineContent(content->get_name());
        if(direction == 0){
                if(offset == 1)
                        ++curMapY;
                else if(offset == -1)
                        --curMapY;
                wattron(map, COLOR_PAIR(CURSOR_PAIR));
                mvwaddch(map, curMapY, curMapX, toPrint);
                wattroff(map, COLOR_PAIR(CURSOR_PAIR));
                return;
        }
        if(curPosY == object.getHeroY() && curPosX == object.getHeroX()){
                wattron(map, COLOR_PAIR(PLAYER_PAIR));
                mvwaddch(map, mapPosY, mapPosX, PLAYER);
                wattroff(map, COLOR_PAIR(PLAYER_PAIR));
        }
        else if(!location -> is_Seen()){
                wattron(map, COLOR_PAIR(INV_PAIR));
                mvwaddch(map, curMapY, curMapX, ' ');
                wattroff(map, COLOR_PAIR(INV_PAIR));
        }
        else
        {
                printGrovnick(location->get_name(), curMapY, curMapX, toPrint);
        }


        if(direction == 'a') --curMapX;
        else if(direction == 'd') ++curMapX;
        else if(direction == 'w') --curMapY;
        else if(direction == 's') ++curMapY;

        curPosX = x;
        curPosY = y;
        location = object.get_grovnic(curPosY, curPosX);
        content = location->get_item();
        if(content && location->is_Seen())
                toPrint = determineContent(content->get_name());
        else toPrint = ' ';
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
                        if(!location->is_Seen()){
                                wattron(map, COLOR_PAIR(INV_PAIR));
                                mvwaddch(map, j, i+((mapX-MAP_SIZE)/2), ' ');
                                wattroff(map, COLOR_PAIR(INV_PAIR));
                        }
                        else{
                                item* content = location->get_item();
                                toPrint = ' ';
                                if(content)
                                        toPrint = determineContent(content->get_name());
                                printGrovnick(location->get_name(), j, i+((mapX-MAP_SIZE)/2), toPrint);
                        }
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
                        if(!location->is_Seen()){
                                wattron(map, COLOR_PAIR(INV_PAIR));
                                mvwaddch(map, j, i+((mapX-MAP_SIZE)/2), ' ');
                                wattroff(map, COLOR_PAIR(INV_PAIR));
                        }
                        else{
                                item* content = location->get_item();
                                toPrint = ' ';
                                if(content)
                                        toPrint = determineContent(content->get_name());
                                printGrovnick(location->get_name(), j, i+((mapX-MAP_SIZE)/2), toPrint);
                        }
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
        if(content == "diamond")
                return TREASURE;
        return ' ';

}

void Display::updateCursorMenu(status& object) {
        for(int i = 1; i<4;++i){
                wmove(menu, i, 0);
                wclrtoeol(menu);
        }
        grovnic* location = object.get_grovnic(curPosY, curPosX);
        if(location->is_occupied()){
                mvwprintw(menu, 1, 0, (location->get_item_info()).data());
        }
        wrefresh(menu);
}

void Display::updatePlayerMenu(status& object) {
        for(int i = menuY-2; i<menuY;++i){
                wmove(menu, i, 0);
                wclrtoeol(menu);
        }
        mvwprintw(menu, menuY-2, 0, "Whiffles: %d", object.getHeroWiffle());
        mvwprintw(menu, menuY-1, 0, "Energy: %d", object.getHeroEnergy());
        wrefresh(menu);
}

void Display::initialMenu(){
        mvwprintw(menu, 5, 0, "Cursor Options: ");
        mvwprintw(menu, 6, 0, "w) North ");
        mvwprintw(menu, 7, 0, "a) West ");
        mvwprintw(menu, 8, 0, "s) South ");
        mvwprintw(menu, 9, 0, "d) East ");

        mvwprintw(menu, 11, 0, "Hero Options: ");
        mvwprintw(menu, 12, 0, "Up Arrow Key) North ");
        mvwprintw(menu, 13, 0, "Left Arrow Key) West ");
        mvwprintw(menu, 14, 0, "Down Arrow Key) South ");
        mvwprintw(menu, 15, 0, "Right Arrow Key) East ");

}

bool Display::update(int userinput, status& object){
  switch(userinput)
  {
    case 'a':
    case 'd':
    case 'w':
    case 's':
        updateCursor(object, userinput);
        if(object.isCursorVisible())
                updateCursorMenu(object);
        break;
    case KEY_LEFT:
    case KEY_RIGHT:
    case KEY_UP:
    case KEY_DOWN:
        updatePlayerPosition(object, userinput);
        updatePlayerMenu(object);
        break;
  }
  return 1;

}