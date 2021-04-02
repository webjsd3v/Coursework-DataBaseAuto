#ifndef _GUI_TOOLS_H
    #define _GUI_TOOLS_H

    #ifndef __PDCURSES_PANEL_H__
        #include <panel.h>
    #endif

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    #ifndef _DELETE_H
        #include "../functions/delete.h"
    #endif

    #ifndef _GUI_SYSMSG_H
        #include "gui_sysmsg.h"
    #endif

    void cls_line(WINDOW *menu_win,int i_line,int i_indent,int i_stop);
    char * gui_dynamic_buffer(WINDOW * w_temp,int start_y,int start_x, const char * sz_template,char * t_buffer,size_t sz_lenbuffer);
    void gui_del_element(int choice_list,struct list_box * s_str);
#endif // _GUI_TOOLS_H

