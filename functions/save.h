#ifndef _SAVE_H
    #define _SAVE_H

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

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    #ifndef _STRUCT_TOOLS
        #include "struct_tools.h"
    #endif

    #ifndef _MISC_H
        #include "misc.h"
    #endif // _MISC_H

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    int try_save(struct list_box * s_t1,char * sz_user_key,char * filename,short i_allow_encr);
    int con_save(struct list_box * s_t1);
    int check_filename(char * filename);
#endif // _SAVE_H



