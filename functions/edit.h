#ifndef _EDIT_H
    #define _EDIT_H

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

    #ifndef _STRUCT_TOOLS
        #include "struct_tools.h"
    #endif

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    int edit_struct(struct list_box ** s_t1,int el_num,char * sz_mod, char * by,char * s_name,char * str_name);
    void by_Fullname(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column);
    void by_Brand(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column);
    void by_Model(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column);
    void by_VIN(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column);
    void con_edit(struct list_box ** s_t1);
#endif // _EDIT_H

