#ifndef _DELETE_H
    #define _DELETE_H

    #ifndef _STDLIB_H
        #include <stdlib.h>
    #endif

    #ifndef _STDIO_H
        #include <stdio.h>
    #endif

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _PRINTLOG_H
        #include "printlog.h"
    #endif // _PRINTLOG_H

    #ifndef _MISC_H
        #include "misc.h"
    #endif // _MISC_H

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    #ifndef _STRUCT_TOOLS
        #include "struct_tools.h"
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    int deleteNote(struct list_box ** s_struct, char * VIN);
    void deleteFirst(struct list_box** list);
    void con_delete(struct list_box** s_temp);
    struct list_box * get_previous(struct list_box * first_id,char * VIN);
#endif // _DELETE_H


