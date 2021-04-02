#include "gui_sort.h"
char *choices_sort[] = {
			"1. Sort by VIN",
			"2. Sort by VIN desc",
			"3. Sort by Full Name",
			"4. Sort by Full desc",
			"5. Sort by Brand",
			"6. Sort by Brand desc",
			"7. Sort by Model",
			"8. Sort by Model desc",
			"9. Exit",
};
int n_choices_sort = sizeof(choices_sort) / sizeof(char *); // трюк плдучения количества записей

char *choices_sort_rus[] = {
			"1. Сортировать по VIN",
			"2. Сортировать по VIN убыв",
			"3. Сортировать по ФИО",
			"4. Сортировать по ФИО",
			"5. Сортировать по Бренд",
			"6. Сортировать по Бренд убыв",
			"7. Сортировать по Модель",
			"8. Сортировать по Модель убыв",
			"9. Выход",
};
int n_choices_sort_rus = sizeof(choices_sort_rus) / sizeof(char *); // трюк плдучения количества записей

void guiconf_M_SORT(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype){ // функция вывода методов сортировки
    switch_panels(ptype); //включить панель LIST
    int is_sorted_s = 0;
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;
    while(1){
        int n_choices_list = 0;
        switch(short_lang_data){
            case 1 :
                n_choices_list = n_choices_sort_rus;
            default :
                n_choices_list = n_choices_sort;

        }
        print_list_sort(menu_win, highlight_li);
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
            case 10:
                choice_list = highlight_li;
                break;
            case KEY_F(10):
                choice_list = M_EXIT_L;
                break;
            case KEY_LEFT:
                choice_list = M_EXIT_L;
                break;
            default:
                show_keyinfo(28,5,c_list);
                break;
        }
        //rule choice
        if(choice_list == M_EXIT_L){
            break;
        }else if(choice_list == 1){
            try_sort(&default_list,"VIN","0");is_sorted_s = 1;
        }else if(choice_list == 2){
            try_sort(&default_list,"VIN","1");
        }else if(choice_list == 3){
            try_sort(&default_list,"Fullname","0");
        }else if(choice_list == 4){
            try_sort(&default_list,"Fullname","1");
        }else if(choice_list == 5){
            try_sort(&default_list,"Brand","0");
        }else if(choice_list == 6){
            try_sort(&default_list,"Brand","1");
        }else if(choice_list == 7){
            try_sort(&default_list,"Model","0");
        }else if(choice_list == 8){
            try_sort(&default_list,"Model","1");
        }else if(choice_list == 9){
            break;
        }else{
            choice_list = 0;
        }
        if(is_sorted_s){
            sys_gui_msg(pmsg(MSG_SORT_OK));
        }
    }
    switch_panels(ptype);
    keypad(menu_win_pre, TRUE);
    keypad(menu_win, FALSE);
}

void print_list_sort(WINDOW *menu_win, int highlight2) // прорисовка меню сортировки
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
	mvwprintw(menu_win, 2, (max_x-strlen(pmsg(MSG_SORT_MSG)))/2, pmsg(MSG_SORT_MSG));

	for(i = 0; i < n_choices_sort; ++i)
	{	if(highlight2 == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
            switch(short_lang_data){
                case 1:
                    mvwprintw(menu_win, y, x, "%s", choices_sort_rus[i]);
                    break;
                default:
                    mvwprintw(menu_win, y, x, "%s", choices_sort[i]);
                }
			wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
		}
		else
            switch(short_lang_data){
                case 1:
                    mvwprintw(menu_win, y, x, "%s", choices_sort_rus[i]);
                    break;
                default:
                    mvwprintw(menu_win, y, x, "%s", choices_sort[i]);
                }
		++y;
	}

	switch(short_lang_data){
        case 1 :
            mvwprintw(menu_win, 19, 2, "---------- Подсказки ----------");
            mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER  # выбор");
            mvwprintw(menu_win, 19 + 3, 2, "<-,ESC,F10 # выход");
            break;
        default :
            mvwprintw(menu_win, 19, 2, "---------- FAST HELP ----------");
            mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER // menu selector");
            mvwprintw(menu_win, 19 + 3, 3, "<- or F10 //exit to pre menu");
	}

	wrefresh(menu_win);
}
