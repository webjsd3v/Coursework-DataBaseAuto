#ifndef _CON_HELP_H
	#include "con_help.h"
#endif
    const char * sz_help[] = {
        "***************************************** HELP **********************************************\n",
        "* 1.  create    | to create new item . Syntax : <VIN> <Fullname> ; <Brand> ; <Model> ;      *\n",
        "* 2.  display   | to list all things                                                        *\n",
        "* 3.  search    | to find any things in database . <name> where <column> <data>             *\n",
        "* 4.  debug!    | debug on , off                                                            *\n",
        "* 5.  delete    | delete VIN from table . Syntax <VIN>                                      *\n",
        "* 6.  get_count | count of entries                                                          *\n",
        "* 7.  help      | simple instruction                                                        *\n",
        "* 8.  clearall  | clear all entries                                                         *\n",
        "* 9.  sort      | sorting elements Syntax <by> <name> <desc>                                *\n",
        "* 10. save      | save to file all things <filename> <key> <encrypt>                        *\n",
        "* 11. edit      | edit element . Syntax <new data> ; <name of column>  by <column> <data>   *\n",
        "* 12. load      | load new base . Syntax <filename> <key>                                   *\n",
        "* 12. menu      | Open GUI menu                                                             *\n",
        "* 12. lang      | Change language EN,RU(Beta)                                               *\n",
        "* 13. Exit      | quit from program                                                         *\n",
        "*********************************************************************************************\n"
    };
    const char * sz_con_help[] = {
        "******************** ? ******************** \n",
        "*                                         * \n",
        "* use -h -? --help -fout -f as parameters * \n",
        "* 1.  -f -fout=filename.xxx | on logging  * \n",
        "* 2.  -h -help | show a brief con help    * \n",
        "* 2.  -? | show this screen               * \n",
        "*                                         * \n",
        "******************** END ****************** \n"
    };

    const char * sz_help_rus[] = {
        "******************************************** Справка *************************************************\n",
        "* 1.  create     | Создать новый элемент . Синтаксис : <VIN> <Полное имя> ; <Марка> ; <Модель> ;      *\n",
        "* 2.  display    | Показать все записи                                                                *\n",
        "* 3.  search     | Найти запись в базе данных . <name> где <название колонки> <данные>                *\n",
        "* 4.  debug!     | Режим отладки вкл , выкл                                                           *\n",
        "* 5.  delete     | Удалить запись с таблицы . Синтаксис <VIN>                                         *\n",
        "* 6.  get_count  | Количество записей                                                                 *\n",
        "* 7.  help       | ( показать эту справку )                                                           *\n",
        "* 8.  clearall   | Удалить все записи                                                                 *\n",
        "* 9.  sort       | Сортировка элементов . Синтаксис <by> <имя> <desc>                                 *\n",
        "* 10. save       | Сохранить в файл <имя файла.формат> <ключ> <encrypt>                               *\n",
        "* 11. edit       | Редактирование элемента . Синтаксис <нов. данные> ; <колонка> by <колонка> <данные>*\n",
        "* 12. load       | Загрузить базу. Синтаксис <имя файла.формат> <ключ>                                *\n",
        "* 12. menu иди m | Включить графический режим                                                         *\n",
        "* 12. lang       | Сменить язык EN,RU(Beta)                                                           *\n",
        "* 13. Exit       | Выход из программы                                                                 *\n",
        "*******************************************************************************************************\n"
    };
    const char * sz_con_help_rus[] = {
        "************************* ? ************************ \n",
        "*                                                  * \n",
        "* Использовать -h -? --help -fout -f как параметры * \n",
        "* 1.  -f -fout=filename.xxx | включить логирование * \n",
        "* 2.  -h -help | Показать все команды программы    * \n",
        "* 2.  -? | Показать этот экран                     * \n",
        "*                                                  * \n",
        "*********************** КОНЕЦ ********************** \n"
    };

    int sz_con_help_max = sizeof(sz_con_help) / sizeof(const char*); // получить размер масива sz_help
    int sz_con_help_max_rus = sizeof(sz_con_help_rus) / sizeof(const char*); // получить размер масива sz_help
    int sz_help_max = sizeof(sz_help) / sizeof(const char*); // получить размер масива sz_help
    int sz_help_rus_max = sizeof(sz_help_rus) / sizeof(const char*); // получить размер масива sz_help
	void terminal_help(){ // вывод справки с консоси через параметр -h --help
        int i;
        puts("\n");
        switch(short_lang_data){ // переключаемся между языками
            case 1 : {
                for(i = 0 ; i < sz_con_help_max_rus ;i++) fprintf_log(filelog,stdout,"%s",sz_con_help_rus[i]); // перебираем массив
                break;
            }
            default:
                for(i = 0 ; i < sz_con_help_max ;i++) fprintf_log(filelog,stdout,"%s",sz_con_help[i]); // перебираем массив
        }

    }

    void con_help(){ // вывод справки в программе коммандой help
        int i;
        puts("\n");
        switch(short_lang_data){ // переключаемся между языками
            case 1 : {
                for(i = 0 ; i < sz_help_rus_max ;i++) fprintf_log(filelog,stdout,"%s",sz_help_rus[i]);  // перебираем массив
                break;
            }
            default :
                for(i = 0 ; i < sz_help_max ;i++) fprintf_log(filelog,stdout,"%s",sz_help[i]); // перебираем массив
        }
    }
