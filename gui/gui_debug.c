#include "gui_debug.h"
void guiconf_M_DEBUG(){
    int y,x;getmaxyx(stdscr,y,x);
    x = 5;
    if(debug_mode){
        move(y-1,x);clrtoeol();
        mvprintw(y-1,x,"DEBUG is OFF ... \n");refresh();
        debug_mode = 0;
    }else{
        move(y-1,x);clrtoeol();
        mvprintw(y-1,x,"DEBUG is ON ... \n");refresh();
        debug_mode = 1;
    }
}
