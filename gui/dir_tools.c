#ifndef _DIR_TOOLS_H
    #include "dir_tools.h"
#endif // _DIR_TOOLS_H



char * get_fnbynum(int i_fnum){ //узнать название файла по номеру
	DIR *dp;
	int i_cou = 0;
	struct dirent *ep;

	dp = opendir ("./");
	if (dp != NULL)
	{
		while ( ( ep = readdir (dp) ) ){
			if(i_cou == i_fnum) break;
			i_cou++;
		}

		(void) closedir (dp);
	}
	return ep->d_name;
}

int get_coffile(DIR *dp){ // получить количество результатов содержимого в определенной папке
	int i_fcount = 0;
	struct dirent *ep;
	if (dp != NULL)
	{
	  while ( ( ep = readdir(dp) ) ){
            i_fcount++;
	  }
	  (void) closedir (dp);
	}
	return i_fcount;
}
