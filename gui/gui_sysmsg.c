#include "gui_sysmsg.h"

void sys_gui_msg(const char * sz_msg){ // функция вызова системных сообщений
    int y,x;
    getmaxyx(stdscr,y,x); x = 5; // получаем координаты макс размера окна
    move(y-3,x);clrtoeol(); // перемещается курсор в самы низ
    mvprintw(y-3,x,sz_msg);refresh(); // выводим системное сообщение
}

void show_keyinfo(int starty,int startx,int ch){ // отображать нажатия клавишей
    wattron(stdscr, A_NORMAL | COLOR_PAIR(1) );
    mvprintw(starty,startx, pmsg(MSG_SYSMSG_MSG1), ch, ch);
    wattroff(stdscr, A_NORMAL | COLOR_PAIR(1) );
    refresh();
}

