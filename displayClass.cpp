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
                                                                                    
Display::~Display() {                                                               
        delwin(menu);                                                               
        delwin(map);                                                                
        endwin();                                                        
}                                                                                   
                                                                                    
void Display::getInput() {                                                          
        getch();                                          
}    

void Display::updateMap(/*grovnick array*/) {
        for(int i = 0; i < 11; ++i) {
                for(int j = 0; j < 11; ++j) {
                                attron(COLOR_PAIR(GRASS_PAIR)); //assuming all grovnicks are meadows for demo
                                if(/*grovnick has food*/)
                                        mvwprintw(map, mapBeginningY+i, mapBeginningX+j, FOOD);
                                else if(/*grovnick has tools*/) 
                                        mvwprintw(map, mapBeginningY+i, mapBeginningX+j, TOOL);
                                else if(/*grovnick has obstacle*/) 
                                        mvwprintw(map, mapBeginningY+i, mapBeginningX+j, OBSTACLE);
                                else mvwprintw(map, mapBeginningY+i, mapBeginningX+j, "");
                                attroff(COLOR_PAIR(GRASS_PAIR));
                }                 
        } 
        //updatePlayerPosition(hero position);                      
}                                                      
                                                          
void Display::updatePlayerPosition(/*pass hero object or coords*/) {
        attron(COLOR_PAIR(PLAYER_PAIR));
        mvwprintw(map, /*hero position y*/, /*hero position x*/, PLAYER);
        attroff(COLOR_PAIR(PLAYER_PAIR));
}                