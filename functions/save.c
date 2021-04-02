#ifndef _SAVE_H
    #include "save.h"
#endif // _SAVE_H

#define RD_BLOCK 500
#define CON_DEF_FILENAME "db.bin"
#define CON_STRING 1024

int try_save(struct list_box * s_t1,char * sz_user_key,char * filename,short i_allow_encr){ //функция сохранения базы данных в файл с поддержкой шифрования
    struct list_box * s_temp = s_t1;
    if(!i_allow_encr){
        FILE *fp;
        if((fp = fopen(filename, "w+")) == NULL){
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FOE));
            return 2;
        }
        if(!get_countofrec(s_t1)){
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_SAVE_ERR1));
            fclose(fp);
            return 2;
        }
        int i_count = 0;
        while(s_t1 != NULL){
            if(i_count == 0){
                fprintf(fp,"%s\n",sz_user_key);
            }else{
                fprintf(fp,"%s %s;%s;%s;\n",s_t1->VIN,s_t1->Fullname,s_t1->Brand,s_t1->Model);
                s_t1 = s_t1->next;
            }

            i_count++;
        }
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_SAVE_OK));
        fclose(fp);
    }else{
        FILE *fp;FILE *fo;
        char tempfile[] = "temp.bin";

        if((fp = fopen(filename, "wb")) == NULL){
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FOE));
            return 2;
        }
        if(!get_countofrec(s_t1)){
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_SAVE_ERR1));
            fclose(fp);
            return 2;
        }
        if (!(fo = fopen(tempfile, "w+"))) {
            fclose(fp);
            fclose(fo);
            remove(tempfile);
            return 2;
        }

        // check if key valid
        // ENCRYPT DECRYPT
        // PREPARE VARIABLES
        unsigned char n = 0, m = 0,
            j = 0,
            s[256];			// ("s-list_box") for RC4

                            // generated. the majority of ciphers use a fixed s-list_box.

        size_t i, bytes_read, key_len = strlen(sz_user_key);

        unsigned char data[RD_BLOCK]; // our data store for plaintext/ciphertext
            // s-list_box initialization
        for (i = 0; i < 256; i++) s[i] = (char)i;

        for (i = 0; i < 256; i++) {
            j = (j + s[i] + sz_user_key[i % key_len]) % 256;
            swap_byte(&s[i], &s[j]);
        }
            //END
        // try encrypt

        int i_count = 0;
        while(s_temp != NULL){
            if(i_count == 0){
                fprintf(fo,"%s\n",sz_user_key);
            }else{
                fprintf(fo,"%s %s;%s;%s;\n",s_temp->VIN,s_temp->Fullname,s_temp->Brand,s_temp->Model);
                s_temp = s_temp->next;
            }

            i_count++;
        }

        fprintf_log(filelog,stdout,"[%i]",i_count);
        fclose(fo);
        // что-то страшное происходит и добавляет строки . Выключаем режим записи для fo
        if (!(fo = fopen(tempfile, "r"))) {
            fclose(fp);
            fclose(fo);
            remove(tempfile);
            return 2;
        }
        int i_count_bytes = 0;
        while ((bytes_read = fread(data, 1, 1, fo)) > 0) {
            for (i = 0; i < bytes_read; i++) {

                // generate byte
                m = (m + 1) % 256;
                n = (n + s[m]) % 256;
                swap_byte(&s[m], &s[n]);

                data[i] ^= s[(s[m] + s[n]) % 256];
            }
            fwrite(data, 1, bytes_read, fp);
            i_count_bytes++;
        }
        if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_SAVE_MSG1),i_count_bytes);
        fclose(fp);
        fclose(fo);
        remove(tempfile);
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_SAVE_EOK));

    }
    return 0;
}


int con_save(struct list_box * s_t1){ //консольная команда для сохранения б.д
    char sz_user_key[254] = {0},filename[254] = {0},encrypt[254] = {0};
    short is_encrypt = 0;
    char str[CON_STRING];
    fgets (str, CON_STRING-1, stdin);
    if(sscanf(str,"%253s %253s %253s",filename,sz_user_key,encrypt) > 1){
        if(strcmp_multi_i(encrypt,"encrypt") == 0) is_encrypt = 1;
    }else{
        if(debug_mode)fprintf_log(filelog,stdout,pmsg(MSG_CMD_SAVE_CON_MSG1),(int)strlen(sz_user_key),(int)strlen(encrypt));
        if(strlen(sz_user_key) == 0 && strlen(encrypt) == 0 && strlen(filename) == 0){
            strcpy(sz_user_key,"");
            strcpy(filename,CON_DEF_FILENAME);
            try_save(s_t1,sz_user_key,filename,is_encrypt);
            return 0;
        }else if(strlen(sz_user_key) == 0 && strlen(encrypt) == 0){
            strcpy(sz_user_key,"");
            if(!check_filename(filename)) return 2;
            try_save(s_t1,sz_user_key,filename,is_encrypt);
            return 0;
        }
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_SAVE_CON_ERR));
        fflush(stdin);
        return 2;
    }
    fflush(stdin);
    try_save(s_t1,sz_user_key,filename,is_encrypt);
    return 0;
}

int check_filename(char * filename){ //защита от посторонних символов при сохранении в файл для функции try_save
    int i_valid = 0;
    if ( (filename[0] >= 'A' && filename[0] <= 'Z') || (filename[0] >= 'a' && filename[0] <= 'z' ) || (filename[0] >= '0' && filename[0] <= '9' ) ){
        i_valid = 1;
    }else{
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_SAVE_CON_ERR2));
    }
    return i_valid;
}

