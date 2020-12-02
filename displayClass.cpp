#include "displayClass.h"                                                           
                                                                           

Display::Display(int y, int x, status& object) {                                                                                                                     
        initscr(); 
        noecho();       

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

  
        posY = DEMO_HERO_START_Y;
        posX = DEMO_HERO_START_X;    

        getmaxyx(stdscr, maxY, maxX);                                                                                                               
        menuSize = 30;
        map = newwin(maxY, maxX-menuSize, 0, 0);                                                                                                     
        menu = newwin(maxY, menuSize, 0, maxX - menuSize); 

        keypad( stdscr, TRUE );
        keypad( map, TRUE );   
                                                                                                  
        getmaxyx(map, mapY, mapX);                                                                                                                      
        mapBeginningY = (mapY-MAP_SIZE)/2;                                                                                             
        mapBeginningX = (mapX-MAP_SIZE)/2;                                                                                                                     
        box(map, 0, 0);
        box(menu, 0, 0);
        wprintw(menu, "Menu");                                                                                                         
        wprintw(map, "Map");
        wrefresh(menu);
        wrefresh(map);                                                                                                  
                                                                                                                       
        initialMap(object);                                                                                                  
        updatePlayerPosition(y, x, object);                                                                                              
}                                                                                 
                                                                                    
Display::~Display() {                                                               
        delwin(menu);                                                               
        delwin(map);                                                                
        endwin();                                                        
}                                                                                   
                                                                                    
void Display::getInput() {                                                          
        getch();                                          
}    
                                                 
                                                          
void Display::updatePlayerPosition(int y, int x) {
        wattron(map, COLOR_PAIR(GRASS_PAIR));
        mvwaddch(map, posY, posX, ' ');
        wattroff(map, COLOR_PAIR(GRASS_PAIR));

        wattron(map, COLOR_PAIR(PLAYER_PAIR));
        posY = mapBeginningY + y;
        posX = mapBeginningX + x;
        mvwaddch(map, posY, posX, PLAYER);
        wattroff(map, COLOR_PAIR(PLAYER_PAIR));
        wrefresh(map);
}  

void Display::initialMap(status& object) {
        int mapMiddle = mapY/2;
        int toDisplay = 128-mapMiddle;
        startedY = toDisplay/2;
        list grovnick;
        char toPrint = ' ';
        for(int i = 0; i < 128; ++i) {
                for(int j = 0; j < mapY; ++j) {
                        grovnick = object.draw_display(j+(toDisplay)/2, i);
                        toPrint = ' ';
                        toPrint = determineContent(grovnick.content);
                        printGrovnick(grovnick.terrain, j, i+mapBeginningX, toPrint);
                        if(mapY > stoppedY) stoppedY = mapY;
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