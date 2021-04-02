#ifndef _GLOBAL_VA_H
    #define _GLOBAL_VA_H
    #ifndef __MALLOC_FORMAT
        #define __MALLOC_FORMAT
        #define MALLOC(x,y) do { y = malloc(x); if (!y) abort(1); } while(0) // check  MALLOC out of memory
    #endif // __MALLOC_FORMAT

    #define MAX_TEMP_STORE 254
    #define FILE_LOG_SIZE 254

    char * sz_store [MAX_TEMP_STORE]; // временно сохранять для дальнейшего оперирования с объектами

    #ifndef GUI_ON
        #define GUI_ON 1
    #endif // GUI_ON
    #ifndef _GUI_OFF
        #define GUI_OFF 0
    #endif

    #ifndef DEBUG_MODE
        #define DEBUG_MODE 1
        short debug_mode = DEBUG_MODE;
    #endif

    #ifndef MAX_WINS
        #define MAX_WINS 3
    #endif // MAX_WINS

    // объявление глобальных переменных
    short is_gui = GUI_OFF;
    char filelog[FILE_LOG_SIZE] = {0};
    char sz_def_filename[FILE_LOG_SIZE] = {0};
    #ifndef DEFAULT_LANG
        #define DEFAULT_LANG 1
        short short_lang_data = DEFAULT_LANG;
    #endif


#endif // _GLOBAL_VA_H
