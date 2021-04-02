#include "gui_list.h"

void guiconf_M_LIST(){ // ���� ������
    switch_panels(WIN_N_LIST); // �������� ���� ������
    switch_panels(WIN_N_SETT); // �������� ������ ������������
    keypad(menu_wins[WIN_N_MAIN], FALSE);
    keypad(menu_wins[WIN_N_LIST], TRUE);
    int choice_list = 0,highlight_li = 1;int c_list = 0;
    while(1){
        int n_choices_list  = get_countofrec(default_list),if_deleted = 0;
        print_list(menu_wins[WIN_N_LIST], highlight_li,n_choices_list,1,WIN_N_LIST);
        c_list = wgetch(menu_wins[WIN_N_LIST]);

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
            case KEY_F(6):
            case 'c':
                choice_list = M_CREATE_L;
                gui_cr_element(menu_wins[WIN_N_SETT],menu_wins[WIN_N_LIST],WIN_N_SETT);
                break;
            case KEY_F(7):
            case 'e':
                choice_list = M_CREATE_L;

                gui_e_element(highlight_li,menu_wins[WIN_N_SETT],menu_wins[WIN_N_LIST],NULL); // ��������� ������ �������������� ��������
                break;
            case 83 : // ^s  ��������� ���
                guiconf_M_SAVE(menu_wins[WIN_N_SETT],menu_wins[WIN_N_LIST],WIN_N_SETT); // ������� ���������� ���
                break;
            case 's' : // ^s  ��������� ���
                sys_quick_save(); // ������� ���������� ���������� �����
                break;
            case 'l':
                guiconf_M_LOAD(menu_wins[WIN_N_SETT],menu_wins[WIN_N_LIST],WIN_N_SETT);
                break;
            case KEY_F(10): /* �������� ������ �� SAVE */
            case KEY_LEFT:
            case 27:        /* ESC KEY */
                choice_list = M_EXIT_L;
                break;
            case 330:
            case KEY_F(8):

                if(get_countofrec(default_list) == 0){
                    sys_gui_msg(pmsg(MSG_CMD_DISPLAY_NOENT));
                }else{
                    gui_del_element(highlight_li,NULL);
                    sys_gui_msg(pmsg(MSG_GUI_LIST_DEL));
                    if_deleted = 1;
                }

                break;
            default:
                show_keyinfo(28,5,c_list);
                break;
        }
        if(if_deleted == 0){
            print_list(menu_wins[WIN_N_LIST], highlight_li,get_countofrec(default_list),1,WIN_N_LIST);
        }else{
            if(get_countofrec(default_list)+1 == highlight_li){
                --highlight_li;
            }
            print_list(menu_wins[WIN_N_LIST], highlight_li,get_countofrec(default_list),1,WIN_N_LIST);
        }

        //rule choice
        if(choice_list == M_EXIT_L){
            break;
        }
        else choice_list = 0;
    }
    switch_panels(WIN_N_LIST); // ����. ���� ������
    switch_panels(WIN_N_SETT); // ���� ������ ������������
    keypad(menu_wins[WIN_N_MAIN], TRUE);
    keypad(menu_wins[WIN_N_LIST], FALSE);
}

void gui_list_view(struct list_box * s_lbt){ // ���� , ������� ���������� ������ ���������� � ���������� VIN
    char FN[100] = {0},SN[100] = {0},N1[100] = {0};
    int i_co_gui = 0,x, y;
    getmaxyx(menu_wins[WIN_N_SETT],y,x);

    while(i_co_gui < (y-2) ){
        cls_line(menu_wins[WIN_N_SETT],2+i_co_gui,2,x-2);
        i_co_gui++;
    }
    wrefresh(menu_wins[WIN_N_SETT]);
	y = WIN_N_LIST_MAX/2;
	wborder(menu_wins[WIN_N_SETT],WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_wins[WIN_N_SETT], y - y + 2, (x-strlen(pmsg(MSG_GUI_LISTINFO_MSG1)))/2, pmsg(MSG_GUI_LISTINFO_MSG1));
    mvwprintw(menu_wins[WIN_N_SETT], y - y + 5, 2, "VIN   : %s",s_lbt->VIN);
    sscanf(s_lbt->Fullname,"%99s %99s %99s",FN,SN,N1);
    mvwprintw(menu_wins[WIN_N_SETT], y - y + 6, 2, pmsg(MSG_GUI_LISTINFO_NAME),FN);
    mvwprintw(menu_wins[WIN_N_SETT], y - y + 7, 2, pmsg(MSG_GUI_LISTINFO_SUR),SN);
    mvwprintw(menu_wins[WIN_N_SETT], y - y + 8, 2, pmsg(MSG_GUI_LISTINFO_NAME2),N1);
    mvwprintw(menu_wins[WIN_N_SETT], y - y + 9, 2, pmsg(MSG_GUI_LISTINFO_BRA),s_lbt->Brand);
    mvwprintw(menu_wins[WIN_N_SETT], y - y + 10, 2,pmsg(MSG_GUI_LISTINFO_MOD),s_lbt->Model);
	wrefresh(menu_wins[WIN_N_SETT]);
}

