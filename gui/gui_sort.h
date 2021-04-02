#ifndef _GUI_SORT_H
    #define _GUI_SORT_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _GUI_SETTINGS_H
        #include "gui_settings.h"
    #endif

    #ifndef _GUI_TOOLS_H
        #include "gui_tools.h"
    #endif

    #ifndef _SORT_H
        #include "../functions/sort.h"
    #endif

    void guiconf_M_SORT(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype);
    void print_list_sort(WINDOW *menu_win, int highlight2);
#endif // _GUI_SORT_H
