#ifndef _SORT_H
    #define _SORT_H

    #ifndef _STDLIB_H
        #include <stdlib.h>
    #endif

    #ifndef _STDIO_H
        #include <stdio.h>
    #endif

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _MISC_H
        #include "misc.h"
    #endif // _MISC_H

    #ifndef _PRINTLOG_H
        #include "printlog.h"
    #endif // _PRINTLOG_H

    #ifndef _CON_DISPLAY_H
        #include "con_display.h"
    #endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _STRUCT_TOOLS
        #include "struct_tools.h"
    #endif

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    void try_sort(struct list_box ** s_t1,char * by_name,char * sz_is_desc);
    int con_sort(struct list_box ** s_t1);
#endif // _SORT_H


