#include "gui_search.h"

char *choices_search[] = {
            "1. By VIN",
            "2. By Full name",
            "3. By Brand",
            "4. By Model",
            "5. Exit"
};

int n_choices_search = sizeof(choices_search) / sizeof(char *); // трюк плдучения количества записей

char *choices_search_rus[] = {
            "1. По VIN",
            "2. По ФИО",
            "3. По бренду",
            "4. По моделе",
            "5. Выход"
};

int n_choices_search_rus = sizeof(choices_search_rus) / sizeof(char *); // трюк плдучения количества записей
// загрузка файлов

void plsl_a(WINDOW * menu_win,int by_type){  // сокращенный макрос для поиска
    char by_name[64];char sz_vinname[254] = {0};
    switch(by_type){
    case 0 :{
        strcpy(by_name,"VIN");
        break;
    }
    case 1 :{
        strcpy(by_name,"Fullname");
        break;
    }
    case 2 :{
        strcpy(by_name,"Brand");
        break;
    }
    case 3 :{
        strcpy(by_name,"Model");
        break;
    }
    default :
        strcpy(by_name,"VIN");
    }
    struct list_box * s_array[1024] = {0};
    mvwprintw(menu_win, 12, 2, pmsg(MSG_GUI_SEARCH_MSG1),by_name);wrefresh(menu_win);
    mvwprintw(menu_win, 13, 2, "->");
    wrefresh(menu_win);
    gui_dynamic_buffer(menu_win,13,4,"",sz_vinname,sizeof(sz_vinname)-1 );
    wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
    mvwprintw(menu_win, 13, 4, "%s",sz_vinname);
    if(menu_win == menu_wins[WIN_N_LIST]){

    search_any(sz_vinname,default_list,"where",by_name,sz_vinname,s_array );
    mvwprintw(menu_win, 14, 4, pmsg(MSG_GUI_SEARCH_MSG2),s_arr_count(s_array));
    wrefresh(menu_win);
    if(s_arr_count(s_array) == 0){
        mvwprintw(menu_win, 15, 3, pmsg(MSG_GUI_CREATE_MSG6));
        wrefresh(menu_win);
        getch();
        return;
    }
    guiconf_M_SEARCH_LIST(menu_wins[WIN_N_SETT],menu_win,WIN_N_SETT,s_array);
    }else{
        guiconf_M_SEARCH_LIST(menu_wins[WIN_N_LIST],menu_win,WIN_N_LIST,s_array);
    }
    wrefresh(menu_win);

}

int s_arr_count(struct list_box ** s_array){ // подсчет результатов поиска
    int i_csa = -1; while(s_array[++i_csa] != 0);
    return i_csa;
}

void print_list_search_list(WINDOW *menu_win, int highlight2,struct list_box ** s_array) // панель результатов поиска
{
    // clear scr
	int x, y, i,max_x;
    getmaxyx(menu_win,y,max_x);
    int i_co_gui = 0;
    while(i_co_gui < y-2){
        cls_line(menu_win,5+i_co_gui,2,max_x-2);
        i_co_gui++;
    }
    wrefresh(menu_win);
    // end
	x = 2; // координаты сдвига от окна
	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, 2, (max_x-strlen(pmsg(MSG_GUI_SEARCH_PRE)))/2, pmsg(MSG_GUI_SEARCH_PRE));
    if(s_arr_count(s_array) != 0){

        int i_counter = 0;
        highlight2 = highlight2-1;
        while(i_counter < highlight2){
            i_counter++;
        }
        for(i = 0; i < 10; ++i)
        {
            if(i < s_arr_count(s_array) - highlight2){
                if(highlight2 == i + highlight2) /* High light the present choice */
                {	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
                    mvwprintw(menu_win, y, x, "%s", s_array[i_counter++]->VIN);
                    wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
                }
                else
                    mvwprintw(menu_win, y, x, "%s", s_array[i_counter++]->VIN);
                ++y;

            }else{
                break;
            }
        }
    }
    switch(short_lang_data){
    case 1 :
        mvwprintw(menu_win, 17, 2, "---------- Подсказки ----------");
        mvwprintw(menu_win, 17 + 2, 3, "-> or ENTER  # выбор");
        mvwprintw(menu_win, 17 + 3, 3, "<-,ESC,F10 # выход");
        mvwprintw(menu_win, 17 + 4, 3, "DEL или F8  # удалить запись");
        break;
    default :
        mvwprintw(menu_win, 17, 2, "---------- FAST HELP ----------");
        mvwprintw(menu_win, 17 + 2, 3, "->,e,ENTER // Edit element");
        mvwprintw(menu_win, 17 + 3, 3, "<-,F10,ESC //exit to pre menu");
        mvwprintw(menu_win, 17 + 4, 3, "DEL,F8     //delete note");

    }


	wrefresh(menu_win);
}

