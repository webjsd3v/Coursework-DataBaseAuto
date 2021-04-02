#include <locale.h>
#include "global_va.h"
#include "./functions/functions.h"
#include "./gui/gui_functions.h"
#include "main_struct.h"
#include "gui_structs.h"
#include "gui_menu.h"
#include "./functions/menu.h"

int main(int argc, char * argv[]){
    setlocale(LC_ALL, ".1251");
    system("chcp 1251 >NULL");
    unitd(argc,argv);

    if(argc < 4 && argc > 1) s_loaded_file(&default_list,argc,argv);

    gui_menu(); // Начальная загрузка начинается с GUI меню

    menu(); // начало работы програи. меню

	destroyStruct(&default_list); // удалить все записи

	return 0;
}

