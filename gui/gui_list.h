#ifndef _GUI_LIST_H
    #define _GUI_LIST_H

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

    #ifndef _GUI_CREATE_H
        #include "gui_create.h"
    #endif

    #ifndef _GUI_EDIT_H
        #include "gui_edit.h"
    #endif

    #ifndef _GUI_SAVE_H
        #include "gui_save.h"
    #endif

    #ifndef _GUI_LOAD_H
        #include "gui_load.h"
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    void guiconf_M_LIST();
    void gui_list_view(struct list_box * s_lbt);
    void print_list(WINDOW *menu_win, int highlight2,int n_choices_list,int enable_list,int ptype);
#endif // _GUI_LIST_H


