#include "unist.h"
// поддержка консольный параметров для запуска программы
int unitd(int argc,char * argv[]){
	const char* short_options = "h?f::";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"fout",optional_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index;
	while((rez = getopt_long(argc,argv,short_options,long_options,&option_index)) != -1){
        switch(rez){
            case 'h' :{
                con_help();
                exit(1);
                break;

            }
            case 'f' :{
				if (optarg!=NULL){
                    fprintf_log(filelog,stdout,"Logfile %s\n",optarg);
					strcpy(filelog,optarg);
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_UNIST_STALOG), get_current_time());
				}else{
					fprintf_log(filelog,stdout,"Using default Logfile.log \n");
					strcpy(filelog,"Logfile.log");
                    fprintf_log(filelog,stdout,pmsg(MSG_CMD_UNIST_STALOG), get_current_time());
				}
				break;
            }
            case '?' : default :{
                terminal_help(); //вызвать справку
                exit(1);
                break;
            }
        }
        option_index = -1; // снова делаем ошибку
	}
	return 0;
}
