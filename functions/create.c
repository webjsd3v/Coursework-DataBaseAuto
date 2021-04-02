#include "create.h"

#define I_MAX_STRING 1023
int create(char * VIN,struct list_box ** s1,char * fFullname,char * fBrand,char * fModel){ //create new note
    int is_file = 0;
    if(fFullname != NULL && fBrand != NULL && fModel !=NULL) is_file = 1;
    if(!is_duplicate(VIN,*s1)){
        char Fullname[128] = {0},Brand[128] = {0},Model[128] = {0};
        if(!is_file ){
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_CREATE_HELP));
            char sz_1str[I_MAX_STRING];
            fgets (sz_1str, I_MAX_STRING, stdin);
            int i_s1 = 0;int i_max_sza = 3;
            char *p = strtok (sz_1str, ";");
            char * sz_array[i_max_sza];int i_s3 = 0;
            for(;i_s3 < i_max_sza;i_s3++){
                sz_array[i_s3] = "";
            }
            while (p != NULL)
            {
                if(i_s1 == i_max_sza) break;
                sz_array[i_s1++] = p;
                p = strtok (NULL, ";");
            }
            if(sz_array[2][strlen(sz_array[2])-1] == '\n') sz_array[2][strlen(sz_array[2])-1] = '\0';
            strcpy(Fullname,sz_array[0]);
            strcpy(Brand,sz_array[1]);
            strcpy(Model,sz_array[2]);
            if(strlen(sz_array[0]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_CREATE_ERR1));
                return 2;
            }else if(strlen(sz_array[1]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_CREATE_ERR2));
                return 2;
            }else if(strlen(sz_array[2]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_CREATE_ERR3));
                return 2;
            }
        }

        if(is_file){

            strcpy(Fullname,fFullname);
            strcpy(Brand,fBrand);
            strcpy(Model,fModel);

        }
        struct list_box * tempS = (struct list_box*)malloc(sizeof(struct list_box));
        if(tempS == NULL){
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_CREATE_ERRMEM));exit(1); // если памяти нет
        }
        tempS->Fullname = strdup(Fullname);
        tempS->Brand = strdup(Brand);
        tempS->Model = strdup(Model);
        tempS->VIN = strdup(VIN);
        tempS->next = *s1;
        if(debug_mode) show_current_line(tempS,1); // Показать созданную строку
        *s1 = tempS;
        if(!is_file) fprintf_log(filelog,stdout,pmsg(MSG_CMD_CREATE_OK));
        clrstdin();

    }else{
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_CREATE_ALLRE),VIN);
        return 2;
    }

    return 0;
}

void con_create(struct list_box ** s_temp){ // консольный вызов функции create
    int is_valid_cr = 1;
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_CON_CREATE_HELP));
    char VIN[32];
    if(1 != scanf("%31s",VIN)){
        fprintf_log(filelog,stdout,"\n");
        is_valid_cr = 0;
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_CON_CREATE_ERR));
        clrstdin();
    }else{
        clrstdin();
        fprintf_log(filelog,stdout,"[%s]OK\n",VIN);
        if(is_valid_cr){
            create(VIN,&*s_temp,NULL,NULL,NULL);
        }
    }
}

/* proverka, na unikalbnostbn VIN */
/* --- START --- */


