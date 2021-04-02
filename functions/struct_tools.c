#ifndef _STRUCT_TOOLS
    #include "struct_tools.h"
#endif // _STRUCT_TOOLS

int get_countofrec(struct list_box * targett){ // показать количество записей в таблице
    struct list_box * target1 = targett;
	int i_count = 0;
	while(target1 != NULL){
		target1  = target1->next;
		i_count++;
	}
	return i_count;
}

void con_debug(){ // включить выкл. режим откладки
    if(debug_mode){
        debug_mode = 0 ; fprintf_log(filelog,stdout,pmsg(MSG_CMD_STRUCT_TOOLS_DEBUG));
    }else{
        debug_mode = 1;
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_STRUCT_TOOLS_DEBUGON));
    }
}

int is_duplicate(char * VIN,struct list_box * db_list){ // проверка , есть ли дупликат елемента
	while(db_list != NULL){
		if(debug_mode) fprintf_log(filelog,stdout,"is_dup*(%s,%s)->\n",VIN,db_list->VIN);
		if(strcmp(VIN,db_list->VIN) == 0) return 1;
		db_list = db_list->next;
	}
	return 0;
}

int destroyStruct(struct list_box ** s_struct){ // уничтожить все данные c list
	int items = 0;
	struct list_box * newbox = *s_struct, *s_temp = NULL;
	while(newbox != NULL){
		s_temp = newbox->next;
        free(newbox->Fullname);
        free(newbox->Brand);
        free(newbox->Model);
        free(newbox->VIN);
		free(newbox);
		newbox = s_temp;
		items++;

	}
	free(newbox);
	*s_struct = newbox;
	fprintf_log(filelog,stdout,pmsg(MSG_CMD_STRUCT_TOOLS_DESTRUCT),items);
	return items;
}

/* показать текущую строку в list_box->next указателе */

void show_current_line(struct list_box * s1,int show_desciption){ // показать текущую строку
    if(show_desciption){
        fprintf_log(filelog,stdout,"_______________________________________________________________________________________\n");
        fprintf_log(filelog,stdout,pmsg(MSG_CMD_DISPLAY_HEAD));
    }
	fprintf_log(filelog,stdout,"|%-18s|%-25s|%-19s|%-20s|\n",s1->VIN,s1->Fullname,s1->Model,s1->Brand);
}

