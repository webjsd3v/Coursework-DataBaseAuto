#include "gui_help.h"

char *help_data[] = {
    "Create , Edit , Delete item - Main function witch ... ; Debug...",
    "rwrw",
    ",rwrwr"
};
int n_help_data = sizeof(help_data) / sizeof(char *); // трюк плдучения количества записей

char *info_data[] = {
    "Something ...",
    "rwrw",
    ",rwrwr"
};
int n_info_data = sizeof(info_data) / sizeof(char *); // трюк плдучения количества записей


void guiconf_M_HELPINFO(char ** sz_data, int i_data){ //быстрая справка
    int stdmax_y = 0, stdmax_x = 0;
    getmaxyx(stdscr,stdmax_y,stdmax_x);
    int starty = stdmax_y - 5, startx = stdmax_x - 10;

    WINDOW * help_win_shadow = newwin(starty, startx+1, 4, 6);
    wbkgdset(help_win_shadow, COLOR_PAIR(2)); // установка фона
    PANEL * help_win_panel_shadow = new_panel(help_win_shadow);

    wborder(help_win_shadow,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);

    update_panels();doupdate();wrefresh(help_win_shadow);

    WINDOW * help_win = newwin(starty, startx, 3, 5);
    wbkgdset(help_win, COLOR_PAIR(1)); // установка фона
    PANEL * help_win_panel = new_panel(help_win);
    int coo_y = 2;int coo_x = 2;

    wborder(help_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);


    update_panels();
    doupdate();
    int i = 0;
    coo_y++;
    mvwprintw(help_win,2,(stdmax_x-strlen("INFO"))/2,"INFO");
    coo_y += 2;
    for( ; i < i_data ; i ++ ){
        mvwprintw(help_win,coo_y,coo_x,"%s",sz_data[i]);
        coo_y++;
    }
    wrefresh(help_win);

    getch();
    wclear(stdscr);
    wrefresh(stdscr);
    del_panel(help_win_panel);
    delwin(help_win);
    del_panel(help_win_panel_shadow);
    delwin(help_win_shadow);

}
