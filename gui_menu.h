
extern char help_data[];
extern char help_data_rus[];
extern char info_data[];
extern char info_data_rus[];
extern int n_help_data;
extern int n_help_data_rus;
extern int n_info_data;
extern int n_info_data_rus;

void guiconf_M_HELPINFO();

char *choices_rus[] = {
			"1.  ������� ��� �����.������",
			"2.  ����� ������� ���. ����.",
			"3.  �������� ��� ������",
			"4.  ���������� ������",
			"5.  ����� ������(��)",
			"6.  ��������� � ����",
			"7.  ��������� �� �����",
			"8.  �������",
			"9.  ����",
			"10. ����� � ���������� ����",
};

char *choices[] = {
			"1.  Create , edit , delete item",
			"2.  Debug ON OFF",
			"3.  Reset all data",
			"4.  Sort data",
			"5.  Search element",
			"6.  save to file",
			"7.  Load from file",
			"8.  Help",
			"9.  Info",
			"10. Exit",
};




int n_choices = sizeof(choices) / sizeof(char *); // ���� ��������� ���������� �������
int n_choices_rus = sizeof(choices_rus) / sizeof(char *); // ���� ��������� ���������� �������

void print_menu(WINDOW *menu_win, int highlight);
int menu_choice(int choice);
void print_menu(WINDOW *menu_win, int highlight) // ������� ����
{
	int y, i,x,x_max;
    getmaxyx(menu_win,y,x_max); // �������� ����. ����� ������� ����
	x = 2; // ���������� ������ �� ����
	y = (y-n_choices)/2;; // ���������� ������ �� ����
	wborder(menu_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);
	mvwprintw(menu_win, 5, (x_max-strlen(pmsg(MSG_GUI_MENU_MAIN)))/2, pmsg(MSG_GUI_MENU_MAIN));

	switch(short_lang_data){
        case 1:
            for(i = 0; i < n_choices; ++i)
            {	if(highlight == i + 1) /* High light the present choice */
                {	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) ); //�������� ���. ������ ��� ������
                    mvwprintw(menu_win, y, x, "%s", choices_rus[i]);
                    wattroff(menu_win, A_REVERSE | COLOR_PAIR(1)); //����. ������
                }
                else
                    mvwprintw(menu_win, y, x, "%s", choices_rus[i]);
                ++y;
            }

            mvwprintw(menu_win, 19, 2, "---------- ��������� ----------");
            mvwprintw(menu_win, 20 + 1, 3, "-> or ENTER // �������������");
            mvwprintw(menu_win, 20 + 2, 3, "h or H      // ������ ������");
            mvwprintw(menu_win, 20 + 3, 3, "F10         // ����� ");
            break;
        default :
            for(i = 0; i < n_choices; ++i)
            {	if(highlight == i + 1) /* High light the present choice */
                {	wattron(menu_win, A_REVERSE | COLOR_PAIR(1) ); //�������� ���. ������ ��� ������
                    mvwprintw(menu_win, y, x, "%s", choices[i]);
                    wattroff(menu_win, A_REVERSE | COLOR_PAIR(1)); //����. ������
                }
                else
                    mvwprintw(menu_win, y, x, "%s", choices[i]);
                ++y;
            }

            mvwprintw(menu_win, 19, 2, "---------- FAST HELP ----------");
            mvwprintw(menu_win, 20 + 1, 3, "-> or ENTER // menu selector");
            mvwprintw(menu_win, 20 + 2, 3, "h or H      // hide panel l");
            mvwprintw(menu_win, 20 + 3, 3, "F10         // exit from menu");
	}

	wrefresh(menu_win);
}

