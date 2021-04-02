#ifndef _GUI_SYSMSG_H
    #define _GUI_SYSMSG_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif
    void sys_gui_msg(const char * sz_msg);
    void show_keyinfo(int starty,int startx,int ch); // показать нажатие клавиш

#endif // _GUI_SYSMSG_H
