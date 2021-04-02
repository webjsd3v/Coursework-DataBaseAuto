
#ifndef _MAIN_STRUCT_H
	#define _MAIN_STRUCT_H
		typedef struct list_box{
		char * Fullname;
		char * Brand;
		char * Model;
		char * VIN;
		struct list_box * next;
	}list_box;

	struct list_box * default_list;

#endif
