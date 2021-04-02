#include "misc.h"
// поменять местами байты в стринге
void swap_byte(unsigned char *x, unsigned char *y) { // функция смешивания
	unsigned char tmp = *x;

	*x = *y; *y = tmp;
}

/* strcmp модифицированный , без чувствительности регистра */
/* для совместимости платформ LINUX */

int strcmp_multi_i (const char *p1, const char *p2)
{
  register unsigned char *s1 = (unsigned char *) p1;
  register unsigned char *s2 = (unsigned char *) p2;
  unsigned char c1, c2;

  do
  {
      c1 = (unsigned char) toupper((int)*s1++);
      c2 = (unsigned char) toupper((int)*s2++);
      if (c1 == '\0')
      {
            return c1 - c2;
      }
  }
  while (c1 == c2);

  return c1 - c2;
}

// макрос для fflush ( очищения потоков ввода )

void clrstdin(){
    fseek(stdin,0,SEEK_END); // фокус покус
}
// показать текущее время
char * get_current_time(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime(&rawtime);
    return asctime(timeinfo);
}

// добавить троеточия , в случае переполнения лимита в строке
char * ell(const char * s1,int i_max){
	char sz_test[999];
	char * tbox = sz_test;
	int len = 0;
	while(*s1 != 0){
		if(i_max == len){
			break;
		}
		*tbox = *s1;
		s1++;tbox++;len++;
	}
	*tbox = '\0';
	tbox -=len;
	if(strlen(s1) > i_max-3){
		sprintf(tbox, "%s...", tbox);
	}else{
		sprintf(tbox, "%s", tbox);
	}
	return tbox;
}
