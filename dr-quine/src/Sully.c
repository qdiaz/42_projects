#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define WRITE(fd,s,i) dprintf(fd,s,10,34,i,s)
#define OPEN(file) open(file,O_CREAT|O_WRONLY,0644)
#define FILENAME(filename,i) sprintf(filename,"Sully_%d.c",i)
#define COMP(filename,comp,i) sprintf(comp,"gcc -Wall -Werror -Wextra -o Sully_%d %s",i,filename)
#define BIN(bin,i) sprintf(bin,"./Sully_%d",i)
#define EXEC(comp) system(comp)
#define MAIN(s) int main(){int i=5;if(i<=0){return(0);}char *env=getenv("_");if(strstr(env,"./Sully_")){i--;}char filename[1000];FILENAME(filename,i);WRITE(OPEN(filename),s,i);char comp[1000];COMP(filename,comp,i);EXEC(comp);char bin[1000];BIN(bin,i);EXEC(bin);}
MAIN("#include <stdio.h>%1$c#include <fcntl.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c#define WRITE(fd,s,i) dprintf(fd,s,10,34,i,s)%1$c#define OPEN(file) open(file,O_CREAT|O_WRONLY,0644)%1$c#define FILENAME(filename,i) sprintf(filename,%2$cSully_%%d.c%2$c,i)%1$c#define COMP(filename,comp,i) sprintf(comp,%2$cgcc -Wall -Werror -Wextra -o Sully_%%d %%s%2$c,i,filename)%1$c#define BIN(bin,i) sprintf(bin,%2$c./Sully_%%d%2$c,i)%1$c#define EXEC(comp) system(comp)%1$c#define MAIN(s) int main(){int i=%3$d;if(i<=0){return(0);}char *env=getenv(%2$c_%2$c);if(strstr(env,%2$c./Sully_%2$c)){i--;}char filename[1000];FILENAME(filename,i);WRITE(OPEN(filename),s,i);char comp[1000];COMP(filename,comp,i);EXEC(comp);char bin[1000];BIN(bin,i);EXEC(bin);}%1$cMAIN(%2$c%4$s%2$c)%1$c")
