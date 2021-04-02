#ifndef _SEARCH_H
    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif // _EXTERN_VA_H

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _STDIO_H
        #include <stdio.h>
    #endif

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _PRINTLOG_H
        #include "printlog.h"
    #endif // _PRINTLOG_H

    #ifndef _STDLIB_H
        #include <stdlib.h>
    #endif

    #ifndef _STRUCT_TOOLS
        #include "struct_tools.h"
    #endif

    #ifndef _MISC_H
        #include "misc.h"
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    #define _SEARCH_H
    list_box ** search_any(char * str,struct list_box * s_temp,char * where, char * s_name, char * sz_mod,struct list_box ** s_array );
    void con_search(struct list_box * struct_list);
#endif // _SEARCH_H



