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
        "******************************************** ������� *************************************************\n",
        "* 1.  create     | ������� ����� ������� . ��������� : <VIN> <������ ���> ; <�����> ; <������> ;      *\n",
        "* 2.  display    | �������� ��� ������                                                                *\n",
        "* 3.  search     | ����� ������ � ���� ������ . <name> ��� <�������� �������> <������>                *\n",
        "* 4.  debug!     | ����� ������� ��� , ����                                                           *\n",
        "* 5.  delete     | ������� ������ � ������� . ��������� <VIN>                                         *\n",
        "* 6.  get_count  | ���������� �������                                                                 *\n",
        "* 7.  help       | ( �������� ��� ������� )                                                           *\n",
        "* 8.  clearall   | ������� ��� ������                                                                 *\n",
        "* 9.  sort       | ���������� ��������� . ��������� <by> <���> <desc>                                 *\n",
        "* 10. save       | ��������� � ���� <��� �����.������> <����> <encrypt>                               *\n",
        "* 11. edit       | �������������� �������� . ��������� <���. ������> ; <�������> by <�������> <������>*\n",
        "* 12. load       | ��������� ����. ��������� <��� �����.������> <����>                                *\n",
        "* 12. menu ��� m | �������� ����������� �����                                                         *\n",
        "* 12. lang       | ������� ���� EN,RU(Beta)                                                           *\n",
        "* 13. Exit       | ����� �� ���������                                                                 *\n",
        "*******************************************************************************************************\n"
    };
    const char * sz_con_help_rus[] = {
        "************************* ? ************************ \n",
        "*                                                  * \n",
        "* ������������ -h -? --help -fout -f ��� ��������� * \n",
        "* 1.  -f -fout=filename.xxx | �������� ����������� * \n",
        "* 2.  -h -help | �������� ��� ������� ���������    * \n",
        "* 2.  -? | �������� ���� �����                     * \n",
        "*                                                  * \n",
        "*********************** ����� ********************** \n"
    };

    int sz_con_help_max = sizeof(sz_con_help) / sizeof(const char*); // �������� ������ ������ sz_help
    int sz_con_help_max_rus = sizeof(sz_con_help_rus) / sizeof(const char*); // �������� ������ ������ sz_help
    int sz_help_max = sizeof(sz_help) / sizeof(const char*); // �������� ������ ������ sz_help
    int sz_help_rus_max = sizeof(sz_help_rus) / sizeof(const char*); // �������� ������ ������ sz_help
	void terminal_help(){ // ����� ������� � ������� ����� �������� -h --help
        int i;
        puts("\n");
        switch(short_lang_data){ // ������������� ����� �������
            case 1 : {
                for(i = 0 ; i < sz_con_help_max_rus ;i++) fprintf_log(filelog,stdout,"%s",sz_con_help_rus[i]); // ���������� ������
                break;
            }
            default:
                for(i = 0 ; i < sz_con_help_max ;i++) fprintf_log(filelog,stdout,"%s",sz_con_help[i]); // ���������� ������
        }

    }

    void con_help(){ // ����� ������� � ��������� ��������� help
        int i;
        puts("\n");
        switch(short_lang_data){ // ������������� ����� �������
            case 1 : {
                for(i = 0 ; i < sz_help_rus_max ;i++) fprintf_log(filelog,stdout,"%s",sz_help_rus[i]);  // ���������� ������
                break;
            }
            default :
                for(i = 0 ; i < sz_help_max ;i++) fprintf_log(filelog,stdout,"%s",sz_help[i]); // ���������� ������
        }
    }
