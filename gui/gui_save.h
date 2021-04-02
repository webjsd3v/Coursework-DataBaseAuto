#ifndef _GUI_SAVE_H
    #define _GUI_SAVE_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _SAVE_H
        #include "../functions/save.h"
    #endif

    #ifndef _GUI_SYSMSG_H
        #include "gui_sysmsg.h"
    #endif

    #ifndef _GUI_TOOLS_H
        #include "gui_tools.h"
    #endif

    #ifndef _GUI_SETTINGS_H
        #include "gui_settings.h"
    #endif

    void print_list_save(WINDOW *menu_win, int highlight2);
    void guiconf_M_SAVE(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype);
    void sys_quick_save();
#endif // _GUI_SAVE_H


