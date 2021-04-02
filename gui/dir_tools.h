#ifndef _DIR_TOOLS_H
    #define _DIR_TOOLS_H

    #ifndef _DIRENT_H_
        #include <dirent.h>
    #endif

    #ifndef _STDLIB_H
        #include <stdlib.h>
    #endif

    char * get_fnbynum(int i_fnum);
    int get_coffile(DIR *dp);

#endif // _DIR_TOOLS_H
