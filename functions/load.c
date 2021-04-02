#ifndef _LOAD_H
    #include "load.h"
#endif // _LOAD_H

#define RD_BLOCK 500
#define CON_DEF_FILENAME "db.bin"
#define CON_STRING 1024

int try_load(struct list_box ** s_t1,char * sz_user_key,const char * filename){ //функция загрузки базы данных с файла с поддержкой шифрования
    if( access( filename, R_OK ) == -1 ) { // если нет доступа к файлу - то выходим с функции
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FNF),filename);
        return 2;
    }
    FILE *fp;int i_count = 0;char loaded_key[1024];short is_nmadecr = 0;
    FILE *fo;char ss1[254] = {0},ss2[254] = {0},ss3[254] = {0};
    char ss4[254] = {0} ;short is_encypt = 0;
    char tempfile [] = "temp.bin"; // устанавливаем загрузку с стандартного файла
    // try open files
    if((fp = fopen(filename, "rb")) == NULL){ // если файл не загружается , выйти с функции
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FOE));
        fclose(fp);
        return 2;
    }
	if (!(fo = fopen(tempfile, "wb"))) { // (бинарный режим записи) прервать функцию , если не откроется файл
		fclose(fp);
		fclose(fo);
		remove(tempfile);
		return 2;
	}
    short try_attempts = 0;
    while(try_attempts != 2){
        if(try_attempts == 1){
            // check if key valid
            // ENCRYPT DECRYPT
            // PREPARE VARIABLES
            unsigned char n = 0, m = 0,
                j = 0,
                s[256];			// ("s-list_box") для RC4

                                // generated. the majority of ciphers use a fixed s-list_box.

            size_t i, bytes_read, key_len = strlen(sz_user_key);
            int i_count_bytes = 0;
            if(key_len){
                unsigned char data[RD_BLOCK]; // Наше хранилище данных для открытого текста / зашифрованного текста
                    // Инициализация s-list_box
                for (i = 0; i < 256; i++) s[i] = (char)i;

                for (i = 0; i < 256; i++) {
                    j = (j + s[i] + sz_user_key[i % key_len]) % 256;
                    swap_byte(&s[i], &s[j]);
                }
                    //END
                // try decrypt

                fclose(fp);
                fprintf_log(filelog,stdout,"%s filename \n ",filename);
                if((fp = fopen(filename, "rb")) == NULL){
                    fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FOE));
                    fclose(fp);
                    return 2;
                }

                while ((bytes_read = fread(data, 1, 1, fp)) > 0) {
                    for (i = 0; i < bytes_read; i++) {
                        // generate byte
                        m = (m + 1) % 256;
                        n = (n + s[m]) % 256;
                        swap_byte(&s[m], &s[n]); // меняем местами байты

                        data[i] ^= s[(s[m] + s[n]) % 256];
                    }
                    i_count_bytes++;
                    fwrite(data, 1, bytes_read, fo); // записываем в файл строку


                }
            }

            if(debug_mode)fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_MSG1),i_count_bytes);
            fclose(fo);
            if (!(fo = fopen(tempfile, "r"))) { // если темп файл нельзя прочитать,выйдет с функции
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERRIO),tempfile );
                fclose(fp);
                fclose(fo);
                remove(tempfile);
                return 2;
            }
            fgets(loaded_key, sizeof (loaded_key), fo); // получаем пароль
            loaded_key[strlen(loaded_key)-1] = 0; // удаляем \n
            if(debug_mode && (!is_gui))printf(pmsg(MSG_CMD_LOAD_MSG2),loaded_key,sz_user_key);
            if(!strcmp(loaded_key,sz_user_key)==0){ // если пароь не совпадает
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERRPASS),sz_user_key);
                is_nmadecr = 1;
            }else{
                fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_POK));
                is_encypt = 1;
                break;
            }
        }
        if(try_attempts == 0){
            fclose(fp);
            if((fp = fopen(filename, "r")) == NULL){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FOE));
                fclose(fp);
                return 2;
            }

            fgets(loaded_key, sizeof (loaded_key), fp);
            if(loaded_key[strlen(loaded_key)-1] == '\n'){  // удаляем лишний символ переноса строки
                loaded_key[strlen(loaded_key)-1] = 0;
            }
            if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_PWE),loaded_key,sz_user_key);
            if(strcmp(loaded_key,sz_user_key)==0){
                fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_POK));
                break;
            }else{
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_PWEERR),sz_user_key);

            }
        }
        try_attempts++;

    }
    if(is_nmadecr == 1){
        fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_PNM));
        fclose(fo);
        fclose(fp);
        remove(tempfile);
        return 2;
    }


    // END
    // with encrypt
    if(is_encypt){
        fflush(stdin); // очищаем буфер ввода
        i_count = 0;
        char sz_1str[1024] = {0};
        while(2 == fscanf(fo,"%s %[^\n]\n",ss1,sz_1str)){

            fprintf_log(filelog,stdout,"[%s] , [%s] \n",ss1,sz_1str);
            int i_s1 = 0;int i_max_sza = 3;
            char *p = strtok (sz_1str, ";");
            char *sz_array[i_max_sza];int i_s3 = 0;
            for(;i_s3 < i_max_sza;i_s3++){ //обнуляем наш массив
                sz_array[i_s3] = "";
            }
            while (p != NULL)
            {
                if(i_s1 == i_max_sza) break;
                sz_array[i_s1++] = p;
                p = strtok (NULL, ";"); // разделяем и сохраняем с помощью разделителя l в наш массив
            }
            strcpy(ss2,sz_array[0]);
            strcpy(ss3,sz_array[1]);
            strcpy(ss4,sz_array[2]);
            if(strlen(sz_array[0]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERR1));
                continue;
            }else if(strlen(sz_array[1]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERR2));
                continue;
            }else if(strlen(sz_array[2]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERR3));
                continue;
            }
            create(ss1,s_t1,ss2,ss3,ss4); // вызываем функцию создания записи
            i_count++;
        }
    }else{ // без шифрования
        i_count = 0;
        fflush(stdin);
        char sz_1str[1024] = {0};
        while(2 == fscanf(fp,"%s %[^\n]\n",ss1,sz_1str)){  // считываем строки
            int i_s1 = 0;
            if(debug_mode) fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_S),ss1,sz_1str);
            char *p = strtok (sz_1str, ";"); // разделяем строку и сохраняем в массив
            int i_max_sza = 3;
            char *sz_array[i_max_sza];int i_s3 = 0;
            for(;i_s3 < i_max_sza;i_s3++){
                sz_array[i_s3] = "";
            }
            while (p != NULL)
            {
                if(i_s1 == i_max_sza) break;
                sz_array[i_s1++] = p;
                p = strtok (NULL, ";");
            }
            strcpy(ss2,sz_array[0]);
            strcpy(ss3,sz_array[1]);
            strcpy(ss4,sz_array[2]);
            if(strlen(sz_array[0]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERR1));
                continue;
            }else if(strlen(sz_array[1]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERR2));
                continue;
            }else if(strlen(sz_array[2]) == 0){
                fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_ERR3));
                continue;
            }
            create(ss1,s_t1,ss2,ss3,ss4); // пытаемся создать запись
        }

    }

    // close files
    fclose(fo);
    fclose(fp);
    remove(tempfile); // удаляем временный файл
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_OK),i_count);
    return 0;
}

