#ifndef _GUI_CREATE_H
    #define _GUI_CREATE_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _STRUCT_TOOLS
        #include "../functions/struct_tools.h"
    #endif

    #ifndef _GUI_TOOLS_H
        #include "gui_tools.h"
    #endif

    #ifndef _GUI_SYSMSG_H
        #include "gui_sysmsg.h"
    #endif

    #ifndef _CREATE_H
        #include "../functions/create.h"
    #endif

    #ifndef _GUI_LIST_H
        #include "gui_list.h"
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    void gui_cr_element(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype);
    void gui_cr_rscr(WINDOW *menu_win);
#endif
