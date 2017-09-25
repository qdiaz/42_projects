#include <stdio.h>
/*
	comment
*/

#define first 0
#define second 1
#define FT()int main(){FILE *f;char *str="#include <stdio.h>%c/*%c%ccomment%c*/%c%c#define first 0%c#define second 1%c#define FT()int main(){FILE *f;char *str=%c%s%c;if(!(f=fopen(%cGrace_kid.c%c, %cw%c))){return(0);}fprintf(f, str, 10, 10, 9, 10, 10, 10, 10, 10, 34, str, 34, 34, 34, 34, 34, 10, 10);fclose(f);return(0);}%cFT()%c";if(!(f=fopen("Grace_kid.c", "w"))){return(0);}fprintf(f, str, 10, 10, 9, 10, 10, 10, 10, 10, 34, str, 34, 34, 34, 34, 34, 10, 10);fclose(f);return(0);}
FT()