int con_load(struct list_box ** s_t1){ //консольная команда для загрузки б.д.
    char sz_user_key[254] = {0},filename[254] = {0};
    char str[CON_STRING];
    fgets (str, CON_STRING-1, stdin);
    if(sscanf(str,"%253s %253s",filename,sz_user_key) > 1){ // считываем строку
        try_load(s_t1,filename,sz_user_key);
    }else{
        if((strlen(sz_user_key) == 0) && (strlen(filename) == 0)){ // если введено тотлько слово Load
            strcpy(filename,CON_DEF_FILENAME);
            strcpy(sz_user_key,"");
            try_load(s_t1,sz_user_key,filename);
            return 0;
        }else if(strlen(sz_user_key) == 0){ // если ключ не введен
            strcpy(sz_user_key,"");
            try_load(s_t1,sz_user_key,filename);
            return 0;
        }else{
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_EIP));
            return 2;
        }
    }
    fflush(stdin);
    try_load(s_t1,sz_user_key,filename);
    return 0;
}

int s_loaded_file(struct list_box ** s_temp,int argc, char * argv[]){ //чтение файла расшифровки , дешифровки
    // argv must be not a parameter to be load
    int i_argv = 0;
    for(;i_argv<argc;i_argv++){ // проверяем наличия символа - в аргументах ,
        if(strlen(argv[i_argv]) != 0){
            if(argv[i_argv][0] == '-'){
                return 0;
            }
        }
    }
    char current_key[254] = {0};short is_keynotafile = 0;
    fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_DE),argc-1);
	if (argc != 3) {

		fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_HELP), argv[0]);
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_Q));
        char is_true[1];
        scanf("%1c",is_true);
        fflush(stdin); // очищаем поток ввода
        if(is_true[0] == 'y' || is_true[0] == 'Y'){
            fprintf_log(filelog,stdout,"PASSWD>");
            scanf("%253[^\n]\n",current_key);
            fflush(stdin);is_keynotafile = 1;
        }else{
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_CANS));
            return 2;
        }
	}
	if(!is_keynotafile){
        FILE * fp;
        if((fp = fopen(argv[2], "r")) == NULL){ // если файл не открылся , прервать работу функции
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_LOAD_FOE));
            fclose(fp);
            return 2;
        }

        fgets(current_key, sizeof (current_key), fp);
        if(current_key[strlen(current_key)-1] == '\n'){ // удаляем лишний символ переноса строки
            current_key[strlen(current_key)-1] = 0;
        }
        if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_LOAD_MSG3),current_key);
	}

    try_load(s_temp,current_key,argv[1]); // пытаемся загрузить файлы
	return 0;
}
