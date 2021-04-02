#ifndef _SEARCH_H
    #include "search.h"
#endif // _SEARCH_H
#define MAX_INPUT_SEARCH 254
//искать по всей структуре , вывести все совпадения
list_box ** search_any(char * str,struct list_box * s_temp,char * where, char * s_name, char * sz_mod , struct list_box ** s_array ){
    fprintf_log(filelog,stdout,"_______________________________________________________________________________________\n");
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_DISPLAY_HEAD));
    int i_co_str = 0;
    short if_success = 0;
    struct list_box * s_t2 = s_temp;




    if(strcmp(where,"where") == 0 ){ // если найдено слово where

        if((s_name != NULL) && (sz_mod != NULL)){
            while(s_t2 != NULL){

                if(strcmp_multi_i(s_name,"VIN") == 0 ){
                    if(
                        (strstr(sz_mod,s_t2->VIN) != NULL )         &&
                        (

                        (strstr(s_t2->Fullname,str) != NULL)        ||
                        (strstr(s_t2->Brand,str) != NULL)           ||
                        (strstr(s_t2->Model,str) != NULL)           ||
                        (strstr(s_t2->VIN,str) != NULL)

                        )
                       )
                    {
                        if(s_array != NULL ) s_array[i_co_str++] = s_t2;
                        show_current_line(s_t2,0);
                    }
                }else if(strcmp_multi_i(s_name,"Fullname") == 0 ){
                    if(
                        (strstr(sz_mod,s_t2->Fullname) != NULL )         &&
                        (

                        (strstr(s_t2->Fullname,str) != NULL)        ||
                        (strstr(s_t2->Brand,str) != NULL)           ||
                        (strstr(s_t2->Model,str) != NULL)           ||
                        (strstr(s_t2->VIN,str) != NULL)

                        )
                       )
                    {
                        if(s_array != NULL ) s_array[i_co_str++] = s_t2;
                        show_current_line(s_t2,0);
                    }
                }else if(strcmp_multi_i(s_name,"Brand") == 0 ){
                    if(
                        (strstr(sz_mod,s_t2->Brand) != NULL )         &&
                        (

                        (strstr(s_t2->Fullname,str) != NULL)        ||
                        (strstr(s_t2->Brand,str) != NULL)           ||
                        (strstr(s_t2->Model,str) != NULL)           ||
                        (strstr(s_t2->VIN,str) != NULL)

                        )
                       )
                    {
                        if(s_array != NULL ) s_array[i_co_str++] = s_t2;
                        show_current_line(s_t2,0);
                    }
                }else if(strcmp_multi_i(s_name,"Model") == 0 ){
                    if(
                        (strstr(sz_mod,s_t2->Model) != NULL )         &&
                        (

                        (strstr(s_t2->Fullname,str) != NULL)        ||
                        (strstr(s_t2->Brand,str) != NULL)           ||
                        (strstr(s_t2->Model,str) != NULL)           ||
                        (strstr(s_t2->VIN,str) != NULL)

                        )
                       )
                    {
                        if(s_array != NULL ) s_array[i_co_str++] = s_t2;
                        show_current_line(s_t2,0);
                    }
                }else{

                    fprintf_log(filelog,stderr,pmsg(MSG_CMD_SEARCH_ERR1));
                }

                s_t2 = s_t2->next;
            }
        }else{

            fprintf_log(filelog,stdout,pmsg(MSG_CMD_SEARCH_ERR2));
        }

    }else{
        while(s_temp != NULL){
            if( (strstr(s_temp->Fullname,str) != NULL) ||
                (strstr(s_temp->Brand,str) != NULL) ||
                (strstr(s_temp->Model,str) != NULL) ||
                (strstr(s_temp->VIN,str) != NULL)
            ){
                if(s_array != NULL )s_array[i_co_str++] = s_t2;
                show_current_line(s_temp,0);
                if_success = 1;
            }
            s_temp = s_temp->next;

        }
    }



    fprintf_log(filelog,stdout,"|__________________|_________________________|___________________|____________________|\n");
	if(!if_success){
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_SEARCH_ERR3));
            return NULL;
	}

	if(s_array != NULL){
        s_array[++i_co_str] = '\0';

        return s_array;
	}else{
        return NULL;
	}

}

void con_search(struct list_box * struct_list){ //поиск элемента по критериям
    char str[MAX_INPUT_SEARCH];
    char where[11] = {0} ,s_name[MAX_INPUT_SEARCH] = {0},s_mod[MAX_INPUT_SEARCH] = {0};
    char sz_str[MAX_INPUT_SEARCH] = {0};
    fgets (str, MAX_INPUT_SEARCH-1, stdin);
    if(sscanf(str,"%253s %10s %253s %253s",sz_str,where,s_name,s_mod) != 0){

        if( (strcmp(where,"where") != 0) && (strlen(s_name) == 0) && (strlen(s_mod) == 0 ) && strlen(sz_str) == 0) {
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_SEARCH_CON_HELP));
            return;
        }else if( (strcmp(where,"where") != 0) && (strlen(s_name) == 0) && (strlen(s_mod) == 0 ) ) {
            system("pause");
            search_any(sz_str,struct_list,"","","",NULL);
            return;
        }else if( (strlen(s_name) == 0 && strlen(s_mod) == 0 ) ){
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_SEARCH_CON_HELP));
            return;
        }else if (strlen(s_mod) == 0){
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_SEARCH_CON_HELP));
            return;
        }else{
            search_any(sz_str,struct_list,where,s_name,s_mod,NULL);
            return;
        }

    }
}