void print_list(WINDOW *menu_win, int highlight2,int n_choices_list,int enable_list,int ptype) // ���������� ������
{
    int x, y, i;
    getmaxyx(menu_win,y,x);
    int i_co_gui = 0;
    while(i_co_gui < y){
        cls_line(menu_win,1+i_co_gui,1,x-1);
        i_co_gui++;
    }
    switch(short_lang_data){
        case 1 :
            mvwprintw(menu_win, 15, 2, "---------- ��������� ----------");
            mvwprintw(menu_win, 15 + 1, 2, "l,          # ������� ����. ");
            mvwprintw(menu_win, 15 + 2, 2, "l + SHIFT   # �������� �� �. ");
            mvwprintw(menu_win, 15 + 3, 2, "<-,F10,ESC  # ����� � ����. �.");
            mvwprintw(menu_win, 15 + 4, 2, "C ��� F6    # ������� ������");
            mvwprintw(menu_win, 15 + 5, 2, "E ��� F7    # �������������");
            mvwprintw(menu_win, 15 + 6, 2, "DEL ��� F8  # ������� ������");
            mvwprintw(menu_win, 15 + 7, 2, "s           # ������� ����. ");
            mvwprintw(menu_win, 15 + 8, 2, "S+SHIFT     # ��������� ��� ");
            wrefresh(menu_win);
            break;
        default :
            mvwprintw(menu_win, 15, 2, "------- Tips and Tricks -------");
            mvwprintw(menu_win, 15 + 2, 2, "l           # load new db  ");
            mvwprintw(menu_win, 15 + 3, 2, "<-,F10,ESC  # exit to pre menu");
            mvwprintw(menu_win, 15 + 4, 2, "C or F6     # create new note");
            mvwprintw(menu_win, 15 + 5, 2, "E or F7     # edit note");
            mvwprintw(menu_win, 15 + 6, 2, "DEL or F8   # remove note");
            mvwprintw(menu_win, 15 + 7, 2, "s           # quick save      ");
            mvwprintw(menu_win, 15 + 8, 2, "S+SHIFT     # save as...      ");
            wrefresh(menu_win);
    }

    wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
    wrefresh(menu_win);
    /* �������� , ��������� �� ���� , ���� �� , �� ���. */
    if( ((PANEL_DATA *)panel_userptr(menu_panels[WIN_N_LIST]))->hide == TRUE ){
            switch_panels(ptype);
    }
    int x1 = x;
	x = 2; // ���������� ������ �� ����

	y = (WIN_N_LIST_MAX/2)-1; // ���������� ������ �� ����
	mvwprintw(menu_win, 2, (x1-strlen(pmsg(MSG_GUI_LISTINFO_LI)))/2, pmsg(MSG_GUI_LISTINFO_LI));
	int i_position = highlight2-1,i_lastel = 0,i_lastel2 = 0;
    if(default_list == NULL){
        return; // terminate print FIX BUG
    }
	struct list_box * t_last = default_list;
    while(t_last != NULL){
        t_last = t_last->next;
        i_lastel2++;
        if(highlight2 <= i_lastel2){
            i_lastel++;
        }
    }

	for(i = 0; i < WIN_N_LIST_MAX; ++i){
        struct list_box * tt = default_list;
        int i_count_l = 0;


        while(i_position != i_count_l){
            if(tt->next != NULL){
                tt=tt->next;
            }
            i_count_l++;
        }
        if( i >= i_lastel ) continue;

        i_position++;
        if(highlight2 == i + highlight2){
            wattron(menu_win, A_REVERSE | COLOR_PAIR(1) );
			mvwprintw(menu_win, y, x, "%i. VIN = %s",i + highlight2,tt->VIN);
			if(enable_list) gui_list_view(tt);
			wattroff(menu_win, A_REVERSE | COLOR_PAIR(1));

		}else{
            mvwprintw(menu_win, y, x, "%i. VIN = %s",i + highlight2,tt->VIN);
		}
		++y;
	}
	wrefresh(menu_win);
}
