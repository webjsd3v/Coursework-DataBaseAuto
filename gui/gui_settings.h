#ifndef _GUI_SETTINGS_H
    #define _GUI_SETTINGS_H

    #ifndef __PDCURSES__
        #include <curses.h>
    #endif

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _STRUCT_TOOLS
        #include "../functions/struct_tools.h"
    #endif

    #ifndef _GUI_SYSMSG_H
        #include "gui_sysmsg.h"
    #endif

    int s_load_settings();
    void init_wins(WINDOW **wins, int n);
    void switch_panels(int type);
    void init_panels(WINDOW **wins, int n);
#endif // _GUI_SETTINGS_H
