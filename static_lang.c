#include "static_lang.h"

#define MAX_LANG 2
#define MAX_RECORDS 512

typedef struct _LANG_MSG_BOX{
    const char * msg_name;
    int msg_id;
}LANG_MSG_BOX;

LANG_MSG_BOX lbox[MAX_LANG][MAX_RECORDS] = {

    {
        {"Welcome to test Struct default_list : \n Type help to display tips \n",MSG_CMD_MENU_WELCOME},
        {"Unknown command \n Type help to display tips \n",MSG_CMD_MENU_UNKCMD},
        {"Get count of records  \n Total : %i records in table \n",MSG_CMD_MENU_COFREC},
        {"No arguments ! Try again > \n",MSG_CMD_MENU_NOARG},
        {"Good bye ! \n",MSG_CMD_MENU_BYE},
        {"menu>",MSG_CMD_MENU_MENU},
        {"|   *** VIN ***    |    *** FULL NAME ***    |   *** MODEL ***   |    *** BRAND ***   |\n",MSG_CMD_DISPLAY_HEAD},
        {"No entries! \n",MSG_CMD_DISPLAY_NOENT},
        {"Total items in list : %i\n",MSG_CMD_DISPLAY_TOTAL},
        {"Please write : <Fullname> <Brand> <Model>\n",MSG_CMD_CREATE_HELP},
        {"Input error  you not type <Full Name> ; <Brand> ; <Model>  ; \n",MSG_CMD_CREATE_ERR1},
        {"Input error  you not type <Brand> ; <Model> ; \n",MSG_CMD_CREATE_ERR2},
        {"Input error  you not type <Model> ; \n",MSG_CMD_CREATE_ERR3},
        {"Memory error !\n",MSG_CMD_CREATE_ERRMEM},
        {"Created successful !\n",MSG_CMD_CREATE_OK},
        {"Car [%s] allready exists! \n",MSG_CMD_CREATE_ALLRE},
        {"Please enter new VIN here -> ",MSG_CMD_CON_CREATE_HELP},
        {"Wrong syntax , <VID>\n",MSG_CMD_CON_CREATE_ERR},
        {"The table is empty! \n",MSG_CMD_DELETE_TEMPTY},
        {"VIN %s not found : ( \n",MSG_CMD_DELETE_VNF},
        {"Element is first in the table ! \n",MSG_CMD_DELETE_EFT},
        {"Delete VIN %s SUCCESS! \n",MSG_CMD_DELETE_OK},
        {"Delete VIN %s FAILURE! \n",MSG_CMD_DELETE_ERR2},
        {"DELETE Note . Syntax <VIN> \n",MSG_CMD_DELETE_CON_HELP},
        {"Too much arg in con_delete !",MSG_CMD_DELETE_CON_ERR},
        {"Unknown char or you can't edit VIN \n",MSG_CMD_EDIT_ERR1},
        {"No entries! Nothing to edit\n",MSG_CMD_EDIT_ERR2},
        {"You have not entered the filter after word BY \n",MSG_CMD_EDIT_ERR3},
        {"We edit only current line! \n",MSG_CMD_EDIT_MSG1},
        {"Before Fullname : %s\n",MSG_CMD_EDIT_BF},
        {"After Fullname : %s\n OK! \n",MSG_CMD_EDIT_AF},
        {"Before Brand : %s\n",MSG_CMD_EDIT_BB},
        {"After Brand : %s\n OK! \n",MSG_CMD_EDIT_AB},
        {"Before Model : %s\n",MSG_CMD_EDIT_BM},
        {"After Model : %s\n OK! \n",MSG_CMD_EDIT_AM},
        {"Unknown char or you can't edit VIN \n",MSG_CMD_EDIT_ERR4},
        {"Success!\n",MSG_CMD_EDIT_OK},
        {"<Wrong input> \n ",MSG_CMD_EDIT_CON_ERR},
        {"edit element . Syntax <new data> ; <name of column>  by <column> <data> \n ",MSG_CMD_EDIT_CON_HELP},
        {"File %s not found \n",MSG_CMD_LOAD_FNF},
        {"File open error! \n",MSG_CMD_LOAD_FOE},
        {"\n i_count_bytes : %i \n",MSG_CMD_LOAD_MSG1},
        {"Can't open or create %s file",MSG_CMD_LOAD_ERRIO},
        {"key %s , key %s\n",MSG_CMD_LOAD_MSG2},
        {"\n The password [%s] does not match after decrypt \n",MSG_CMD_LOAD_ERRPASS},
        {"PASSWORD OK!\n",MSG_CMD_LOAD_POK},
        {"PASSWD without encrypt COMPARING [%s] AND [%s]\n",MSG_CMD_LOAD_PWE},
        {"The password [%s] does not match without decrypt, try other method... \n",MSG_CMD_LOAD_PWEERR},
        {"Sorry can't open . Password not matched \n",MSG_CMD_LOAD_PNM},
        {"Error in line not type <Full Name> ; <Brand> ; <Model> ; \n",MSG_CMD_LOAD_ERR1},
        {"Error in line not type <Brand> ; <Model> ; \n",MSG_CMD_LOAD_ERR2},
        {"Error in line not type <Model> ; \n",MSG_CMD_LOAD_ERR3},
        {"Scanning : [%s] [%s] \n",MSG_CMD_LOAD_S},
        {"Load OK! Total : %i lines \n",MSG_CMD_LOAD_OK},
        {"Wrong input <filename> <key>\n",MSG_CMD_LOAD_EIP},
        {"Detect encrypted files! Reading data ... Total %i files \n",MSG_CMD_LOAD_DE},
        {"usage: %s key_file target_file output_file \n",MSG_CMD_LOAD_HELP},
        {"Want to try to enter the password?! Y / N \n",MSG_CMD_LOAD_Q},
        {"Canceling... \n",MSG_CMD_LOAD_CANS},
        {"\nin s_loaded_file . Current key loaded as [%s] \n",MSG_CMD_LOAD_MSG3},
        {"Can't saving \'nothing!\'\n",MSG_CMD_SAVE_ERR},
        {"Saving OK!\n",MSG_CMD_SAVE_OK},
        {"Can't saving \'nothing!\'\n",MSG_CMD_SAVE_ERR1},
        {"%i bytes : \n",MSG_CMD_SAVE_MSG1},
        {"Encrypt and save OK! \n",MSG_CMD_SAVE_EOK},
        {"sz_user_key : %i encrypt : %i \n",MSG_CMD_SAVE_CON_MSG1},
        {"Wrong input <filename> <key> <encrypt> \n",MSG_CMD_SAVE_CON_ERR},
        {"Invalid filename . Allow only A-z and 0-9 first letter \n",MSG_CMD_SAVE_CON_ERR2},
        {"Wrong input \n",MSG_CMD_SEARCH_ERR1},
        {"Not entered value of <type of > <data>\n",MSG_CMD_SEARCH_ERR2},
        {"Not found : ( \n",MSG_CMD_SEARCH_ERR3},
        {"type <name> where <column> <data>\n",MSG_CMD_SEARCH_CON_HELP},
        {"Can't sort one element ! \n",MSG_CMD_SORT_ERR1},
        {"Using method : %i, desc : %i \n",MSG_CMD_SORT_MSG1},
        {"-----------------------BEFORE EDIT-------------------------\n",MSG_CMD_SORT_MSG2},
        {" \n Find previous element: [%s] == MIN : [%s]\n\n",MSG_CMD_SORT_MSG3},
        {"-----NEW TABLE-------%s-------;------ \n",MSG_CMD_SORT_MSG4},
        {"-------------END----------- \n",MSG_CMD_SORT_MSG5},
        {"Sort complete! \n",MSG_CMD_SORT_OK},
        {"Sorting by VIN as default . Err , name not entered \n",MSG_CMD_SORT_HELP},
        {"Sorting by VIN as default . Err , must be \"by\" only \n",MSG_CMD_SORT_HELP1},
        {"Sorting by VIN as default \n",MSG_CMD_SORT_HELP2},
        {"Debugging disabled \n",MSG_CMD_STRUCT_TOOLS_DEBUG},
        {"Debugging enabled \n",MSG_CMD_STRUCT_TOOLS_DEBUGON},
        {"Just removed from memory : %i items!\n",MSG_CMD_STRUCT_TOOLS_DESTRUCT},
        {"Start logging ... %s\n",MSG_CMD_UNIST_STALOG},
        {"Using default Logfile.log \n",MSG_CMD_UNIST_MSG}



    },

    {
        {"����� ���������� � ����� ������ ����������� ���� ������ : \n �������� help ��� ������� ������ \n",MSG_CMD_MENU_WELCOME},
        {"����������� �������. \n ������� help ��� ����������� ���������. \n",MSG_CMD_MENU_UNKCMD},
        {"�������� ���������� ������� � ���������  \n ����� : %i ������� � ������� \n",MSG_CMD_MENU_COFREC},
        {"��� ���������� ! ���������� ��� ��� > \n",MSG_CMD_MENU_NOARG},
        {"���� ! \n",MSG_CMD_MENU_BYE},
        {"����>",MSG_CMD_MENU_MENU},
        {"|   *** VIN ***    |    *** ������ ���  ***  |   *** ������ ***  |   *** ����� ***    |\n",MSG_CMD_DISPLAY_HEAD},
        {"��� �������! \n",MSG_CMD_DISPLAY_NOENT},
        {"����� ��������� : %i\n",MSG_CMD_DISPLAY_TOTAL},
        {"����������, ��������: <������ ���> <�����> <������> \n",MSG_CMD_CREATE_HELP},
        {"������ �����,  �� �� ����� <������ ���>; <�����>; <������>; \n",MSG_CMD_CREATE_ERR1},
        {"������ �����,  �� �� ����� <�����>; <������>; \n",MSG_CMD_CREATE_ERR2},
        {"������ �����,  �� �� ����� <������>; \n",MSG_CMD_CREATE_ERR3},
        {"������ ������ !\n",MSG_CMD_CREATE_ERRMEM},
        {"������� �������!\n",MSG_CMD_CREATE_OK},
        {"���������� [%s] ��� ����������! \n",MSG_CMD_CREATE_ALLRE},
        {"������� ����� VIN ����� -> ",MSG_CMD_CON_CREATE_HELP},
        {"������������ ��������� , <VID>\n",MSG_CMD_CON_CREATE_ERR},
        {"������� �����!\n",MSG_CMD_DELETE_TEMPTY},
        {"VIN %s �� ������ : ( \n",MSG_CMD_DELETE_VNF},
        {"������� ������ � �������!\n",MSG_CMD_DELETE_EFT},
        {"VIN %s ������! \n",MSG_CMD_DELETE_OK},
        {"VIN %s �������� �� ��������� , ������! \n",MSG_CMD_DELETE_ERR2},
        {"������� ������ . ��������� <VIN> \n",MSG_CMD_DELETE_CON_HELP},
        {"������� ����� ����������!",MSG_CMD_DELETE_CON_ERR},
        {"����������� ������ ��� �� �� ������ ������������� VIN \n",MSG_CMD_EDIT_ERR1},
        {"��� �������! ������ ������������� \n",MSG_CMD_EDIT_ERR1},
        {"�� �� ����� ������ ����� ����� BY \n",MSG_CMD_EDIT_ERR2},
        {"�� ����������� ������ ������� ������! \n",MSG_CMD_EDIT_MSG1},
        {"���� Fullname : %s\n",MSG_CMD_EDIT_BF},
        {"����� Fullname : %s\n OK! \n",MSG_CMD_EDIT_AF},
        {"���� Brand : %s\n",MSG_CMD_EDIT_BB},
        {"����� Brand : %s\n OK! \n",MSG_CMD_EDIT_AB},
        {"���� Model : %s\n",MSG_CMD_EDIT_BM},
        {"����� Model : %s\n OK! \n",MSG_CMD_EDIT_AM},
        {"����������� ������ ��� �� �� ������ ������������� VIN \n",MSG_CMD_EDIT_ERR3},
        {"�����!\n",MSG_CMD_EDIT_OK},
        {"<������ �����> \n ",MSG_CMD_EDIT_CON_ERR},
        {"������������� ������� . ��������� <����� ������> ; <��� �������>  by <�������> <������> \n ",MSG_CMD_EDIT_CON_HELP},
        {"���� %s �� ������ \n",MSG_CMD_LOAD_FNF},
        {"������ �������� �����! \n",MSG_CMD_LOAD_FOE},
        {"\n ���������� ������ : %i \n",MSG_CMD_LOAD_MSG1},
        {"�� ���� ������� ��� ������� %s ����",MSG_CMD_LOAD_ERRIO},
        {"���� %s , ���� %s\n",MSG_CMD_LOAD_MSG2},
        {"\n ������ [%s] �� ��������� ����� ����������� \n",MSG_CMD_LOAD_ERRPASS},
        {"������ OK!\n",MSG_CMD_LOAD_POK},
        {"������ ��� ���������� . ��������� [%s] � [%s]\n",MSG_CMD_LOAD_PWE},
        {"������ [%s] �� ������������� ����� �����������, �������� ������ ����� ... \n",MSG_CMD_LOAD_PWEERR},
        {"��������, �� ���� �������. ������ �� ������������� \n",MSG_CMD_LOAD_PNM},
        {"������ � ������ <������ ���>; <�����>; <������>; \n",MSG_CMD_LOAD_ERR1},
        {"������ � ������ <�����>; <������>; \n",MSG_CMD_LOAD_ERR2},
        {"������ � ������ <������> ; \n",MSG_CMD_LOAD_ERR3},
        {"������������ : [%s] [%s] \n",MSG_CMD_LOAD_S},
        {"�������� OK! ����� : %i ������� \n",MSG_CMD_LOAD_OK},
        {"������ ����� <��� �����> <����>\n",MSG_CMD_LOAD_EIP},
        {"����������� ������������� ������! ������ ������ ... ����� %i ������� \n",MSG_CMD_LOAD_DE},
        {"����������: %s key_file target_file output_file \n",MSG_CMD_LOAD_HELP},
        {"������ ����������� ������ ������?! Y / N \n",MSG_CMD_LOAD_Q},
        {"������... \n",MSG_CMD_LOAD_CANS},
        {"\n � s_loaded_file . ������� ���� �������� [%s] \n",MSG_CMD_LOAD_MSG3},
        {"�� ������� ��������� \'�������!\'\n",MSG_CMD_SAVE_ERR},
        {"���������� OK!\n",MSG_CMD_SAVE_OK},
        {"�� ������� ��������� \'�������!\'\n",MSG_CMD_SAVE_ERR1},
        {"%i ������ : \n",MSG_CMD_SAVE_MSG1},
        {"���������� � ���������� OK! \n",MSG_CMD_SAVE_EOK},
        {"sz_user_key : %i ���������� : %i \n",MSG_CMD_SAVE_CON_MSG1},
        {"�������� ���� <��� �����> <����> <encrypt> \n",MSG_CMD_SAVE_CON_ERR},
        {"�������� ��� ����� . ����������� A-z � 0-9 ������ ����� \n",MSG_CMD_SAVE_CON_ERR2},
        {"������ ����� \n",MSG_CMD_SEARCH_ERR1},
        {"�� ��������� �������� <���> <������>\n",MSG_CMD_SEARCH_ERR2},
        {"�� ������� : ( \n",MSG_CMD_SEARCH_ERR3},
        {"��� <���> ��� <�������> <������>\n",MSG_CMD_SEARCH_CON_HELP},
        {"���������� ������������� ���� ������� ! \n",MSG_CMD_SORT_ERR1},
        {"���������� ����� : %i, desc : %i \n",MSG_CMD_SORT_MSG1},
        {"-----------------------����� ����������-------------------------\n",MSG_CMD_SORT_MSG2},
        {" \n ����� ���������� �������: [%s] == MIN : [%s]\n\n",MSG_CMD_SORT_MSG3},
        {"-----����� �������-------%s-------;------ \n",MSG_CMD_SORT_MSG4},
        {"-------------�����----------- \n",MSG_CMD_SORT_MSG5},
        {"���������� ���������! \n",MSG_CMD_SORT_OK},
        {"���������� �� VIN �� ��������� . ������, ��� �� ������� \n",MSG_CMD_SORT_HELP},
        {"���������� �� VIN �� ���������. ������, ������ ���� \"by\" ������ \n",MSG_CMD_SORT_HELP1},
        {"���������� �� VIN �� ��������� \n",MSG_CMD_SORT_HELP2},
        {"������� ��������� \n",MSG_CMD_STRUCT_TOOLS_DEBUG},
        {"������� �������� \n",MSG_CMD_STRUCT_TOOLS_DEBUGON},
         {"������� �� ������ : %i �������!\n",MSG_CMD_STRUCT_TOOLS_DESTRUCT},
         {"������ ����������� ... %s\n",MSG_CMD_UNIST_STALOG},
         {"��������� Logfile.log \n",MSG_CMD_UNIST_MSG}

    }

};

int change_lang(){
    LANG_MSG_BOX * current_lang = lbox[short_lang_data];
    if(current_lang == lbox[EN_EN]){
        current_lang = lbox[EN_RU];
        short_lang_data = EN_RU;
    }else{
        current_lang = lbox[EN_EN];
        short_lang_data = EN_EN;
    }
    return 0;
}

const char * pmsg(int id_msg){
    LANG_MSG_BOX * current_lang = lbox[short_lang_data];
    return current_lang[id_msg].msg_name;
}
