#include "gui_load.h"

char *choices_load[] = {
            "1. Quick load",
            "2. Load from file...",
            "3. Exit",
};

int n_choices_load = sizeof(choices_load) / sizeof(char *); // трюк плдучения количества записей
// загрузка файлов
void guiconf_M_LOAD(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype){
    switch_panels(ptype);
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;
    while(1){
        int n_choices_list = n_choices_load;
        print_list_load(menu_win, highlight_li);
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
            try_load(&default_list,"",sz_def_filename);
            mvwprintw(menu_win, 15, 2, "LOADED %s OK! PRESS ENTER!",sz_def_filename);wrefresh(menu_win);
            getch();clrstdin();
            choice_list = 0;
        }else if(choice_list == 2){
            if(menu_win == menu_wins[WIN_N_LIST]){
                guiconf_M_LOADLIST(menu_wins[WIN_N_SETT],menu_wins[WIN_N_LIST],WIN_N_SETT);
            }else{
                guiconf_M_LOADLIST(menu_wins[WIN_N_LIST],menu_wins[WIN_N_SETT],WIN_N_LIST);
            }

            choice_list = 0;
        }else if(choice_list == 3){
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

void print_list_load(WINDOW *menu_win, int highlight2)
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
	mvwprintw(menu_win, 2, (max_x-strlen("LOAD METHOD"))/2, "LOAD METHOD");

	for(i = 0; i < n_choices_load; ++i)
	{	if(highlight2 == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
			mvwprintw(menu_win, y, x, "%s", choices_load[i]);
			wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices_load[i]);
		++y;
	}

	mvwprintw(menu_win, 19, 2, "---------- FAST HELP ----------");
	mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER // menu selector");
	mvwprintw(menu_win, 19 + 3, 3, "<- or F10 //exit to pre menu");
	wrefresh(menu_win);
}
// с поддержкой браузера
void guiconf_M_LOADLIST(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype){
    switch_panels(ptype);
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;char sz_selected[1024] = {0};
    char sz_path[1024];
    strcpy(sz_path, _getcwd(sz_path, sizeof(sz_path)) ); // начать с текущей директории
    while(1){
        int n_choices_list = get_coffile(opendir (sz_path));

        if(strlen(sz_selected) != 0 ){
            int y,max_x;
            getmaxyx(menu_win,y,max_x);
            int i_co_gui = 0;
            while(i_co_gui < (y-2) ){
                cls_line(menu_win,2+i_co_gui,2,max_x-2);
                i_co_gui++;
            }
            wrefresh(menu_win);

            wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
            mvwprintw(menu_win, 2, (max_x-strlen("BROWSER"))/2, "BROWSER");

            mvwprintw(menu_win, 5, y-y+2, "SELECTED : '%s'!",sz_selected);wrefresh(menu_win);
            getch();clrstdin();
            mvwprintw(menu_win, 6, 2, "LOAD THIS FILE Y/N ?");wrefresh(menu_win);
            int ch4 = getch();
            if(ch4 == 'Y' || ch4 == 'y' || ch4 == '\n' ){
                mvwprintw(menu_win, 6, 2, "WANT TO ENTER PASSWORD Y/N ?");wrefresh(menu_win);
                int ch5 = getch();char PASSWD[254] = {0};strcpy(PASSWD,"");
                if(ch5 == 'Y' || ch5 == 'y' || ch5 == '\n' ){

                    mvwprintw(menu_win, 7, 2, "ENTER PASSWORD : ");wrefresh(menu_win);
                    mvwprintw(menu_win, 8, 2, "->");
                    wrefresh(menu_win);
                    echo();
                    mvwscanw(menu_win,8,4,"%127[^\n]s",PASSWD) ;clrstdin();
                    wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);;wrefresh(menu_win); /* fix borders */
                    noecho();
                }
                mvwprintw(menu_win, 9, 2, "OK . LOADING...");wrefresh(menu_win);
                if(try_load(&default_list,PASSWD,sz_selected) == 2){
                    mvwprintw(menu_win, 12, 2, "ERR LOADING :( PRESS ANY KEY");wrefresh(menu_win);
                }else{
                    mvwprintw(menu_win, 12, 2, "SUCCESS! PRESS ANY KEY");wrefresh(menu_win);
                }

                getch();clrstdin();
            }
            strcpy(sz_selected,"");
            continue;
        }

        print_list_loadlist(menu_win, highlight_li,n_choices_list);
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
        }
        if(choice_list > 1){
            char sz_tpath[1024];sprintf(sz_tpath,"./%s",get_fnbynum(choice_list-1) );

            if( strcmp("..",get_fnbynum(choice_list-1) ) == 0 ) {
                chdir("..");
                _getcwd(sz_path, sizeof(sz_path));
                choice_list = 0;
                continue;
            }else if( chdir(sz_tpath) == 0 ){
                _getcwd(sz_path, sizeof(sz_path));
                choice_list = 0;
                continue;
            }else{
                strcpy(sz_selected,get_fnbynum(choice_list-1));
            }
            choice_list = 0;

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

void print_list_loadlist(WINDOW *menu_win, int highlight2,int n_browserlist)
{
	int x, y, i,max_x;
    getmaxyx(menu_win,y,max_x);
    int i_co_gui = 0;
    while(i_co_gui < (y-2) ){
        cls_line(menu_win,4+i_co_gui,2,max_x-2);
        i_co_gui++;
    }
    wrefresh(menu_win);

	x = 2; // координаты сдвига от окна
	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, 2, (max_x-strlen("BROWSER"))/2, "BROWSER");

    DIR *dp;
    dp = opendir ("./");
    if (dp != NULL)
    {
            int i_counter = 0;
            struct dirent * ept;
            highlight2 = highlight2-1;
            while(i_counter < highlight2){
                i_counter++;
                ept = readdir(dp);
            }
            for(i = 0; i < 13; ++i){
                if(i < n_browserlist-highlight2){
                    ept = readdir(dp);
                    if(highlight2 == i + highlight2) /* High light the present choice */
                    {
                        wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
                        mvwprintw(menu_win, y, x, "%s", ept->d_name);
                        wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
                    }
                    else
                        mvwprintw(menu_win, y, x, "%s", ept->d_name);
                        ++y;
                }else{
                    break;
                }

            }
    }

    (void) closedir (dp);
    //



	mvwprintw(menu_win, 19, 2, "---------- FAST HELP ----------");
	mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER // menu selector");
	mvwprintw(menu_win, 19 + 3, 2, "<-,ESC,F10,l //exit to pre menu");
	mvwprintw(menu_win, 19 + 4, 3, "UP DOWN //navigation buttons");
	wrefresh(menu_win);
}
