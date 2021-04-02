#ifndef _GUI_LOAD_H
    #define _GUI_LOAD_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

	#ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
	#endif

	#ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
	#endif

    #ifndef _LOAD_H
        #include "../functions/load.h"
    #endif

    #ifndef _GUI_TOOLS_H
        #include "gui_tools.h"
    #endif

    #ifndef _GUI_SETTINGS_H
        #include "gui_settings.h"
    #endif

    #ifndef _DIR_TOOLS_H
        #include "dir_tools.h"
    #endif

    void guiconf_M_LOAD(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype);
    void print_list_load(WINDOW *menu_win, int highlight2);
    void guiconf_M_LOADLIST(WINDOW *menu_win,WINDOW *menu_win_pre,int ptype);
    void print_list_loadlist(WINDOW *menu_win, int highlight2,int n_browserlist);

#endif // _GUI_LOAD_H

