#include "sort.h"
#define CON_SORT_STR 1024

void try_sort(struct list_box ** s_t1,char * by_name,char * sz_is_desc){ // функция сортировки элементов
    struct list_box * s_check = *s_t1;
    if(get_countofrec(s_check) == 1){ // проверка , если одна запись , то выйти из функции .
        fprintf_log(filelog,stdout,"Can't sort one element ! \n");
        return;
    }
    int is_desc = 0,i_passes = 0;
    //check sz_is_desc
    if(strcmp_multi_i(sz_is_desc,"1") == 0 || strcmp_multi_i(sz_is_desc,"desc") == 0) is_desc = 1; // устанавливаем флаг переменную , если пришел агрумент с desc , что означает "сортировка по убыванию"
    //end
    // check by_name
    int i_method = 0; // стандартно метод сортировки на 0
    // Устанавливаем метод сортировки , если был передан соответствующий аргумент
    if( (strcmp_multi_i(by_name,"VIN") == 0) || (strcmp_multi_i(by_name,"0") == 0) ) i_method = 0;
    else if( (strcmp_multi_i(by_name,"Fullname") == 0) || (strcmp_multi_i(by_name,"1") == 0 )) i_method = 1;
    else if( (strcmp_multi_i(by_name,"Brand") == 0) || (strcmp_multi_i(by_name,"2") == 0 ))  i_method = 2;
    else if( (strcmp_multi_i(by_name,"Model") == 0) || (strcmp_multi_i(by_name,"3") == 0 )) i_method = 3;
    // END
    if(debug_mode) { fprintf_log(filelog,stdout,"Using method : %i, desc : %i \n",i_method,is_desc); };
    struct list_box * s_i = *s_t1;
    struct list_box * s_i_start = s_i;

    for(; s_i != NULL ; s_i = s_i->next){

        //show_table(s_i);
        struct list_box * min = s_i;
        struct list_box * s_j;
        switch(i_method){
            case 0 :{ // находим найменший символ ASCII по VIN
                for(s_j=s_i->next;s_j != NULL;s_j = s_j->next ){
                    int i1 = 0;
                    int l1 = strlen(min->VIN),l2 = strlen(s_j->VIN);
                    while(((int)min->VIN[i1] == ((int)s_j->VIN[i1])) && l1 != i1 && l2 != i1 ) i1++;
                    if(is_desc){
                        if( ((int)min->VIN[i1]) < ((int)s_j->VIN[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->VIN[0]),((int)s_j->VIN[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->VIN[0]),(int)s_j->VIN[0]);
                        }
                    }else{
                        if( ((int)min->VIN[i1]) > ((int)s_j->VIN[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->VIN[0]),((int)s_j->VIN[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->VIN[0]),(int)s_j->VIN[0]);
                        }
                    }

                }
                break;
            }
            case 1 :{ // находим найменший символ ASCII по ФИО
                for(s_j=s_i->next;s_j != NULL;s_j = s_j->next ){
                    int i1 = 0;
                    int l1 = strlen(min->Fullname),l2 = strlen(s_j->Fullname);
                    while(((int)min->Fullname[i1] == ((int)s_j->Fullname[i1])) && l1 != i1 && l2 != i1 ) i1++;
                    if(is_desc){
                        if( ((int)min->Fullname[i1]) < ((int)s_j->Fullname[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->Fullname[0]),((int)s_j->Fullname[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i]\n",((int)min->Fullname[0]),(int)s_j->Fullname[0]);
                        }
                    }else{
                        if( ((int)min->Fullname[i1]) > ((int)s_j->Fullname[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->Fullname[0]),((int)s_j->Fullname[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->Fullname[0]),(int)s_j->Fullname[0]);
                        }
                    }

                }
                break;
            }
            case 2 :{ // находим найменший символ ASCII по Бренду
                for(s_j=s_i->next;s_j != NULL;s_j = s_j->next ){
                    int i1 = 0;
                    int l1 = strlen(min->Brand),l2 = strlen(s_j->Brand);
                    while(((int)min->Brand[i1] == ((int)s_j->Brand[i1])) && l1 != i1 && l2 != i1 ) i1++;
                    if(is_desc){
                        if( ((int)min->Brand[i1]) < ((int)s_j->Brand[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->Brand[0]),((int)s_j->Brand[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->Brand[0]),(int)s_j->Brand[0]);
                        }
                    }else{
                        if( ((int)min->Brand[i1]) > ((int)s_j->Brand[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->Brand[0]),((int)s_j->Brand[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->Brand[0]),(int)s_j->Brand[0]);
                        }
                    }

                }
                break;
            }
            case 3 :{ //находим найменший символ ASCIIпо модели
                for(s_j=s_i->next;s_j != NULL;s_j = s_j->next ){
                    int i1 = 0;
                    int l1 = strlen(min->Model),l2 = strlen(s_j->Model);
                    while(((int)min->Model[i1] == ((int)s_j->Model[i1])) && l1 != i1 && l2 != i1 ) i1++;
                    if(is_desc){
                        if( ((int)min->Model[i1]) < ((int)s_j->Model[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->Model[0]),((int)s_j->Model[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->Model[0]),(int)s_j->Model[0]);
                        }
                    }else{
                        if( ((int)min->Model[i1]) > ((int)s_j->Model[i1])){
                        if(debug_mode) fprintf_log(filelog,stdout,"%i > %i \n",((int)min->Model[0]),((int)s_j->Model[0]));
                            min = s_j;
                        }else{
                            if(debug_mode) fprintf_log(filelog,stdout,"continue [%i < %i] \n",((int)min->Model[0]),(int)s_j->Model[0]);
                        }
                    }

                }
                break;
            }
        }
        // we have min->next pointer
        // создаем временные хранилища для указателей , чтобы потом ими оперировать
        struct list_box * s_temp_i = s_i;
        struct list_box * s_temp_in = s_i;
        struct list_box * s_temp_n = min->next;
        struct list_box * s_temp_p = NULL;
        // ger previous
        if(debug_mode){
            if(!is_gui) system("cls && clear"); // очищаем экран
        }
        if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_MSG2));
        if(debug_mode) show_table(s_i); // отображаем текущий список всех зяписей
        if(debug_mode) fprintf_log(filelog,stdout,"____________________________VIN____________________________\n");
        if(debug_mode) fprintf_log(filelog,stdout,"******************@@@@@@@@@@ %s @@@@@@@@@@******************\n",min->VIN);
        if(debug_mode) fprintf_log(filelog,stdout,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~ %i ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",i_passes);
        if(s_i == min){
            i_passes++;
            s_i = min;
            continue;
        }
        while((s_temp_i->next != NULL )){
            if(s_temp_p != NULL){
                if(s_temp_p->next == min ) break;
            }
            if(s_temp_p == NULL){
                if(debug_mode) fprintf_log(filelog,stdout,"s_temp_p == NULL\n");
            }else{
                if(debug_mode) fprintf_log(filelog,stdout,"s_temp_p == %s\n",s_temp_p->VIN);
            }
            s_temp_p = s_temp_i; // save previous element
            s_temp_i = s_temp_i->next;

        }
        // Напечатать предыдущий элемент и сравнить с min
        if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_MSG3),s_temp_p->VIN,min->VIN );
        // end
        if(debug_mode){
                if(!is_gui)getchar();
        }
        if(s_temp_p != NULL){
            if(s_temp_p != s_temp_in){
                min->next = s_temp_in->next;
                s_temp_p->next = s_temp_in;
                s_temp_in->next = s_temp_n;
            }else{
                min->next = s_temp_in;
                s_temp_in->next = s_temp_n;
            }
        }


        s_i = min;

        if(!i_passes){
             s_i_start = min; // устанавливаем минимальное значение на пизицио по номеру цикла в начало
        }else{
            struct list_box * s_starttemp = s_i_start;
            int i_star = 0;
            while(i_star != (i_passes + 1) ){
                if(i_star == (i_passes-1) ){
                    s_starttemp->next = min;
                }
                if(s_starttemp->next != NULL){
                    s_starttemp = s_starttemp->next;
                }
                i_star++;
            }
        }
        i_passes++;
        if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_MSG4),min->VIN );
        if(debug_mode) show_table(s_i_start);
        if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_MSG5));
        if(debug_mode){
            if(!is_gui) getchar();
        }
    }
    s_i = s_i_start;
    *s_t1 = s_i; // обновим нажу структуру

    if(debug_mode)show_table(*s_t1);
    if(debug_mode) fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_OK));
    clrstdin(); // очистим буфер ввода
}

int con_sort(struct list_box ** s_t1){ //консольный вызов метода сорт
    char is_desc[254] = {0},by_name[254] = {0},by[254] = {0};
    char str[CON_SORT_STR];
    fgets (str, CON_SORT_STR-1, stdin); // получаем строку
    if(sscanf(str,"%253s %253s %253s[^\n]",by,by_name,is_desc) > 0){ // сканирование ввода с клавиатуры
        if(strcmp_multi_i(by,"by") == 0){ // есди найдено слово by
            if(strlen(by_name) != 0){
                clrstdin();
                try_sort(s_t1,by_name,is_desc);
                return 0;
            }else{
                fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_HELP)); // вывести подсказку , то , что имя не введено
                try_sort(s_t1,"","");
                clrstdin();
                return 0;
            }
        }else{
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_HELP1)); // ошибка , должно быть только слово "by"
            try_sort(s_t1,"","");
            clrstdin();
            return 0;
        }
    }else{
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_SORT_HELP2)); // стандартно запускается сортировка по VIN
        try_sort(s_t1,"","");
        clrstdin();
        return 0;
    }
    return 0;
}

