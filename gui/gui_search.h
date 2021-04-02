#ifndef _GUI_SEARCH_H
    #define _GUI_SEARCH_H

    #ifndef _SEARCH_H
        #include "../functions/search.h"
    #endif

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _GUI_TOOLS_H
        #include "gui_tools.h"
    #endif

    #ifndef _GUI_SETTINGS_H
        #include "gui_settings.h"
    #endif

    #ifndef _GUI_EDIT_H
        #include "gui_edit.h"
    #endif

    void plsl_a(WINDOW * menu_win,int by_type);
    int s_arr_count(struct list_box ** s_array);
    void print_list_search_list(WINDOW *menu_win, int highlight2,struct list_box ** s_array);
    void guiconf_M_SEARCH_LIST(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype,struct list_box ** s_array);
    void print_list_search(WINDOW *menu_win, int highlight2);
    void guiconf_M_SEARCH(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype);
#endif // _GUI_SEARCH_H


