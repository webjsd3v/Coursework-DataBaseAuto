#ifndef _STDIO_H
    #include <stdio.h>
#endif
#ifndef _STRING_H
    #include <string.h>
#endif
#ifndef _TIME_H
    #include <time.h>
#endif // _TIME_H
#ifndef _CTYPE_H
    #include <ctype.h>
#endif // _TIME_H

#ifndef _MISC_H
    #define _MISC_H
    void swap_byte(unsigned char *x, unsigned char *y);
    int strcmp_multi_i (const char *p1, const char *p2);
    void clrstdin();
    char * get_current_time();
    char * ell(const char * s1,int i_max);
#endif // _MISC_H


