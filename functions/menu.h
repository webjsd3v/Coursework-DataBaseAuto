#define C_EXIT "exit"
#define C_DISPLAY "display"
#define C_CREATE "create"
#define C_HELP "help"
#define C_SEARCH "search"
#define C_SDEBUG "debug!"
#define C_DELETE "delete"
#define C_GET_COUNT "get_count"
#define C_SAVE "save"
#define C_LOAD "load"
#define C_SORT "sort"
#define C_CLEAR_ALL "clearall"
#define C_EDIT "edit"
#define C_TEST "test"
#define C_MENU "menu"
#define C_MENU_M "m"
#define C_LANG "lang"

void menu(){
    fprintf_log(filelog,stdout,pmsg(MSG_MENU_MSG) );
    while(1){
        clrstdin(); // Clear buffer data stdin
        fprintf_log(filelog,stdout,"%s",pmsg(MSG_MENU_MSG2));
        char cl_cmd[10];int is_exit = 0;int is_valid = 1;
        if(scanf("%9s",cl_cmd) == 0){
            fprintf_log(filelog,stderr,pmsg(MSG_MENU_MSG3) );is_valid = 0;
        }
        if(!is_valid) continue;
        /* -- MENU -- */
        if(strcmp(C_EXIT,cl_cmd) == 0) is_exit = 1;

        else if(strcmp(C_DISPLAY,cl_cmd) == 0) show_table(default_list);

        else if(strcmp(C_CREATE,cl_cmd) == 0) con_create(&default_list);

        else if(strcmp(C_HELP,cl_cmd) == 0) con_help();

        else if(strcmp(C_SEARCH,cl_cmd) == 0)con_search(default_list);

        else if(strcmp(C_SDEBUG,cl_cmd) == 0) con_debug();

        else if(strcmp(C_DELETE,cl_cmd) == 0) con_delete(&default_list);

        else if(strcmp(C_SAVE,cl_cmd) == 0) con_save(default_list);

        else if(strcmp(C_LOAD,cl_cmd) == 0) con_load(&default_list);

        else if(strcmp(C_SORT,cl_cmd) == 0) con_sort(&default_list);

        else if(strcmp(C_CLEAR_ALL,cl_cmd) == 0) destroyStruct(&default_list);

        else if(strcmp(C_EDIT,cl_cmd) == 0) con_edit(&default_list);

        else if(strcmp(C_LANG,cl_cmd) == 0) change_lang();

        else if( (strcmp(C_MENU,cl_cmd) == 0 ) || (strcmp(C_MENU_M,cl_cmd) == 0 ) ) gui_menu();

        else if(strcmp(C_GET_COUNT,cl_cmd)== 0){
            fprintf_log(filelog,stdout,pmsg(MSG_MENU_MSG4),get_countofrec(default_list));
        }else{
            fprintf_log(filelog,stderr,pmsg(MSG_MENU_MSG5));
        }
            if(is_exit){
            fprintf_log(filelog,stdout,pmsg(MSG_MENU_MSG6));
            break;
        }
    }
}
