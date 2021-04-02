#ifndef _PRINTLOG_H
    #include "printlog.h"
#endif // _PRINTLOG_H
// функция для контроля вывода одновременно в два потока ( в файл и на экран )
int fprintf_log(char * filelog,FILE * descriptor,const char *format, ...)
{

	int log_enable = 0,i_countf = 0;
	if((strlen(filelog) == 0 ) ) { // если пришел аргумент filelog(название лог файла) и он пуст

	}else{
        log_enable = 1; // это нужно для проверки , включено ли логирование
	}

   va_list arg; //

   va_start (arg, format); // инициализируем список аргументов

	if(log_enable){
        FILE * logpf;
        if((logpf = fopen(filelog,"a+")) == NULL){ // проверка на открытие файла ( a+ - режим чтения + добавления в конец )
            fprintf(stderr,pmsg(MSG_CMD_LOAD_FOE));
            fclose(logpf);
            return 0;
        }
		vfprintf (logpf, format, arg); // выводим в файл
		if(!is_gui) i_countf = vfprintf (descriptor, format, arg); // и в консоль
		fclose(logpf); // закрываем файл
	}else{
	    if(!is_gui) i_countf = vfprintf (descriptor, format, arg); // выводим просто в консоль
        //если графический режим не включен
	}

   va_end (arg);
    return i_countf;
}
