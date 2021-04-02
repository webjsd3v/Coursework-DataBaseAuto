#ifndef _DELETE_H
    #include "delete.h"
#endif // _DELETE_H
int deleteNote(struct list_box ** s_struct, char * VIN){ // удаление конкретного VIN со структуры

	struct list_box * target = *s_struct;
	/* Если таблица пуста */
	if(!get_countofrec(target)){
		fprintf_log(filelog,stderr,pmsg(MSG_CMD_DELETE_TEMPTY));
		return 2;
	}
	/* Если VIN не найден */
	if(is_duplicate(VIN,target) == 0 ){
		fprintf_log(filelog,stderr,pmsg(MSG_CMD_DELETE_VNF),VIN);
		return 2;
	}
	struct list_box * s_temp  = target ;
	if(s_temp == NULL ) return 2; // if found err memory
	list_box * previous = get_previous(target,VIN); // получить предыдущий элемент

	if(strcmp(previous->VIN,VIN ) == 0){
		fprintf_log(filelog,stdout,pmsg(MSG_CMD_DELETE_EFT));
		deleteFirst(s_struct);
		fprintf_log(filelog,stdout,pmsg(MSG_CMD_DELETE_OK),VIN);
		return 1;

	}
	list_box * delTarget = previous->next;

	if((delTarget!=NULL) && (strcmp(delTarget->VIN,VIN) == 0 ) ) { // если все хорошо , удаляем с кучи
		previous->next = delTarget->next;
		free(delTarget->Fullname);
		free(delTarget->Brand);
		free(delTarget->Model);
		free(delTarget->VIN);

		free(delTarget);
		fprintf_log(filelog,stdout,pmsg(MSG_CMD_DELETE_OK),VIN);
		return 0;
	}
	fprintf_log(filelog,stdout,pmsg(MSG_CMD_DELETE_ERR2),VIN);
	return 1;
}

void deleteFirst(struct list_box** list) // проверка первого элемента на удаление
{
  struct list_box* temp = *list;
  if (*list != NULL)
  {
    *list = (*list)->next;
    free(temp->Fullname);
    free(temp->Brand);
    free(temp->Model);
    free(temp->VIN);
    free(temp);
  }
}

void con_delete(struct list_box** s_temp){ // функция удаления записи
    char VIN[32];
    puts(pmsg(MSG_CMD_DELETE_CON_HELP));
    if(1 != scanf("%31s",VIN) ){ // получаем строку
       fprintf_log(filelog,stderr,pmsg(MSG_CMD_DELETE_CON_ERR));
    }else{
        deleteNote(&*s_temp,VIN);
    }

}

/* scan and find previous id */
/* --- START --- */
struct list_box * get_previous(struct list_box * first_id,char * VIN){ // возвращает предыдущий элемент
	if(first_id == NULL) return NULL;
	if(strcmp(VIN,first_id->VIN) == 0) return first_id;
	list_box * previous = first_id,*now = first_id;
	if((now = now->next) == NULL ) return now = NULL;

	if(strcmp(VIN,now->VIN) == 0) return previous;

	while(now != NULL){

		previous = now;
		now = now->next;
		if(strcmp(VIN,now->VIN) == 0) return previous;
	}

	return previous = NULL;
}
/* Get count of records */
