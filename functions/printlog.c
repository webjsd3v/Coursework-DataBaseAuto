#ifndef _PRINTLOG_H
    #include "printlog.h"
#endif // _PRINTLOG_H
// функция для контроля вывода одновременно в два потока ( в файл и на экран )
int fprintf_log(char * filelog,FILE * descriptor,const char *format, ...)
{

	int log_enable = 0,i_countf = 0;
	if((strlen(filelog) == 0 ) ) {

	}else{
        log_enable = 1;
	}

   va_list arg;

   va_start (arg, format);

	if(log_enable){
        FILE * logpf;
        if((logpf = fopen(filelog,"a+")) == NULL){
            fprintf(stderr,pmsg(MSG_CMD_LOAD_FOE));
            fclose(logpf);
            return 0;
        }
		vfprintf (logpf, format, arg);
		if(!is_gui) i_countf = vfprintf (descriptor, format, arg);
		fclose(logpf);
	}else{
	    if(!is_gui) i_countf = vfprintf (descriptor, format, arg);

	}

   va_end (arg);
    return i_countf;
}
