#ifndef _CON_DISPLAY_H
    #define _CON_DISPLAY_H

    #ifndef _STDIO_H
        #include <stdio.h>
    #endif

    #ifndef _PRINTLOG_H
        #include "printlog.h"
    #endif // _PRINTLOG_H

    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _MISC_H
        #include "misc.h"
    #endif // _MISC_H

    #ifndef _STDLIB_H
        #include <stdlib.h>
    #endif

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif // _EXTERN_VA_H

    #ifndef _MAIN_STRUCT_H
        #include "../main_struct.h"
    #endif // _MAIN_STRUCT_H

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    void show_table(struct list_box * newbox);
#endif // _CON_DISPLAY_H

