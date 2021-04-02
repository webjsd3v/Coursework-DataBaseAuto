#ifndef _LOAD_H
    #define _LOAD_H

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

    #ifndef _CREATE_H
        #include "create.h"
    #endif

    #ifndef _UNISTD_H
        #include <unistd.h>
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    int try_load(struct list_box ** s_t1,char * sz_user_key,const char * filename);
    int con_load(struct list_box ** s_t1);
    int s_loaded_file(struct list_box ** s_temp,int argc, char * argv[]);
#endif // _LOAD_H

