#include "displayClass.h"                                                           
                                                                           
                                                                             
Display::Display() {                                      
        initscr();                                        
        refresh();                                        
        noecho(); 
        if(has_colors() == FALSE){
                endwin();
                printf("This terminal does not support color. Exiting...\n");
                exit(1);
        }
        start_color();   
        init_pair(PLAYER_PAIR, COLOR_YELLOW, COLOR_RED);
        init_pair(GRASS_PAIR, COLOR_BLACK, COLOR_GREEN);                                                  
        getmaxyx(stdscr, maxY, maxX);                                   
        menuSize = 30;                                                              
        map = newwin(maxY, maxX-menuSize, 0, 0);                                    
        menu = newwin(maxY, menuSize, 0, maxX - menuSize);        
        mapBeginningY = (mapY-MAP_SIZE)/2;
        mapBeginningX = (mapX-MAP_SIZE)/2;                  
        box(map, 0, 0);                                                             
        box(menu, 0, 0);     
        wprintw(map, "Map");                                                       
        wprintw(menu, "Menu");                                                                                                    
        wrefresh(menu);                                                             
        wrefresh(map);                                                              
}  

Display::Display(int y, int x) {                                                                                                                     
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
        noecho();                                                                                                      
        getmaxyx(stdscr, maxY, maxX);                                                                                                               
        menuSize = 30;
        map = newwin(maxY, maxX-menuSize, 0, 0);                                                                                                     
        menu = newwin(maxY, menuSize, 0, maxX - menuSize);                                                                                              
        getmaxyx(map, mapY, mapX);                                                                                                                      
        mapBeginningY = (mapY-MAP_SIZE)/2;                                                                                             
        mapBeginningX = (mapX-MAP_SIZE)/2;                                                                                                                     
        box(map, 0, 0);
        box(menu, 0, 0);
        wprintw(menu, "Menu");                                                                                                         
        wprintw(map, "Map");
        wrefresh(menu);
        wrefresh(map);                                                                                                  
                                                                                                                       
        updateMap();                                                                                                   
        updatePlayerPosition(y, x);                                                                                              
}                                                                                 
                                                                                    
Display::~Display() {                                                               
        delwin(menu);                                                               
        delwin(map);                                                                
        endwin();                                                        
}                                                                                   
                                                                                    
void Display::getInput() {                                                          
        getch();                                          
}    

void Display::updateMap(/*TODO: array of grovnicks*/) {                                                                                                            
        for(int i = 0; i < 11; ++i) {                                                                                   
                for(int j = 0; j < 11; ++j) {
                                wattron(map, COLOR_PAIR(GRASS_PAIR)); //assuming all grovnicks are meadows for demo

                                if(j == 0 && i == 0)
                                        mvwaddch(map, mapBeginningY+i, mapBeginningX+j, OBSTACLE);
                                else if(j == 10 && i == 0)
                                        mvwaddch(map, mapBeginningY+i, mapBeginningX+j, FOOD);
                                else if(j == 10 && i == 10)
                                        mvwaddch(map, mapBeginningY+i, mapBeginningX+j, TOOL);
                                else mvwaddch(map, mapBeginningY+i, mapBeginningX+j, ' ');
                
                                wattroff(map, COLOR_PAIR(GRASS_PAIR));
                                wrefresh(map);
                }
        }
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
        list grovnick;
        char toPrint = ' ';
        for(int i = 0; i < 128; ++i) {
                for(int j = 0; j < mapY; ++j) {
                        grovnick = object.draw_display(j+(toDisplay)/2, i);

                        if(grovnick.content == "null")
                                toPrint == ' ';
                ///     else if(grovnick.content == "axe" || grovnick.content == "hatchet")
                //              toPrint = TOOL;
                        else if(grovnick.content == "food")
                                toPrint == FOOD;
                        else if(grovnick.content == "ship")
                                toPrint == SHIP;
                        else if(grovnick.content == "tree" || grovnick.content == "boulder")
                                toPrint == OBSTACLE;
                        else if(grovnick.content == "$")
                                toPrint == TREASURE;
                        else toPrint == ' ';


                        if(grovnick.terrain == "meadow") {
                                wattron(map, COLOR_PAIR(GRASS_PAIR));
                                mvwaddch(map, j, i+mapBeginningX, toPrint);
                                wattroff(map, COLOR_PAIR(GRASS_PAIR));
                        }
                        else if(grovnick.terrain == "swamp") {
                                wattron(map, COLOR_PAIR(SWAMP_PAIR));
                                mvwaddch(map, j, i+mapBeginningX, toPrint);
                                wattroff(map, COLOR_PAIR(SWAMP_PAIR));
                        }
                        else if(grovnick.terrain == "water") {
                                wattron(map, COLOR_PAIR(WATER_PAIR));
                                mvwaddch(map, j, i+mapBeginningX, toPrint);
                                wattroff(map, COLOR_PAIR(WATER_PAIR));
                        }
                        else if(grovnick.terrain == "wall") {
                                wattron(map, COLOR_PAIR(WALL_PAIR));
                                mvwaddch(map, j, i+mapBeginningX, toPrint);
                                wattroff(map, COLOR_PAIR(WALL_PAIR));
                        }

                }
        }
        wrefresh(map);
}             