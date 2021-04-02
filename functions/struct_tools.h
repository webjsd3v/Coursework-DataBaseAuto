#ifndef _STRUCT_TOOLS

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

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    #define _STRUCT_TOOLS
    int get_countofrec(struct list_box * targett);
    void con_debug();
    int is_duplicate(char * VIN,struct list_box * db_list);
    int destroyStruct(struct list_box ** s_struct);
    void show_current_line(struct list_box * s1,int show_desciption);
#endif // _STRUCT_TOOLS
