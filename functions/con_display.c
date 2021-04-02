#include "con_display.h"

//показать все записи в таблице , без полной информации ( VIN и Владелец )
void show_table(struct list_box * newbox){ // показать все записи
    if(!is_gui){
        int items = 0; //устанавливаем счетчик
        fprintf_log(filelog,stdout,"_______________________________________________________________________________________\n");
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_DISPLAY_HEAD) );
        while(newbox != NULL){ // начинаем перебирать все записи , пока не достигнем NULL
            char sz_arr[4][1024]; // сохраняем для удобства в двумерный массив информацию с VIN
            strcpy(sz_arr[0],ell(newbox->VIN,14));
            strcpy(sz_arr[1],ell(newbox->Fullname,21));
            strcpy(sz_arr[2],ell(newbox->Model,16) );
            strcpy(sz_arr[3],ell(newbox->Brand,15) );
            fprintf_log(filelog,stdout,"|%-18s|%-25s|%-19s|%-20s|\n",sz_arr[0],sz_arr[1],sz_arr[2],sz_arr[3] );
            items++;
            newbox = newbox->next; // переходим к следующей записи
        }
        if(!items){ // если 0 записей
            fprintf_log(filelog,stderr,pmsg(MSG_CMD_DISPLAY_NOENT));
        }else{ // показывает количество найденных записей
            fprintf_log(filelog,stdout,pmsg(MSG_CMD_DISPLAY_TOTAL),items);
        }
    }
}
