#ifndef _CREATE_H
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

    int create(char * VIN,struct list_box ** s1,char * fFullname,char * fBrand,char * fModel); //  создать новую запись
    void con_create(struct list_box ** s_temp); //консольная команда для создания новго элемента
#endif // _CREATE_H