int menu_choice(int choice){ // �������� ������� ��� �������� ����
    while(1){
        switch(choice){
            case M_LIST : {
                if(get_countofrec(default_list) == 0){
                    sys_gui_msg(pmsg(MSG_GUI_MENU_NOENT));
                }
                guiconf_M_LIST();
                return choice;
            }
            case M_DEBUG : {
                guiconf_M_DEBUG();
                return choice;
            }
            case M_SORT : {
                guiconf_M_SORT(menu_wins[WIN_N_LIST],menu_wins[WIN_N_MAIN],WIN_N_LIST);
                return choice;
            }
            case M_SAVE : {
                guiconf_M_SAVE(menu_wins[WIN_N_LIST],menu_wins[WIN_N_MAIN],WIN_N_LIST);
                return choice;
            }
            case M_LOAD : {
                guiconf_M_LOAD(menu_wins[WIN_N_LIST],menu_wins[WIN_N_MAIN],WIN_N_LIST);
                return choice;
            }
            case M_SEARCH :{
                guiconf_M_SEARCH(menu_wins[WIN_N_LIST],menu_wins[WIN_N_MAIN],WIN_N_LIST);
                return choice;
            }
            case M_RESET : {
                guiconf_M_RESET();
                return choice;
            }
            case M_HELP :{
                switch(short_lang_data){
                    case 1 :
                        guiconf_M_HELPINFO(help_data_rus,n_help_data_rus,pmsg(MSG_GUI_HELPINFO_MSG2));
                        break;
                    default :
                        guiconf_M_HELPINFO(help_data,n_help_data,pmsg(MSG_GUI_HELPINFO_MSG2));

                }
                return choice;
            }
            case M_INFO :{
                switch(short_lang_data){
                    case 1 :
                        guiconf_M_HELPINFO(info_data_rus,n_info_data_rus,pmsg(MSG_GUI_HELPINFO_MSG1));
                        break;
                    default :
                        guiconf_M_HELPINFO(info_data,n_info_data,pmsg(MSG_GUI_HELPINFO_MSG1));
                }
                return choice;
            }
            case M_EXIT : return choice;
            default : {
                return choice;
            }
        }
    }
}

int gui_menu()
{
    strcpy(sz_def_filename,FILE_DEFAULT); // ���������� ����������� ���� ������
    is_gui = GUI_ON;
    if (s_load_settings()){
            is_gui = GUI_OFF;
            return 2; // �������� curses.h
    }
    int highlight = 1; // ��������� 1
	int choice = 0; // ���������� ����� �� 0
	int c;

    init_wins(menu_wins,MAX_WINS); // ������� ����� ����
    init_panels(menu_wins,MAX_WINS); // ������� ������
    /* END */
    print_menu(menu_wins[WIN_N_MAIN], highlight);
	keypad(menu_wins[WIN_N_MAIN], TRUE); // �������� ��������� �� ����������
    mvprintw(0, 0, pmsg(MSG_GUI_MENU_MSG1));refresh();

	int i_winc = 0;
	refresh();
	for(;i_winc < MAX_WINS;i_winc++){
        wrefresh(menu_wins[MAX_WINS]);
	}
    print_menu(menu_wins[WIN_N_MAIN], highlight);

	while(1)
	{	c = wgetch(menu_wins[WIN_N_MAIN]);

		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
            case 'h' :{
				temp = (PANEL_DATA *)panel_userptr(menu_panels[WIN_N_LIST]);
				if(temp->hide == FALSE)
				{
                    switch_panels(WIN_N_LIST);
					mvprintw(27, 5, pmsg(MSG_GUI_MENU_HID));
				}
				else
				{
				    switch_panels(WIN_N_LIST);
					mvprintw(27, 5, "                     ");
					mvprintw(27, 5, pmsg(MSG_GUI_MENU_SHOW));
				}
				break;

            }

			case 10: // KEY ENTER
			case KEY_RIGHT:
				choice = highlight;
				break;
			case KEY_F(10) : //����. ������
            case 27:
            case KEY_LEFT:
				choice = M_EXIT;
				break;
			default:

                show_keyinfo(28,5,c);
				break;
		}
		print_menu(menu_wins[WIN_N_MAIN], highlight);
		//rule choice
		if(choice) choice = menu_choice(choice);
        if(choice == M_EXIT) break;
        else choice = 0;
         move(0,0);clrtoeol();
         mvprintw(0, 0, pmsg(MSG_GUI_MENU_MSG2));refresh();
    }
	mvprintw(23, 0, pmsg(MSG_GUI_MENU_MSG3), choice, choices[choice - 1]);
	clrtoeol();
	refresh();
    // ����������� ��������� ������� � ����
    int si = 0;

    for(si = 0; si < MAX_WINS; ++si)
    {
        del_panel(menu_panels[si]);
        delwin(menu_wins[si]);

    }
	endwin(); // ������������� �������
	is_gui = GUI_OFF;
	return 0;
}


