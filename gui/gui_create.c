#include "gui_create.h"
// макрофункция создания элемента
void gui_cr_element(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype){
	int x, y;
    getmaxyx(menu_win,y,x);
    int i_co_gui = 0;

    while(i_co_gui < (y-2) ){
        cls_line(menu_win,2+i_co_gui,2,x-2);
        i_co_gui++;
    }
    wrefresh(menu_win);


	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    while(1){
        //refresh screen

        gui_cr_rscr(menu_win);

        int c_list,choice_list = 0;
        if(menu_wins[WIN_N_LIST] == menu_win_pre){
            print_list(menu_win_pre, 1,get_countofrec(default_list),0,WIN_N_LIST); // test
            wrefresh(menu_win_pre);
        }else{
            print_list(menu_win_pre, 1,get_countofrec(default_list),0,WIN_N_SETT);
        }
        c_list = wgetch(menu_win);
        switch(c_list){
            case KEY_LEFT:
                choice_list = M_EXIT_C;
                break;
            case KEY_BACKSPACE:
                choice_list = M_EXIT_C;
                break;
            default:
                show_keyinfo(28,5,c_list);
                break;
        }
        if(choice_list == -1){
            int i_co_gui = 0;
            while(i_co_gui < (y-2) ){
                cls_line(menu_win,2+i_co_gui,2,x-2);
                i_co_gui++;
            }

            ;wrefresh(menu_win);

            break;
        }
        mvwprintw(menu_win, y-y+6, 2, pmsg(MSG_GUI_CREATE_MSG1));
        mvwprintw(menu_win, 7, 2, "->");

        char sz_name[32] = {0},sz_fullname[254] = {0},sz_model[254] = {0},sz_brand[254] = {0};
        echo();
        gui_dynamic_buffer(menu_win,7,4,"",sz_name,sizeof(sz_name)-1 );
        noecho();
        wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */

        mvwprintw(menu_win, 7, 4, "%s",sz_name);wrefresh(menu_win);

        clrstdin();
        if(strlen(sz_name) == 0){
            mvwprintw(menu_win, 22, (x-strlen(pmsg(MSG_GUI_CREATE_CANS)))/2 , pmsg(MSG_GUI_CREATE_CANS));
            wrefresh(menu_win);getch();clrstdin();
            continue;
        }
        mvwprintw(menu_win, 8, 2, pmsg(MSG_GUI_CREATE_EFN));
        mvwprintw(menu_win, 9, 2, "->");
        echo();
        gui_dynamic_buffer(menu_win,9,4,"",sz_fullname,sizeof(sz_fullname)-1 );
        noecho();
        wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
        mvwprintw(menu_win, 9, 4, "%s",sz_fullname);wrefresh(menu_win);
        clrstdin();
        if(strlen(sz_fullname) == 0){
            mvwprintw(menu_win, 22, (x-strlen(pmsg(MSG_GUI_CREATE_CANS)))/2 , pmsg(MSG_GUI_CREATE_CANS));
            wrefresh(menu_win);getch();clrstdin();
            continue;
        }
        mvwprintw(menu_win, 10, 2, pmsg(MSG_GUI_CREATE_EM));
        mvwprintw(menu_win, 11, 2, "->");
        echo();
        gui_dynamic_buffer(menu_win,11,4,"",sz_model,sizeof(sz_model)-1 );
        noecho();
        wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
        mvwprintw(menu_win, 11, 4, "%s",sz_model);wrefresh(menu_win);
        clrstdin();
        if(strlen(sz_model) == 0){
            mvwprintw(menu_win, 22, (x-strlen(pmsg(MSG_GUI_CREATE_CANS)))/2 , pmsg(MSG_GUI_CREATE_CANS));
            wrefresh(menu_win);getch();clrstdin();
            continue;
        }
        mvwprintw(menu_win, 12, 2, pmsg(MSG_GUI_CREATE_EB));
        mvwprintw(menu_win, 13, 2, "->");
        echo();
        gui_dynamic_buffer(menu_win,13,4,"",sz_brand,sizeof(sz_brand)-1 );
        noecho();
        wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
        mvwprintw(menu_win, 13, 4, "%s",sz_brand);wrefresh(menu_win);
        clrstdin();
        if(strlen(sz_brand) == 0){
            mvwprintw(menu_win, 22, (x-strlen(pmsg(MSG_GUI_CREATE_CANS)))/2 , pmsg(MSG_GUI_CREATE_CANS));
            wrefresh(menu_win);getch();clrstdin();
            continue;
        }
        mvwprintw(menu_win, 15, (x-strlen(pmsg(MSG_GUI_CREATE_MSG2)))/2, pmsg(MSG_GUI_CREATE_MSG2) );
        mvwprintw(menu_win, 17, 4, "%s ; %s",sz_name,sz_fullname);
        mvwprintw(menu_win, 18, 4, "%s ; %s",sz_model,sz_brand);
        mvwprintw(menu_win, 20, (x-strlen(pmsg(MSG_GUI_CREATE_MSG3)))/2, pmsg(MSG_GUI_CREATE_MSG3) );
        wrefresh(menu_win);
        int ynchar = getch();clrstdin();
        noecho();
        wrefresh(menu_win);
        if( (ynchar == 'Y') || (ynchar == 'y') || (ynchar == '\n' ) ) {
                create(sz_name,&default_list,sz_fullname,sz_brand,sz_model);
                mvwprintw(menu_win, 22, (x-strlen(pmsg(MSG_GUI_CREATE_OK)))/2  , pmsg(MSG_GUI_CREATE_OK));
                wrefresh(menu_win);
        }else if(ynchar == 'n' || (ynchar == 'N')){
                mvwprintw(menu_win, 22, (x-strlen(pmsg(MSG_GUI_CREATE_CANS)))/2 , pmsg(MSG_GUI_CREATE_CANS));
                wrefresh(menu_win);
        }
        getch();clrstdin();
        //rule choice
        choice_list = 0;
        update_panels();
        doupdate();

    }

    keypad(menu_win_pre, TRUE); // включить клавиатуру для предыдущего окна
    keypad(menu_win, FALSE); // выключить клавиатуру для текущего окна
	update_panels();
	doupdate();
	wrefresh(menu_win);
}
// заголовок
void gui_cr_rscr(WINDOW *menu_win){
    werase(menu_win);
    wrefresh(menu_win);
	int x, y;
    getmaxyx(menu_win,y,x);
	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, y - y + 2, (x-strlen(pmsg(MSG_GUI_CREATE_MSG4)))/2, pmsg(MSG_GUI_CREATE_MSG4));
	mvwprintw(menu_win, 3, (x-strlen(pmsg(MSG_GUI_CREATE_MSG5)))/2, pmsg(MSG_GUI_CREATE_MSG5));
	mvwprintw(menu_win, 4, (x-strlen(pmsg(MSG_GUI_CREATE_MSG6)))/2, pmsg(MSG_GUI_CREATE_MSG6));
	wrefresh(menu_win);
}
