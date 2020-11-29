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
                                /*if(grovnick has food)
                                        mvwprintw(map, mapBeginningY+i, mapBeginningX+j, FOOD);
                                else if(grovnick has tools)
                                        mvwprintw(map, mapBeginningY+i, mapBeginningX+j, TOOL);
                                else mvwprintw(map, mapBeginningY+i, mapBeginningX+j, "");*/
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