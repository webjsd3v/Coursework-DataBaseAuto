#ifndef _STATIC_LANG_H
    #define _STATIC_LANG_H

    #ifndef _EXTERN_VA_H
        #include "extern_va.h"
    #endif
    enum
    {
         EN_EN,
         EN_RU
    };

    enum
    {
         MSG_CMD_MENU_WELCOME,
         MSG_CMD_MENU_UNKCMD,
         MSG_CMD_MENU_COFREC,
         MSG_CMD_MENU_NOARG,
         MSG_CMD_MENU_BYE,
         MSG_CMD_MENU_MENU,
         MSG_CMD_DISPLAY_HEAD,
         MSG_CMD_DISPLAY_NOENT,
         MSG_CMD_DISPLAY_TOTAL,
         MSG_CMD_CREATE_HELP,
         MSG_CMD_CREATE_ERR1,
         MSG_CMD_CREATE_ERR2,
         MSG_CMD_CREATE_ERR3,
         MSG_CMD_CREATE_ERRMEM,
         MSG_CMD_CREATE_OK,
         MSG_CMD_CREATE_ALLRE,
         MSG_CMD_CON_CREATE_HELP,
         MSG_CMD_CON_CREATE_ERR,
         MSG_CMD_DELETE_TEMPTY,
         MSG_CMD_DELETE_VNF,
         MSG_CMD_DELETE_EFT,
         MSG_CMD_DELETE_OK,
         MSG_CMD_DELETE_ERR2,
         MSG_CMD_DELETE_CON_HELP,
         MSG_CMD_DELETE_CON_ERR,
         MSG_CMD_EDIT_ERR1,
         MSG_CMD_EDIT_ERR2,
         MSG_CMD_EDIT_ERR3,
         MSG_CMD_EDIT_MSG1,
         MSG_CMD_EDIT_BF,
         MSG_CMD_EDIT_AF,
         MSG_CMD_EDIT_BB,
         MSG_CMD_EDIT_AB,
         MSG_CMD_EDIT_BM,
         MSG_CMD_EDIT_AM,
         MSG_CMD_EDIT_ERR4,
         MSG_CMD_EDIT_OK,
         MSG_CMD_EDIT_CON_ERR,
         MSG_CMD_EDIT_CON_HELP,
         MSG_CMD_LOAD_FNF,
         MSG_CMD_LOAD_FOE,
         MSG_CMD_LOAD_MSG1,
         MSG_CMD_LOAD_ERRIO,
         MSG_CMD_LOAD_MSG2,
         MSG_CMD_LOAD_ERRPASS,
         MSG_CMD_LOAD_POK,
         MSG_CMD_LOAD_PWE,
         MSG_CMD_LOAD_PWEERR,
         MSG_CMD_LOAD_PNM,
         MSG_CMD_LOAD_ERR1,
         MSG_CMD_LOAD_ERR2,
         MSG_CMD_LOAD_ERR3,
         MSG_CMD_LOAD_S,
         MSG_CMD_LOAD_OK,
         MSG_CMD_LOAD_EIP,
         MSG_CMD_LOAD_DE,
         MSG_CMD_LOAD_HELP,
         MSG_CMD_LOAD_Q,
         MSG_CMD_LOAD_CANS,
         MSG_CMD_LOAD_MSG3,
         MSG_CMD_SAVE_ERR,
         MSG_CMD_SAVE_OK,
         MSG_CMD_SAVE_ERR1,
         MSG_CMD_SAVE_MSG1,
         MSG_CMD_SAVE_EOK,
         MSG_CMD_SAVE_CON_MSG1,
         MSG_CMD_SAVE_CON_ERR,
         MSG_CMD_SAVE_CON_ERR2,
         MSG_CMD_SEARCH_ERR1,
         MSG_CMD_SEARCH_ERR2,
         MSG_CMD_SEARCH_ERR3,
         MSG_CMD_SEARCH_CON_HELP,
         MSG_CMD_SORT_ERR1,
         MSG_CMD_SORT_MSG1,
         MSG_CMD_SORT_MSG2,
         MSG_CMD_SORT_MSG3,
         MSG_CMD_SORT_MSG4,
         MSG_CMD_SORT_MSG5,
         MSG_CMD_SORT_OK,
         MSG_CMD_SORT_HELP,
         MSG_CMD_SORT_HELP1,
         MSG_CMD_SORT_HELP2,
         MSG_CMD_STRUCT_TOOLS_DEBUG,
         MSG_CMD_STRUCT_TOOLS_DEBUGON,
         MSG_CMD_STRUCT_TOOLS_DESTRUCT,
         MSG_CMD_UNIST_STALOG,
         MSG_CMD_UNIST_MSG,
         MSG_GUI_CREATE_MSG1,
         MSG_GUI_CREATE_CANS,
         MSG_GUI_CREATE_EFN,
         MSG_GUI_CREATE_EM,
         MSG_GUI_CREATE_EB,
         MSG_GUI_CREATE_MSG2,
         MSG_GUI_CREATE_MSG3,
         MSG_GUI_CREATE_OK,
         MSG_GUI_CREATE_MSG4,
         MSG_GUI_CREATE_MSG5,
         MSG_GUI_CREATE_MSG6,
         MSG_GUI_DEBUG_ON,
         MSG_GUI_DEBUG_OFF,
         MSG_GUI_EDIT_EFN,
         MSG_GUI_EDIT_NFN,
         MSG_GUI_EDIT_MSG1,
         MSG_GUI_EDIT_EM,
         MSG_GUI_EDIT_NM,
         MSG_GUI_EDIT_NB,
         MSG_GUI_EDIT_NBB,
         MSG_GUI_EDIT_EE,
         MSG_GUI_HELPINFO_MSG1,
         MSG_GUI_HELPINFO_MSG2,
         MSG_GUI_LIST_DEL,
         MSG_GUI_LISTINFO_MSG1,
         MSG_GUI_LISTINFO_NAME,
         MSG_GUI_LISTINFO_SUR,
         MSG_GUI_LISTINFO_NAME2,
         MSG_GUI_LISTINFO_BRA,
         MSG_GUI_LISTINFO_MOD,
         MSG_GUI_LISTINFO_LI,
         MSG_GUI_LOAD_MSG1,
         MSG_GUI_LOAD_MSG2,
         MSG_GUI_LOAD_MSG3,
         MSG_GUI_LOAD_MSG4,
         MSG_GUI_LOAD_MSG5,
         MSG_GUI_LOAD_MSG6,
         MSG_GUI_LOAD_MSG7,
         MSG_GUI_LOAD_MSG8,
         MSG_GUI_LOAD_MSG9,
         MSG_GUI_LOAD_MSG10,
         MSG_GUI_RESET,
         MSG_GUI_SAVE_MSG1,
         MSG_GUI_SAVE_MSG2,
         MSG_GUI_SAVE_MSG3,
         MSG_GUI_SAVE_MSG4,
         MSG_GUI_SAVE_MSG5,
         MSG_GUI_SAVE_MSG6,
         MSG_GUI_SAVE_MSG7,
         MSG_GUI_SAVE_MSG8,
         MSG_GUI_SAVE_EP,
         MSG_GUI_SAVE_SA,
         MSG_GUI_SAVE_SAA,
         MSG_GUI_SAVE_MSG9,
         MSG_GUI_SEARCH_PRE,
         MSG_GUI_SEARCH_MSG1,
         MSG_GUI_SEARCH_MSG2,
         MSG_GUI_SETT,
         MSG_SYSMSG_MSG1,
         MSG_SORT_MSG,
         MSG_SORT_OK,
         MSG_GUI_TOOLS_MSG1,
         MSG_GUI_MENU_MSG1,
         MSG_GUI_MENU_HID,
         MSG_GUI_MENU_SHOW,
         MSG_GUI_MENU_MAIN,
         MSG_GUI_MENU_NOENT,
         MSG_GUI_MENU_MSG2,
         MSG_GUI_MENU_MSG3,
         MSG_MENU_MSG,
         MSG_MENU_MSG2,
         MSG_MENU_MSG3,
         MSG_MENU_MSG4,
         MSG_MENU_MSG5,
         MSG_MENU_MSG6

    };

    int change_lang();
    const char * pmsg(int id_msg);

#endif
