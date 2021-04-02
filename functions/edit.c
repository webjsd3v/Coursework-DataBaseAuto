#ifndef _EDIT_H
    #include "edit.h"
#endif // _EDIT_H

int edit_struct(struct list_box ** s_t1,int el_num,char * sz_mod, char * by,char * s_name,char * str_name){ //функция редактирования элемента
   struct list_box * s_temp = *s_t1;
   if(el_num == -1){
    fprintf_log(filelog,stderr,pmsg(MSG_CMD_EDIT_ERR1));
    return 2;
   }
    if(!get_countofrec(s_temp)){ // если у нас не 0 записей
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_EDIT_ERR2));
        return 1;
    }
    if(strcmp_multi_i(by,"by") == 0){ // если обнаружено слово by
        if((strcmp_multi_i(s_name,"Fullname") == 0) && (str_name != NULL)){
            // replace all with this name in Full name column
            by_Fullname(s_t1,str_name,sz_mod,el_num);
            return 0;
        }
        if((strcmp_multi_i(s_name,"Brand") == 0) && (str_name != NULL)){
            by_Brand(s_t1,str_name,sz_mod,el_num);
            return 0;
        }
        if((strcmp_multi_i(s_name,"Model") == 0) && (str_name != NULL)){
            by_Model(s_t1,str_name,sz_mod,el_num);
            return 0;
        }
        if((strcmp_multi_i(s_name,"VIN") == 0) && (str_name != NULL)){
            by_VIN(s_t1,str_name,sz_mod,el_num);
            return 0;
        }
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_ERR3));
    }
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_MSG1));
    switch(el_num){
        case 0 : {
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BF),s_temp->Fullname);
            strcpy(s_temp->Fullname,sz_mod);
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AF),s_temp->Fullname);
            break;
        }
        case 1 : {
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BB),s_temp->Brand);
            strcpy(s_temp->Brand,sz_mod);
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AB),s_temp->Brand);
            break;
        }
        case 2 : {
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BM),s_temp->Model);
            strcpy(s_temp->Model,sz_mod);
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AM),s_temp->Model);
            break;
        }
        default : {
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_EDIT_ERR3));
        }
    }

    return 0;
}

void by_Fullname(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column){ //доп. функция для редактирование в конкретной колонке Fullname
    struct list_box * s_t1 = *s_temp;
    while(s_t1 != NULL){
        switch(i_column){
             case 0 :{
                if(strstr(s_t1->Fullname,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BF),s_t1->Fullname);
                    strcpy(s_t1->Fullname,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AF),s_t1->Fullname);
                }
                break;
            }
             case 1 :{
                if(strstr(s_t1->Fullname,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BB),s_t1->Brand);
                    strcpy(s_t1->Brand,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AB),s_t1->Brand);
                }
                break;
            }
             case 2 :{
                if(strstr(s_t1->Fullname,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BM),s_t1->Model);
                    strcpy(s_t1->Model,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AM),s_t1->Model);
                }
                break;
            }
            default : {
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_EDIT_ERR3));
            }
        }


        s_t1 = s_t1->next;
    }
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_OK));
}

void by_Brand(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column){ //доп. функция для редактирование в конкретной колонке Model
    struct list_box * s_t1 = *s_temp;
    while(s_t1 != NULL){
        switch(i_column){
             case 0 :{
                if(strstr(s_t1->Brand,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BF),s_t1->Fullname);
                    strcpy(s_t1->Fullname,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AF),s_t1->Fullname);
                }
                break;
            }
             case 1 :{
                if(strstr(s_t1->Brand,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BB),s_t1->Brand);
                    strcpy(s_t1->Brand,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AB),s_t1->Brand);
                }
                break;
            }
             case 2 :{
                if(strstr(s_t1->Brand,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BM),s_t1->Model);
                    strcpy(s_t1->Model,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AM),s_t1->Model);
                }
                break;
            }
            default : {
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_EDIT_ERR3));
            }
        }

        s_t1 = s_t1->next;
    }
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_OK));
}
void by_Model(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column){ //доп. функция для редактирование в конкретной колонке Model
    struct list_box * s_t1 = *s_temp;
    while(s_t1 != NULL){
        switch(i_column){
             case 0 :{
                if(strstr(s_t1->Model,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BF),s_t1->Fullname);
                    strcpy(s_t1->Fullname,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AF),s_t1->Fullname);
                }
                break;
            }
             case 1 :{
                if(strstr(s_t1->Model,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BB),s_t1->Brand);
                    strcpy(s_t1->Brand,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AB),s_t1->Brand);
                }
                break;
            }
             case 2 :{
                if(strstr(s_t1->Model,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BM),s_t1->Model);
                    strcpy(s_t1->Model,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AM),s_t1->Model);
                }
                break;
            }
            default : {
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_EDIT_ERR3));
            }
        }


        s_t1 = s_t1->next;
    }
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_OK));
}

void by_VIN(struct list_box ** s_temp,char * sz_char,char * sz_replacer,int i_column){ //доп. функция для редактирование в конкретной колонке VIN
    struct list_box * s_t1 = *s_temp;
    while(s_t1 != NULL){
        switch(i_column){
             case 0 :{
                if(strstr(s_t1->VIN,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BF),s_t1->Fullname);
                    strcpy(s_t1->Fullname,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AF),s_t1->Fullname);
                }
                break;
            }
             case 1 :{
                if(strstr(s_t1->VIN,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BB),s_t1->Brand);
                    strcpy(s_t1->Brand,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AB),s_t1->Brand);
                }
                break;
            }
             case 2 :{
                if(strstr(s_t1->VIN,sz_char) !=NULL ){
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_BM),s_t1->Model);
                    strcpy(s_t1->Model,sz_replacer);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_AM),s_t1->Model);
                }
                break;
            }
        }

        s_t1 = s_t1->next;
    }
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_OK));
}

void con_edit(struct list_box ** s_t1){ //консольная команда для редактирование существующего элемента
    char str[1023] = {0};
    fgets (str, 1023, stdin);
    char sz_temp1[254] = {0},sz_temp2[254] = {0};
    char sz_temp3[254] = {0},sz_temp4[10] = {0};
    char sz_temp5[254] = {0}; int i_case = 0;
    char sz_buffer[1024];

    str[strlen(str)-1] = '\0'; // удаляем символ перевода на новую строку

    char *p = strtok (str, ";"); // делим строку на лексемы с разделителем ;
    char *sz_array[3] = {0};
    int i_s1 = 0;
    while (p != NULL)
    {
        sz_array[i_s1++] = p;
        p = strtok (NULL, ";");
    }
    int ii1 = 0;
    for(;ii1 < 2; ii1++){
        if(sz_array[ii1] == NULL){
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_CON_ERR));
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_CON_HELP));
            return;
        }
    }
    strcpy(sz_temp2,sz_array[0]);
    strcpy(sz_buffer,sz_array[1]);
    if(0 < sscanf(sz_buffer,"%253s %253s %253s %253s",sz_temp1,sz_temp3,sz_temp4,sz_temp5 )){
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_CON_ERR));
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_EDIT_CON_HELP));
        return;
    }

    if(strcmp_multi_i(sz_temp1,"Fullname")==0) i_case = 0;
    else if((strcmp_multi_i(sz_temp1,"Model")) == 0) i_case = 1;
    else if((strcmp_multi_i(sz_temp1,"Brand")) == 0) i_case = 2;
    else i_case = -1;
    edit_struct(s_t1,i_case,sz_temp2,sz_temp3,sz_temp4,sz_temp5);

    clrstdin();
}
