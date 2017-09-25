#include <stdio.h>
/*
 	First comment
*/
void hello(){}
int main(){
	/*
		Second comment
	*/
	hello();
	char *str = "#include <stdio.h>%c/*%c%cFirst comment%c*/%cvoid hello(){}%cint main(){%c%c/*%c%c%cSecond comment%c%c*/%c%chello();%c%cchar *str = %c%s%c;%c%cprintf(str, 10, 10, 9, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10);%c%creturn (0);%c}%c";
	printf(str, 10, 10, 9, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10);
	return (0);
}
