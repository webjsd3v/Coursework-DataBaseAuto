#include "gui_edit.h"
// функция - окно , для редактирования записи в графическом меню
void gui_e_element( int highlight,WINDOW *menu_win,WINDOW *menu_win_pre, struct list_box * t_str ){

    werase(menu_win);
    wrefresh(menu_win);
    if(get_countofrec(default_list) == 0){
        sys_gui_msg( pmsg(MSG_CMD_DISPLAY_NOENT) );
        return;
    }
	int x, y;
    getmaxyx(menu_win,y,x);
	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
    keypad(menu_win_pre, FALSE);
    keypad(menu_win, TRUE);
    while(1){
        //refresh screen
        gui_e_rscr(menu_win);

        int c_list,choice_list = 0;
        if(t_str == NULL)print_list(menu_win_pre, 1,get_countofrec(default_list),0,WIN_N_LIST);
        c_list = wgetch(menu_win);
        switch(c_list){
            case KEY_F(10): /* Привязки выхода их SAVE */
            case KEY_LEFT:
            case 27:        /* ESC KEY */
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
            werase(menu_win);wrefresh(menu_win);
            break;
        }
        struct list_box * s_etemp = default_list;
        if(t_str == NULL){
            int i_count_l = 1;
            while(i_count_l != highlight ){
            if(s_etemp->next != NULL){
                s_etemp = s_etemp->next;
            }
                i_count_l++;
            }
        }else{
            s_etemp = t_str;
        }


        char sz_fullname[254] = {0},sz_model[254] = {0},sz_brand[254] = {0};
        mvwprintw(menu_win, y-y+6, (x-strlen(pmsg(MSG_GUI_EDIT_EFN)))/2, pmsg(MSG_GUI_EDIT_EFN));
        mvwprintw(menu_win, 7, 2, "'%s'",s_etemp->Fullname);
        wrefresh(menu_win);
        int ch1 = 0,ch2 = 0,ch3 = 0;
        noecho();
        ch1 = getch();
        wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
        if(ch1 == 27 || ch1 == KEY_F(10)) break;
        if(ch1 == 'Y' || ch1 == 'y' || ch1 == '\n' ){
            clrstdin();
            mvwprintw(menu_win, 8, 2, pmsg(MSG_GUI_EDIT_NFN));wrefresh(menu_win);
            gui_dynamic_buffer(menu_win,8,strlen(pmsg(MSG_GUI_EDIT_NFN) )+2,s_etemp->Fullname,sz_fullname,sizeof(sz_fullname)-1 );

            wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
            mvwprintw(menu_win, 8, strlen(pmsg(MSG_GUI_EDIT_NFN))+2, "%s",sz_fullname);wrefresh(menu_win);
            if(strlen(sz_fullname) != 0){
                edit_struct(&default_list,0,sz_fullname,"by","Fullname",s_etemp->Fullname);
                mvwprintw(menu_win, 22, 4  , pmsg(MSG_GUI_EDIT_MSG1),sz_fullname);
                wrefresh(menu_win);
            }

        }clrstdin();
        mvwprintw(menu_win, 9, (x-strlen(pmsg(MSG_GUI_EDIT_EM)))/2, pmsg(MSG_GUI_EDIT_EM));
        mvwprintw(menu_win, 10, 2, "'%s'",s_etemp->Model);
        wrefresh(menu_win);
        ch2 = getch();
        if(ch2 == 27 || ch2 == KEY_F(10)) break;
        if(ch2 == 'Y' || ch2 == 'y' || ch2 == '\n' ){
            clrstdin();
            mvwprintw(menu_win, 11, 2, pmsg(MSG_GUI_EDIT_NM));wrefresh(menu_win);
            gui_dynamic_buffer(menu_win,11,strlen(pmsg(MSG_GUI_EDIT_NM) )+2,s_etemp->Model,sz_model,sizeof(sz_model)-1 );

            wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
            mvwprintw(menu_win, 11, strlen(pmsg(MSG_GUI_EDIT_NM) )+2, "%s",sz_model);wrefresh(menu_win);
            if(strlen(sz_model) != 0){
                edit_struct(&default_list,2,sz_model,"by","Model",s_etemp->Model);
                mvwprintw(menu_win, 22, 4  , pmsg(MSG_GUI_EDIT_MSG1),sz_model);
                wrefresh(menu_win);
            }

        }clrstdin();
        mvwprintw(menu_win, 12, (x-strlen(pmsg(MSG_GUI_EDIT_NBB)))/2, pmsg(MSG_GUI_EDIT_NBB));
        mvwprintw(menu_win, 13, 2, "'%s'",s_etemp->Brand);
        wrefresh(menu_win);
        ch3 = getch();
        if(ch3 == 27 || ch3 == KEY_F(10)) break;
        if(ch3 == 'Y' || ch3 == 'y' || ch3 == '\n' ){

            clrstdin();
            mvwprintw(menu_win, 14, 2, pmsg(MSG_GUI_EDIT_NB));wrefresh(menu_win);
            gui_dynamic_buffer(menu_win,14,strlen(pmsg(MSG_GUI_EDIT_NB) )+2,s_etemp->Brand,sz_brand,sizeof(sz_brand)-1 );
            wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);wrefresh(menu_win); /* fix borders */
            mvwprintw(menu_win, 14, strlen(pmsg(MSG_GUI_EDIT_NB) )+2, "%s",sz_brand);wrefresh(menu_win);
            if(strlen(sz_brand) != 0){
                edit_struct(&default_list,1,sz_brand,"by","Brand",s_etemp->Brand);
                mvwprintw(menu_win, 22, 4  , pmsg(MSG_GUI_EDIT_MSG1),sz_brand);
                wrefresh(menu_win);
            }


        }clrstdin();
        getch();clrstdin();
        //rule choice
        choice_list = 0;
    }
    keypad(menu_win_pre, TRUE);
    keypad(menu_win, FALSE);
	update_panels();
	doupdate();
	wrefresh(menu_win);
}

void gui_e_rscr(WINDOW *menu_win){ // заголовок , который будет отображаться в окне EDIT
    int x, y;
    getmaxyx(menu_win,y,x);
    int i_co_gui = 0;
    while(i_co_gui < y){ // очистка конкретной области окна
        cls_line(menu_win,1+i_co_gui,2,x);
        i_co_gui++;
    }
    wrefresh(menu_win);

	y = WIN_N_LIST_MAX/2; // координаты сдвига от окна
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, y - y + 2, (x-strlen(pmsg(MSG_GUI_EDIT_EE)))/2, pmsg(MSG_GUI_EDIT_EE));
	mvwprintw(menu_win, 3, (x-strlen(pmsg(MSG_GUI_CREATE_MSG5)))/2, pmsg(MSG_GUI_CREATE_MSG5));
	mvwprintw(menu_win, 4, (x-strlen(pmsg(MSG_GUI_CREATE_MSG6)))/2, pmsg(MSG_GUI_CREATE_MSG6));
	wrefresh(menu_win);
}
