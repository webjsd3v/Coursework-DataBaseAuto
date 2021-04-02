#ifndef _GUI_STRUCTS_H
	#define _GUI_STRUCTS_H

    #define WIN_N_LIST_MAX 10

    #define MAX_WINS 3
    #define WIN_N_MAIN 0
    #define WIN_N_LIST 1
    #define WIN_N_SETT 2

    #define M_EXIT 10
    #define M_INFO 9
    #define M_HELP 8
    #define M_LOAD 7
    #define M_SAVE 6
    #define M_SEARCH 5
    #define M_SORT 4
    #define M_RESET 3
    #define M_DEBUG 2
    #define M_LIST 1
    #define M_EXIT_L -1
    #define M_EXIT_C -1

    #define M_CREATE_L 1

    #define FILE_DEFAULT "db.bin"

    /* winbox style */

    #define WIN_BSTY 43
    #define WIN_BSTX 43
    #define WIN_BSTY2 42
    #define WIN_BSTX2 42
    #define WIN_BSTC1 43
    #define WIN_BSTC2 43
    #define WIN_BSTC3 43
    #define WIN_BSTC4 43

    /* end */

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

	typedef struct _PANEL_DATA {
		int hide;	/* TRUE if panel is hidden */
	}PANEL_DATA;

	WINDOW * menu_wins[MAX_WINS];
	PANEL * menu_panels[MAX_WINS]; // create new dynamic panels
	PANEL_DATA panel_datas[MAX_WINS];
	PANEL_DATA *temp;

#endif
