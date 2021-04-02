#include "gui_reset.h"

void guiconf_M_RESET(){ //сбросить все данные в структуре ( очистить полностью )
    int y,x;getmaxyx(stdscr,y,x);
    x = 5;
    move(y-1,x);clrtoeol();
    mvprintw(y-1,x,"All elements are deleted ! Total %i",destroyStruct(&default_list));refresh();
}