void guiconf_M_SEARCH_LIST(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype,struct list_box ** s_array){ // навигатор по результатам поиска
    switch_panels(ptype);
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;
    while(1){
        int n_choices_list = s_arr_count(s_array);
        print_list_search_list(menu_win, highlight_li,s_array);
        c_list = wgetch(menu_win);
        switch(c_list){
            case KEY_UP:
                if(highlight_li == 1)
                    highlight_li = n_choices_list;
                else
                    --highlight_li;
                break;
            case KEY_DOWN:
                if(highlight_li == n_choices_list)
                    highlight_li = 1;
                else
                    ++highlight_li;
                break;
            case KEY_F(10): /* Привязки выхода их SAVE */
            case KEY_LEFT:
            case 27:        /* ESC KEY */
                choice_list = M_EXIT_L;
                break;
            case 10:    /* привязки выбора */
            case KEY_RIGHT:
            case 'e':
                gui_e_element(highlight_li,menu_wins[WIN_N_LIST],menu_wins[WIN_N_SETT],s_array[highlight_li-1]); // включение панели редактирования элемента
                choice_list = 0;
                break;
            case 330:
            case KEY_F(8):

                if(get_countofrec(default_list) == 0){
                    sys_gui_msg(pmsg(MSG_CMD_DISPLAY_NOENT));
                }else{
                    gui_del_element(highlight_li,s_array[highlight_li-1]);
                    sys_gui_msg(pmsg(MSG_GUI_LIST_DEL));

                }
                choice_list = M_EXIT_L;
                break;
            default:
                show_keyinfo(28,5,c_list);
                break;
        }
        if(choice_list == M_EXIT_L){
            break;
        }else{
            choice_list = 0;
        }
        update_panels();
        doupdate();

    }
    switch_panels(ptype);
    keypad(menu_win_pre, TRUE);
    keypad(menu_win, FALSE);
}

void print_list_search(WINDOW *menu_win, int highlight2) // прорисовка меню поиска
{
	int x, y, i,max_x;
    getmaxyx(menu_win,y,max_x);
    int i_co_gui = 0;
    while(i_co_gui < y-2){
        cls_line(menu_win,5+i_co_gui,2,max_x-2);
        i_co_gui++;
    }
    wrefresh(menu_win);

	x = 2; // координаты сдвига от окна
	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, 2, (max_x-strlen(pmsg(MSG_GUI_SEARCH_PRE)))/2, pmsg(MSG_GUI_SEARCH_PRE));

    switch(short_lang_data){
        case 1 :

             for(i = 0; i < n_choices_search_rus; ++i)
            {	if(highlight2 == i + 1) /* High light the present choice */
                {	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
                    mvwprintw(menu_win, y, x, "%s", choices_search_rus[i]);
                    wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
                }
                else
                    mvwprintw(menu_win, y, x, "%s", choices_search_rus[i]);
                ++y;
            }

            mvwprintw(menu_win, 19, 2, "---------- Подсказки ----------");
            mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER  # выбор");
            mvwprintw(menu_win, 19 + 3, 2, "<-,ESC,F10 # выход");

            break;

        default:
            for(i = 0; i < n_choices_search; ++i)
            {	if(highlight2 == i + 1) /* High light the present choice */
                {	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
                    mvwprintw(menu_win, y, x, "%s", choices_search[i]);
                    wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
                }
                else
                    mvwprintw(menu_win, y, x, "%s", choices_search[i]);
                ++y;
            }

            mvwprintw(menu_win, 19, 2, "---------- FAST HELP ----------");
            mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER // menu selector");
            mvwprintw(menu_win, 19 + 3, 3, "<- or F10 //exit to pre menu");
            }

	wrefresh(menu_win);
}

void guiconf_M_SEARCH(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype){ // навигатор по методам поиска
    switch_panels(ptype);
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;
    while(1){
        int n_choices_list =  0;
        switch(short_lang_data){
            case 1 :
                n_choices_list = n_choices_search_rus;
                break;
            default :
                n_choices_list = n_choices_search;
        }

        print_list_search(menu_win, highlight_li);
        c_list = wgetch(menu_win);
        switch(c_list){
            case KEY_UP:
                if(highlight_li == 1)
                    highlight_li = n_choices_list;
                else
                    --highlight_li;
                break;
            case KEY_DOWN:
                if(highlight_li == n_choices_list)
                    highlight_li = 1;
                else
                    ++highlight_li;
                break;
            case 10:    /* привязки выбора */
            case KEY_RIGHT:
                choice_list = highlight_li;
                break;

            case KEY_F(10): /* Привязки выхода их SAVE */
            case KEY_LEFT:
            case 27:        /* ESC KEY */
            case 'l':        /* S KEY */
                choice_list = M_EXIT_L;
                break;
            default:
                show_keyinfo(28,5,c_list);
                break;
        }
        if(choice_list == M_EXIT_L){
            break;
        }else if(choice_list == 1){
            plsl_a(menu_win,0);
            choice_list = 0;
        }else if(choice_list == 2){
            plsl_a(menu_win,1);
            choice_list = 0;
        }else if(choice_list == 3){
            plsl_a(menu_win,2);
            choice_list = 0;
        }else if(choice_list == 4){
            plsl_a(menu_win,3);
            choice_list = 0;
        }else if(choice_list == 5){
            break;
        }else{
            choice_list = 0;
        }
        update_panels();
        doupdate();

    }
    switch_panels(ptype);
    keypad(menu_win_pre, TRUE);
    keypad(menu_win, FALSE);
}
