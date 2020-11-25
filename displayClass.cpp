#include "displayClass.h"                                                           
                                                                           
                                                                             
Display::Display() {                                      
        initscr();                                        
        refresh();                                        
        noecho();                                                      
        getmaxyx(stdscr, maxY, maxX);                                   
        menuSize = 30;                                                              
        map = newwin(maxY, maxX-menuSize, 0, 0);                                    
        menu = newwin(maxY, menuSize, 0, maxX - menuSize);                          
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
                                                          
                