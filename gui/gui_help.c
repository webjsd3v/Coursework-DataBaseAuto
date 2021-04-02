#include "gui_help.h"


char *help_data[] = {
    "Navigation in the program in any menu you can navigate the items using the arrows up and down.",
    "From any menu item it is possible to exit with F10, the arrow <- dibo select the item EXIT",
    "..."
};


char *help_data_rus[] = {
    "1.0 Навигация в программе : в любом меню можно перемещаться по пунктам с помощью стрелочек вверх и вниз.  ",
    "1.1 C любого пункта меню можно выйти с помощью F10, стрелочка <- либо выбрать пункт ВЫХОД",
    "2.0 Пункт \"Создать или Редак.запись\" - в нем находятся список записей. Их можно создавать, удалять ",
    "отредактировать. Перемещаться по списку нам помогают стрелочки вверх и вниз. Есть возможность загружать",
    "список с существующего файла ( Есть два варианта L - быстрая загрузка со стандартного файла \"db.bin\"",
    "либо расширеный режим загрузки SHIFT + L. Так же можно и сохранять в стандартный файл с помощью клавиши ",
    "'s' либо расширеный режим S + SHIFT. Чтобы создать новую запись, достаточно нажать 'c' либо F6",
    "Если нужно поправить информацию в записи - для начала выберем ее и нажмем F7 либо 'e' . После создания ",
    "либо редактирования, вам нужно будет выйти в список и в этом нам помогут наши стандартные клавиши для ",
    "выхода F10, 'l'(если мы в пункте загрузки с файла), 's' ( в пункте сохранения ), 'e' и 'c' (редак. и  ",
    "сохранения соответственно ). Выход в главное меню <- либо F10 ",
    "3.0 \"Режим отладки\" - скрывать, либо отображать системные сообщения",
    "4.0 \"Сбросить все данные\" - очистить все записи с нашего списка",
    "5.0 \"Сортировка данных\" - есть вожможность сортировать записи по определенной колонке (возр. и убыванию)",
    "6.0 \"Поиск записи\" - можно найти 1 или несколько записей, выбрав один из пунктов и указав ключевое слово . ",
    "Далее вас перебросит в список результатов поиска. В нем вы можете отредактировать или удалить нужную вам ",
    "информацию."
    "7.0 В пунктах загрузки и сохранения, есть поддержка шифрования файла ",
    "..."
};

int n_help_data = sizeof(help_data) / sizeof(char *); // трюк плдучения количества записей
int n_help_data_rus = sizeof(help_data_rus) / sizeof(char *); // трюк плдучения количества записей

char *info_data[] = {
    "..."
};

char *info_data_rus[] = {
    "..."
};

int n_info_data = sizeof(info_data) / sizeof(char *); // трюк плдучения количества записей
int n_info_data_rus = sizeof(info_data_rus) / sizeof(char *); // трюк плдучения количества записей

void guiconf_M_HELPINFO(char ** sz_data, int i_data,const char * sz_header){ //быстрая справка
    int stdmax_y = 0, stdmax_x = 0;
    getmaxyx(stdscr,stdmax_y,stdmax_x);
    int starty = stdmax_y - 5, startx = stdmax_x - 10;

    //WINDOW * help_win_shadow = newwin(starty, startx+1, 4, 6);
    //wbkgdset(help_win_shadow, COLOR_PAIR(2)); // установка фона
    //PANEL * help_win_panel_shadow = new_panel(help_win_shadow);

    //wborder(help_win_shadow,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);

    //update_panels();doupdate();wrefresh(help_win_shadow);

    WINDOW * help_win = newwin(starty, startx, 3, 5);
    wbkgdset(help_win, COLOR_PAIR(1)); // установка фона
    PANEL * help_win_panel = new_panel(help_win);
    int coo_y = 2;int coo_x = 2;

    wborder(help_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4); // отобразить окно с подробным оформлением


    update_panels();
    doupdate();
    int i = 0;
    coo_y++;
    mvwprintw( help_win,2,(stdmax_x-strlen( sz_header ) )/2, sz_header );
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
    //del_panel(help_win_panel_shadow);
    //delwin(help_win_shadow);

}
