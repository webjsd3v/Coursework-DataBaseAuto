#ifndef _GUI_HELP_H
    #define _GUI_HELP_H

	#ifndef __PDCURSES_PANEL_H__
		#include <panel.h>
	#endif

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _GUI_STRUCTS_H
        #include "../gui_structs.h"
    #endif

    void guiconf_M_HELPINFO(char ** sz_data, int i_data);
#endif // _GUI_HELP_H
