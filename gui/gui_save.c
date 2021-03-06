#include "gui_save.h"

char *choices_save[] = {
			"1. Quick save",
			"2. Custom , without encrypt",
			"2. Custom , with encrypt",
			"9. Exit",
};

int n_choices_save = sizeof(choices_save) / sizeof(char *); // ???? ????????? ?????????? ???????

char *choices_save_rus[] = {
			"1. ??????? ??????????",
			"2. ????????? ???, ??? ????.",
			"2. ????????? ??? , ? ????.",
			"9. ?????",
};

int n_choices_save_rus = sizeof(choices_save_rus) / sizeof(char *); // ???? ????????? ?????????? ???????

void guiconf_M_SAVE(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype){ // ??????? ??????????? ???????????? ?????? ??????????
    switch_panels(ptype);
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;
    while(1){
        int n_choices_list = 0;
        switch(short_lang_data){
            case 1 :
                n_choices_list = n_choices_save_rus;
                break;
            default :
                n_choices_list = n_choices_save;
        }

        print_list_save(menu_win, highlight_li);
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
            case 10:    /* ???????? ?????? */
            case KEY_RIGHT:
                choice_list = highlight_li;
                break;

            case KEY_F(10): /* ???????? ?????? ?? SAVE */
            case KEY_LEFT:
            case 27:        /* ESC KEY */
            case 's':        /* S KEY */
                choice_list = M_EXIT_L;
                break;
            default:
                show_keyinfo(28,5,c_list);
                break;
        }
        if(choice_list == M_EXIT_L){
            break;
        }else if(choice_list == 1){

            if(get_countofrec(default_list) != 0){
                try_save(default_list,"",sz_def_filename,0);
                mvwprintw(menu_win, 17, 2, pmsg(MSG_GUI_SAVE_MSG1),sz_def_filename);
                wrefresh(menu_win);
            }else{
                mvwprintw(menu_win, 17, 2, pmsg(MSG_GUI_SAVE_MSG2));
                wrefresh(menu_win);
            }
            getch();clrstdin();choice_list = 0;
        }else if(choice_list == 2){
            int y_pos = 10;char NF[128] = {0};
            mvwprintw(menu_win, y_pos, 2, pmsg(MSG_GUI_SAVE_MSG3));wrefresh(menu_win);
            mvwprintw(menu_win, y_pos+2, 2, "->");
            wrefresh(menu_win);
            echo();
            gui_dynamic_buffer(menu_win,y_pos+2,4,sz_def_filename,NF,sizeof(NF)-1 );
            noecho();
            wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
            if(strlen(NF) == 0){
                mvwprintw(menu_win, y_pos+7, 2, pmsg(MSG_GUI_SAVE_MSG4));wrefresh(menu_win);
                getch();clrstdin();choice_list = 0;
                continue;
            }

            mvwprintw(menu_win, y_pos+2,4, "%s",NF) ;wrefresh(menu_win);
            mvwprintw(menu_win, y_pos+4,3, pmsg(MSG_GUI_SAVE_MSG5));wrefresh(menu_win);
            mvwprintw(menu_win, y_pos+5,3, pmsg(MSG_GUI_SAVE_MSG6),NF);wrefresh(menu_win);
            int ch4 = getch();
            if(ch4 == 'Y' || ch4 == 'y' || ch4 == '\n' ){
                strcpy(sz_def_filename,NF);
                try_save(default_list,"",sz_def_filename,0);
                mvwprintw(menu_win, y_pos+7, 2, pmsg(MSG_GUI_SAVE_MSG7),sz_def_filename);wrefresh(menu_win);
                getch();clrstdin();
            }else{
                mvwprintw(menu_win, y_pos+7, 2, pmsg(MSG_GUI_CREATE_CANS));wrefresh(menu_win);
            }
            choice_list = 0;
        }else if(choice_list == 3){
            int y_pos = 10;char NF[128] = {0},NK[128] = {0};
            mvwprintw(menu_win, y_pos, 2, pmsg(MSG_GUI_SAVE_MSG8));wrefresh(menu_win);
            mvwprintw(menu_win, y_pos+2, 2, "->");
            wrefresh(menu_win);
            echo();
            gui_dynamic_buffer(menu_win,y_pos+2,4,sz_def_filename,NF,sizeof(NF)-1 );
            noecho();
            wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
            if(strlen(NF) == 0){
                mvwprintw(menu_win, y_pos+7, 2, pmsg(MSG_GUI_SAVE_MSG4));wrefresh(menu_win);
                getch();clrstdin();choice_list = 0;
                continue;

            }

            mvwprintw(menu_win, y_pos+2,4, "%s",NF) ;wrefresh(menu_win);
            mvwprintw(menu_win, y_pos+4,3, pmsg(MSG_GUI_SAVE_MSG5));wrefresh(menu_win);
            mvwprintw(menu_win, y_pos+5,3, pmsg(MSG_GUI_SAVE_MSG6),NF);wrefresh(menu_win);
            int ch4 = getch();
            if(ch4 == 'Y' || ch4 == 'y' || ch4 == '\n' ){
                mvwprintw(menu_win, y_pos+6, 2, pmsg(MSG_GUI_SAVE_EP));wrefresh(menu_win);
                mvwprintw(menu_win, y_pos+7, 2, "->");
                wrefresh(menu_win);
                mvwscanw(menu_win,y_pos+8,4,"%127[^\n]s",NK) ;clrstdin();
                wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
                if(strlen(NF) == 0){
                    mvwprintw(menu_win, y_pos+7, 2, pmsg(MSG_GUI_SAVE_MSG4));wrefresh(menu_win);
                    getch();clrstdin();
                    continue;
                }
                mvwprintw(menu_win, y_pos+8,3, pmsg(MSG_GUI_SAVE_SA));wrefresh(menu_win);
                int ch5 = getch();
                if(ch5 == 'Y' || ch5 == 'y' || ch5 == '\n' ){
                    strcpy(sz_def_filename,NF);
                    if(strlen(NK) != 0){
                        try_save(default_list,NK,sz_def_filename,1);
                        mvwprintw(menu_win, y_pos+8, 2, pmsg(MSG_GUI_SAVE_MSG7),sz_def_filename);wrefresh(menu_win);
                    }else{
                        mvwprintw(menu_win, y_pos+8, 2, pmsg(MSG_GUI_SAVE_MSG4),sz_def_filename);wrefresh(menu_win);
                    }


                    getch();clrstdin();
                }
            }else{
                mvwprintw(menu_win, y_pos+8, 2, pmsg(MSG_GUI_SAVE_MSG4));wrefresh(menu_win);
            }
            choice_list = 0;
        }else if(choice_list == 4){
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

void print_list_save(WINDOW *menu_win, int highlight2) // ?????????? ???? ??????????
{
	int x, y, i,max_x;
    getmaxyx(menu_win,y,max_x);
    int i_co_gui = 0;
    while(i_co_gui < y-1){
        cls_line(menu_win,5+i_co_gui,0,max_x-1);
        i_co_gui++;
    }
    wrefresh(menu_win);

	x = 2; // ?????????? ?????? ?? ????
	y = WIN_N_LIST_MAX/2; // ?????????? ?????? ?? ????
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, 2, (max_x-strlen(pmsg(MSG_GUI_SAVE_SAA)))/2, pmsg(MSG_GUI_SAVE_SAA));

	for(i = 0; i < n_choices_save; ++i)
	{	if(highlight2 == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
            switch(short_lang_data){
                case 1 :
                    mvwprintw(menu_win, y, x, "%s", choices_save_rus[i]);
                    break;
                default :
                    mvwprintw(menu_win, y, x, "%s", choices_save[i]);
            }

			wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));
		}
		else
            switch(short_lang_data){
                case 1 :
                    mvwprintw(menu_win, y, x, "%s", choices_save_rus[i]);
                    break;
                default :
                    mvwprintw(menu_win, y, x, "%s", choices_save[i]);
            }
		++y;
	}
    switch(short_lang_data){
        case 1 :
            mvwprintw(menu_win, 19, 2, "---------- ????????? ----------");
            mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER  # ?????");
            mvwprintw(menu_win, 19 + 3, 2, "<-,ESC,F10 # ?????");
            break;
        default:
            mvwprintw(menu_win, 19, 2, "---------- FAST HELP ----------");
            mvwprintw(menu_win, 19 + 2, 3, "-> or ENTER // menu selector");
            mvwprintw(menu_win, 19 + 3, 3, "<- or F10 //exit to pre menu");
    }
	wrefresh(menu_win);
}

void sys_quick_save(){ // ??????? ???????? ?????????? ?????????? ????? / ??????????
    char sz_msg[512];
    sprintf(sz_msg,pmsg(MSG_GUI_SAVE_MSG9),sz_def_filename );
    sys_gui_msg(sz_msg);
    try_save(default_list,"",sz_def_filename,0); // ???????? ??????????
}
