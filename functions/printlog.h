#ifndef _PRINTLOG_H
    #define _PRINTLOG_H
    #ifndef _STDLIB_H
        #include <stdlib.h>
    #endif
    #ifndef _STDIO_H
        #include <stdio.h>
    #endif
    #ifndef _STRING_H
        #include <string.h>
    #endif

    #ifndef _STATIC_LANG_H
        #include "../static_lang.h"
    #endif

    #ifndef _EXTERN_VA_H
        #include "../extern_va.h"
    #endif // _EXTERN_VA_H
    #include <stdarg.h>
    int fprintf_log(char * filelog,FILE * descriptor,const char *format, ...);
#endif // _PRINTLOG_H
