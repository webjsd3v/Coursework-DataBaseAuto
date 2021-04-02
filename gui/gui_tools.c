#include "gui_tools.h"

void cls_line(WINDOW *menu_win,int i_line,int i_indent,int i_stop){ //фиксированное удаление строки
    char sz_tchar[1024] = {0}; int i_counter = 0;
    while(i_counter < i_stop){
        if(i_counter < 1024){
            sz_tchar[i_counter] = ' ';
        }
        i_counter++;
    }
    sz_tchar[i_counter] = 0;
    mvwprintw(menu_win,i_line,i_indent,"%s",sz_tchar);
}

char * gui_dynamic_buffer(WINDOW * w_temp,int start_y,int start_x, const char * sz_template,char * t_buffer,size_t sz_lenbuffer){ // буфер , с возможностью автозаполнения по шаблону
    char sz_templatein[1024] = {0};
    strcpy(sz_templatein,sz_template);
    if(strlen(sz_templatein) == 0) strcpy(sz_templatein,"");
    int pos = 0;
    int current_y = start_y, current_x = start_x;
    mvwaddstr(w_temp,start_y,current_x,sz_templatein);
    wrefresh(w_temp);
    current_x += strlen(sz_templatein);
    pos += strlen(sz_templatein);
    strcpy(t_buffer,sz_templatein);

    while(1){
        int i_endwhile = 0;
        int ss1,ss2; getbegyx(w_temp,ss1,ss2); // получить координаты 0 -й точки текущего окна
         curs_set(2); move(ss1+current_y,ss2+current_x); // включить жирный курсор и переместиться на нужную позицию
         mvaddch(ss1+current_y,ss2+current_x,' '); // деаем отступ
        int get_tchar = getch();
         curs_set(0); // выключить курсор
        switch(get_tchar){
            case 10 :{
                i_endwhile = 1;
                wrefresh(w_temp);
                break;
            }
            case 8 :{
                if(pos != 0){
                    mvwaddch(w_temp,current_y,--current_x,' '); // очищаем символ , если нажали блекспейс

                    --pos;
                    wrefresh(w_temp);
                }
                break;
            }
            default :{
                if(pos < sz_lenbuffer){ // стандартный , любой символ
                    mvwaddch(w_temp,current_y,current_x++,get_tchar);
                    t_buffer[pos] = get_tchar ;
                    pos++;
                    wrefresh(w_temp);
                }

            }
        }
        if(i_endwhile) break;

    }
    t_buffer[pos] = '\0'; // закрываем массив
    return t_buffer;
}

void gui_del_element(int choice_list,struct list_box * s_str){
    int i_count_l = 0;struct list_box * s1_stemp;
    if(s_str == NULL){
        s1_stemp = default_list; // создаем указатель на начало первого элемента
        while(i_count_l != (choice_list-1) ){ // выполняем перебор до определенного элемента
        if(s1_stemp->next != NULL){
            s1_stemp = s1_stemp->next;
        }
        i_count_l++;
        }
    }else{
        s1_stemp = s_str;
    }

    if(debug_mode){ // проверяем в режиме откладки удаленные данные
        char sz_tempstr[1024];
        sprintf(sz_tempstr,pmsg(MSG_GUI_TOOLS_MSG1),i_count_l,choice_list,s1_stemp->VIN);
        sys_gui_msg(sz_tempstr); // выводим системное сообщение
    }
    deleteNote(&default_list,s1_stemp->VIN); // удаляем найденый элемент после перебора
}


