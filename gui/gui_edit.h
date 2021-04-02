#ifndef _GUI_EDIT_H
    #define _GUI_EDIT_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _GUI_SYSMSG_H
        #include "gui_sysmsg.h"
    #endif

    #ifndef _STRUCT_TOOLS
        #include "../functions/struct_tools.h"
    #endif

    #ifndef _EDIT_H
        #include "../functions/edit.h"
    #endif

    #ifndef _GUI_TOOLS_H
        #include "gui_tools.h"
    #endif

    #ifndef _GUI_LIST_H
        #include "gui_list.h"
    #endif

    void gui_e_element(int highlight,WINDOW *menu_win,WINDOW *menu_win_pre,struct list_box * t_str);
    void gui_e_rscr(WINDOW *menu_win);
#endif // _GUI_EDIT_H
