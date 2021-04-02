#include "gui_settings.h"
#define WIDTH 35
#define HEIGHT 25

// загрузка основных настроек

int s_load_settings(){
    initscr(); // вызов курса
    clear(); // очистить экран
    noecho(); // выключить эхо ввода с клавиатуры
    cbreak();	/* Line buffering disabled. pass on everything */
    /* enable and create first palette */
    if(!has_colors() && can_change_color()){
        endwin();
        printf("Terminal not supported colors :( \n");
        return 1;
    } // enable color functionality
    start_color(); // инициализация цветов
    init_pair(1, 2, COLOR_BLACK); // create pair #1
    init_pair(2, COLOR_GREEN,COLOR_GREEN ); // create pair #1
    curs_set(0); // убрать курсор
    return 0;
}
// установка виртуальных окон
void init_wins(WINDOW **wins, int n) //подготовка и создание виртуальных окон
{
    int starty = 2, startx = 5, i = 0;

    for(; i < n; ++i)
    {
        switch(i){
            case 2 : {
                wins[i] = newwin(HEIGHT, 10, starty, startx); //создать новое окно
            }
            default :{
                wins[i] = newwin(HEIGHT, WIDTH, starty, startx); //создать новое окно
            }

        }

        wbkgdset(wins[i], COLOR_PAIR(1)); // установка фона
        wclear(wins[i]); //очистка дисплея
        wrefresh(wins[i]); //обновление прорисовки
        startx += 35;
    }
}

// функция ключения , отключения конкретного окна
void switch_panels(int type){ // переключатель вкл. выкл. для виртуальных панелей
    temp = (PANEL_DATA *)panel_userptr(menu_panels[type]);
    if(temp->hide != FALSE){
        temp->hide = FALSE;
        show_panel(menu_panels[type]);
    }else{
        temp->hide = TRUE;
        wclear(menu_wins[type]);
        wrefresh(menu_wins[type]);
        hide_panel(menu_panels[type]);
    }

    update_panels();
    doupdate();
}

void init_panels(WINDOW **wins, int n){ // привязка окон к панелям
    int i = 0;
    for(i= 0; i < n; ++i){
        menu_panels[i] = new_panel(wins[i]); /* Push n, order: stdscr n*/
        panel_datas[i].hide = FALSE; // инициализировать данные панели и указать , что ничего не скрыто
        set_panel_userptr(menu_panels[i], &panel_datas[i]);
        wborder(wins[i],WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
    }
    ((PANEL_DATA *)panel_userptr(menu_panels[WIN_N_LIST]))->hide = TRUE;
    hide_panel(menu_panels[WIN_N_LIST]);
    ((PANEL_DATA *)panel_userptr(menu_panels[WIN_N_SETT]))->hide = TRUE;
    hide_panel(menu_panels[WIN_N_SETT]);
    update_panels();
    doupdate();
}
