#include "gui_help.h"


char *help_data[] = {
    "Navigation in the program in any menu you can navigate the items using the arrows up and down.",
    "From any menu item it is possible to exit with F10, the arrow <- dibo select the item EXIT",
    "..."
};


char *help_data_rus[] = {
    "1.0 ��������� � ��������� : � ����� ���� ����� ������������ �� ������� � ������� ��������� ����� � ����.  ",
    "1.1 C ������ ������ ���� ����� ����� � ������� F10, ��������� <- ���� ������� ����� �����",
    "2.0 ����� \"������� ��� �����.������\" - � ��� ��������� ������ �������. �� ����� ���������, ������� ",
    "���������������. ������������ �� ������ ��� �������� ��������� ����� � ����. ���� ����������� ���������",
    "������ � ������������� ����� ( ���� ��� �������� L - ������� �������� �� ������������ ����� \"db.bin\"",
    "���� ���������� ����� �������� SHIFT + L. ��� �� ����� � ��������� � ����������� ���� � ������� ������� ",
    "'s' ���� ���������� ����� S + SHIFT. ����� ������� ����� ������, ���������� ������ 'c' ���� F6",
    "���� ����� ��������� ���������� � ������ - ��� ������ ������� �� � ������ F7 ���� 'e' . ����� �������� ",
    "���� ��������������, ��� ����� ����� ����� � ������ � � ���� ��� ������� ���� ����������� ������� ��� ",
    "������ F10, 'l'(���� �� � ������ �������� � �����), 's' ( � ������ ���������� ), 'e' � 'c' (�����. �  ",
    "���������� �������������� ). ����� � ������� ���� <- ���� F10 ",
    "3.0 \"����� �������\" - ��������, ���� ���������� ��������� ���������",
    "4.0 \"�������� ��� ������\" - �������� ��� ������ � ������ ������",
    "5.0 \"���������� ������\" - ���� ����������� ����������� ������ �� ������������ ������� (����. � ��������)",
    "6.0 \"����� ������\" - ����� ����� 1 ��� ��������� �������, ������ ���� �� ������� � ������ �������� ����� . ",
    "����� ��� ���������� � ������ ����������� ������. � ��� �� ������ ��������������� ��� ������� ������ ��� ",
    "����������."
    "7.0 � ������� �������� � ����������, ���� ��������� ���������� ����� ",
    "..."
};

int n_help_data = sizeof(help_data) / sizeof(char *); // ���� ��������� ���������� �������
int n_help_data_rus = sizeof(help_data_rus) / sizeof(char *); // ���� ��������� ���������� �������

char *info_data[] = {
    "..."
};

char *info_data_rus[] = {
    "..."
};

int n_info_data = sizeof(info_data) / sizeof(char *); // ���� ��������� ���������� �������
int n_info_data_rus = sizeof(info_data_rus) / sizeof(char *); // ���� ��������� ���������� �������

void guiconf_M_HELPINFO(char ** sz_data, int i_data,const char * sz_header){ //������� �������
    int stdmax_y = 0, stdmax_x = 0;
    getmaxyx(stdscr,stdmax_y,stdmax_x);
    int starty = stdmax_y - 5, startx = stdmax_x - 10;

    //WINDOW * help_win_shadow = newwin(starty, startx+1, 4, 6);
    //wbkgdset(help_win_shadow, COLOR_PAIR(2)); // ��������� ����
    //PANEL * help_win_panel_shadow = new_panel(help_win_shadow);

    //wborder(help_win_shadow,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4);

    //update_panels();doupdate();wrefresh(help_win_shadow);

    WINDOW * help_win = newwin(starty, startx, 3, 5);
    wbkgdset(help_win, COLOR_PAIR(1)); // ��������� ����
    PANEL * help_win_panel = new_panel(help_win);
    int coo_y = 2;int coo_x = 2;

    wborder(help_win,WIN_BSTY,WIN_BSTX,WIN_BSTY2,WIN_BSTX2,WIN_BSTC1,WIN_BSTC2,WIN_BSTC3,WIN_BSTC4); // ���������� ���� � ��������� �����������


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
