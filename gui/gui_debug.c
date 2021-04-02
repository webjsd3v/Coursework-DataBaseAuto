#include "gui_debug.h"
void guiconf_M_DEBUG(){ // вкл. выкл. граф меню
    int y,x;getmaxyx(stdscr,y,x);
    x = 5;
    if(debug_mode){
        move(y-1,x);clrtoeol();
        mvprintw(y-1,x,pmsg(MSG_GUI_DEBUG_ON));refresh();
        debug_mode = 0;
    }else{
        move(y-1,x);clrtoeol();
        mvprintw(y-1,x,pmsg(MSG_GUI_DEBUG_OFF));refresh();
        debug_mode = 1;
    }
}
